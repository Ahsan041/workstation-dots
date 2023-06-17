(self: super: {
  picom = super.picom.overrideAttrs (oldAttrs: {
    pname = "picom-ftlabs";
    version = "1.0";
    src = fetchTarball {
        url = "https://gitlab.com/ahsanur041/picom-ftlabs/-/archive/1.0/picom-ftlabs-1.0.tar.gz";
    };
    buildInputs = oldAttrs.buildInputs ++ (with super; [ cmake libev git pcre2 ]);
  });
})
