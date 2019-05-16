PREFIX=/usr/local
MAN_PREFIX=$(PREFIX)
BIN_PREFIX=$(CURDIR)/bin
DATA_PREFIX=data/

XX = g++
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_mixer -lSDL2_image -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -isystem /usr/local/include

CXXFLAGS = -Wall -c -g -Wno-reorder -std=c++14 -DDATA_PREFIX=\"$(DATA_PREFIX)\" $(SDL_INCLUDE) 
LDFLAGS = $(SDL_LIB) -lz -ltinyxml

BIN_DIR = ./bin
SRCS    = $(wildcard src/*.cpp)
OBJS    = $(SRCS:.cpp=.o)

TARGET = $(BIN_DIR)/alienattack

all : clean make_dirs $(TARGET) 

$(TARGET) : $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

.cpp.o: 
	$(CXX) $(CXXFLAGS) $< -o $@
	
install:
	install -d $(DATA_PREFIX)
	cp -R data/* $(DATA_PREFIX)
	chmod -R a+rX,g-w,o-w $(DATA_PREFIX)
	cp alienattack $(BIN_PREFIX)
	chmod a+rx,g-w,o-w $(BIN_PREFIX)/alienattack
	install -d $(MAN_PREFIX)/man/man6/
	cp  alienattack.6 $(MAN_PREFIX)/man/man6/
	chmod a+rx,g-w,o-w $(MAN_PREFIX)/man/man6/alienattack.6 

make_dirs :
	mkdir -p $(BIN_DIR)
	
check:
	valgrind --log-file=valgrind.output --leak-check=yes --tool=memcheck $(TARGET)

clean:
	rm -f bin/* && rm -f $(shell find . -name '*.o') 

#TESTS #########################################################################
# Testing iteration is make clean, make game-tests, ./bin/GameTests
TESTSRCS  = $(wildcard tests/*.cpp)
TESTOBJS  = $(SRCS:.cpp=.o)

game-tests: $(TESTOBJS) 
	$(CXX) $^ $(LDFLAGS) -lgtest -lgmock -pthread -o bin/game-tests	

