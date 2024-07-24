#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// date1가 더 크면 1, 같으면 0, 작으면 -1
int compDate(pair<int, int> date1, pair<int, int> date2) {
    if (date1.first > date2.first) {
        return 1;
    } 
    else if (date1.first == date2.first) {
        if (date1.second > date2.second) {
            return 1;
        } else if (date1.second == date2.second) {
            return 0;
        } else {
            return -1;
        }
    }
    else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<pair<int, int>, pair<int, int>>> flowers(N);
    for (int i = 0; i < N; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flowers[i] = {{sm, sd}, {em, ed}};
    }

    sort(flowers.begin(), flowers.end());

    int count = 0;
    pair<int, int> current_end = {3, 1};
    pair<int, int> last_end = {3, 1};
    bool found = false;

    for (int i = 0; i < N; i++) {
        if (compDate(flowers[i].first, current_end) <= 0) {
            if (compDate(flowers[i].second, last_end) > 0) {
                last_end = flowers[i].second;
                found = true;
            }
        } else {
            if (found) {
                current_end = last_end;
                count++;
                if (compDate(current_end, {11, 30}) > 0) {
                    cout << count << "\n";
                    return 0;
                }
                i--;
                found = false;
            } else {
                cout << 0 << "\n";
                return 0;
            }
        }
    }

    if (found && compDate(last_end, {11, 30}) > 0) {
        count++;
        cout << count << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}