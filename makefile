all: snake-curses

SRC = src/main.cpp
DEPS = src/window.h

snake-curses: $(SRC) $(DEPS)
	g++ $(SRC) -lncurses -o snake-curses

clean:
	rm -f snake-curses
