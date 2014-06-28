# Alien-Attack-Linux
==================

Example project from 'SDL Game Development' by Shaun Mitchell. The book explains everything from a Windows user perspective. Here are instructions to get everything working under Ubuntu:

### Download & compile the latest version SDL2 
Including image, ttf, and mixer extensions.  Please see my [gist explaining how to build said extensions][1]. 

### Install support libraries for Alien Attack
    sudo apt-get install libtinyxml-dev
    sudo apt-get install tiled  #for the .tmx files, Tiled Map Editor

### Testing supports w/Google-Test 
Note: I wrote integration tests, not unit tests.  Writing them to help me get intimate with the source quicker.  I may remove them when I'm done.

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
    
    
[1]: https://gist.github.com/WillSams/e2bb2874ace22b90f90f