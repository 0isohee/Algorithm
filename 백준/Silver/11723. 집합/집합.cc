#include <iostream>
#include <string>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    int s = 0;

    for (int i = 0; i < m; i++) {
        string mode;
        cin >> mode;

        if (mode == "add") {
            int x;
            cin >> x;
            s = s | (1 << (x - 1));
        } else if (mode == "remove") {
            int x;
            cin >> x;
            s = s & ~(1 << (x - 1));
        } else if (mode == "check") {
            int x;
            cin >> x;
            if (s & (1 << (x - 1))) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (mode == "toggle") {
            int x;
            cin >> x;
            s = s ^ (1 << (x - 1));
        } else if (mode == "all") {
            s = (1 << 20) - 1; // 1048575
        } else if (mode == "empty") {
            s = 0;
        }
    }
    return 0;
}
