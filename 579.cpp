#include <cstdio>

int main() {
    while (true) {
        int h, m;
        scanf("%d:%d", &h, &m);
        if (h == 0 && m == 0) break;
        h = h % 12;

        double mangle = m * 6;
        double hangle = (h * 30) + (0.5 * m);

        double ans = hangle - mangle;
        if (ans < 0) ans *= -1;
        if (360 - ans < ans) ans = 360 - ans;
        printf("%.3f\n", ans);
    }
}
