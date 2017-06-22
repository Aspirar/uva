#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    if (a.size() != b.size()) return false;
    int count[200] = { };
    for (int i = 0; i < a.size(); i++) {
        count[tolower(a[i])]++;
    }
    for (int i = 0; i < b.size(); i++) {
        count[tolower(b[i])]--;
    }
    for (int i = 0; i < a.size(); i++) {
        if (count[tolower(a[i])] != 0) return false;
    }
    return true;
}

int main() {
    vector< string > words;

    while (true) {
        string word;
        cin >> word;
        if (word == "#") break;
        words.push_back(word);
    }

    vector< string > ananagrams;
    for (int i = 0; i < words.size(); i++) {
        bool found = true;
        for (int j = 0; j < words.size(); j++) {
            if (i == j) continue;
            if (compare(words[i], words[j])) {
                found = false;
                break;
            }
        }
        if (found) ananagrams.push_back(words[i]);
    }

    sort(ananagrams.begin(), ananagrams.end());
    for (int i = 0; i < ananagrams.size(); i++) {
        cout << ananagrams[i] << endl;
    }
}
