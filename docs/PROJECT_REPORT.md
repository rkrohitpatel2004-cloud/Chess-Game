# Chess Game — Project Report

**Name:** Rohit

## 1. Aim

To develop a console-based two-player Chess Game in C++ using Object-Oriented Programming concepts.

## 2. Objectives

- Represent a chess board programmatically.
- Implement movement rules for chess pieces.
- Validate player moves.
- Implement turn management and captures.
- Detect check, checkmate and stalemate.
- Demonstrate inheritance and polymorphism.

## 3. Algorithm

1. Initialize an 8×8 chess board with all pieces in their standard starting positions.
2. Display the board and ask the current player for source and destination squares.
3. Check whether the selected piece belongs to the current player.
4. Validate the movement according to the type of chess piece.
5. Reject the move if it leaves the player's king in check.
6. Apply the move and change the turn.
7. Check for checkmate or stalemate.
8. Continue until a player wins, a draw occurs, or the user exits.

## 4. OOP Concepts

The project uses abstraction, inheritance, polymorphism and encapsulation. `Piece` is an abstract base class and each chess piece overrides `validMove()`.

## 5. Input

Moves are entered as two coordinates, for example `e2 e4`.

## 6. Output

The current board is displayed after every valid move, and the program reports invalid moves, check, checkmate or stalemate.

## 7. Limitations

Castling and en-passant are not implemented. Pawn promotion is automatically handled as promotion to a queen.

## 8. Future Scope

A GUI, chess AI, move history, undo, timers, save/load and online multiplayer can be added.
