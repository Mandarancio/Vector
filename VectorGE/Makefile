CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -fopenmp


BIN = ./Debug

LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image -lBox2D

TARGET =  $(BIN)/2048


SRCVECTOR_CORE= ./src/core/Entity.cpp\
				./src/core/stateMachine/*.cpp

SRCVECTOR_GAME= ./src/game/*.cpp\
				./src/game/primitives/*.cpp\
				./src/game/primitives/geometry/*.cpp\
				./src/game/gui/*.cpp\
				./src/game/events/*.cpp\
				./src/game/armature/*.cpp\
				./src/game/animation/*.cpp
				
SRCVECTOR_EXTRA= ./src/support/*.cpp

SRCDEMO1= ./demo/2048/2048.cpp  \
 	  ./demo/2048/Board.cpp \
 	  ./demo/2048/Cell.cpp

prog2048: ./demo/2048/2048.cpp
	$(CXX) -o $(BIN)/2048 $(SRCDEMO1) $(SRCVECTOR_CORE) $(SRCVECTOR_GAME) $(SRCVECTOR_EXTRA) $(OBJS)  $(LIBS)

all:   prog2048

clean: rm -f $(BIN)/*