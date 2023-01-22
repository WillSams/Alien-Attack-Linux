# SDL2 Install Instructions

On Debian-based systems, do the following.

## Dependencies

```bash
sudo apt update
sudo aptinstall libxext-dev build-essential automake autoconf libtool
sudo aptinstall mesa-common-dev libasound2-dev libpulse-dev
sudo aptinstall libpng-dev libjpeg-dev libwebp-dev libtiff-dev libmodplug-dev
```

## SDL2 & Extensions

```bash
BUILD_DIR=~/build-sdl2
mkdir -p $BUILDDIR && cd $_

git clone https://github.com/libsdl-org/SDL -b SDL2
cd SDL
mkdir build && cd $_
../configure
make && sudo make install

cd $BUILDDIR
git clone https://github.com/libsdl-org/SDL_image
cd SDL_image
mkdir build && cd $_
../configure
make && sudo make install

cd $BUILDDIR
git clone https://github.com/libsdl-org/SDL_mixer
cd SDL_mixer
mkdir build && cd $_
../configure
make && sudo make install

cd $BUILDDIR
git clone https://gitlab.freedesktop.org/freetype/freetype.git
cd freetype && ./autogen.sh
make && sudo make install

cd $BUILDDIR
git clone https://github.com/libsdl-org/SDL_ttf
cd SDL_ttf
mkdir build && cd $_
../configure
make && sudo make install

cd $BUILDDIR
git clone https://github.com/libsdl-org/SDL_net
cd SDL_net
mkdir build && cd $_
../configure
make && sudo make install
```

You should be able to build Alien Attack.  To cleanup, execute `rm -rf $BUILDDIR`.
