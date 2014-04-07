CXXFLAGS = -O3 -Wall -fmessage-length=0 

DEBUGFLAGS = -g -ggdb 

VECTORFLAGS = -fopenmp

BIN = ./Debug

LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image -lBox2D

TARGET =  $(BIN)/2048

INCLUDE = -I./src/

DEMO_LIBS= -lVector

SRCVECTOR_CORE = ./src/core/Entity.cpp\
				./src/core/stateMachine/*.cpp

SRCVECTOR_GAME = ./src/game/*.cpp \
				./src/game/primitives/*.cpp \
				./src/game/primitives/geometry/*.cpp \
				./src/game/gui/*.cpp  \
				./src/game/events/*.cpp \
				./src/game/armature/*.cpp \
				./src/game/animation/*.cpp \
				./src/game/physics/*.cpp
				
SRCVECTOR_EXTRA = ./src/support/*.cpp

SRCDEMO_2048 = ./demo/2048/*.cpp

SRCDEMO_GUI = ./demo/gui/*.cpp

SRCDEMO_TESTGAME = ./demo/testGame/*.cpp \
				   ./demo/testGame/game/*.cpp
 	  
all: vector demos

demos: demo.2048 demo.gui demo.testGame
 	  
vector:  $(SRCVECTOR_CORE) $(SRCVECTOR_GAME) $(SRCVECTOR_EXTRA)

	$(CXX) -shared -fPIC -o $(BIN)/libVector.so $(SRCVECTOR_CORE) $(SRCVECTOR_GAME) $(SRCVECTOR_EXTRA) $(OBJS) $(LIBS) $(CXXFLAGS) $(DEBUGFLAGS)
demo.2048: $(SRCDEMO_2048)
	$(CXX) -o $(BIN)/2048 $(SRCDEMO_2048) $(OBJS) -L$(BIN) $(LIBS) $(DEMO_LIBS) $(INCLUDE) $(CXXFLAGS)  $(DEBUGFLAGS)

demo.gui : $(SRCDEMO_GUI)
	$(CXX) -o $(BIN)/demo_gui $(SRCDEMO_GUI) $(OBJS) -L$(BIN) $(LIBS) $(DEMO_LIBS) $(INCLUDE) $(CXXFLAGS)  $(DEBUGFLAGS)

demo.testGame : $(SRCDEMO_TESTGAME)
	$(CXX) -o $(BIN)/testGame $(SRCDEMO_TESTGAME) $(OBJS) -L$(BIN) $(LIBS) $(DEMO_LIBS) $(INCLUDE) $(CXXFLAGS)  $(DEBUGFLAGS)

clean: 
	rm -rf $(BIN)/*