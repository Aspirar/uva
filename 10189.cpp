#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t = 0;
    while (true) {
        t++;
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        if (t != 1) cout << endl;

        vector< string > field;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            field.push_back(s);
        }

        cout << "Field #" << t << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*') {
                    cout << '*';
                    continue;
                }

                int near = 0;
                if (i-1 >= 0) {
                    if (j-1 >= 0 && field[i-1][j-1] == '*') near++;
                    if (field[i-1][j] == '*') near++;
                    if (j+1 < m && field[i-1][j+1] == '*') near++;
                }
                if (i+1 < n) {
                    if (j-1 >= 0 && field[i+1][j-1] == '*') near++;
                    if (field[i+1][j] == '*') near++;
                    if (j+1 < m && field[i+1][j+1] == '*') near++;
                }
                if (j-1 >= 0 && field[i][j-1] == '*') near++;
                if (j+1 < m && field[i][j+1] == '*') near++;
                cout << near;
            }
            cout << endl;
        }
    }
}
