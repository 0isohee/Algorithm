#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<climits>

using namespace std;

int N, M;
int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};
int maxV = INT_MIN;
vector<vector<int>> map;
vector<int> selectWall(3,0);
vector<pair<int, int>> wallList;

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int findSafeArea(vector<int> selectWall) {

    vector<vector<int>> copymap = map;

    for (int i=0; i<3; i++) {
        pair<int,int> now = wallList[selectWall[i]];
        copymap[now.first][now.second] = 1;
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int,int>> q;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (copymap[i][j] == 2) {
                q.push({i,j});
                visited[i][j] = true;

                while (!q.empty()) {
                    pair<int,int> now = q.front();
                    q.pop();

                    for (int d=0; d<4; d++) {
                        int nx = now.first + dx[d];
                        int ny = now.second + dy[d];

                        if (isRange(nx,ny) && !visited[nx][ny] && copymap[nx][ny] == 0) {
                            q.push({nx,ny});
                            visited[nx][ny] = true;
                            copymap[nx][ny] = 2;
                        }
                    }
                }
            }
        }
    }

    int c = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (copymap[i][j] == 0) {
                c ++;
            }
        }
    }
    return c;
}

void setWall(int L, int start) {

    if (L == 3) {
        maxV = max(maxV, findSafeArea(selectWall));
        return;
    }

    for (int i=start; i<wallList.size(); i++) {
        selectWall[L] = i;
        setWall(L+1, i+1);
    }
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    map.resize(N, vector<int>(M,0));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                wallList.push_back({i,j});
            }
        }
    }

    setWall(0,0);

    cout << maxV << "\n";
    return 0;
}