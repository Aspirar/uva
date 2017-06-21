#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        char board[8][8];
        int r = 0, c = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '/') {
                r++;
                c = 0;
            }
            else if (ch - '0' <= 8) {
                int skip = ch - '0';
                for (int j = 0; j < skip; j++) {
                    board[r][c] = '0';
                    c++;
                }
            }
            else {
                board[r][c] = ch;
                c++;
            }
        }

        bool attacked[8][8] = {};
        for (int a = 0; a < 8; a++) for (int b = 0; b < 8; b++) {
            int piece = board[a][b];
            if (piece == '0') continue;
            attacked[a][b] = true;

            if (piece == 'q' || piece == 'Q' || piece == 'r' || piece == 'R') {
                for (int i = a, j = b-1; j >= 0 && board[i][j] == '0'; j--) attacked[i][j] = true;
                for (int i = a, j = b + 1; j < 8 && board[i][j] == '0'; j++) attacked[i][j] = true;
                for (int i = a-1, j = b; i >= 0 && board[i][j] == '0'; i--) attacked[i][j] = true;
                for (int i = a + 1, j = b; i < 8 && board[i][j] == '0'; i++) attacked[i][j] = true;
            }

            if (piece == 'q' || piece == 'Q' || piece == 'b' || piece == 'B') {
                for (int i = a-1, j = b-1; i >= 0 && j >= 0 && board[i][j] == '0'; i--, j--) attacked[i][j] = true;
                for (int i = a+1, j = b+1; i < 8 && j < 8 && board[i][j] == '0'; i++, j++) attacked[i][j] = true;
                for (int i = a+1, j = b-1; i < 8 && j >= 0 && board[i][j] == '0'; i++, j--) attacked[i][j] = true;
                for (int i = a-1, j = b+1; i >= 0 && j < 8 && board[i][j] == '0'; i--, j++) attacked[i][j] = true;
            }

            if (piece == 'k' || piece == 'K') {
                if (a-1 >= 0) {
                    if (b-1 >= 0) attacked[a-1][b-1] = true;
                    attacked[a-1][b] = true;
                    if (b+1 < 8) attacked[a-1][b+1] = true;
                }
                if (a+1 < 8) {
                    if (b-1 >= 0) attacked[a+1][b-1] = true;
                    attacked[a+1][b] = true;
                    if (b+1 < 8) attacked[a+1][b+1] = true;
                }
                if (b-1 >= 0) attacked[a][b-1] = true;
                if (b+1 < 8) attacked[a][b+1] = true;
            }

            if (piece == 'n' || piece == 'N') {
                int r[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
                int c[] = { -1, 1, 2, 2, -1, 1, -2, -2 };
                for (int k = 0; k < 8; k++) {
                    int i = a + r[k];
                    int j = b + c[k];
                    if (i >= 0 && i < 8 && j >= 0 && j < 8) attacked[i][j] = true;
                }
            }

            if (piece == 'p') {
                if (a+1 < 8) {
                    if (b-1 >= 0) attacked[a+1][b-1] = true;
                    if (b+1 < 8) attacked[a+1][b+1] = true;
                }
            }

            if (piece == 'P') {
                if (a-1 >= 0) {
                    if (b-1 >= 0) attacked[a-1][b-1] = true;
                    if (b+1 < 8) attacked[a-1][b+1] = true;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) {
            if (!attacked[i][j]) count++;
        }

        cout << count << endl;
    }
}
