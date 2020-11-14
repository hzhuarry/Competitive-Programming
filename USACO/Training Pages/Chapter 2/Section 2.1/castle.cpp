/*
ID: hzhu7271
LANG: C++
TASK: castle
*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int M, N, a[50][50];
int room_color[50][50], color_size[2501];

struct wall {
    int i, j, combined_room_size;
    char direction;
    wall(int i, int j, int combined_room_size, char direction) :
        i(i), j(j), combined_room_size(combined_room_size), direction(direction)
    {
    }
    bool operator <(const wall& other) {
        if(combined_room_size == other.combined_room_size) {
            if(j == other.j) {
                if(i == other.i) {
                    /* prioritize 'N' over 'E' */
                    return direction == 'N';
                }
                /* prioritize bottommost wall */
                return i > other.i;
            }
            /* prioritize leftmost wall */
            return j < other.j;
        }
        /* prioritize larger room size */
        return combined_room_size > other.combined_room_size;
    }
};

bool ok(int i, int j) {
    return i>=0 and j>=0 and i<N and j<M and room_color[i][j]==0;
}

void floodfill(int i, int j, int color) {
    if(!ok(i, j))
        return;
    room_color[i][j] = color;
    color_size[color]++;
    for(int k=0; k<4; ++k) {
        if((a[i][j] & (1 << k)) == 0) {
            floodfill(i+dx[k], j+dy[k], color);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("castle.in");
    ofstream cout("castle.out");

    cin >> M >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> a[i][j];
        }
    }

    int color = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(room_color[i][j] == 0) {
                floodfill(i, j, ++color);
            }
        }
    }

    /* print out number of rooms the castle has */
    cout << color << endl;

    int largest_singular_room_size = 0;
    for(int i=1; i<=color; ++i)
        largest_singular_room_size = max(largest_singular_room_size, color_size[i]);
    /* print out the size of the largest room */
    cout << largest_singular_room_size << endl;

    vector<wall> walls;
    
    /* check walls between (i, j) and (i, j+1) */
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M-1; ++j) {
            if(a[i][j] & (1 << 2)) {
                int c1 = room_color[i][j], c2 = room_color[i][j+1];
                if(c1 != c2) {
                    walls.push_back(wall(i, j, color_size[c1]+color_size[c2], 'E'));
                }
            }
        }
    }

    /* check walls between (i, j) and (i+1, j) */
    for(int i=0; i<N-1; ++i) {
        for(int j=0; j<M; ++j) {
            if(a[i+1][j] & (1 << 1)) {
                int c1 = room_color[i][j], c2 = room_color[i+1][j];
                if(c1 != c2) {
                    walls.push_back(wall(i+1, j, color_size[c1]+color_size[c2], 'N'));
                }
            }
        }
    }

    sort(walls.begin(), walls.end());

    /* print the size of the largest room creatable by removing one wall */
    cout << walls[0].combined_room_size << endl;

    /* print the single wall to remove to make the largest room possible */
    cout << walls[0].i+1 << " " << walls[0].j+1 << " " << walls[0].direction << endl;
    return 0;
}


