# ♟️ C++ Chess Game

A console-based two-player Chess Game developed in **C++** using **Object-Oriented Programming (OOP)** concepts.

## Features

- 8×8 chess board
- Two-player turn-based gameplay
- Pawn, Rook, Knight, Bishop, Queen and King movement
- Capturing pieces
- Invalid move detection
- Check detection
- Checkmate detection
- Stalemate detection
- Automatic pawn promotion to Queen
- Modular OOP-based source code

> Note: This is an educational console project. Advanced tournament rules such as castling and en-passant are not implemented in this version.

## Technologies

- C++17
- OOP
- Standard Library (`iostream`, `memory`, `string`, etc.)

## Project Structure

```text
Chess-Game/
├── src/
│   ├── main.cpp
│   ├── Board.h
│   ├── Board.cpp
│   ├── Piece.h
│   ├── Pieces.h
│   └── Pieces.cpp
├── screenshots/
├── docs/
├── README.md
├── .gitignore
└── LICENSE
```

## How to Run

### Linux / macOS

```bash
g++ -std=c++17 src/main.cpp src/Board.cpp src/Pieces.cpp -o chess
./chess
```

### Windows (MinGW)

```bash
g++ -std=c++17 src/main.cpp src/Board.cpp src/Pieces.cpp -o chess.exe
chess.exe
```

## How to Play

Enter moves in chess notation using coordinates:

```text
e2 e4
e7 e5
g1 f3
```

Type `quit` to exit.

## OOP Concepts Used

- **Abstraction:** `Piece` provides a common interface for chess pieces.
- **Inheritance:** Pawn, Rook, Knight, Bishop, Queen and King inherit from `Piece`.
- **Polymorphism:** Each piece implements its own `validMove()` function.
- **Encapsulation:** Board state and movement logic are managed by the `Board` class.

## Future Improvements

- Graphical user interface
- Chess AI / computer opponent
- Castling
- En-passant
- Move history and undo
- Chess timer
- Save/load game
- Online multiplayer

## Author

**Rohit**

## License

MIT License. See [LICENSE](LICENSE).
