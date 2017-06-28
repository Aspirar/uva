#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair< int, int > ii;

int main() {
    int t;
    cin >> t;

    for (int T = 1; T <= t; T++) {
        int r, c, m, n;
        cin >> r >> c >> m >> n;

        int w;
        cin >> w;

        int grid[110][110] = { };
        for (int i = 0; i < w; i++) {
            int a, b;
            cin >> a >> b;
            grid[a][b] = -1;
        }

        int dx[] = { m, -m, n, -n, m, -m, n, -n };
        int dy[] = { n, -n, -m, m, -n, n, m, -m };

        int max = 8;
        if (m == 0 || n == 0 || m == n) max = 4;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == -1) continue;
                for (int k = 0; k < max; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
                    if (grid[ni][nj] == -1) continue;
                    grid[ni][nj]++;
                }
            }
        }

        int even = 0, odd = 0;
        queue< ii > q;
        q.push(make_pair(0, 0));

        while (!q.empty()) {
            ii square = q.front();
            q.pop();
            int i = square.first;
            int j = square.second;
            if (grid[i][j] == -1) continue;
            if (i < 0 || j < 0 || i >= r || j >= c) continue;
            if (grid[i][j] % 2 == 0) even++;
            else odd++;
            grid[i][j] = -1;
            for (int k = 0; k < max; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
                if (grid[ni][nj] == -1) continue;
                q.push(make_pair(ni, nj));
            }
        }

        cout << "Case " << T << ": " << even << " " << odd << endl;
    }
}
