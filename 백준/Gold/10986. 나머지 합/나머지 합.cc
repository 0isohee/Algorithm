#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<long> sum(n,0);
    vector<long> remainer(m,0);
    long answer = 0;
    cin >> sum[0];
    
    for (int i=1; i<n; i++){
        int temp;
        cin >> temp;
        sum[i] = sum[i-1] + temp;
    }
    
    for (int i=0; i<n; i++){
        int r = sum[i] % m;
        if (r == 0){
            answer += 1;
        }
        remainer[r]++;
    }
    
    for (int i=0; i<m; i++){
        if (remainer[i] > 1){
            answer += (remainer[i] * (remainer[i]-1) / 2);
        }
    }
    cout << answer << "\n";
}