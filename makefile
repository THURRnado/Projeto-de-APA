CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = main.cpp guloso.cpp mov_one.cpp ler_entrada.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)