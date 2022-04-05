# ===================================================================
# Makefile for ASTER.IA.DS
# ===================================================================
BUILD_FLAGS= -Wall
LINK_FLAGS= -lm -lGL -lGLU -lglut

Executable=ASTERIADS
Sources= $(wildcard src/*.cpp)
Object= $(patsubst src/%.cpp,obj/%.o,$(Sources))

all: setup_directories build/$(Executable)

setup_directories:
	mkdir -p obj build

# rules	
build/$(Executable): $(Object)
	g++ -o $@ $(Object) $(LINK_FLAGS)
	
obj/%.o: src/%.cpp
	g++ -c -o $@ $< $(BUILD_FLAGS)

# clean
clean:
	rm -rf build obj