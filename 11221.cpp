#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int T = 1; T <= t; T++) {
        cout << "Case #" << T << ":" << endl;
        string input;
        getline(cin, input);

        string s = "";
        for (int i = 0; i < input.size(); i++) {
            if (isalpha(input[i])) s += input[i];
        }

        int k = sqrt(s.size());
        if (k * k != s.size()) {
            cout << "No magic :(" << endl;
            continue;
        }

        string r = "";
        for (int i = 0; i < k; i++) {
            for (int j = i; j < s.size(); j += k) {
                r += s[j];
            }
        }
        
        if (isPalindrome(s) && isPalindrome(r)) {
            cout << k << endl;
        } else {
            cout << "No magic :(" << endl;
        }
    }
}
