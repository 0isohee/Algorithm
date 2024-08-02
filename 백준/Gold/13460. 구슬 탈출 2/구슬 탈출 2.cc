#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<tuple>

using namespace std;

int dx [] = {0, 1, 0, -1};
int dy [] = {1, 0, -1, 0};

vector<vector<char>> map;
pair<int, int> RedPos;
pair<int, int> BluePos;
pair<int, int> HolePos;

bool moveMarble(int &rx, int &ry, int &bx, int &by, int dir) {
    bool redInHole = false, blueInHole = false;

    int redMoves = 0, blueMoves = 0;
    while (map[rx + dx[dir]][ry + dy[dir]] != '#' && map[rx][ry] != 'O') {
        rx += dx[dir];
        ry += dy[dir];
        redMoves++;
        if (map[rx][ry] == 'O') {
            redInHole = true;
            break;
        }
    }
    while (map[bx + dx[dir]][by + dy[dir]] != '#' && map[bx][by] != 'O') {
        bx += dx[dir];
        by += dy[dir];
        blueMoves++;
        if (map[bx][by] == 'O') {
            blueInHole = true;
            break;
        }
    }

    if (blueInHole) return false; // 파란 구슬이 구멍에 빠지면 실패
    if (redInHole) return true;   // 빨간 구슬이 구멍에 빠지면 성공

    // 구슬이 겹치는 경우 처리
    if (rx == bx && ry == by) {
        if (redMoves > blueMoves) {
            rx -= dx[dir];
            ry -= dy[dir];
        } else {
            bx -= dx[dir];
            by -= dy[dir];
        }
    }
    return true;
}

int main() {   
    int N, M;
    cin >> N >> M;
    
    map.resize(N, vector<char>(M));

    for (int i=0; i<N; i++){
        string temp;
        cin >> temp;
        for (int j=0; j<M; j++){
            map[i][j] = temp[j];
        
            if (map[i][j] == 'R'){
                RedPos = {i,j};
            } else if (map[i][j] == 'B') {
                BluePos = {i,j};
            } else if (map[i][j] == 'O') {
                HolePos = {i,j};
            } 
        }
    }

    queue<tuple<int, int, int, int, int>> q;
    q.push(make_tuple(RedPos.first, RedPos.second, BluePos.first, BluePos.second, 0));
    vector<vector<vector<vector<bool>>>> visited(N, vector<vector<vector<bool>>>(M, vector<vector<bool>>(N, vector<bool>(M, false))));
    visited[RedPos.first][RedPos.second][BluePos.first][BluePos.second] = true;

    while (!q.empty()) {
        int rx, ry, bx, by, cnt;
        tie(rx, ry, bx, by, cnt) = q.front();
        q.pop();

        if (cnt >= 10) {
            cout << -1 << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            if (!moveMarble(nrx, nry, nbx, nby, i)) continue;
            if (nrx == HolePos.first && nry == HolePos.second) {
                cout << cnt + 1 << "\n";
                return 0;
            }
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push(make_tuple(nrx, nry, nbx, nby, cnt + 1));
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}