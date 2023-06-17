pkgs:

{
  enable = true;
  vimAlias = true;
  extraConfig = ''
    luafile ./lua/user/options.lua
  '';

  plugins = with pkgs.vimPlugins; [

  ]

}

