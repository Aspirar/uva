#include <iostream>
#include <cmath>
using namespace std;

int main() {
    while (true) {
        long long size, p;
        cin >> size >> p;
        if (size == 0 && p == 0) break;

        long long centre = size / 2 + 1;
        long long complete = sqrt(p);
        if (complete % 2 == 0) complete--;

        long long ansX = centre + complete / 2;
        long long ansY = centre + complete / 2;

        if (complete * complete != p) {
            p -= complete * complete;
            long long step = complete + 1;
            ansX += 1;
            ansY += 1;
            for (int i = 0; i < 4; i++) {
                if (!p) break;
                for (int j = 0; j < step; j++) {
                    if (!p) break;
                    if (i == 0) ansX--;
                    else if (i == 1) ansY--;
                    else if (i == 2) ansX++;
                    else if (i == 3) ansY++;
                    p--;
                }
            }
        }

        cout << "Line = " << ansY << ", column = " << ansX << ".\n";
    }
}
