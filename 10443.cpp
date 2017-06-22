#include <iostream>
#include <vector>
#include <string>
using namespace std;

char lose(char form) {
    if (form == 'R') return 'P';
    if (form == 'P') return 'S';
    if (form == 'S') return 'R';
    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c, n;
        cin >> r >> c >> n;

        vector< string > grid(r);
        vector< string > winner(r);
        for (int i = 0; i < r; i++) {
            cin >> grid[i];
            winner[i] = grid[i];
        }

        while (n--) {
            for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
                char form = grid[i][j];
                int loss = 0;
                if (i-1 >= 0 && grid[i-1][j] == lose(form)) ++loss;
                if (i+1 < r && grid[i+1][j] == lose(form)) ++loss;
                if (j-1 >= 0 && grid[i][j-1] == lose(form)) ++ loss;
                if (j+1 < c && grid[i][j+1] == lose(form)) ++loss;
                if (loss > 0) winner[i][j] = lose(form);
                else winner[i][j] = form;
            }

            for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
                grid[i][j] = winner[i][j];
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }

        if (t != 0) cout << endl;
    }
}
