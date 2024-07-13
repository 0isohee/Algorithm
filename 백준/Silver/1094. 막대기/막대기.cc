#include<iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >> X;

    int cnt =0;

    for (int i=0; i<8; i++){
        if (X & (1 << i)) {
            cnt ++;
        }
    }
    cout << cnt << "\n";
    return 0;
}