#include <iostream>
#include <vector>
#include <string>
using namespace std;

int checkInstances(vector< string > &big, vector< string > &small) {
    int N = big.size(), n = small.size();

    int count = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        bool found = true;
        for (int k = 0; k < n; k++) for (int l = 0; l < n; l++) {
            int r = i + k, c = j + l;
            if (r >= N || c >= N) {
                found = false;
                break;
            }
            if (big[r][c] != small[k][l]) {
                found = false;
                break;
            }
        }
        if (found) count++;
    }
    return count;
}

void rotate(vector< string > &square) {
    int n = square.size();
    vector< string > copy(square);

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        square[j][n-i-1] = copy[i][j];
    }
}

int main() {
    while (true) {
        int N, n;
        cin >> N >> n;
        if (N == 0 && n == 0) break;

        vector< string > big(N);
        for (int i = 0; i < N; i++) {
            cin >> big[i];
        }

        vector< string > small(n);
        for (int i = 0; i < n; i++) {
            cin >> small[i];
        }

        cout << checkInstances(big, small) << " ";
        rotate(small);
        cout << checkInstances(big, small) << " ";
        rotate(small);
        cout << checkInstances(big, small) << " ";
        rotate(small);
        cout << checkInstances(big, small) << endl;
    }
}
