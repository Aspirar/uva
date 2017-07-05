#include <iostream>
#include <vector>
#include <string>
using namespace std;

void convert(vector< string > &g) {
    vector< string > copy(g);
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
        int sum = 0;
        if (i > 0) sum += copy[i-1][j] - '0';
        if (i < 2) sum += copy[i+1][j] - '0';
        if (j > 0) sum += copy[i][j-1] - '0';
        if (j < 2) sum += copy[i][j+1] - '0';
        sum %= 2;
        g[i][j] = sum + '0';
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector< string > g(3);
        for (int i = 0; i < 3; i++) {
            cin >> g[i];
        }

        int index = 0;
        while (true) {
            if (g[0] + g[1] + g[2] == "000000000") break;
            convert(g);
            ++index;
        }

        cout << index-1 << endl;
    }
}
