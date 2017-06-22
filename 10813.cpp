#include <iostream>
using namespace std;

bool check(int card[5][5]) {
    for (int i = 0; i < 5; i++) {
        bool flag = true;
        for (int j = 0; j < 5; j++) {
            if (card[i][j] != 100) {
                flag = false;
                break;
            }
        }
        if (flag == true) return true;
    }

    for (int j = 0; j < 5; j++) {
        bool flag = true;
        for (int i = 0; i < 5; i++) {
            if (card[i][j] != 100) {
                flag = false;
                break;
            }
        }
        if (flag == true) return true;
    }

    bool flag = true;
    for (int i = 0, j = 0; i < 5, j < 5; i++, j++) {
        if (card[i][j] != 100) {
            flag = false;
            break;
        }
    }
    if (flag == true) return true;

    flag = true;
    for (int i = 0, j = 4; i < 5, j >= 0; i++, j--) {
        if (card[i][j] != 100) {
            flag = false;
            break;
        }
    }
    if (flag == true) return true;

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int card[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 2 && j == 2) {
                    card[i][j] = 100;
                    continue;
                }
                cin >> card[i][j];
            }
        }

        int ans = 0;
        for (int round = 0; round < 75; round++) {
            int n;
            cin >> n;
            bool found = false;
            for (int i = 0; i < 5; i++) {
                if (found) break;
                for (int j = 0; j < 5; j++) {
                    if (card[i][j] == n) {
                        card[i][j] = 100;
                        found = true;
                        break;
                    }
                }
            }

            if (check(card) == true) {
                if (!ans) ans = round + 1;
            }
        }

        cout << "BINGO after " << ans << " numbers announced" << endl;
    }
}
