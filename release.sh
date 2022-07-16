#!/usr/bin/bash

DESKFAIRY_RELEASE_VERSION="v0.3"
DESKFAIRY_RELEASE_DIR="DeskFairy_${DESKFAIRY_RELEASE_VERSION}"
DESKFAIRY_RELEASE_RAR="${DESKFAIRY_RELEASE_DIR}.rar"
DESKFAIRY_RELEASE_URL="https://github.com/NeuraXmy/DeskFairy/releases/download/${DESKFAIRY_RELEASE_VERSION}/${DESKFAIRY_RELEASE_RAR}"


download_resources() {
	mkdir downloads
	cd downloads
	wget $DESKFAIRY_RELEASE_URL -O $DESKFAIRY_RELEASE_RAR
	unrar x $DESKFAIRY_RELEASE_RAR
	mv $DESKFAIRY_RELEASE_DIR/resources ../release/
	cd ..
	rm -rf downloads
}

mkdir release
mv build/DeskFairy release/
download_resources
