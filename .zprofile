if [ -z "${DISPLAY}" ] && [ "${XDG_VTNR}" -eq 1 ]; then
  exec i3
fi
LOCALE_ARCHIVE=$HOME/.nix-profile/lib/locale/locale-archive
