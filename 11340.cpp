#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int k;
        cin >> k;

        double paid[300] = { };
        for (int i = 0; i < k; i++) {
            char ch;
            cin >> ch;
            cin >> paid[ch];
        }

        int m;
        cin >> m;
        cin.ignore();

        double amount = 0;
        while (m--) {
            string s;
            getline(cin, s);

            for(int i = 0, len = s.size(); i < len; i++) {
                amount += paid[s[i]];
            }
        }

        amount /= 100;
        printf("%0.2lf$\n", amount);
    }
}
