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

    int N;
    cin >> N;
    vector<pair<long, long>> meeting(N);
    for (int i=0; i<N; i++){
        long s, e;
        cin >> s >> e;
        meeting[i] = {e,s};
    }
    sort(meeting.begin(), meeting.end());

    long end_time = meeting[0].first;
    long start_time = meeting[0].second;

    int cnt = 1;

    for (int i=1; i<N; i++){
        if (meeting[i].second >= end_time){
            end_time = meeting[i].first;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}