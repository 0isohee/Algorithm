#include<iostream>
#include<vector>
using namespace std;

struct Robot {
    int r, c, d;
};

int N, M;
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1}; 
vector<vector<int>> map;
Robot robot;

bool move() {
    int rr = robot.r;
    int rc = robot.c;
    int rd = robot.d;

    if (map[rr][rc] == 0) {
        map[rr][rc] = 2; 
    }

    bool foundUnclean = false;
    for (int i = 0; i < 4; i++) {
        int nd = (rd + 3) % 4; 
        int nr = rr + dx[nd];
        int nc = rc + dy[nd];

        if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] == 0) { 
            robot.r = nr; 
            robot.c = nc;
            robot.d = nd;  
            return true;  
        }
        rd = nd; 
    }

    // 만약 4방향 모두 청소가 되어있거나 벽인 경우 후진을 시도
    int backDir = (rd + 2) % 4; 
    int nr = rr + dx[backDir];
    int nc = rc + dy[backDir];

    if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] != 1) {
        robot.r = nr;
        robot.c = nc;
        return true; 
    }

    return false; 
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin >> robot.r >> robot.c >> robot.d;
    map.resize(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        if (!move()) break;
    }

    int cleanedCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2) {
                cleanedCnt++;
            }
        }
    }

    cout << cleanedCnt << "\n";  
    return 0;
}