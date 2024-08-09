#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};


// 블록 크기와 좌표를 맞춰주는 함수
vector<pair<int,int>> normalize(vector<pair<int,int>> cells) {
    int minX = cells[0].first;
    int minY = cells[0].second;
    for(auto cell: cells) {
        minX = min(minX, cell.first);
        minY = min(minY, cell.second);
    }
    for(auto& cell: cells) {
        cell.first -= minX;
        cell.second -= minY;
    }
    sort(cells.begin(), cells.end()); // 좌표를 정렬하여 비교를 쉽게 만듭니다.
    return cells;
}

// 블록의 좌표들을 90도 회전시키는 함수
vector<pair<int,int>> rotate(const vector<pair<int,int>>& blockShape) {
    vector<pair<int,int>> rotated;
    for (const auto& cell : blockShape) {
        rotated.push_back({cell.second, -cell.first});
    }
    return normalize(rotated);
}

// 주어진 보드에서 특정 블록의 모양을 추출하는 함수
vector<pair<int,int>> extractShape(vector<vector<int>>& table, int x, int y, int mode) {
    int n = table.size();
    int m = table[0].size();
    vector<pair<int,int>> shape;
    queue<pair<int,int>> q;
    
    q.push({x,y});
    table[x][y] = -1;
    shape.push_back({x, y});
    
    while (!q.empty()) {
        pair<int,int> now = q.front();
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || table[nx][ny] != mode) continue;
            q.push({nx, ny});
            table[nx][ny] = -1;
            shape.push_back({nx, ny});
        }
    }
    
    return normalize(shape);
}

// 블록 회전을 포함하여 퍼즐 조각을 보드에 맞출 수 있는지 확인하는 함수
bool canFit(const vector<pair<int,int>>& blockShape, const vector<pair<int,int>>& blankShape) {
    if (blockShape.size() != blankShape.size()) return false;
    vector<pair<int,int>> rotatedBlock = blockShape;
    for (int rotation = 0; rotation < 4; ++rotation) {
        if (rotatedBlock == blankShape) return true;
        rotatedBlock = rotate(rotatedBlock);
    }
    return false;
}

// 블록과 빈 칸을 매칭하여 최대 채울 수 있는 칸을 계산하는 함수
int findBlock(vector<vector<pair<int,int>>>& blocks, vector<vector<pair<int,int>>>& blanks) {
    int score = 0;
    vector<bool> usedBlank(blanks.size(), false);
    
    for (int i = 0; i < blocks.size(); i++) {
        for (int j = 0; j < blanks.size(); j++) {
            if (!usedBlank[j] && canFit(blocks[i], blanks[j])) {
                score += blocks[i].size();
                usedBlank[j] = true;
                break;
            }
        }
    }
    return score;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    int n = table.size();
    
    vector<vector<pair<int,int>>> blocks;
    vector<vector<pair<int,int>>> blanks;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1) {
                blocks.push_back(extractShape(table, i, j, 1));
            }
            if (game_board[i][j] == 0) {
                blanks.push_back(extractShape(game_board, i, j, 0));
            }
        }
    }
    
    int answer = findBlock(blocks, blanks);
    return answer;
}
