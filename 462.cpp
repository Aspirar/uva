#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    while (true) {

        string cards[13];
        if (!(cin >> cards[0])) break;
        for (int i = 1; i <= 12; i++) {
            cin >> cards[i];
        }

        map<char, int> count;
        for (int i = 0; i < 13; i++) {
            char suit = cards[i][1];
            count[suit] += 1;
        }

        int score = 0;
        map<char, int> stopped;
        for (int i = 0; i < 13; i++) {
            char card = cards[i][0];
            char suit = cards[i][1];

            if (card == 'A') {
                score += 4;
                stopped[suit] = 1;
            }
            if (card == 'K') {
                score += 3;
                if (count[suit] == 1) score -= 1;
                else stopped[suit] = 1;
            }
            if (card == 'Q') {
                score += 2;
                if (count[suit] <= 2) score -= 1;
                else stopped[suit] = 1;
            }
            if (card == 'J') {
                score += 1;
                if (count[suit] <= 3) score -= 1;
            }
        }

        char suits[] = {'S', 'H', 'D', 'C'};

        int stoppedTotal = 0;
        for (int i = 0; i < 4; i++) {
            char suit = suits[i];
            stoppedTotal += stopped[suit];
        }
        if (stoppedTotal == 4 && score >= 16) {
            cout << "BID NO-TRUMP" << endl;
            continue;
        }

        char most;
        int mostCount = 0;
        for (int i = 0; i < 4; i++) {
            char suit = suits[i];
            if (count[suit] == 2) score += 1;
            if (count[suit] == 1) score += 2;
            if (count[suit] == 0) score += 2;

            if (count[suit] > mostCount) {
                mostCount = count[suit];
                most = suit;
            }
        }

        if (score >= 14) {
            cout << "BID " << most << endl;
        } else {
            cout << "PASS" << endl;
        }
    }
}
