#include <bits/stdc++.h>
using namespace std;

const int MX = 18;
int N;
char grid[MX][MX];
set<string> ans;
/* row1 = string starting from the top left to part of the diagonal on row[i]; same for row2 but starts at bottom right */
set<string> row1[MX], row2[MX];

void solve1(int x=0, int y=0, string s=""){
    if(x==N or y == N)
        return;
    s += grid[x][y];
    if(x+y==N-1){
        row1[x].insert(s);
        return;
    }
    solve1(x+1, y, s);
    solve1(x, y+1, s);
}

void solve2(int x=N-1, int y=N-1, string s=""){
    if(x<0 or y<0)
        return;
    s += grid[x][y];
    if(x+y == N-1){
        row2[x].insert(s);
        return;
    }
    solve2(x-1, y, s);
    solve2(x, y-1, s);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("palpath.in");
    ofstream cout("palpath.out");
    
    cin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> grid[i][j];
        }
    }
    solve1();
    solve2();

    for(int i=0; i<N; ++i){
        for(string s : row1[i]){
            if(row2[i].find(s) != row2[i].end()){
                ans.insert(s);
            }
        }
    }
    cout << (int)ans.size() << endl;
    return 0;
}
