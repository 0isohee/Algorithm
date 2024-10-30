#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>  // For memset
using namespace std;

int N, M, rotateCnt, selectNum[6], input[51][51], map[51][51], rotateOps[6][3], minV;
bool isSelect[6];

// 회전 배열 생성
void rotateMap(int x, int y, int d);
void findMinValue();
void permutation(int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    cin >> N >> M >> rotateCnt;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }
    for (int i = 0; i < rotateCnt; i++) {
        cin >> rotateOps[i][0] >> rotateOps[i][1] >> rotateOps[i][2];
    }

    // 초기값 설정
    minV = INT_MAX;
    memset(isSelect, false, sizeof(isSelect));

    // 순열 생성
    permutation(0);
    cout << minV << "\n";
    return 0;
}

void permutation(int cnt) {
    if (cnt == rotateCnt) {
        // map 배열 복사
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = input[i][j];
            }
        }
        
        // 회전 수행
        for (int i = 0; i < rotateCnt; i++) {
            rotateMap(rotateOps[selectNum[i]][0], rotateOps[selectNum[i]][1], rotateOps[selectNum[i]][2]);
        }
        
        // 최소값 갱신
        findMinValue();
        return;
    }

    for (int i = 0; i < rotateCnt; i++) {
        if (isSelect[i]) continue;
        isSelect[i] = true;
        selectNum[cnt] = i;
        permutation(cnt + 1);
        isSelect[i] = false;
    }
}

void findMinValue() {
    for (int row = 0; row < N; row++) {
        int rowSum = 0;
        for (int col = 0; col < M; col++) {
            rowSum += map[row][col];
        }
        minV = min(minV, rowSum);
    }
}

void rotateMap(int x, int y, int d) {
    int x1 = x - d - 1;
    int y1 = y - d - 1;
    int x2 = x + d - 1;
    int y2 = y + d - 1;

    int row = x2 - x1 + 1;
    int col = y2 - y1 + 1;
    
    vector<vector<int>> newMap(row, vector<int>(col));

    // 서브 매트릭스 복사
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            newMap[i][j] = map[x1 + i][y1 + j];
        }
    }

    // 회전 방향
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    // 회전 본격 시작
    int loopCnt = min(row, col) / 2;
    for (int cnt = 0; cnt < loopCnt; cnt++) {
        int r = cnt, c = cnt, temp = newMap[r][c];

        for (int dir = 0; dir < 4; dir++) {
            while (true) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                
                if (nr < cnt || nr >= row - cnt || nc < cnt || nc >= col - cnt) break;
                
                int swap = newMap[nr][nc];
                newMap[nr][nc] = temp;
                temp = swap;
                r = nr;
                c = nc;
            }
        }
    }

    // 회전된 값 원래 배열에 복사
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            map[x1 + i][y1 + j] = newMap[i][j];
        }
    }
}