#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<pair<int, int>> q;
vector<vector<int>> visited;
int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};
int n, m;

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    visited.resize(n, vector<int>(m,false));
    
    q.push({0,0});
    visited[0][0] = 1;
    
    while (!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        
        for (int d=0; d<4; d++){
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] > 0) continue;
            if (maps[nx][ny] == 1) {
                visited[nx][ny] = visited[now.first][now.second] + 1;
                q.push({nx,ny});
            }
        }
    }
    
    return visited[n-1][m-1] == 0 ? -1 : visited[n-1][m-1];
}