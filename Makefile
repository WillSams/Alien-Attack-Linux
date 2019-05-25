BIN 					= alienattack
BIN_DIR   		= $(CURDIR)/bin
TARGET 				= $(BIN_DIR)/$(BIN)
TESTS-TARGET 	= $(BIN_DIR)/game-tests
HOMEUSER			=	$(if $(SUDO_USER),$(SUDO_USER),$(USER))
DATA_PREFIX		=	/home/$(HOMEUSER)/.$(BIN)/
LOCAL 				=	/usr/local

XX = g++
LIB = -L/usr/local/lib -lSDL2 -lSDL2_mixer -lSDL2_image -Wl,-rpath=/usr/local/lib
INCLUDE = -isystem -I/usr/local/include

CXXFLAGS = -Wall -c -g -Wno-reorder -std=c++14 -DDATA_PREFIX=\"$(DATA_PREFIX)\" $(INCLUDE) 
LDFLAGS = $(LIB) -lz -ltinyxml

SRCS      = $(wildcard src/*.cpp)
SRCS     	+= main.cpp
OBJS      = $(SRCS:.cpp=.o)
TESTSRCS  = $(wildcard tests/*.cpp)
TESTSRCS  += $(wildcard src/*.cpp)
TESTOBJS  = $(TESTSRCS:.cpp=.o)

all : clean make_dirs $(TARGET)

clean:
	rm -f bin/* && rm -f $(shell find . -name '*.o') 
	
make_dirs:
	mkdir -p $(BIN_DIR) $(DATA_PREFIX)

$(TARGET) : $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

.cpp.o: 
	$(CXX) $(CXXFLAGS) $< -o $@

tests: clean-tests tests-target

clean-tests:
	rm -f bin/game-tests tests/*.o

tests-target: $(TESTOBJS)
	$(CXX) $^ $(LDFLAGS) -lgtest -lgmock -pthread -o $(TESTS-TARGET)
	
#execute with elevated priveleges. 
install:
	mkdir -p $(DATA_PREFIX)
	install -d $(DATA_PREFIX)
	cp -R data/* $(DATA_PREFIX)
	chmod -R a+rX,g-w,o-w $(DATA_PREFIX)
	chown -hR $(USER):$(USER) $(DATA_PREFIX)
	cp $(TARGET) $(LOCAL)/bin
	chmod a+rx,g-w,o-w $(LOCAL)/bin/$(BIN)

#execute with elevated priveleges. 
uninstall:
	-rm -rf $(DATA_PREFIX)
	-rm $(LOCAL)/bin/$(BIN)
	
check:
	valgrind --log-file=valgrind.output --leak-check=yes --tool=memcheck $(TARGET)

run:
	$(TARGET)

run-tests:
	$(TESTS-TARGET)
	
