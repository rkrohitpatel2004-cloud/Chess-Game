#include <iostream>
#include "Board.h"
using namespace std;

int main() {
    Board board;
    cout << "\n===== C++ CHESS GAME =====\n";
    cout << "Enter moves like: e2 e4\n";
    cout << "Type 'quit' to exit.\n\n";
    board.print();

    string from, to;
    while (true) {
        cout << (board.whiteTurn() ? "White" : "Black") << " to move: ";
        cin >> from;
        if (from == "quit" || from == "exit") break;
        cin >> to;

        if (!board.move(from, to)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board.print();
        if (board.isCheckmate(!board.whiteTurn())) {
            cout << (board.whiteTurn() ? "White" : "Black") << " wins by checkmate!\n";
            break;
        }
        if (board.isStalemate(!board.whiteTurn())) {
            cout << "Draw by stalemate!\n";
            break;
        }
        if (board.inCheck(!board.whiteTurn()))
            cout << "Check!\n";
    }
    cout << "Game ended.\n";
    return 0;
}
