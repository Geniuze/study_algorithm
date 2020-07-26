#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string> > res;

bool isValid(vector<string> &board, int row, int col) {
    int n = board.size();

    for (int i = 0; i<row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i=row-1,j=col-1; i>=0 && j>=0; i--,j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i=row-1,j=col+1; i>=0 && j<n; i--,j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

int backtrace(vector<string> &board, int row) {
    if (row == board.size())  {
        res.push_back(board);
        return 0;
    }

    int n = board[row].size();
    for (int col = 0; col < n; col++) {
        if (!isValid(board, row, col)) {
            continue;
        }

        board[row][col] = 'Q';
        backtrace(board, row+1);
        board[row][col] = '.';
    }
    return 0;
}

int main() {
    int n = 5;
    vector<string> board(n, string(n, '.'));
    backtrace(board, 0);
    for (vector<vector<string> >::iterator it = res.begin(); it != res.end(); it++) {
        for (vector<string>::iterator its = it->begin(); its != it->end(); its++) {
            cout << *its << endl;
        }
        cout << endl;
    }
    return 0;
}