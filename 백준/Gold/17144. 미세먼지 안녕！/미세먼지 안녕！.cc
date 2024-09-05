#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

int R, C, T;
int Ux, Uy, Dx, Dy;
int map[50][50] = {0,};
int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};

void dustMove() {

    queue<pair<int,int>> q;
    vector<vector<int>> newMap(R, vector<int>(C,0));

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (map[i][j] > 0) {
                q.push({i,j});
            }
        }
    }

    while (!q.empty()) {

        pair<int,int> now = q.front();
        q.pop();

        int c = 0;
        int m = 0;
        for (int d=0; d<4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == -1) continue;
            c++;
            newMap[nx][ny] += trunc(map[now.first][now.second] / 5);
            m = trunc(map[now.first][now.second] / 5);
        }
        newMap[now.first][now.second] += (map[now.first][now.second] - (m * c));
    }

   for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            map[i][j] = newMap[i][j];
        }
    }
}

void machineOn() {
    // 1. 상단 공기청정기 : 우 -> 상 -> 좌 -> 하 
    for (int i = Ux - 1; i > 0; i--) map[i][0] = map[i - 1][0]; // 위쪽에서 아래로
    for (int i = 0; i < C - 1; i++) map[0][i] = map[0][i + 1]; // 왼쪽에서 오른쪽으로
    for (int i = 0; i < Ux; i++) map[i][C - 1] = map[i + 1][C - 1]; // 아래쪽에서 위로
    for (int i = C - 1; i > 1; i--) map[Ux][i] = map[Ux][i - 1]; // 오른쪽에서 왼쪽으로
    map[Ux][1] = 0; // 공기청정기 바로 오른쪽은 정화됨

    // 2. 하단 공기청정기 : 우 -> 하 -> 좌 -> 상
    for (int i = Dx + 1; i < R - 1; i++) map[i][0] = map[i + 1][0]; // 아래에서 위로
    for (int i = 0; i < C - 1; i++) map[R - 1][i] = map[R - 1][i + 1]; // 왼쪽에서 오른쪽으로
    for (int i = R - 1; i > Dx; i--) map[i][C - 1] = map[i - 1][C - 1]; // 위쪽에서 아래로
    for (int i = C - 1; i > 1; i--) map[Dx][i] = map[Dx][i - 1]; // 오른쪽에서 왼쪽으로
    map[Dx][1] = 0; // 공기청정기 바로 오른쪽은 정화됨

    map[Ux][Uy] = -1;
    map[Dx][Dy] = -1;
}

void printMap(vector<vector<int>> map) {

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int countDust() {
    int a = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            a += map[i][j];
        }
    }
    a += 2;

    return a;
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C >> T;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> map[i][j];
        }
    }

    bool c = false;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (map[i][j] == -1) {
                Ux = i;
                Uy = j;
                c = true;
                break;
            }
        }
        if (c) break;
    }
    Dx = Ux + 1;
    Dy = Uy;

    while (T > 0) {

        dustMove();
        machineOn();
        T --;
    }
    cout << countDust() << "\n";
    return 0;
}