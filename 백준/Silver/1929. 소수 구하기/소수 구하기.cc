#include<iostream>
#include<cmath>

using namespace std;

bool isSosu(int num){
    if (num == 1) return false;
    for (int i=2; i<=(int)sqrt(num); i++){
        if (num % i == 0) return false;
    }
    return true;
}
int main(){
    int M, N;
    cin >> M >> N;
    
    for (int i=M; i<=N; i++){
        if (isSosu(i)) {
            cout << i << "\n";
        }
    }
    return 0;
}