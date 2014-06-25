# Alien-Attack-Linux
==================

Example project from 'SDL Game Development' by Shaun Mitchell

### To get everything working under Ubuntu:
    sudo apt-get install libxmu-dev libxi-dev libopenal-dev
    
    # Download & compile the latest version of libGLEW (1.9?)

    git clone git://git.code.sf.net/p/glew/code glew
    cd glew
    make extensions && make
    sudo make install
    make clean

### Download & compile the latest version SDL2 (including image, ttf, and mixer extensions).  Please see https://gist.github.com/WillSams/e2bb2874ace22b90f90f

### Install support libraries for Alien Attack
    sudo apt-get install libtinyxml-dev
    sudo apt-get install tiled  #for the .tmx files, Tiled Map Editor

### Testing supports w/Google-Test (Note: I wrote integration tests, not unit tests)
    sudo apt-get install libgtest-dev
    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    sudo make
    sudo cp *.a /usr/lib  # copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder

    #download Google Mock (http://code.google.com/p/googlemock/downloads/list) and extract contents to /usr/src
    cd /usr/src/gmock*
    sudo cmake CMakeLists.txt
    sudo make
    sudo cp *.a /usr/lib
