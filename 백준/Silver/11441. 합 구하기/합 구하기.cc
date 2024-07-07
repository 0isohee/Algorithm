#include<iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int numbers[n+1];

    numbers[0] = 0;
    for (int i=1; i<=n; i++){
        cin >> numbers[i];
    }
    for (int i=1; i<=n; i++){
        numbers[i] = numbers[i-1] + numbers[i];
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++){
        int s, e;
        cin >> s >> e;
        
        cout << numbers[e] - numbers[s-1] << "\n";
    }
    return 0;
}