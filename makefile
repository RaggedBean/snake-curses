all: snake-curses

SRC = src/*
DEPS = src/*

snake-curses: $(SRC) $(DEPS)
	g++ $(SRC) -lncurses -o snake-curses

clean:
	rm -f snake-curses
