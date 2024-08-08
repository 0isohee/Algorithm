#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Shark {
    int speed, dir, size;
};

struct comp {
    bool operator()(const Shark &a, const Shark &b) const {
        return a.size > b.size;
    }
};

int R, C, M;
// 방향: 상(1), 하(2), 우(3), 좌(4)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<vector<Shark>>> map;

void moveSharks(vector<vector<vector<Shark>>> &map) {
    vector<vector<vector<Shark>>> newMap(R + 1, vector<vector<Shark>>(C + 1));
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (!map[i][j].empty()) {
                Shark s = map[i][j][0];
                int nx = i, ny = j;
                int speed = s.speed;
                
                if (s.dir == 0 || s.dir == 1) {
                    speed %= (R - 1) * 2;
                } else {
                    speed %= (C - 1) * 2;
                }

                for (int k = 0; k < speed; ++k) {
                    nx += dx[s.dir];
                    ny += dy[s.dir];

                    if (nx > R || nx < 1 || ny > C || ny < 1) {
                        nx -= dx[s.dir];
                        ny -= dy[s.dir];
                        s.dir = (s.dir % 2 == 0) ? s.dir + 1 : s.dir - 1;
                        nx += dx[s.dir];
                        ny += dy[s.dir];
                    }
                }

                newMap[nx][ny].push_back(s);
            }
        }
    }

    map = newMap;
}

void catchShark(int col, int &totalSize) {
    for (int row = 1; row <= R; ++row) {
        if (!map[row][col].empty()) {
            totalSize += map[row][col][0].size;
            map[row][col].clear();
            break;
        }
    }
}

void resolveConflicts() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (map[i][j].size() > 1) {
                sort(map[i][j].begin(), map[i][j].end(), comp());
                map[i][j].erase(map[i][j].begin() + 1, map[i][j].end());
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C >> M;

    map.resize(R + 1, vector<vector<Shark>>(C + 1));

    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Shark newShark;
        newShark.speed = s;
        newShark.size = z;
        newShark.dir = d - 1;
        map[r][c].push_back(newShark);
    }

    int totalSize = 0;

    for (int col = 1; col <= C; ++col) {
        catchShark(col, totalSize);
        moveSharks(map);
        resolveConflicts();
    }

    cout << totalSize << "\n";

    return 0;
}
