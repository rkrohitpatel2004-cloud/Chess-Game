#pragma once
#include "Piece.h"

class Pawn : public Piece { public: Pawn(bool w); bool validMove(int fr,int fc,int tr,int tc,const Board& b) const override; };
class Rook : public Piece { public: Rook(bool w); bool validMove(int fr,int fc,int tr,int tc,const Board& b) const override; };
class Knight : public Piece { public: Knight(bool w); bool validMove(int fr,int fc,int tr,int tc,const Board& b) const override; };
class Bishop : public Piece { public: Bishop(bool w); bool validMove(int fr,int fc,int tr,int tc,const Board& b) const override; };
class Queen : public Piece { public: Queen(bool w); bool validMove(int fr,int fc,int tr,int tc,const Board& b) const override; };
class King : public Piece { public: King(bool w); bool validMove(int fr,int fc,int tr,int tc,const Board& b) const override; };
