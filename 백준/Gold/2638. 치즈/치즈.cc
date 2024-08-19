#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> map;
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1}; 

// 치즈와 맞닿은 외부 공기 체크
void bfs(vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                if (map[nx][ny] == 0) { // 외부 공기
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } 
            }
        }
    }
}

// 치즈 녹이는 함수
int meltCheese() {
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    bfs(visited);

    bool hasCheese = false;
    int melted = 0;

    vector<vector<int>> meltMap(N, vector<int>(M, 0));

    // 치즈 녹는 부분 체크
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) { 
                int airTouch = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny]) {
                        airTouch++;
                    }
                }
                if (airTouch >= 2) {
                    meltMap[i][j] = 1;
                    melted++;
                }
                hasCheese = true;
            }
        }
    }

    // 실제로 치즈를 녹임
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (meltMap[i][j] == 1) {
                map[i][j] = 0;
            }
        }
    }

    return melted;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    map.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int time = 0;
    
    while (true) {  
        int melted = meltCheese();
        if (melted == 0) break; 
        time++;
    }

    cout << time << "\n";

    return 0;
}