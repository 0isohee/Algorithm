#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cmath>
#include<algorithm>
using namespace std;

int N, M, D;
int dx [] = {-1, 0, 1, 0};
int dy [] = {0, -1, 0, 1};
int maxV = 0;

vector<vector<int>> map;
vector<int> selectPolice(3, 0);

struct comp {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
        if (get<0>(a) == get<0>(b)) {
            return get<2>(a) < get<2>(b);
        }
        return get<0>(a) < get<0>(b); 
    }
};

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int getDis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int findDis(vector<int> policeNum) {
    vector<vector<int>> tempMap = map; 
    int cnt = 0;

    while (true) {
        vector<pair<int, int>> deadList;

        for (int i = 0; i < 3; i++) {
            int px = policeNum[i];
            int py = N;

            queue<pair<int, int>> q;
            vector<tuple<int, int, int>> enemyList;
            vector<vector<bool>> visited(N, vector<bool>(M, false));
            q.push({px, py});

            while (!q.empty()) {
                auto now = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if (isRange(ny, nx) && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        int distance = getDis(ny, nx, py, px);
                        if (distance <= D && tempMap[ny][nx] == 1) {
                            enemyList.push_back({distance, ny, nx});
                        }
                        q.push({nx, ny});
                    }
                }
            }

            if (!enemyList.empty()) {
                sort(enemyList.begin(), enemyList.end(), comp());
                deadList.push_back({get<1>(enemyList[0]), get<2>(enemyList[0])});
            }
        }

        for (auto& enemy : deadList) {
            if (tempMap[enemy.first][enemy.second] == 1) {
                tempMap[enemy.first][enemy.second] = 0;
                cnt++;
            }
        }

        bool enemiesLeft = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tempMap[i][j] == 1) {
                    enemiesLeft = true;
                    break;
                }
            }
            if (enemiesLeft) break;
        }

        if (!enemiesLeft) break;

        for (int i = N - 1; i > 0; i--) {
            tempMap[i] = tempMap[i - 1];
        }
        fill(tempMap[0].begin(), tempMap[0].end(), 0); 
    }

    return cnt;
}

void setPolice(int L, int start) {
    if (L == 3) {
        maxV = max(maxV, findDis(selectPolice));
        return;
    }
    for (int i = start; i < M; i++) {
        selectPolice[L] = i;
        setPolice(L + 1, i + 1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> D;
    map.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    setPolice(0, 0);

    cout << maxV << "\n";
    return 0;
}