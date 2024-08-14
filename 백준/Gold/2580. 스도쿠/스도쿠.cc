#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> map;

pair<int, int> findPair(int x, int y) {
    return {x / 3 * 3, y / 3 * 3};
}

vector<int> getList(int x, int y) {
    vector<bool> visited(10, false);

    // 가로, 세로 확인
    for (int i = 0; i < 9; i++) {
        if (map[x][i] != 0) visited[map[x][i]] = true;
        if (map[i][y] != 0) visited[map[i][y]] = true;
    }

    // 3x3 블록 확인
    pair<int, int> startPos = findPair(x, y);
    for (int i = startPos.first; i < startPos.first + 3; i++) {
        for (int j = startPos.second; j < startPos.second + 3; j++) {
            if (map[i][j] != 0) visited[map[i][j]] = true;
        }
    }

    vector<int> temp;
    for (int i = 1; i < 10; i++) {
        if (!visited[i]) {
            temp.push_back(i);
        }
    }

    return temp;
}

bool DFS() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (map[i][j] == 0) {
                vector<int> numList = getList(i, j);
                for (int n : numList) {
                    map[i][j] = n;
                    if (DFS()) return true;
                    map[i][j] = 0;  // 백트래킹
                }
                return false;  // 가능한 숫자가 없으면 잘못된 경로
            }
        }
    }
    return true; // 모든 칸을 채웠다면 성공
}

void printMap() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    map.resize(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
        }
    }

    DFS();
    printMap();

    return 0;
}
