#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool isPrefix(string& a, string& b) {
    if (b.substr(0, a.size()) == a) return true;
    return false;
}

int main(){
    int T;
    cin >> T;

    for (int tc=0; tc<T; tc++){
        int n;
        cin >> n;
        vector<string> telephones(n);
        for (int i=0; i<n; i++){
            cin >> telephones[i];
        }
        sort(telephones.begin(), telephones.end());

        bool check = false;
        for (int i=0; i<n-1; i++){
            if (isPrefix(telephones[i], telephones[i+1])) {
                check = true;
                break;
            }
        }

        if (check) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
