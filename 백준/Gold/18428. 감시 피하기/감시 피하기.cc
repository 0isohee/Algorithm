#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
bool mode = false;
vector<vector<int>> map;
vector<pair<int,int>> blockPos;
vector<int> selectBlock;

void print(vector<vector<int>> m) {
    for(int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }    
}

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isPossible(vector<int> blocks) {
    
    vector<vector<int>> temp = map;
    
    for (int i=0; i<3; i++) {
        
        int x = blockPos[blocks[i]].first;
        int y = blockPos[blocks[i]].second;
        
        //장애물: -1, 선생님: 2, 학생들 1, 벽: 0
        temp[x][y] = -1;
    }
    
    queue<pair<int,int>> q;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (temp[i][j] == 2) {
                q.push({i,j});
            }
        }
    }
    
    //q 안에는 선생님 좌표 들어감 -> 선생님별로 모두 다 학생 안마주치고 내려가면 밑에서 true 반환
    while (!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        
        for (int d=0; d<4; d++) {
            int length = 1;
            while (true) {
                int nx = now.first+(dx[d]*length);
                int ny = now.second+(dy[d]*length);
                
                if (isRange(nx,ny)) {
                    //장애물이면 그만하기
                    if (temp[nx][ny] == -1) {
                        break;
                    }
                    //학생들 만나면 이 위치는 안됨 -> 바로 false
                    else if (temp[nx][ny] == 1) {
                        return false;
                    }
                    length ++;
                }
                //범위 벗어나서까지 찾지 않기
                else {
                    break;
                }
            }
        }
    }
    return true;
}

void makeBlock(int s, int L) {
    
    if (mode == true) {
        return;    
    }
    
    if (L == 3) {
        // isPossible(selectBlock);
        if (isPossible(selectBlock)) {
            mode = true;
        }
        return;
    }
    
    for (int i=s; i<M; i++) {
        selectBlock[L] = i;
        makeBlock(i+1, L+1);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    map.resize(N, vector<int>(N, 0));
    selectBlock.resize(3, 0);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char c;
            cin >> c;
            if (c == 'T') {
                map[i][j] = 2;
            } else if (c == 'S') {
                map[i][j] = 1;
            } else {
                blockPos.push_back({i,j});
            }
        }
    } 
    
    M = blockPos.size();
    // print(map);
    makeBlock(0, 0);
    
    if (mode == true) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}