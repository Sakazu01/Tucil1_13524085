CXX = g++
CXXFLAGS = -std=c++17
SRC = src
BIN = bin

cli: $(BIN)/queens.exe
$(BIN)/queens.exe: $(SRC)/input.cpp $(SRC)/solutions.cpp $(SRC)/main.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN):
	mkdir $(BIN)

all: cli

run: cli
	.\$(BIN)\queens.exe

clean:
	rm -f $(BIN)/queens.exe

.PHONY: all cli run clean
