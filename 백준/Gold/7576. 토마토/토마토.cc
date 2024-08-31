#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int M, N;
int dx [] = {-1, 0, 1, 0};
int dy [] = {0, -1, 0, 1};
vector<vector<int>> map;
vector<vector<int>> visited;

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    cin >> M >> N;
    map.resize(N, vector<int>(M, 0));    
    visited.resize(N, vector<int>(M, 0));  
    queue<pair<int,int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        pair<int,int> now = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if (isRange(nx, ny) && visited[nx][ny] == 0 && map[nx][ny] == 0) {
                visited[nx][ny] = visited[now.first][now.second] + 1;
                q.push({nx, ny});
                map[nx][ny] = 1; 
            }
        }
    }

    int maxDays = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {  
                cout << -1 << endl;
                return 0;
            }
            maxDays = max(maxDays, visited[i][j]);
        }
    }

    cout << maxDays - 1 << endl;

    return 0;
}