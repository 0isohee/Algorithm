#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<vector<string>> ticketList;
vector<bool> visited;

bool DFS(int L, string s) {
    
    answer.push_back(s);
    
    if (ticketList.size() == L) {
        return true;
    }
    
    for (int i=0; i<ticketList.size(); i++) {
        if (ticketList[i][0] == s && !visited[i]) {
            visited[i] = true;
            if (DFS(L+1, ticketList[i][1])) {
                return true;
            }
            visited[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    ticketList = tickets;
    
    visited.resize(tickets.size(), false);
    
    DFS(0, "ICN");
    return answer;
}