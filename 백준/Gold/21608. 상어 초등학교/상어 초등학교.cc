#include<iostream>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

int N;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
vector<vector<int>> studentInfo;    //학생들 정보 (N행 4열)
vector<vector<int>> sitNum;         //자리 배치표
vector<vector<int>> sitCnt;         //남은 자리 몇갠지 확인하는 곳
vector<vector<bool>> isSit;         //자리에 사람 있는지 확인하는 배열
vector<int> studentOrder;           //학생 순서

struct Info {
    int blankCnt, row, col;
    Info(int c, int x, int y) : blankCnt(c), row(x), col(y) {}
};

struct cmp {
    bool operator()(Info a, Info b) {
        if (a.blankCnt == b.blankCnt) {
            if (a.row == b.row) {
                return a.col > b.col;
            }
            return a.row > b.row;
        }
        return a.blankCnt < b.blankCnt; 
    } 
};

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isIn(int number, vector<int> favoriteList) {
    for (int i=0; i<4; i++) {
        if (favoriteList[i] == number) return true;
    }
    return false;
}

void findMaxBlank(int number, vector<int> favoriteList) {
    
    sitCnt.resize(N, vector<int>(N, 0));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (isSit[i][j]) continue;
            int c = 0;
            for (int d=0; d<4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (isRange(nx, ny)) {
                    if (!isSit[nx][ny]) {
                        c++;
                    }
                    if (isIn(sitNum[nx][ny], favoriteList)) {
                        c+=1000;
                    }
                }
            }
            sitCnt[i][j] = c;
        }
    }

    priority_queue<Info, vector<Info>, cmp> pq;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (isSit[i][j]) continue;
            pq.push(Info(sitCnt[i][j], i, j));
        }
    }
    
    Info i = pq.top(); pq.pop();
    
    //자리 배치표에 숫자 적고 방문 배열 체크
    sitNum[i.row][i.col] = number;
    isSit[i.row][i.col] = true;
}

int getStudentScore(int number, int x, int y) {

    int cnt = 0;

    for (int d=0; d<4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (isRange(nx,ny) && isIn(sitNum[nx][ny], studentInfo[number])) {
            cnt ++;
        }
    }

    if (cnt == 1){
        return 1;
    } else if (cnt == 2) {
        return 10;
    } else if (cnt == 3) {
        return 100;
    } else if (cnt == 4) {
        return 1000;
    } else {
        return cnt;
    }

}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    studentInfo.resize(N*N, vector<int>(4,0));
    sitNum.resize(N, vector<int>(N, -1));
    isSit.resize(N, vector<bool>(N, false));
    
    for (int i=0; i<N*N; i++) {
        int n;
        cin >> n;
        studentOrder.push_back(n-1);
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        studentInfo[n-1][0] = a-1;
        studentInfo[n-1][1] = b-1;
        studentInfo[n-1][2] = c-1;
        studentInfo[n-1][3] = d-1;
    }
    
    for (int i=0; i<studentOrder.size(); i++) {
        findMaxBlank(studentOrder[i], studentInfo[studentOrder[i]]);
    }

    int score = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            score += getStudentScore(sitNum[i][j], i, j);
        }
    }
    cout << score << "\n";
    return 0;
}