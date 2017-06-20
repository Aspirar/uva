#include <iostream>
using namespace std;

int main() {
    while (true) {
        double h, u, d, f;
        cin >> h >> u >> d >> f;
        if (h == 0) break;

        double slide = (f / 100.0) * u;
        double height = 0;
        int day = 0;

        while (true) {
            day++;

            height += u;
            u -= slide;
            if (u < 0) u = 0;

            if (height > h) {
                cout << "success on day " << day << endl;
                break;
            }

            height -= d;
            if (height < 0) {
                cout << "failure on day " << day << endl;
                break;
            }
        }
    }
}
