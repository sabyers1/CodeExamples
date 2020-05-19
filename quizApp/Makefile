CXX       := g++
# Unix style Makefile to build example code.
# -g 	adds debugger information
# -Wall	adds most of warnings.
# Removed '-ggdb' flag don't know what it is.
# Changed '-std=c++17' to '-std=C++11
CXX_FLAGS :=  -g -Wall

BIN     := .
SRC     := .
INCLUDE := .

LIBRARIES   :=
EXECUTABLE  := quizapp


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	rm $(BIN)/*
