#include<iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double a,b;
    cin >> a >> b;
    cout.precision(10);
    double c = a/b;
    cout << c;
    return 0;
}