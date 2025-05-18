# MyRunner - Naruto Infinite Runner

A dynamic side-scrolling runner game built with CSFML (Simple and Fast Multimedia Library for C) featuring Naruto-themed gameplay. The game combines classic infinite runner mechanics with Naruto-style animations and parallax scrolling effects.

## Project Overview

MyRunner is an engaging infinite runner game that features:
- Naruto-themed character and animations
- Parallax scrolling backgrounds
- Dynamic obstacle system
- Collision detection
- Score tracking
- Multiple game states
- Interactive menus
- Custom animations and effects

## Project Structure

```
MyRunner/
├── src/
│   ├── main.c                    # Program entry point
│   ├── my_runner.c              # Core game logic
│   ├── my_setup.c               # Game initialization
│   ├── set_char_struct.c        # Character setup
│   ├── set_paralax_struct.c     # Parallax background
│   ├── set_obstacles_struct.c   # Obstacle management
│   ├── move_elems.c             # Element movement
│   ├── map_gestion.c            # Map handling
│   ├── obstacle_colision.c      # Collision detection
│   └── [Other source files]     # Additional game logic
├── my_png/                      # Game assets
├── lib/                         # Library files
├── include/                     # Header files
└── Makefile                     # Build configuration

```

## Game Assets

- `Naruto_sprites.png`: Main character animations
- `Naruto_run.png`: Running animation frames
- `Naruto_jump.png`: Jumping animation frames
- `background.png`: Scrolling background
- `ground.png`: Ground tiles
- `crow.png`: Obstacle sprites

## Dependencies

- CSFML Library (Simple and Fast Multimedia Library for C)
- C compiler (gcc recommended)
- Make build system

## Building the Project

To compile the game:

```bash
make
```

This will generate the `my_runner` executable.

## Playing the Game

### Starting the Game

```bash
./my_runner [map_file]
```

Optional: Provide a map file to load a custom level configuration.

### Controls

- **Space**: Jump
- **Escape**: Pause game
- **Enter**: Select menu options
- **Arrow Keys**: Navigate menus

### Game Features

1. **Main Menu**
   - Start game
   - Level selection
   - Quit option

2. **Gameplay**
   - Infinite running mechanics
   - Dynamic obstacle generation
   - Parallax scrolling backgrounds
   - Score system
   - Character animations

3. **Pause Menu**
   - Resume game
   - Return to main menu
   - Restart level
   - Quit game

4. **Game Over Screen**
   - Final score display
   - Restart option
   - Return to main menu

## Implementation Details

The game is built with several key systems:
- Parallax scrolling background system
- Dynamic obstacle generation and management
- Collision detection system
- Character animation state machine
- Event handling system
- Menu state management
- Custom map loading and parsing

## Technical Features

- Smooth sprite animations
- Multiple parallax layers
- Efficient collision detection
- Memory management
- Custom map format support
- State-based game flow

## Building and Cleaning

Available make targets:
- `make`: Build the game
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Rebuild the project

## Map Format

Custom maps can be created using the following format:
```
# Example map format
G: Ground block
O: Obstacle
-: Empty space
```

## License

This project is licensed under the terms provided in the LICENSE file.

## Contributing

Contributions are welcome! Feel free to submit issues and pull requests.

## Credits

- Character designs inspired by Naruto
- CSFML Library for graphics
- Custom artwork and animations
- Sound effects and music 