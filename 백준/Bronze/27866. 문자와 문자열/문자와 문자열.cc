#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int idx;
    cin >> idx;
    cout << s.at(idx-1) << "\n";
    return 0;
}