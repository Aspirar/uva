#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    while (true) {
        string input;
        getline(cin, input);
        if (input == "DONE") break;

        string s = "";
        for (int i = 0; i < input.size(); i++) {
            if (isalpha(input[i])) s += tolower(input[i]);
        }
        bool palindrome = true;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                palindrome = false;
                break;
            }
        }

        if (palindrome) cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;
    }
}
