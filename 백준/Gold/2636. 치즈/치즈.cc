#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<vector<int>> map;

bool isAir(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

void meltCheese() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    // 가장자리 공기를 큐에 삽입하고 BFS를 시작
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];

            if (isAir(nx, ny) || visited[nx][ny]) continue;

            if (map[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    // 치즈가 녹는 처리
    vector<pair<int, int>> to_melt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) { // 치즈 발견
                int contact_count = 0;

                // 치즈 주변의 공기와 접촉된 부분 확인
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (!isAir(nx, ny) && visited[nx][ny]) {
                        contact_count++;
                    }
                }

                // 공기와 2면 이상 접촉한 치즈는 녹는다.
                if (contact_count > 0) {
                    to_melt.push_back({i, j});
                }
            }
        }
    }

    for (auto p : to_melt) {
        map[p.first][p.second] = 0;
    }
}

bool checkRemainingCheese() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) return true; 
        }
    }
    return false; 
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
    int lastCheeseCount = 0;

    while (checkRemainingCheese()) {
        lastCheeseCount = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1) lastCheeseCount++;
            }
        }
        meltCheese();
        time++;
    }

    cout << time << "\n";
    cout << lastCheeseCount << "\n";
    return 0;
}