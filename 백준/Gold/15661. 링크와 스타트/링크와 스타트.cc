#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> map(N+1, vector<int> (N+1,0));

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    int minv = INT16_MAX;
    //step 1. bitmaking을 이용한 부분집합 생성.
    for (int i=0; i<(1<<N); i++){
        vector<int> start, link;
        for (int b = 0; b < N; b++) {
            if (i & (1 << b)) {
                start.push_back(b + 1);
            } else {
                link.push_back(b + 1);
            }
        }
        if (start.size() <= 1 || link.size() <= 1) continue;

        // vector start와 link에서 각각 2명씩 뽑아서 순열 생성
        vector<int> start_combinations;
        vector<int> link_combinations;

        for (int j = 0; j < start.size(); j++) {
            for (int k = j + 1; k < start.size(); k++) {
                start_combinations.push_back(start[j]);
                start_combinations.push_back(start[k]);
            }
        }

        for (int j = 0; j < link.size(); j++) {
            for (int k = j + 1; k < link.size(); k++) {
                link_combinations.push_back(link[j]);
                link_combinations.push_back(link[k]);
            }
        }

        int Sx, Sy = 0;
        int Lx, Ly = 0;

        int startSum = 0;
        for (int j = 0; j < start_combinations.size(); j += 2) {
            Sx = start_combinations[j];
            Sy = start_combinations[j + 1];
            startSum += map[Sx][Sy];
            startSum += map[Sy][Sx];
        }

        int linkSum = 0;
        for (int j = 0; j < link_combinations.size(); j += 2) {
            Lx = link_combinations[j];
            Ly = link_combinations[j + 1];
            linkSum += map[Lx][Ly];
            linkSum += map[Ly][Lx];
        }

        minv = min(minv, abs(startSum - linkSum));
    }
    cout << minv << "\n";
    return 0;
}