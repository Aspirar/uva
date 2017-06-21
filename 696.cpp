#include <iostream>
using namespace std;

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0) break;
        int r = m, c = n;

        int ans;
        if (m == 2 || n == 2) {
            if (n == 2) {
                n = m;
                m = 2;
            }

            int blocks = (((n + 1) / 2) + 1) / 2;
            if ((n/2) % 2 == 0) ans = (blocks - 1) * 4 + 2;
            else ans = blocks * 4;

            if (n > ans) ans = n;
        } else {
            ans = (m * n + 1) / 2;
        }

        if (r == 1) ans = c;
        if (c == 1) ans = r;
        if (r == 0 || c == 0) ans = 0;
        cout << ans << " knights may be placed on a " << r << " row " << c << " column board." << endl;
    }
}
