(self: super: {
  st = super.st.overrideAttrs (oldAttrs: {
    pname = "st-ar";
    version = "1.0.0";
    src = fetchTarball {
        url = "https://gitlab.com/ahsanur041/st-ar/-/archive/1.0/st-ar-1.0.tar.gz";
    };
    buildInputs = oldAttrs.buildInputs ++ (with super; [ harfbuzz ]);
  });
})
