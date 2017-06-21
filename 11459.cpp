#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int p, s, dies;
        cin >> p >> s >> dies;
        vector< int > players(p, 1);

        map< int, int > ladders;
        for (int i = 0; i < s; i++) {
            int from, to;
            cin >> from >> to;
            ladders[from] = to;
        }

        int index = 0;
        bool finish = false;
        for (int i = 0; i < dies; i++) {
            int roll;
            cin >> roll;
            if (finish) continue;
            if (p == 0) continue;
            players[index] += roll;
            if (players[index] >= 100) {
                players[index] = 100;
                finish = true;
            }
            if (ladders[players[index]]) {
                players[index] = ladders[players[index]];
            }
            if (players[index] >= 100) {
                players[index] = 100;
                finish = true;
            }
            index = (index + 1) % p;
        }

        for (int i = 0; i < p; i++) {
            cout << "Position of player " << (i+1) << " is " << players[i] << ".\n";
        }
    }
}
