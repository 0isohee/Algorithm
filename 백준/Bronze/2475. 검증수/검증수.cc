#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num[5];
    int sumv = 0;
    for (int i=0; i<5; i++){
        cin >> num[i]; 
        sumv += (num[i] * num[i]);
    }
    cout << sumv % 10;
    return 0;
}