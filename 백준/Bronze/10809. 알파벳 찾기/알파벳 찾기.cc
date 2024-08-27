#include<iostream>
#include<string>
using namespace std;
int main() {
    
    string s;
    cin >> s;
    
    for (int i=97; i<123; i++) {
        bool c = false;
        for (int j=0; j<s.length(); j++) {
            if (s.at(j) - i == 0) {
                c = true;
                cout << j << " ";
                break;
            }
        }
        if (!c) {
            cout << -1 << " ";
        }
    }
    return 0;
}