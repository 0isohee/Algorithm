#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<utility>

using namespace std;

int N, L, R;
int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};
vector<vector<int>> map;

int isRange(int v) {
    return v >= L && v <= R;
}

bool peopleMove() {

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    bool isMoved = false;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j]) continue;

            vector<pair<int, int>> unionCoords;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            unionCoords.push_back({i, j});
            
            int sumV = map[i][j];
            while (!q.empty()) {

                pair<int,int> now = q.front();
                q.pop();

                for (int d=0; d<4; d++) {
                    int nx = dx[d] + now.first;
                    int ny = dy[d] + now.second;
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if (isRange(abs(map[now.first][now.second]-map[nx][ny])) && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                        sumV += map[nx][ny];
                        unionCoords.push_back({nx,ny});
                    }
                }
            }

            if (unionCoords.size() > 1) {
                isMoved = true;
                int newP = trunc(sumV / unionCoords.size());
                for (auto coord : unionCoords) {
                    map[coord.first][coord.second] = newP;
                }
            }
        }
    }
    
    return isMoved;
}

void printMap() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> L >> R;
    map.resize(N, vector<int>(N,0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    int time = 0;
    while (true) {
        if (!peopleMove()) break;
        time ++;
    }
    cout << time << "\n";
    return 0;
}