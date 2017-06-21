#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin.ignore();

        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'r' || c == 'Q') cout << min(a, b) << endl;
        else if (c == 'k') cout << (a * b + 1) / 2 << endl;
        else cout << ((a + 1) / 2) * ((b + 1) / 2) << endl;
    }
}
