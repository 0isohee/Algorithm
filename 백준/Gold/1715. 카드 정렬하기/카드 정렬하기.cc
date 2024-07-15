#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;

    for (int i=0; i<N; i++){
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int sumv = 0;
    int cnt = 0;
    int ans = 0;
    while (!pq.empty()){

        cnt++;
        sumv += pq.top();
        pq.pop();

        if (cnt == 2) {
            ans += sumv;
            pq.push(sumv);
            sumv = 0;
            cnt = 0;
        }
    }

    // for (int i=0; i<N; i++){
    // }
    cout << ans << "\n";
    return 0;
}