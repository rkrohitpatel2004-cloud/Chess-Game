#include "Pieces.h"
#include "Board.h"
#include <cstdlib>

Pawn::Pawn(bool w):Piece(w,w?'P':'p'){}
Rook::Rook(bool w):Piece(w,w?'R':'r'){}
Knight::Knight(bool w):Piece(w,w?'N':'n'){}
Bishop::Bishop(bool w):Piece(w,w?'B':'b'){}
Queen::Queen(bool w):Piece(w,w?'Q':'q'){}
King::King(bool w):Piece(w,w?'K':'k'){}

bool Pawn::validMove(int fr,int fc,int tr,int tc,const Board& b) const {
    int d=white?1:-1;
    if(fc==tc && !b.at(tr,tc)) {
        if(tr-fr==d) return true;
        int start=white?1:6;
        return fr==start && tr-fr==2*d && !b.at(fr+d,fc);
    }
    return std::abs(tc-fc)==1 && tr-fr==d && b.at(tr,tc) && b.at(tr,tc)->isWhite()!=white;
}

bool Rook::validMove(int fr,int fc,int tr,int tc,const Board& b) const {
    if(fr!=tr && fc!=tc) return false;
    return b.pathIsClear(fr,fc,tr,tc);
}

bool Knight::validMove(int fr,int fc,int tr,int tc,const Board&) const {
    int dr=std::abs(tr-fr), dc=std::abs(tc-fc);
    return (dr==2&&dc==1)||(dr==1&&dc==2);
}

bool Bishop::validMove(int fr,int fc,int tr,int tc,const Board& b) const {
    if(std::abs(tr-fr)!=std::abs(tc-fc)) return false;
    return b.pathIsClear(fr,fc,tr,tc);
}

bool Queen::validMove(int fr,int fc,int tr,int tc,const Board& b) const {
    bool straight=(fr==tr||fc==tc);
    bool diagonal=(std::abs(tr-fr)==std::abs(tc-fc));
    return (straight||diagonal)&&b.pathIsClear(fr,fc,tr,tc);
}

bool King::validMove(int fr,int fc,int tr,int tc,const Board&) const {
    return std::max(std::abs(tr-fr),std::abs(tc-fc))==1;
}
