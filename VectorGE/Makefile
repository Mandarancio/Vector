CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -fopenmp


BIN = ./Debug

LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image -lBox2D

TARGET =  $(BIN)/2048


SRCVECTOR_CORE = ./src/core/Entity.cpp\
				./src/core/stateMachine/*.cpp

SRCVECTOR_GAME = ./src/game/*.cpp \
				./src/game/primitives/*.cpp \
				./src/game/primitives/geometry/*.cpp \
				./src/game/gui/*.cpp  \
				./src/game/events/*.cpp \
				./src/game/armature/*.cpp \
				./src/game/animation/*.cpp
				
SRCVECTOR_EXTRA = ./src/support/*.cpp

SRCDEMO_2048 = ./demo/2048/*.cpp

SRCDEMO_GUI = ./demo/gui/*.cpp
 	  
all: vector demo.2048 demo.gui
 	  
vector:  $(SRCVECTOR_CORE) $(SRCVECTOR_GAME) $(SRCVECTOR_EXTRA)

	$(CXX) -shared -fPIC -o $(BIN)/libVector.so $(SRCVECTOR_CORE) $(SRCVECTOR_GAME) $(SRCVECTOR_EXTRA) $(OBJS)  $(LIBS)
demo.2048: $(SRCDEMO_2048)
	$(CXX) -o $(BIN)/2048 $(SRCDEMO_2048) $(SRCVECTOR_CORE) $(SRCVECTOR_GAME) $(SRCVECTOR_EXTRA) $(OBJS)  $(LIBS)

demo.gui : $(SRCDEMO_GUI)
	$(CXX) -o $(BIN)/demo_gui $(SRCDEMO_GUI) $(SRCVECTOR_CORE) $(SRCVECTOR_GAME) $(SRCVECTOR_EXTRA) $(OBJS)  $(LIBS)


clean: 
	rm -rf $(BIN)/*