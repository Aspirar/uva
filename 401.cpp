#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<char, char> mirror;
    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';

    string s;
    while (cin >> s) {
        bool palindrome = true;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                palindrome = false;
                break;
            }
        }

        bool mirrored = true;
        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if (s[i] != mirror[s[j]]) {
                mirrored = false;
                break;
            }
        }

        cout << s;
        if (palindrome && mirrored) {
            cout << " -- is a mirrored palindrome." << endl;
        } else if (mirrored) {
            cout << " -- is a mirrored string." << endl;
        } else if (palindrome) {
            cout << " -- is a regular palindrome." << endl;
        } else {
            cout << " -- is not a palindrome." << endl;
        }
        cout << endl;
    }
}
