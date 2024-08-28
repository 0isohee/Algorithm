#include<iostream>
#include<vector>
using namespace std;
int main() {
    
    int k;
    cin >> k;
    vector<int> temp;
    
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            temp.pop_back();
            continue;
        }
        temp.push_back(a);
    }
    int sum = 0;
    for (int i=0; i<temp.size(); i++) {
        sum += temp[i];
    }
    cout << sum << "\n";
    
    return 0;
}