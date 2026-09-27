# AlphaC

A chess game and engine implementation written in C++ using SFML(for UI).

## Overview

This project is a chess engine built from scratch with the goal of understanding how chess engines work internally. The focus is on implementing the game's rules, move validation, game-state management,position evaluation function and eventually developing a competitive AI opponent.

## Game Features

- Chess board representation
- Legal move generation
- Move validation
- Check detection
- Checkmate detection
- Piece captures
- Turn management
- Interactive graphical interface using SFML

# Engine Features

- Static board evaluation function
- Minimax search algorithm
- Alpha-Beta pruning optimization
- Decision tree exploration for move selection
- AI opponent (Black) vs Human player (White)
- Automatic best-move calculation
- Position scoring and analysis
- Configurable search depth

## Work in Progress

- Engine performance optimization
- Search depths greater than 3-4 currently experience noticeable slowdowns due to the rapid growth of the game tree
- Preparing the engine for deeper searches and stronger gameplay
- Improving move generation

**## Installation**

### Arch-Based

```bash
curl -LO https://raw.githubusercontent.com/DevBarik731/AlphaC/main/install_scripts/Arch_install.sh
chmod +x Arch_install.sh
./Arch_install.sh
```