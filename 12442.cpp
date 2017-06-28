#include <iostream>
#include <vector>
using namespace std;

typedef vector< int > vi;

vi visited;
vi count;
vi link;

int dfs(int start) {
    visited[start] = 1;
    int c = 0;
    if (link[start] != -1 && !visited[link[start]]) c += 1 + dfs(link[start]);
    visited[start] = 0;
    count[start] = c;
    return c;
}

int main() {
    int t;
    cin >> t;

    for (int T = 1; T <= t; T++) {
        int n;
        cin >> n;

        link.assign(n, -1);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            link[u-1] = v-1;
        }

        visited.assign(n, 0);
        count.assign(n, -1);

        int max = 0;
        int m = 0;

        for (int i = 0; i < n; i++) {
            if (count[i] == -1) dfs(i);
            if (count[i] > max) {
                max = count[i];
                m = i;
            }
        }

        cout << "Case " << T << ": " << m + 1 << endl;
    }
}
