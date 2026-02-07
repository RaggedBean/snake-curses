# Snake-curses

A classic terminal-based Snake game implemented in C++ on Linux, using the ncurses library.

The project follows the **MVC** (Model-View-Controller) architecture:

- **Model** — Game logic  
  (`snake.h`, `fruit.h`)
- **View** — Rendering / display  
  (`drawable.h`, `window.h`)
- **Controller** — User input handling & game loop  
  (`game.h`)

## Controls

- **Arrow keys** or **WASD** → Move the snake  
- **Q** or **Esc** → Quit the game

## Build & Run

### Requirements

- Operating system: Linux (tested on Ubuntu / Debian)  
- Compiler: g++ (version 7 or newer recommended)  
- Library: ncurses

### Installation of dependencies (Ubuntu/Debian)

```bash
sudo apt update
sudo apt-get install libncurses5-dev libncursesw5-dev
git clone https://github.com/RaggedBean/snake-curses.git
cd snake-curses
make
make clean
./snake
```

