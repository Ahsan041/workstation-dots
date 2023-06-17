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
    (import ./picom-overlay.nix)
  ];

  # Make ready  for nix flakes
  nix.settings.experimental-features = [ "nix-command" "flakes" ];

  # Bootloader.
  boot.loader = {
    systemd-boot.enable = true;
    efi.canTouchEfiVariables = true;
    efi.efiSysMountPoint = "/boot/efi";   
  };
  
  # Setup keyfile
  boot.initrd.secrets = {
    "/crypto_keyfile.bin" = null;
  };

  boot.kernelParams = [ 
    "module_blacklist=i915" 
    "slub_debug=FZP"
    "page_poison=1"
    "page_alloc.shuffle=1"
  ];

  boot.kernelModules = [ "kvm-intel" ];
  boot.kernelPackages = pkgs.linuxPackages_6_1_hardened;

  boot.kernel.sysctl."kernel.unprivileged_userns_clone" = mkDefault "1";


  boot.blacklistedKernelModules = [ 
    "ax25"
    "netrom"
    "rose" 
    "adfs"
    "affs"
    "bfs"
    "befs"
    "cramfs"
    "efs"
    "erofs"
    "exofs"
    "freevxfs"
    "f2fs"
    "hfs"
    "hpfs"
    "jfs"
    "minix"
    "nilfs2"
    "ntfs"
    "omfs"
    "qnx4"
    "qnx6"
    "sysv"
    "ufs"
    "firewire-core"
    "dccp"
    "sctp"
    "rds"
    "tipc"
  ];

  security = {
    lockKernelModules = mkDefault true;
    protectKernelImage = mkDefault true;
    allowSimultaneousMultithreading = mkDefault false;
    forcePageTableIsolation = mkDefault true;
    virtualisation.flushL1DataCache = mkDefault "always";
    apparmor.enable = mkDefault true;
    apparmor.killUnconfinedConfinables = mkDefault true;
    auditd.enable = mkDefault true;
  };

  # Restrict ptrace() usage to processes with a pre-defined relationship
  # (e.g., parent/child)
  boot.kernel.sysctl = {
    "kernel.yama.ptrace_scope" = mkOverride 500 1;
    "kernel.kptr_restrict" = mkOverride 500 2;
    "kernel.sysrq" = mkDefault "0";
    "kernel.unprivileged_bpf_disabled" = mkDefault "1";
    "dev.tty.ldisc_autoload" = mkDefault "0";
    "net.core.bpf_jit_enable" = mkDefault false;
    "kernel.ftrace_enabled" = mkDefault false;
    "net.ipv4.conf.all.log_martians" = mkDefault true;
    "net.ipv4.conf.all.rp_filter" = mkDefault "1";
    "net.ipv4.conf.default.log_martians" = mkDefault true;
    "net.ipv4.conf.default.rp_filter" = mkDefault "1";
    "net.ipv4.icmp_echo_ignore_broadcasts" = mkDefault true;
    "net.ipv4.conf.all.accept_redirects" = mkDefault false;
    "net.ipv4.conf.all.secure_redirects" = mkDefault false;
    "net.ipv4.conf.default.accept_redirects" = mkDefault false;
    "net.ipv4.conf.default.secure_redirects" = mkDefault false;
    "net.ipv6.conf.all.accept_redirects" = mkDefault false;
    "net.ipv6.conf.default.accept_redirects" = mkDefault false;
    "net.ipv4.conf.all.send_redirects" = mkDefault false;
    "net.ipv4.conf.default.send_redirects" = mkDefault false;
  #  "fs.protected_fifos" = mkDefault "2";
  #  "fs.protected_regular" = mkDefault "2";
  #  "fs.suid_dumpable" = mkDefault "0";
  };

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
      wallpaper.mode = "fill";
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
        i3-resurrect
        autotiling-rs
        polybar 
        dunst        
      ];
    };
    videoDrivers = [ "intel" "nvidia" ];
  };

  services.sysstat.enable = true;

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
    xfce.thunar
    pfetch
    nodejs
    zathura
    linuxHeaders
    lynis
    papirus-icon-theme
    starship
    lxappearance 
    brave
    git
    pymol
    htop
    emacs-gtk
    mpv
    bleachbit
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
    aide
    fd
    libev
    ckb-next
    evince
    btop
    eww
    bat
    ckb-next
    neovim
    haveged
    xarchiver
    st
    killall
    plymouth
    evince
    xournalpp
    qt5ct
    acct
    tabnine
    libsForQt5.qtstyleplugins
    texlive.combined.scheme-medium
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
    memoryAllocator.provider = mkDefault "scudo";
    shells = with pkgs; [ zsh ];
    variables = {
      SCUDO_OPTIONS = mkDefault "ZeroContents=1";
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

  services.emacs.enable = false;
  services.emacs.install = true;
  #services.emacs.package = import /home/ahsan/.emacs.d { pkgs = pkgs; };

  environment.etc = {
    issue = {
      text = ''
  -- WARNING -- This system is for the use of authorized users only. Individuals 
  using this computer system without authority or in excess of their authority 
  are subject to having all their activities on this system monitored and 
  recorded by system personnel. Anyone using this system expressly consents to 
  such monitoring and is advised that if such monitoring reveals possible 
  evidence of criminal activity system personal may provide the evidence of such 
  monitoring to law enforcement officials.
  '';
      mode = "0440";
    };
  };

  system.stateVersion = "23.05"; # Did you read the comment?
}
