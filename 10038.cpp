#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        bool save[3010] = { };
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if (i > 0) {
                int diff = abs(a - prev);
                save[diff] = true;
            }

            prev = a;
        }

        bool jolly = true;
        for (int i = 1; i < n; i++) {
            if (save[i] == false) {
                jolly = false;
                break;
            }
        }

        if (jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
}
