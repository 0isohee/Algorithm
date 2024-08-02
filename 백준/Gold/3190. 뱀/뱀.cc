#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx [] = {0,1,0,-1}; // 동, 남, 서, 북
int dy [] = {1,0,-1,0};
struct apple {
    int x,y;
};

struct snake {
    int hx, hy;
    int tx, ty;
    int length;
    int mode;
    queue<pair<int, int>> body; // 뱀의 몸 위치 저장
};

void changeDir(snake &s, char dir){
    // 왼쪽 회전
    if (dir == 'L'){
        s.mode = (s.mode + 3) % 4;
    }
    // 오른쪽 회전
    else if (dir == 'D'){  
        s.mode = (s.mode + 1) % 4;
    }
}

bool moveSnake(snake &s, int &N, vector<vector<int>> &board){
    // 현재 방향으로 직진
    int nx = s.hx + dx[s.mode];
    int ny = s.hy + dy[s.mode];

    // 벽이나 몸에 부딪힌지 확인
    if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == 2) {
        return false;
    }

    // 이동
    s.hx = nx;
    s.hy = ny;
    s.body.push({nx, ny});

    // 사과 먹은지 확인
    if (board[nx][ny] == 1) {
        board[nx][ny] = 0;
        s.length++;
    } else {
        // 꼬리 이동
        auto tail = s.body.front();
        s.body.pop();
        board[tail.first][tail.second] = 0;
    }

    // 머리 위치 업데이트
    board[nx][ny] = 2;

    return true;
}

int main() {   
    int N, K, L;
    cin >> N >> K;

    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

    for (int i=0; i<K; i++){
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 사과 위치
    }
    cin >> L;

    vector<pair<int, char>> directions(L);
    for (int i=0; i<L; i++){
        int t;
        char c;
        cin >> t >> c;
        directions[i] = {t, c};
    }

    /* snake initialize */
    snake s;
    s.hx = 1;
    s.hy = 1;
    s.tx = 1;
    s.ty = 1;
    s.mode = 0;     // 처음은 오른쪽으로 직진하는 방향으로 설정
    s.length = 1;
    s.body.push({1, 1});
    board[1][1] = 2; // 뱀 위치 표시

    int globalTime = 0;
    int dirIndex = 0;

    while (true) {
        globalTime++;

        // 뱀 이동
        if (!moveSnake(s, N, board)) {
            break;
        }
        
        // 방향 전환
        if (dirIndex < L && globalTime == directions[dirIndex].first) {
            changeDir(s, directions[dirIndex].second);
            dirIndex++;
        }
    }
    cout << globalTime << "\n";
    return 0;
}