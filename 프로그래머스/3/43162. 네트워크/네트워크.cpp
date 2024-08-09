#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<bool> visited;

void DFS(int node, int n, vector<vector<int>> &computers) {
    visited[node] = true;
    
    for (int i = 0; i < n; i++) {
        if (computers[node][i] == 1 && !visited[i]) {
            DFS(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    visited.resize(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            DFS(i, n, computers);
        }
    }
    return answer;
}
