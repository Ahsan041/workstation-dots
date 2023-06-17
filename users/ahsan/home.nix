{ config, pkgs, lib, ... }:

{
  home.username = "ahsan";
  home.homeDirectory = "/home/ahsan";

  home.stateVersion = "22.11";

  # Let Home Manager install and manage itself.
  programs.home-manager.enable = true;

  programs.gpg = {
    enable = true;
  };

  services.gpg-agent = {
    enable = true;
    pinentryFlavor = "gtk2";
  };

  programs.neovim = {
    enable = true;
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
      nix-up = "sudo nixos-rebuild switch --upgrade";
      home-up = "home-manager switch";
      clean = "sudo nix-collect-garbage && sudo nix-collect-garbage -d && sudo nixos-rebuild boot";
    };
    history = {
      save = 10000;
      size = 10000;
      path = "${config.xdg.dataHome}/zsh/history";
    };
  };
}


