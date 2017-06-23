#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair< int, int > ii;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int npages = (n + 3) / 4;

        int f1 = npages * 4, f2 = 1, b1 = 2, b2 = npages * 4 - 1;
        cout << "Printing order for " << n << " pages:" << endl;
        for (int i = 0; i < npages; i++) {
            if (f1 <= n || f2 <= n) {
                cout << "Sheet " << (i+1) << ", front: ";
                if (f1 > n) cout << "Blank, ";
                else cout << f1 << ", ";
                if (f2 > n) cout << "Blank" << endl;
                else cout << f2 << endl;
            }
            if (b1 <= n || b2 <= n) {
                cout << "Sheet " << (i+1) << ", back : ";
                if (b1 > n) cout << "Blank, ";
                else cout << b1 << ", ";
                if (b2 > n) cout << "Blank" << endl;
                else cout << b2 << endl;
            }
            f1 -= 2;
            f2 += 2;
            b1 += 2;
            b2 -= 2;
        }
    }
}
