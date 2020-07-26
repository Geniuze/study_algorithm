#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int> > > res;

bool isValid(vector<vector<int> > &track, int row, int col, int val) {
    for ()
}

int backtrace(vector<vector<int> > &track, int row, int col) {

    if (row == track.size() && col == track.size()) {
        res.push_back(track);
        return 0;
    }

    int n = track.size();
    for (int i = 0; i<n; i++) {
        if (!isValid(track, row, col, i))
            continue;

        track[row][col] = i;

        if (col < n - 1)
            backtrace(track, row, col+1);
        else
            backtrace(track, row+1, 0);

        track[row][col] = -1;
    }

    return 0;
}


int main() {
    vector<vector<int> > track(3, vector<int>(3, -1));

}
