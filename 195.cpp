#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

bool compare(char a, char b) {
    if (tolower(a) == tolower(b)) return a < b;
    return tolower(a) < tolower(b);
}

bool compare2(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) continue;
        if (tolower(s1[i]) == tolower(s2[i])) return s1[i] < s2[i];
        return tolower(s1[i]) < tolower(s2[i]);
    }
    return s1 < s2;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string input;
        cin >> input;

        int count[200] = { };
        string word = input;

        vector< string > words;
        sort(word.begin(), word.end());
        do {
            words.push_back(word);
        } while (next_permutation(word.begin(), word.end()));

        sort(words.begin(), words.end(), compare2);
        for (int i = 0; i < words.size(); i++) {
            cout << words[i] << endl;
        }
    }
}
