# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ lib, config, pkgs, ... }:

with lib;

{
  imports =
    [
      # Include the results of the hardware scan.
      ./hardware-configuration.nix
    ];

  nixpkgs.overlays = [
    (import ./st-overlay.nix)
  ];

  # Make ready  for nix flakes
  nix.settings.experimental-features = [ "nix-command" "flakes" ];

  # Bootloader.
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;
  boot.loader.efi.efiSysMountPoint = "/boot/efi";

  # Setup keyfile
  boot.initrd.secrets = {
    "/crypto_keyfile.bin" = null;
  };

  boot.kernelParams = [ "module_blacklist=i915" ];
  boot.kernelModules = [ "kvm-intel" ];
  boot.kernelPackages = pkgs.linuxPackages_6_1_hardened;

  boot.kernel.sysctl."kernel.unprivileged_userns_clone" = mkDefault "1";

  networking = {
    hostName = "nixos";
    wireless.enable = false;
    networkmanager.enable = true;
  };

  # Set your time zone.
  time.timeZone = "America/Edmonton";

  # Select internationalisation properties.
  i18n.defaultLocale = "en_CA.UTF-8";

  # Sound 
  sound.enable = false;
  security.rtkit.enable = true;
  services.pipewire = {
    enable = true;
    alsa.enable = true;
    pulse.enable = true;
  };

  # Configure keymap in X11
  services.xserver = {
    enable = true;
    layout = "us";
    xkbVariant = "";
    desktopManager = {
      xterm.enable = false;
    };
    excludePackages = [ pkgs.xterm ];
    displayManager = {
      defaultSession = "none+i3";
    };
    windowManager.i3 = {
      enable = true;
      extraPackages = with pkgs; [
        rofi
        i3lock-fancy-rapid
        i3-swallow
        polybar
        nitrogen
        dunst
      ];
    };
    videoDrivers = [ "intel" "nvidia" ];
  };

  services.picom.enable = true;

  hardware = {
    opengl.enable = true;
    nvidia = {
      package = config.boot.kernelPackages.nvidiaPackages.stable;
      powerManagement.enable = true;
    };
    ckb-next.enable = true;
  };

  fonts = {
    fontconfig = {
      subpixel = {
        rgba = "rgb";
        lcdfilter = "default";
      };
      hinting = {
        enable = true;
        style = "hintfull";
      };
      antialias = true;
    };
    fonts = with pkgs; [
      fira-code
      fira-code-symbols
      (nerdfonts.override { fonts = [ "FiraCode" "JetBrainsMono" ]; })
    ];
  };

  # Define a user account. Don't forget to set a password with ‘passwd’.
  users.users.ahsan = {
    isNormalUser = true;
    description = "Ahsanur Rahman";
    extraGroups = [ "networkmanager" "wheel" ];
    packages = with pkgs; [ ];
  };

  # Allow unfree packages
  nixpkgs.config.allowUnfree = true;

  # List packages installed in system profile. To search, run:
  # $ nix search wget
  environment.systemPackages = with pkgs; [
    wget
    xsel
    xclip
    mesa
    linux-firmware
    gnumake
    git
    xfce.thunar
    neofetch
    nodejs
    zathura
    linuxHeaders
    papirus-icon-theme
    starship
    lxappearance
    brave
    pymol
    htop
    emacs-gtk
    mpv
    transmission-gtk
    python3
    gcc12
    rustup
    cmake
    xfce.xfce4-power-manager
    xfce.xfconf
    pulsemixer
    vulkan-tools
    mc
    fd
    lazygit
    ckb-next
    evince
    btop
    eww
    bat
    ckb-next
    i3-resurrect
    i3-auto-layout
    neovim
    xarchiver
    st
    killall
    plymouth
    evince
    xournalpp
    qt5ct
    libsForQt5.qtstyleplugins
  ];

  programs.thunar.plugins = with pkgs.xfce; [
    thunar-archive-plugin
    thunar-volman
    thunar-media-tags-plugin
  ];

  services = {
    gvfs.enable = true;
    tumbler.enable = true;
    flatpak.enable = true;
  };

  xdg.portal = {
    enable = true;
    extraPortals = [ pkgs.xdg-desktop-portal-gtk ];
  };

  services.xserver.screenSection = ''
        Option         "Stereo" "0"
    Option         "nvidiaXineramaInfoOrder" "DFP-3"
    Option         "metamodes" "DP-2: nvidia-auto-select +2304+0 {viewportin=3096x1296, ForceCompositionPipeline=On}, DP-0: 2560x1440 +0+0 {viewportin=2304x1296, ForceCompositionPipeline=On}, DP-4: 2560x1440 +5400+0 {viewportin=2304x1296, ForceCompositionPipeline=On}"
    Option         "AllowIndirectGLXProtocol" "off"
    Option         "TripleBuffer" "on"
  '';

  programs.zsh.enable = true;
  users.defaultUserShell = pkgs.zsh;
  environment = {
    shells = with pkgs; [ zsh ];
    variables = {
      EDITOR = "nvim";
    };
  };

  qt = {
    enable = true;
    style = lib.mkForce "gtk2";
    platformTheme = lib.mkForce "gtk2";
  };

  # Autoupdate
  system.autoUpgrade = {
    enable = true;
    channel = "https://nixos.org/channels/nixos-unstable";
  };

  services.power-profiles-daemon.enable = true;
  systemd = {
    user.services.polkit-gnome-authentication-agent-1 = {
      description = "polkit-gnome-authentication-agent-1";
      wantedBy = [ "graphical-session.target" ];
      wants = [ "graphical-session.target" ];
      after = [ "graphical-session.target" ];
      serviceConfig = {
        Type = "simple";
        ExecStart = "${pkgs.polkit_gnome}/libexec/polkit-gnome-authentication-agent-1";
        Restart = "on-failure";
        RestartSec = 1;
        TimeoutStopSec = 10;
      };
    };
  };


  system.stateVersion = "23.05"; # Did you read the comment?
}
