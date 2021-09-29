#include <bits/stdc++.h>
using namespace std;

char grid[8][8];
bool row[8], diag1[16], diag2[16];
int ans;

void search(int col = 0) {
    /* past the end of the board */
    if(col == 8) {
        ++ans;
        return;
    }
    /* place one queen on each row */ 
    for(int r=0; r<8; ++r) {
        /* diag1 => row + col, diag2 => row - col + n - 1 */
        if(!row[r] and !diag1[r + col] and !diag2[r - col + 8 - 1] and grid[r][col] != '*') {
            row[r] = diag1[r + col] = diag2[r - col + 8 - 1] = 1;
            search(col + 1);
            row[r] = diag1[r + col] = diag2[r - col + 8 - 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            cin >> grid[i][j];
        }
    }
    search(0);
    cout << ans;
}
