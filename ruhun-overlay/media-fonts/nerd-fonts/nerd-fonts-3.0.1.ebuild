# Copyright 2023 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2
#
# This ebuild is derived from http://gpo.zugaina.org/Overlays/ROKO__ and http://gpo.zugaina.org/Overlays/gentoo-zh
# TODO: FontPatcher is not yet included in this ebuild. Will do that later, but PR are welcome :)

EAPI=8

inherit font check-reqs

DESCRIPTION="Collection of fonts that are patched to include a high number of glyphs (icons)."
HOMEPAGE="https://nerdfonts.com"
RESTRICT="mirror"

LICENSE="MIT
		OFL-1.1
		Apache-2.0
		CC-BY-SA-4.0
		BitstreamVera
		BSD
		WTFPL-2
		Vic-Fieger-License
		UbuntuFontLicense-1.0"
SLOT="0"
KEYWORDS="~amd64 ~x86"

DIRNAME=(
  FiraCode
  JetBrainsMono
  NerdFontsSymbolsOnly
  SourceCodePro
  Ubuntu
  UbuntuMono
)

IUSE_FLAGS=(${DIRNAME[*],,})
IUSE="${IUSE_FLAGS[*]}"

MY_URI="https://github.com/ryanoasis/${PN}/releases/download/v${PV}"
TAG_URI="https://github.com/ryanoasis/nerd-fonts/raw/v${PV}"
SRC_URI="
	firacode?               ( "${MY_URI}/FiraCode.tar.xz" -> "FiraCode-${PV}.tar.xz"  )
	jetbrainsmono?          ( "${MY_URI}/JetBrainsMono.tar.xz" -> "JetBrainsMono-${PV}.tar.xz"  )
    nerdfontssymbolsonly?   ( "${MY_URI}/NerdFontsSymbolsOnly.tar.xz" -> "NerdFontsSymbolsOnly-${PV}.tar.xz"  "${TAG_URI}/10-nerd-font-symbols.conf" -> "10-nerd-font-symbols.conf-${PV}" )
	sourcecodepro?          ( "${MY_URI}/SourceCodePro.tar.xz" -> "SourceCodePro-${PV}.tar.xz"  )
	ubuntu?                 ( "${MY_URI}/Ubuntu.tar.xz" -> "Ubuntu-${PV}.tar.xz"  )
	ubuntumono?             ( "${MY_URI}/UbuntuMono.tar.xz" -> "UbuntuMono-${PV}.tar.xz"  )

DEPEND="app-arch/xz-utils"
RDEPEND="media-libs/fontconfig"

CHECKREQS_DISK_BUILD="4G"
CHECKREQS_DISK_USR="4G"

S="${WORKDIR}"
FONT_CONF=(
	"${FILESDIR}"/10-nerd-font-symbols.conf
)
FONT_S=${S}

pkg_pretend() {
	check-reqs_pkg_setup
}
src_prepare() {
	if use nerdfontssymbolsonly ; then
		install -m644 "${DISTDIR}/10-nerd-font-symbols.conf-${PV}" "${S}/10-nerd-font-symbols.conf" || die
	fi

	default
}

src_install() {
	declare -A font_filetypes
	local otf_file_number ttf_file_number

	otf_file_number=$(ls ${S} | grep -i otf | wc -l)
	ttf_file_number=$(ls ${S} | grep -i ttf | wc -l)

	if [[ ${otf_file_number} != 0 ]]; then
		font_filetypes[otf]=
	fi

	if [[ ${ttf_file_number} != 0 ]]; then
		font_filetypes[ttf]=
	fi

	FONT_SUFFIX="${!font_filetypes[@]}"

	font_src_install
}

pkg_postinst() {
	einfo "Installing font-patcher via an ebuild is hard, because paths are hardcoded differently"
	einfo "in .sh files. You can still get it and use it by git cloning the nerd-font project and"
	einfo "running it from the cloned directory."
	einfo "https://github.com/ryanoasis/nerd-fonts"

	elog "You might have to enable 50-user.conf and 10-nerd-font-symbols.conf by using"
	elog "eselect fontconfig"
}
