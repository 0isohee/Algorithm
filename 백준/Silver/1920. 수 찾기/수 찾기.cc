#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    map<long long, int> number;
    for (int i=0; i<N; i++){
        long long temp;
        cin >> temp;
        number[temp] =  i+1;
    }

    int M;
    cin >> M;
    for (int i=0; i<M; i++){
        long long check;
        cin >> check;
        if (number[check]){
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}