#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<utility>
#include<algorithm>

using namespace std;

struct comp {
    bool operator()(const tuple<int,int,int> &a,const tuple<int,int,int> &b) {
        if (get<0>(a) == get<0>(b)) {
            if (get<1>(a) == get<1>(b)) {
                return get<2>(a) < get<2>(b);
            }
            return get<1>(a) < get<1>(b);
        }
        return get<0>(a) < get<0>(b);
    }
};

int dx [] = {-1,1,0,0};
int dy [] = {0,0,-1,1};
int N;
int t;
int Sx, Sy;
int sharkSize = 2;
int current = 0;
vector<vector<int>> map;

bool BFS() {

    vector<vector<int>> visited(N, vector<int>(N,0));
    vector<tuple<int,int,int>> fishList;
    queue<pair<int,int>> q;

    visited[Sx][Sy] = 1;
    q.push({Sx,Sy});

    if (current == sharkSize) {
        sharkSize ++;
        current = 0;
    }

    while (!q.empty()) {

        pair<int,int> now = q.front();
        q.pop();
        
        for (int d=0; d<4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] > 0) continue;
            if (map[nx][ny] > sharkSize) continue;
            visited[nx][ny] = visited[now.first][now.second] + 1;
            if (map[nx][ny] < sharkSize && map[nx][ny] > 0) {
                fishList.push_back({visited[nx][ny], nx,ny});
            }
            q.push({nx,ny});
        }
    }

    if (fishList.empty()) {
        return false;
    }

    sort(fishList.begin(), fishList.end(), comp());
    // cout << "dis : " << get<0>(fishList[0]) << "\n";
    int goalx = get<1>(fishList[0]);
    int goaly = get<2>(fishList[0]);

    map[Sx][Sy] = 0;
    map[goalx][goaly] = 9;
    t += (get<0>(fishList[0]) -1);
    current ++;

    Sx = goalx;
    Sy = goaly;
    return true;
}

// void printMap() {

//     cout << "eat :  " << current << " sharkSize : " << sharkSize << "\n";
//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             cout << map[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }
int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    map.resize(N, vector<int>(N,0));


    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9){
                Sx = i;
                Sy = j;
            }
        }
    }
    
    t = 0;
    while (true) {
        if (!BFS()) break;
        // printMap();
        // cout << "\n";
    }
    cout << t << "\n";
    return 0;
}