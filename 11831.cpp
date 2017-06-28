#include <iostream>
#include <string>
using namespace std;

char plus90(char cur) {
    if (cur == 'N') return 'L';
    if (cur == 'L') return 'S';
    if (cur == 'S') return 'O';
    if (cur == 'O') return 'N';
    return 0;
}

char minus90(char cur) {
    if (cur == 'N') return 'O';
    if (cur == 'O') return 'S';
    if (cur == 'S') return 'L';
    if (cur == 'L') return 'N';
}

int main() {
    while (true) {
        int n, m, s;
        cin >> n >> m >> s;
        if (n == 0 && m == 0 && s == 0) break;

        cin.ignore();
        char grid[n][m];
        int r = 0, c = 0;
        char dir = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' || grid[i][j] == 'O') {
                    r = i;
                    c = j;
                    dir = grid[i][j];
                }
            }
            cin.ignore();
        }

        string ins;
        cin >> ins;

        int count = 0;
        for (int i = 0; i < ins.length(); i++) {
            char a = ins[i];

            if (a == 'D') dir = plus90(dir);
            else if (a == 'E') dir = minus90(dir);
            else {
                int nr = r;
                int nc = c;

                if (dir == 'N') nr -= 1;
                if (dir == 'S') nr += 1;
                if (dir == 'L') nc += 1;
                if (dir == 'O') nc -= 1;

                if (nr < 0 || nr >= n) continue;
                if (nc < 0 || nc >= m) continue;
                if (grid[nr][nc] == '#') continue;

                r = nr;
                c = nc;
                if (grid[r][c] == '*') {
                    count++;
                    grid[r][c] = '.';
                }
            }
        }

        cout << count << endl;
    }
}
