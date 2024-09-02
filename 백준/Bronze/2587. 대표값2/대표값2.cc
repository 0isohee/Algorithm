#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
   vector<int> number(5,0);
    int sumv = 0;
    for (int i=0; i<5; i++) {
        cin >> number[i];
        sumv += number[i];
    }
    sort(number.begin(), number.end());
    
    cout << (sumv/5) << "\n";
    cout << number[2] << "\n";
    
    return 0;
}