#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> temp;
    
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        
        if (s == "push") {
            int x;
            cin >> x;
            temp.push_back(x);
        } 
        else if (s == "pop") {  
            if (!temp.empty()) {
                cout << temp.back() << "\n";
                temp.pop_back();
            } else {
                cout << -1 << "\n";
            }
        } 
        else if (s == "size") {
            cout << temp.size() << "\n";
        } 
        else if (s == "empty") {
            if (!temp.empty()) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } 
        else if (s == "top") {
            if (!temp.empty()) {
                cout << temp.back() << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            
        }
    }
    return 0;
}