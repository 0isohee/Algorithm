#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> bookPos;
    vector<int> bookNeg;
    
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp > 0) {
            bookPos.push_back(temp);
        } else {
            bookNeg.push_back(temp);
        }
    }
    
    if (!bookPos.empty()) {
        sort(bookPos.rbegin(), bookPos.rend());
    }
    if (!bookNeg.empty()) {
        sort(bookNeg.begin(), bookNeg.end());
    }

    int sumv = 0;

    if (N >= M) {
        if (!bookNeg.empty() && !bookPos.empty()) {
            if (abs(bookNeg[0]) > bookPos[0]) {
                sumv += abs(bookNeg[0]);
                for (int i = M; i < bookNeg.size(); i += M) {
                    sumv += (abs(bookNeg[i]) * 2);
                }
                for (int i = 0; i < bookPos.size(); i += M) {
                    sumv += (bookPos[i] * 2);
                }
            } else {
                sumv += abs(bookPos[0]);
                for (int i = 0; i < bookNeg.size(); i += M) {
                    sumv += (abs(bookNeg[i]) * 2);
                }
                for (int i = M; i < bookPos.size(); i += M) {
                    sumv += (bookPos[i] * 2);
                }
            }
        } else if (!bookNeg.empty()) {
            sumv += abs(bookNeg[0]);
            for (int i = M; i < bookNeg.size(); i += M) {
                sumv += (abs(bookNeg[i]) * 2);
            }
        } else if (!bookPos.empty()) {
            sumv += abs(bookPos[0]);
            for (int i = M; i < bookPos.size(); i += M) {
                sumv += (bookPos[i] * 2);
            }
        }
    } else {
        if (!bookPos.empty() && bookNeg.empty()) {
            sumv += bookPos[0];
        } else if (bookPos.empty() && !bookNeg.empty()) {
            sumv += abs(bookNeg[bookNeg.size() - 1]);
        } else if (!bookPos.empty() && !bookNeg.empty()) {
            sumv += max(bookPos[0], abs(bookNeg[bookNeg.size() - 1]));
        }
    }

    cout << sumv << "\n";
    return 0;
}
