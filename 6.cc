#include <iostream>
#include <list>

using namespace std;

typedef list<int> lint;

list<list<int> > res;
int backtrack(list<int> &nums, list<int> track) {
    if (track.size() == nums.size()) {
        res.push_back(track);
        return 0;
    }

    for (lint::iterator it = nums.begin(); it != nums.end(); it++) {
        int tracked = false;
        for (lint::iterator itt = track.begin(); itt != track.end(); itt++) {
            if (*itt == *it) {
                tracked = true;
                break;
            }
        }

        if ( tracked ) continue;

        track.push_back(*it);
        backtrack(nums, track);
        track.remove(*it);
    }
    return 0;
}

int main() {
    lint nums;
    lint track;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    backtrack(nums, track);

    for (list<list<int> >::iterator it = res.begin(); it != res.end(); it++) {
        for (list<int>::iterator iti = it->begin(); iti != it->end(); iti++) {
            cout << *iti << " ";
        }
        cout << endl;
    }
    return 0;
}
