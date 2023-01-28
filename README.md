# Alien Attack

This is an example project from ['SDL Game Development' by Shaun Mitchell][1], a book originally published back in 2013.  The original source code for the book can now be found on Github [here][2].  If you are interested in learning more about [SDL (Simple DirectMedia Layer)][3] and making games, I highly recommend you buy this book.

I originally created this repo back in 2014 as I worked my way through the book.  In December 2022, I decided I wanted to pick up C/C++ games development again, unfortunately breaking any forked version of this repo.  I decided to revisit this project and see improve upon it as I write my own game engine throughout 2023.  I plan to make a number of changes, including:

* Adding support for Nintendo Switch.  This is possible because of the [libnx][9] port of SDL.  This also includes:
* Switching to libtinyxml2 instead of libtinyxml.  Very much linked to the previous bullet point.

I've done the above already in another unlinked repo.  I plan to merge those changes into this repo over the next few days.

In addition to the above:

* Put all behaviors under test to expose change points for any future changes. A very important step and will be done before the above changes.
* Eliminate memory leaks.  The usage of smart pointers will be introduced but I'll also explain the reasoning behind the changes [here][10].

## Pre-requisites

I've included a Makefile that should work on most Linux systems, including Windows Subsystem for Linux and possibly for MacOS.  You'll need to install SDL2 and the SDL2 image, ttf, and mixer extensions.  To install these extensions on a Debian based system, you can follow [these instructions][4].  If you're on a different system, you'll need to install the SDL2 and extensions [per the instructions for your system][5].  If you already have SDL2 and extensions installed, only steps you need is to install [Tiled][6], [Valgrind][7], and [Igloo][8] if you don't have those already.  On Debian-based systems, you can do the following:

```bash
sudo update && sudo apt install cmake llibtinyxml-dev tiled valgrind

git clone https://github.com/codewars/igloo.git
cd igloo
git submodule add -b headers-only https://github.com/banditcpp/snowhouse snowhouse
git submodule update --init --recursive
mkdir build && cd build
cmake ..
sudo cmake --build .. --target install
```

I'll update these instructions for WSL and MacOS, eventually.  However, if anyone wants to submit a PR for these, I'd be happy to accept it.

## Running

Just simply type `make && make run` to build and run the game.

[1]: https://www.packtpub.com/game-development/sdl-game-development
[2]: https://github.com/PacktPublishing/SDL-Game-Development
[3]: https://www.libsdl.org/
[4]: docs/SDL2-install-instructions.md
[5]: https://wiki.libsdl.org/SDL2/Installation
[6]: http://www.mapeditor.org/
[7]: http://valgrind.org/
[8]: https://github.com/codewars/igloo
[9]: https://switchbrew.org/wiki/Setting_up_Development_Environment
[10]: docs/memory-management.md
