#include <iostream>
using namespace std;

int main() {
    while (true) {
        int s, b;
        cin >> s >> b;
        if (s == 0 && b == 0) break;

        int left[100010] = { };
        int right[100010] = { };

        for (int i = 1; i <= s; i++) {
            left[i] = i-1;
            right[i] = i+1;
        }
        right[s] = 0;

        while (b--) {
            int l, r;
            cin >> l >> r;

            if (left[l]) cout << left[l];
            else cout << "*";
            cout << " ";
            if (right[r]) cout << right[r];
            else cout << "*";
            cout << endl;

            left[right[r]] = left[l];
            right[left[l]] = right[r];
        }
        cout << "-" << endl;
    }
}
