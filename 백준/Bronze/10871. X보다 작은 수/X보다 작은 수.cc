#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    vector<int> number(N,0);
    for (int i=0; i<N; i++){
        cin >> number[i];
        if (number[i] < X){
            cout << number[i] << " ";
        }
    }
    return 0;
}