#include <iostream>
using namespace std;

int main () {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int sum[n+1] = {};
    
    for (int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        sum[i] = sum[i-1] + temp;
    }
    
    for (int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        cout << sum[y] - sum[x-1] << "\n";
    }
}