#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int toNumber(string s) {
    stringstream ss;
    ss << s;
    int num;
    ss >> num;
    return num;
}

int valueOf(string s) {
    if (s == "X" || s == "/") return 10;
    return toNumber(s);
}

int main() {
    while (true) {
        string s;
        getline(cin, s);
        if (s == "Game Over") break;

        stringstream ss;
        ss << s;
        vector< string > scores;
        while (ss >> s) {
            scores.push_back(s);
        }

        vector< int > ans(scores.size(), 0);

        int total = 0;

        int frames = 0;
        for (int i = 0; frames < 20; i++) {
            if (scores[i] == "X") {
                frames += 2;
                total += 10;
                if (i < scores.size() - 2 && scores[i+2] == "/") total += 10;
                else if (i < scores.size() - 2) total += valueOf(scores[i+1]) + valueOf(scores[i+2]);
            } else if (scores[i] == "/") {
                ++frames;
                total += 10;
                if (i < scores.size() - 1) total += valueOf(scores[i+1]) - valueOf(scores[i-1]);
            } else {
                ++frames;
                total += valueOf(scores[i]);
            }
        }

        cout << total << endl;
    }
}
