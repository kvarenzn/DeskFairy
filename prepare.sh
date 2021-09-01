#!/usr/bin/bash

CUBISM_SDK_VERSION="4-r.3"
CUBISM_SDK_DIR="CubismSdkForNative-${CUBISM_SDK_VERSION}"
CUBISM_SDK_ZIP="${CUBISM_SDK_DIR}.zip"
CUBISM_URL="https://cubism.live2d.com/sdk-native/bin/${CUBISM_SDK_ZIP}"

prepare_cubism_sdk() {
	mkdir downloads
	wget $CUBISM_URL -O downloads/${CUBISM_SDK_ZIP}
	cd downloads
	
	# PWD=./downloads
	unzip ${CUBISM_SDK_ZIP}
	cd ${CUBISM_SDK_DIR}

	# PWD=./downloads/${CUBISM_SDK_DIR}
	mkdir ../../3rdparty/cubismcore/
	mv ./Core/include/ ../../3rdparty/cubismcore/include
	mv ./Core/dll/linux/x86_64/ ../../3rdparty/cubismcore/lib
	cd ../../

	# PWD=./
	rm -rf ./downloads/
}


prepare_cubism_sdk
