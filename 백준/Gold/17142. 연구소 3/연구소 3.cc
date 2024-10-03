#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

int N, M, minV;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
vector<vector<int>> map;
vector<pair<int,int>> virusPos;
vector<int> selectVirus;
int emptyCount = 0; // 빈 칸의 개수를 셀 변수

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int findTime(vector<int> s) {
    
    vector<vector<int>> temp(N, vector<int>(N,0));
    vector<vector<int>> distance(N, vector<int>(N,-1));  // 초기값을 -1로 설정
    vector<vector<bool>> visited(N, vector<bool>(N,false));
    queue<pair<int,int>> q;
    
    for (int i=0; i<M; i++) {
        pair<int,int> now = virusPos[s[i]];
        temp[now.first][now.second] = 2;
        distance[now.first][now.second] = 0;  // 시작 위치는 0초로 설정
        visited[now.first][now.second] = true;
        q.push({now.first, now.second});    
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            // 벽 표시
            if (map[i][j] == 1) {
                visited[i][j] = true;
                temp[i][j] = 1;
            }
            // 비활성 바이러스 표시
            if (map[i][j] == 2 && !visited[i][j]) {
                temp[i][j] = 3;
            }
        }
    }
    
    int filledCount = 0; // 채운 빈 칸의 개수를 셀 변수
    while (!q.empty()) {
        pair<int,int> n = q.front();
        q.pop();
        
        for (int d=0; d<4; d++){
            int nx = n.first + dx[d];
            int ny = n.second + dy[d];
            
            if (isRange(nx, ny) && !visited[nx][ny] && temp[nx][ny] != 1) {
                distance[nx][ny] = distance[n.first][n.second] + 1;
                q.push({nx,ny});
                visited[nx][ny] = true;
                
                // 빈 칸에 퍼질 때만 채운 빈 칸의 개수를 증가
                if (map[nx][ny] == 0) {
                    filledCount++;
                }
            }
        }
    }
    
    if (filledCount != emptyCount) { // 모든 빈 칸에 퍼지지 않았다면
        return INT_MAX;
    }
    
    int d = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == 0 && distance[i][j] > d) {
                d = distance[i][j];
            }
        }
    }
    return d;
}

void getVirus(int L, int s) {
    
    if (L == M) {
        minV = min(findTime(selectVirus), minV);
        return;   
    }
    
    for (int i=s; i<virusPos.size(); i++) {
        selectVirus[L] = i;
        getVirus(L+1, i+1);
    }
}

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    
    map.resize(N, vector<int>(N,0));
    selectVirus.resize(M, 0);
    minV = INT_MAX;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virusPos.push_back({i,j});
            }
            if (map[i][j] == 0) {
                emptyCount++;  // 빈 칸 개수 세기
            }
        }
    }
    
    if (emptyCount == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    getVirus(0,0);
    
    if (minV == INT_MAX) {
        cout << -1 << "\n";
    } else {
        cout << minV << "\n";
    }
    return 0;
}
