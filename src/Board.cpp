#include "Board.h"
#include "Pieces.h"
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

Board::Board(){ setup(); }

void Board::setup(){
    for(auto &row:squares) for(auto &p:row) p.reset();
    squares[0][0]=make_unique<Rook>(true); squares[0][1]=make_unique<Knight>(true); squares[0][2]=make_unique<Bishop>(true); squares[0][3]=make_unique<Queen>(true); squares[0][4]=make_unique<King>(true); squares[0][5]=make_unique<Bishop>(true); squares[0][6]=make_unique<Knight>(true); squares[0][7]=make_unique<Rook>(true);
    for(int c=0;c<8;c++) squares[1][c]=make_unique<Pawn>(true);
    squares[7][0]=make_unique<Rook>(false); squares[7][1]=make_unique<Knight>(false); squares[7][2]=make_unique<Bishop>(false); squares[7][3]=make_unique<Queen>(false); squares[7][4]=make_unique<King>(false); squares[7][5]=make_unique<Bishop>(false); squares[7][6]=make_unique<Knight>(false); squares[7][7]=make_unique<Rook>(false);
    for(int c=0;c<8;c++) squares[6][c]=make_unique<Pawn>(false);
}

bool Board::pathClear(int fr,int fc,int tr,int tc) const {
    int dr=(tr>fr)-(tr<fr), dc=(tc>fc)-(tc<fc);
    int r=fr+dr,c=fc+dc;
    while(r!=tr||c!=tc){ if(squares[r][c]) return false; r+=dr;c+=dc; }
    return true;
}

bool Board::hasKing(bool w) const { for(auto &row:squares) for(auto &p:row) if(p&&p->isWhite()==w&&p->getSymbol()==(w?'K':'k')) return true; return false; }

bool Board::squareAttacked(int r,int c,bool byWhite) const {
    for(int fr=0;fr<8;fr++) for(int fc=0;fc<8;fc++) if(squares[fr][fc]&&squares[fr][fc]->isWhite()==byWhite){
        char s=tolower(squares[fr][fc]->getSymbol());
        int dr=r-fr,dc=c-fc;
        if(s=='p'){ int d=byWhite?1:-1; if(dr==d&&abs(dc)==1) return true; }
        else if(s=='n'){ if((abs(dr)==2&&abs(dc)==1)||(abs(dr)==1&&abs(dc)==2)) return true; }
        else if(s=='k'){ if(max(abs(dr),abs(dc))==1) return true; }
        else if(s=='r'||s=='b'||s=='q'){
            bool ok=(s=='r'?(dr==0||dc==0):(s=='b'?abs(dr)==abs(dc):(dr==0||dc==0||abs(dr)==abs(dc))));
            if(ok&&pathClear(fr,fc,r,c)) return true;
        }
    }
    return false;
}

bool Board::inCheck(bool w) const {
    for(int r=0;r<8;r++) for(int c=0;c<8;c++) if(squares[r][c]&&squares[r][c]->isWhite()==w&&tolower(squares[r][c]->getSymbol())=='k') return squareAttacked(r,c,!w);
    return true;
}

bool Board::wouldLeaveKingInCheck(int fr,int fc,int tr,int tc) {
    // This compact implementation copies board state by temporarily moving ownership.
    auto moving=std::move(squares[fr][fc]);
    auto captured=std::move(squares[tr][tc]);
    squares[tr][tc]=std::move(moving);
    bool check=inCheck(squares[tr][tc]->isWhite());
    squares[fr][fc]=std::move(squares[tr][tc]);
    squares[tr][tc]=std::move(captured);
    return check;
}

bool Board::move(const string& from,const string& to){
    if(from.size()!=2||to.size()!=2) return false;
    int fc=tolower(from[0])-'a', fr=from[1]-'1', tc=tolower(to[0])-'a', tr=to[1]-'1';
    if(!inBounds(fr,fc)||!inBounds(tr,tc)||!squares[fr][fc]) return false;
    Piece* p=squares[fr][fc].get();
    if(p->isWhite()!=whiteToMove) return false;
    if(squares[tr][tc]&&squares[tr][tc]->isWhite()==p->isWhite()) return false;
    if(!p->validMove(fr,fc,tr,tc,*this)) return false;
    if(wouldLeaveKingInCheck(fr,fc,tr,tc)) return false;
    squares[tr][tc]=std::move(squares[fr][fc]);
    // Simple promotion to queen.
    if(tolower(squares[tr][tc]->getSymbol())=='p' && (tr==0||tr==7)) squares[tr][tc]=make_unique<Queen>(whiteToMove);
    whiteToMove=!whiteToMove;
    return true;
}

bool Board::hasLegalMove(bool w) {
    for(int fr=0;fr<8;fr++) for(int fc=0;fc<8;fc++) if(squares[fr][fc]&&squares[fr][fc]->isWhite()==w)
        for(int tr=0;tr<8;tr++) for(int tc=0;tc<8;tc++) if(!(squares[tr][tc]&&squares[tr][tc]->isWhite()==w) && squares[fr][fc]->validMove(fr,fc,tr,tc,*this) && !wouldLeaveKingInCheck(fr,fc,tr,tc)) return true;
    return false;
}

bool Board::isCheckmate(bool w) { return inCheck(w)&&!hasLegalMove(w); }
bool Board::isStalemate(bool w) { return !inCheck(w)&&!hasLegalMove(w); }

void Board::print() const {
    cout << "\n  a b c d e f g h\n";
    for(int r=7;r>=0;r--){ cout << r+1 << ' '; for(int c=0;c<8;c++) cout << (squares[r][c]?squares[r][c]->getSymbol():'.') << ' '; cout << r+1 << '\n'; }
    cout << "  a b c d e f g h\n\n";
}
