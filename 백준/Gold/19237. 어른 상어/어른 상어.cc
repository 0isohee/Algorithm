#include<iostream>
#include<vector>
#include<utility>

using namespace std;

struct Shark {
    int x, y;
    int num;
    int dir;
    bool isQuit;
    vector<vector<int>> directions;
};

int dx[] = {0, -1, 1, 0, 0}; // 상, 하, 좌, 우
int dy[] = {0, 0, 0, -1, 1};
int N, M, k;
vector<vector<int>> map;
vector<vector<pair<int, int>>> record;
vector<Shark> sharkList;

void printMap(vector<vector<pair<int,int>>> map) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            cout << map[i][j].first << " " << map[i][j].second << " ";
        }
        cout << "\n";
    }
}

void init() {
    map.resize(N, vector<int>(N, 0));
    record.resize(N, vector<pair<int, int>>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    sharkList.resize(M);

    for (int i = 0; i < M; i++) {
        Shark s;
        s.num = i + 1;
        s.isQuit = false;
        cin >> s.dir;
        sharkList[i] = s;
    }

    for (int i = 1; i <= M; i++) {
        Shark s = sharkList[i - 1];
        for (int j = 0; j < 4; j++) {
            vector<int> temp;
            for (int z = 0; z < 4; z++) {
                int a;
                cin >> a;
                temp.push_back(a);
            }
            s.directions.push_back(temp);
        }
        sharkList[i - 1] = s;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] != 0) {
                Shark &s = sharkList[map[i][j] - 1];
                s.x = i;
                s.y = j;
                sharkList[map[i][j] - 1] = s;
            }
        }
    }

    for (int i = 0; i < sharkList.size(); i++) {
        Shark s = sharkList[i];
        record[s.x][s.y].first = s.num;
        record[s.x][s.y].second = k;
    }
}

void earseSmell() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (record[i][j].second > 0) {
                record[i][j].second -= 1;
                if (record[i][j].second == 0) {
                    record[i][j].first = 0;
                }
            }
        }
    }
}

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void moveShark(Shark &s) {
    bool moved = false;
    int newX = s.x, newY = s.y, newDir = s.dir;

    // 냄새 없는 칸으로 이동
    for (int i = 0; i < 4; i++) {
        int ndir = s.directions[s.dir - 1][i];
        int nx = s.x + dx[ndir];
        int ny = s.y + dy[ndir];

        if (isRange(nx, ny) && record[nx][ny].first == 0) {
            newX = nx;
            newY = ny;
            newDir = ndir;
            moved = true;
            break;
        }
    }

    // 냄새 없는 칸이 없을 경우 자신의 냄새가 있는 칸으로 이동
    if (!moved) {
        for (int i = 0; i < 4; i++) {
            int ndir = s.directions[s.dir - 1][i];
            int nx = s.x + dx[ndir];
            int ny = s.y + dy[ndir];
            if (isRange(nx, ny) && record[nx][ny].first == s.num) {
                newX = nx;
                newY = ny;
                newDir = ndir;
                break;
            }
        }
    }

    s.x = newX;
    s.y = newY;
    s.dir = newDir;
}

void handleCollisions() {
    vector<vector<int>> tempMap(N, vector<int>(N, 0)); // 임시 맵

    for (Shark &s : sharkList) {
        if (s.isQuit) continue; // 추방된 상어는 무시
        int x = s.x;
        int y = s.y;

        if (tempMap[x][y] == 0) {
            tempMap[x][y] = s.num; // 그 칸에 처음 도달한 상어 기록
        } else {
            // 충돌 발생, 번호가 작은 상어만 남김
            if (tempMap[x][y] < s.num) {
                s.isQuit = true; // 번호가 큰 상어는 퇴출
            } else {
                for (Shark &otherShark : sharkList) {
                    if (otherShark.num == tempMap[x][y]) {
                        otherShark.isQuit = true; // 기존 상어 퇴출
                        break;
                    }
                }
                tempMap[x][y] = s.num; // 번호 작은 상어로 갱신
            }
        }
    }
}

void drawMap() {
    for (Shark &s : sharkList) {
        if (s.isQuit) continue; // 퇴출된 상어는 기록하지 않음
        record[s.x][s.y] = {s.num, k}; // 상어 기록과 냄새 갱신
    }
}

void gameStart() {
    
    for (int i = 0; i < sharkList.size(); i++) {
        if (sharkList[i].isQuit) continue; // 퇴출된 상어는 이동하지 않음
        moveShark(sharkList[i]); // 상어 이동
    }

    earseSmell(); // 냄새 지우기
    handleCollisions(); // 충돌 처리

    drawMap(); // 맵 그리기
}
int checkSharkCnt() {
    int c = 0;
    for (int i=0; i<sharkList.size(); i++) {
        if (!sharkList[i].isQuit) {
            c ++;
        }
    }
    return c;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> k;

    init();

    int time = 0;
    int cnt = 0;
    while (time <= 1000) {
        // cout << "time : " << time << "\n";
        // printMap(record); // 현재 맵 상태 출력
        // cout << "\n";
        
        cnt = checkSharkCnt();
        if (cnt == 1) break;

        gameStart();
        time ++;
    }
    
    if (time > 1000 && cnt > 1) {
        cout << -1 << "\n";
    } else {
        cout << time << "\n";
    }
    return 0;
}
