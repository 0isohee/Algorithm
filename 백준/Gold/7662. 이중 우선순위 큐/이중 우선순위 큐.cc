#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {
        priority_queue<long long> maxHeap;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        unordered_map<long long, int> counter;
        int k;
        cin >> k;
        for (int i=0; i<k; i++){
            char c;
            cin >> c;

            if (c == 'I'){
                long long n;
                cin >> n;
                maxHeap.push(n);
                minHeap.push(n);
                counter[n]++;
            }
            else if (c == 'D'){
                int mode;
                cin >> mode;

                if (mode == 1 && !maxHeap.empty()){
                    while (!maxHeap.empty() && counter[maxHeap.top()] == 0) {
                        maxHeap.pop();
                    }
                    if (!maxHeap.empty()) {
                        long long maxVal = maxHeap.top();
                        maxHeap.pop();
                        counter[maxVal]--;
                    }
                } else if (mode == -1 && !minHeap.empty()){
                    while (!minHeap.empty() && counter[minHeap.top()] == 0) {
                        minHeap.pop();
                    }
                    if (!minHeap.empty()) {
                        long long minVal = minHeap.top();
                        minHeap.pop();
                        counter[minVal]--;
                    }
                }
            }
        }

        while (!minHeap.empty() && counter[minHeap.top()] == 0) {
            minHeap.pop();
        }
        while (!maxHeap.empty() && counter[maxHeap.top()] == 0) {
            maxHeap.pop();
        }

        if (minHeap.empty() && maxHeap.empty()) {
            cout << "EMPTY" << "\n";
        } else {
            cout << maxHeap.top() << " " << minHeap.top() << "\n";
        }
    }
    return 0;
}
