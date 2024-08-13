#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;

struct Chicken {
    int x, y; 
};

int N, M;
int minV = INT_MAX;
int dx [] = {-1,0,1,0};
int dy [] = {0,-1,0,1};
vector<vector<int>> map;
vector<Chicken> chickenList;
vector<pair<int,int>> homeList;
vector<int> checkList;


int getDis(vector<int> checkList) {

    int ans = 0;
    for (int i=0; i<homeList.size(); i++) {
        int hx = homeList[i].first;
        int hy = homeList[i].second;
        int minv = INT_MAX;
        
        for (int j = 0; j < checkList.size(); j++) {
            int cx = chickenList[checkList[j]].x;
            int cy = chickenList[checkList[j]].y;
            minv = min(minv, abs(cx - hx) + abs(hy - cy));
        }
       ans += minv;
    }
    return ans;
}

void DFS(int now, int L) {
    if (L == M) {
        minV = min(minV, getDis(checkList));
        return;
    }
    for (int i=now; i<chickenList.size(); i++) {
        checkList[L] = i;
        DFS(i+1, L+1);
    }
}

int main() {

    cin >> N >> M;
    map.resize(N, vector<int>(N,0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
    int number = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == 2) {
                Chicken c;
                c.x = i;
                c.y = j;
                chickenList.push_back(c);
            } 
            else if (map[i][j] == 1) {
                homeList.push_back({i,j});
            }
        }
    }

    checkList.resize(M,0);
    DFS(0,0);
    cout << minV << "\n";
    return 0;
}