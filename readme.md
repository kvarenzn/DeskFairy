# DeskFairy

A desktop pet based on Qt & Live2D

Supporting platform: Linux x64

Tested on `archlinux rolling x64`

## Requirements

+ Qt 5.15
+ Box2D
+ GLEW
+ Live2D Cubism SDK (this does not need to be installed manually)

## Build
1. Make sure you have `unzip`, `unar`, `wget`, `cmake`, `make` and a bash-like shell (`bash` or `zsh`) installed.
2. Install and configure the requirements mentioned above.
2. `cd` to the root directory of this project.
3. `./prepare.sh` or `bash ./prepare.sh`
4. `cmake -B ./build`
5. `cd ./build`
6. `make`
7. `cd ..`
8. `./release.sh` or `bash ./release.sh`

## Run
1. `cd release`
2. `./DeskFairy`
3. Enjoy.

## Changes
+ Removed support for Windows x64
+ Added support for Linux x64
+ Removed Touhou Launcher (perhaps WINE support may be added in the future)
+ Change of `ItemManager`: removed `b2MouseJoint`, use `b2_kinematicBody` now
+ Now, by default, the executable is at the same directory as `profile`, `screenshot` and `resoureces` 
