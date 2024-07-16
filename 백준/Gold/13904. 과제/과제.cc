#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<pair<int, int>> homework(N);

    for (int i=0; i<N; i++){
        int d,w;
        cin >> d >> w;
        homework[i] = {d, w};
    }

    //역 정렬
    sort(homework.rbegin(), homework.rend());

    //최대 힙
    priority_queue<int, vector<int>> pq;

    int current_day = homework[0].first;
    int j = 0;
    int score = 0;

    for (int i=current_day; i>=1; i--){

        while (j < N && homework[j].first >= i){
            pq.push(homework[j].second);
            j++;
        }

        if (!pq.empty()) {
            score += pq.top();
            pq.pop();
        }
    }
    cout << score << "\n";
    return 0;
}