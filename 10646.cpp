#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int T = 1; T <= t; T++) {
        string pile[52];
        for (int i = 0; i < 52; i++) {
            cin >> pile[i];
        }

        int Y = 0;
        int current = 24;
        for (int i = 0; i < 3; i++) {
            int value = pile[current][0] - '0';
            current -= 1;
            int X;
            if (value >= 2 && value <= 9) {
                X = value;
            } else {
                X = 10;
            }

            Y += X;
            current -= (10 - X);
        }

        int index;
        Y -= 1;
        if (Y <= current) {
            index = Y;
        } else {
            Y -= current;
            index = 24 + Y;
        }

        cout << "Case " << T << ": " << pile[index] << endl;
    }
}
