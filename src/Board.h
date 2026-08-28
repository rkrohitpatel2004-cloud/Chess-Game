#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Piece.h"

class Board {
    std::unique_ptr<Piece> squares[8][8];
    bool whiteToMove = true;
    void setup();
    bool pathClear(int fr, int fc, int tr, int tc) const;
    bool squareAttacked(int r, int c, bool byWhite) const;
    bool hasKing(bool white) const;
    bool wouldLeaveKingInCheck(int fr, int fc, int tr, int tc);
public:
    Board();
    Piece* at(int r, int c) const { return squares[r][c].get(); }
    bool inBounds(int r, int c) const { return r >= 0 && r < 8 && c >= 0 && c < 8; }
    bool pathIsClear(int fr, int fc, int tr, int tc) const { return pathClear(fr,fc,tr,tc); }
    bool whiteTurn() const { return whiteToMove; }
    void print() const;
    bool move(const std::string& from, const std::string& to);
    bool inCheck(bool white) const;
    bool hasLegalMove(bool white);
    bool isCheckmate(bool white);
    bool isStalemate(bool white);
};
