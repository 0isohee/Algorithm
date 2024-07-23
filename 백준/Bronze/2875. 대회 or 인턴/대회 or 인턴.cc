#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int minTeam = min((int)(N/2), M);
    int remainPeople = N+M-K;
    cout << min(minTeam, (int)(remainPeople/3)) << "\n";
}