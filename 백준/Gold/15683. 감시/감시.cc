#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>

using namespace std;

int N, M;
int minV = INT_MAX;

int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};
vector<vector<int>> map;
vector<vector<int>> checkMap;
vector<pair<int,int>> cctvPos;

// CCTV별 감시 방향
vector<vector<vector<int>>> cctvDirections = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},    
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, 
    {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}}, 
    {{0, 1, 2, 3}} 
};

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void mark(int x, int y, int dir, vector<vector<int>> &tempMap) {

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    while (isRange(nx,ny)) {
        if (tempMap[nx][ny] == 6) {
            break;
        }
        if (tempMap[nx][ny] == 0) {
            tempMap[nx][ny] = -1;
        }
        nx += dx[dir];
        ny += dy[dir];
    }
}

void DFS(int L, vector<vector<int>> tempMap) {

    if (L == cctvPos.size()) {

        int c = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (tempMap[i][j] == 0) {
                    c++;
                }
            }
        }
        minV = min(minV, c);
        return;
    }

    int x = cctvPos[L].first;
    int y = cctvPos[L].second;
    int n = tempMap[x][y];

    for (const auto &dirs : cctvDirections[n]) {
        vector<vector<int>> newMap = tempMap;

        for (int dir : dirs) {
            mark(x,y,dir,newMap);
        }
        DFS(L+1, newMap);
    }
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    map.resize(N, vector<int>(M,0));
    checkMap.resize(N, vector<int>(M,0));

    int cnt = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
            if (map[i][j] > 0 && map[i][j] < 6) {
                cctvPos.push_back({i,j});
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            checkMap[i][j] = map[i][j];
        }
    }

    DFS(0, checkMap);

    cout << minV << "\n";
    return 0;
}