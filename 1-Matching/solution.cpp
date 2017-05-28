#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int indexOf(string val, vector<string> vec) {
    return distance(vec.begin(), find(vec.begin(), vec.end(), val));
}

class Matching {
    public:
    static const vector<vector<string>> S;

    vector<string> findMatch(vector<string> x, vector<string> y) {
        vector<string> result(4);

        for (int i = 0; i < 4; i++) {
            // https://www.youtube.com/watch?v=Xm_dS-wEFvs
            result[i] = x[i] == y[i] ? x[i] : this->S[i][3 - (indexOf(x[i], this->S[i]) + indexOf(y[i], this->S[i]))];
        }
        return result;
    }
};

const vector<vector<string>> Matching::S {
    {"CIRCLE", "SQUIGGLE", "DIAMOND"},
    {"RED", "BLUE", "GREEN"},
    {"SOLID", "STRIPED", "EMPTY"},
    {"ONE", "TWO", "THREE"}
};