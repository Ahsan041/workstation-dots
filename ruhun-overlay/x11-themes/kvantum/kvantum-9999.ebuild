# Copyright 1999-2023 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2

EAPI=8

inherit cmake xdg

DESCRIPTION="SVG-based theme engine for Qt5, KDE Plasma and LXQt"
HOMEPAGE="https://github.com/tsujan/Kvantum"
EGIT_REPO_URI="https://github.com/tsujan/Kvantum.git"

LICENSE="GPL-3"
SLOT="0"
KEYWORDS="~amd64"
IUSE=""

DEPEND="
	dev-qt/qtcore:6
	dev-qt/qtgui:6
	dev-qt/qtsvg:6
	dev-qt/qtwidgets:6
	dev-qt/qtx11extras:6
	kde-frameworks/kwindowsystem:5
	x11-libs/libX11
	x11-libs/libXext
"
RDEPEND="${DEPEND}"
BDEPEND="dev-qt/linguist-tools:5"
