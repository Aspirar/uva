#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int TC = 1; TC <= t; TC++) {
        int n;
        cin >> n;

        vector< int > a;
        for (int i = 0; i < n; i++) {
            int e;
            cin >> e;
            a.push_back(e);
        }

        sort(a.begin(), a.end());

        cout << "Case " << TC << ": " << a[n-1] << endl;
    }
}
