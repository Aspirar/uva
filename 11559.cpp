#include <iostream>
using namespace std;

int main() {
    int n, b, h, w;
    while (cin >> n) {
        cin >> b >> h >> w;

        bool found = false;
        int cost = 100000000;

        for (int i = 0; i < h; i++) {
            int price;
            cin >> price;

            bool bedsAvailable = false;
            for (int j = 0; j < w; j++) {
                int a;
                cin >> a;
                if (a >= n) {
                    bedsAvailable = true;
                }
            }

            if (bedsAvailable) {
                int stayCost = price * n;
                if (stayCost < cost) {
                    cost = stayCost;
                    if (cost <= b) found = true;
                }
            }
        }

        if (found) cout << cost << endl;
        else cout << "stay home" << endl;
    }
}
