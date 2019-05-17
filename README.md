# Alien-Attack-Linux
=====================

Example project from ['SDL Game Development' by Shaun Mitchell][2]. The book explains everything from a Windows user perspective. Here are instructions to get everything working under Linux (especially Debian/Ubuntu):

### Download & compile the latest version SDL2 
Including image, ttf, and mixer extensions.  Please see my [gist explaining how to build those extensions][1]. 

### Install map editing support tool, [Tiled Map Editor][3]
    sudo apt-get install libtinyxml-dev
    sudo apt-get install tiled  #for the .tmx files

### Testing support w/Google-Test
    git clone https://github.com/google/googletest /tmp/googletest
    cd /tmp/googletest && cmake . && make
    sudo bash -c "make install"
    rm -rf /tmp/googletest
    
If you don't have SDL, Valgrind, or Google Test installed, try [this][4] script.
    
    
[1]: https://gist.github.com/WillSams/e2bb2874ace22b90f90f
[2]: https://www.packtpub.com/game-development/sdl-game-development
[3]: http://www.mapeditor.org/
[4]: https://gist.github.com/WillSams/e2bb2874ace22b90f90f
