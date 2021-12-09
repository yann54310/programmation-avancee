CC = g++
CFLAGS = -W -Wall -std=c++17 -g
LIBS =
LDFLAGS = `sdl2-config --cflags --libs`
INCLUDES = 
EXEC = main
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.c=.o)

all: $(EXEC)
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)