#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    string tempa = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != ' ') tempa += a[i];
    }
    a = tempa;
    string tempb = "";
    for (int i = 0; i < b.size(); i++) {
        if (b[i] != ' ') tempb += b[i];
    }
    b = tempb;
    if (a.size() != b.size()) return false;
    int count[300] = { };
    for (int i = 0; i < a.size(); i++) {
        count[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++) {
        count[b[i]]--;
    }
    for (int i = 0; i < a.size(); i++) {
        if (count[a[i]] != 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();

    while (t--) {
        vector< string > phrases;
        while (true) {
            string input;
            getline(cin, input);
            if (input == "") break;
            phrases.push_back(input);
        }

        vector< string > anagrams;
        for (int i = 0; i < phrases.size(); i++) {
            for (int j = i + 1; j < phrases.size(); j++) {
                if (compare(phrases[i], phrases[j])) {
                    if (phrases[i] < phrases[j]) {
                        anagrams.push_back(phrases[i] + " = " + phrases[j]);
                    } else {
                        anagrams.push_back(phrases[j] + " = " + phrases[i]);
                    }
                }
            }
        }

        sort(anagrams.begin(), anagrams.end());

        for (int i = 0; i < anagrams.size(); i++) {
            cout << anagrams[i] << endl;
        }
        if (t) cout << endl;
    }
}
