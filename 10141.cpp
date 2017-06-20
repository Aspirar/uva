#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 0;
    while (true) {
        num++;
        int n, p;
        cin >> n >> p;
        if (n == 0 && p == 0) break;
        cin.ignore();

        string s;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
        }

        double compliance = 0;
        string ans;
        double cost = 100000000;

        for (int i = 0; i < p; i++) {
            string name;
            getline(cin, name);
            
            double d;
            int r;
            cin >> d >> r;
            cin.ignore();

            for (int j = 0; j < r; j++) {
                getline(cin, s);
            }

            double c = (double)r / n;
            if (c > compliance) {
                compliance = c;
                ans = name;
                cost = d;
            } else if (c == compliance) {
                if (d < cost) {
                    compliance = c;
                    ans = name;
                    cost = d;
                }
            }
        }

        if (num != 1) cout << endl;
        cout << "RFP #" << num << endl;
        cout << ans << endl;
    }
}
