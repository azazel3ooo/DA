CC         =g++ -fdiagnostics-color=always -g
CXXFLAGS   +=-std=c++17 -g #-Ofast
LDFLAGS    =

# Should be equivalent to your list of C++ files, if you don't build selectively
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))
TARGET=solution

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
$(OBJ):

clean:
	rm -f $(OBJ) $(TARGET)

