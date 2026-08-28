#pragma once
#include <string>

class Board;

class Piece {
protected:
    bool white;
    char symbol;
public:
    Piece(bool isWhite, char s) : white(isWhite), symbol(s) {}
    virtual ~Piece() = default;
    bool isWhite() const { return white; }
    char getSymbol() const { return symbol; }
    virtual bool validMove(int fr, int fc, int tr, int tc, const Board& board) const = 0;
};
