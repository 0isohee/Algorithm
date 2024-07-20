#include<iostream>
#include<cmath>
using namespace std;

int main(){
    
    int T;
    cin >> T;
    for (int i=0; i<T; i++){
        int A, B;
        cin >> A >> B;
        cout << "Case #" << i+1 << ": " << A+B << "\n";
    }
    
    return 0;
}