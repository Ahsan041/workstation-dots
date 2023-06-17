{ config, pkgs, lib, ... }:

{
  home.username = "ahsan";
  home.homeDirectory = "/home/ahsan";

  home.stateVersion = "22.11";

  # Let Home Manager install and manage itself.
  programs.home-manager.enable = true;

  programs.neovim = import ./.config/nvim/nvim.nix pkgs;
  

  programs.gpg = {
    enable = true;
  };

  services.gpg-agent = {
    enable = true;
    pinentryFlavor = "gtk2";
  };

  programs.git = {
    enable = true;
    userName = "ahsanur041";
    userEmail = "ahsanur041@gmail.com";
  };

  home.packages = with pkgs; [
    git-crypt
    gnupg
    pinentry_gtk2
    gummy
  ];

  # qt = {
  #   enable = true;
  #   platformTheme = "gtk";
  # };

  programs.zsh = {
    enable = true;
    shellAliases = {
      ll = "ls -l";
      g = "lazygit";
      audit = "sudo lynis audit system";
      nix-up = "sudo nixos-rebuild switch --upgrade";
      home-up = "home-manager switch";
      clean = "sudo nix-collect-garbage && sudo nix-collect-garbage -d && sudo nixos-rebuild boot";
    };
    history = {
      save = 10000;
      size = 10000;
      path = "${config.xdg.dataHome}/zsh/history";
    };
    zplug = {
      enable = true;
      plugins = [
        { name = "zsh-users/zsh-autosuggestions"; }
        { name = "esc/conda-zsh-completion"; }
        { name = "hlissner/zsh-autopair"; }
        { name = "zap-zsh/supercharge"; }
        { name = "zap-zsh/vim"; }
        { name = "zap-zsh/zap-prompt"; }
        { name = "zap-zsh/fzf"; }
        { name = "zdharma-continuum/fast-syntax-highlighting"; }
        { name = "chisui/zsh-nix-shell"; }
      ];
    };
  };
}


