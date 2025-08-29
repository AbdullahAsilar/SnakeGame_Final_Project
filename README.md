# Snake Game - C++ Object-Oriented Design

A classic Snake game implementation showcasing advanced C++ Object-Oriented Programming principles. Built as part of the CE2SH4 course with emphasis on clean architecture, memory management, and extensible design patterns.

## 🎮 Game Features

**Core Gameplay:**
- Classic snake movement with WASD/Arrow key controls
- Border wrapping mechanics
- Dynamic food spawning with collision avoidance
- Progressive scoring system
- Self-collision detection with game over state

**Advanced Features:**
- **Variable Speed Control**: 5-level speed system (125ms to 45ms delays)
- **Mystery Foods**: Special items with unique effects
  - `!` symbol: +10 score, no length increase
  - `@` symbol: +5 score, +5 length segments
- **Multi-Food System**: Up to 5 food items simultaneously on board

## 🏗️ Architecture & Design Patterns

### Object-Oriented Structure
This project demonstrates several key OOD principles:

```
objPos                 → Encapsulates single board position (x, y, symbol)
objPosArrayList       → Dynamic container for position collections  
GameMechs             → Centralized game state management
Player                → Snake behavior and movement logic
Food                  → Food generation and special effects system
```

### Design Principles Applied
- **Encapsulation**: Each class manages its own data with controlled access
- **Composition**: Player contains objPosArrayList for body segments
- **Single Responsibility**: Clear separation of concerns across classes
- **Memory Safety**: Proper RAII implementation with Rule of Four compliance

## 🛠️ Technical Implementation

### Memory Management
- **Heap Allocation**: Dynamic arrays for scalable snake body
- **RAII Pattern**: Automatic resource management via destructors  
- **Deep Copy Semantics**: Proper copy constructors and assignment operators
- **Zero Memory Leaks**: Validated with systematic testing

### Key Algorithms
- **Snake Movement**: Head insertion + tail removal for smooth animation
- **Collision Detection**: Efficient body segment checking
- **Food Generation**: Random placement with overlap validation
- **Boundary Wrapping**: Seamless edge-to-edge transitions

## 📁 Project Structure

```
src/
├── objPos.cpp/.h              # Position data structure
├── objPosArrayList.cpp/.h     # Dynamic array implementation  
├── GameMechs.cpp/.h           # Game state management
├── Player.cpp/.h              # Snake logic and controls
├── Food.cpp/.h                # Food system and effects
├── MacUILib.cpp/.h            # Cross-platform I/O library
└── Project.cpp                # Main game loop

objPosArrayList_TestSuite/     # Unit testing framework
```

## 🚀 Build & Run

### Prerequisites
- C++17 compatible compiler (g++, clang++)
- Linux/macOS/Windows with terminal support

### Compilation
```bash
# Standard build
g++ -std=c++17 -O2 -Wall \
  objPos.cpp objPosArrayList.cpp GameMechs.cpp \
  Player.cpp Food.cpp MacUILib.cpp Project.cpp \
  -o snake

./snake
```

### Alternative (if Makefile provided)
```bash
make
./snake
```

## 🎯 Controls

| Input | Action |
|-------|--------|
| `W/A/S/D` or `Arrow Keys` | Snake movement |
| `=` | Increase speed |
| `-` | Decrease speed |
| `ESC` | Exit game |

## 🔧 Development Process

The project followed an iterative development approach:

1. **Foundation** (Iteration 0): Core data structures and basic rendering
2. **Movement System** (Iteration 1): Player controls and game mechanics integration  
3. **Dynamic Collections** (Iteration 2A): Robust array list implementation with comprehensive testing
4. **Food System** (Iteration 2B): Random generation with collision avoidance
5. **Game Logic** (Iteration 3): Growth mechanics and collision detection
6. **Advanced Features** (Bonus): Multi-food system and special effects

## 🧪 Testing & Quality Assurance

- **Unit Testing**: Comprehensive test suite for objPosArrayList
- **Memory Validation**: Zero-leak guarantee with proper cleanup
- **Edge Case Handling**: Boundary conditions and error states
- **Code Review**: Peer validation and documentation standards

## 👥 Development Team

**Abdullah Asilar**
- Iteration 2A: Implemented objPosArrayList (array-backed list), with focus on correctness/robustness under tests.
- Iteration 2B: Implemented random food generation and validation against snake body occupancy.  
- Feature 3: Implemented self-collision detection and integrated lose/exit flags for clean termination.
- Bonus Features:Designed and implemented mystery/special food logic (effects, rules) and multi-food support; integrated with score/length updates.
- Collaboration: Assisted in debugging across modules and reviewed partner code paths.

**Gobind Kailey** 
- Iterations 0-1: Completed skeleton familiarization, objPos special members, Player FSM port, and early movement.
- Features 1-2: Integrated body composition (list-based head insert / tail remove) and growth on food consumption; wired scoring.n
- Performed final code review, added comments, and verified no memory leakage.

## 🎯 Learning Outcomes

This project demonstrates proficiency in:
- **Advanced C++ Concepts**: RAII, Rule of Four, smart memory management
- **Design Patterns**: Composition, encapsulation, interface segregation
- **Software Engineering**: Iterative development, testing, documentation
- **Problem Solving**: Algorithm optimization, edge case handling

---

*Note: This implementation prioritizes educational value and clean code architecture over performance optimization, making it ideal for demonstrating OOP principles and C++ best practices.*