#include<iostream>
using namespace std;
int main(){
    
    long long X;
    cin >> X;
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        X -= (a * b);
    }
    if (X == 0) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}