#include <iostream>
using namespace std;

int main() {
    while (true) {
        int k;
        cin >> k;
        if (k == 0) break;

        int a, b;
        cin >> a >> b;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;

            if (x == a || y == b) cout << "divisa" << endl;
            else if (x > a && y > b) cout << "NE" << endl;
            else if (x < a && y > b) cout << "NO" << endl;
            else if (x > a && y < b) cout << "SE" << endl;
            else if (x < a && y < b) cout << "SO" << endl;
        }
    }
}
