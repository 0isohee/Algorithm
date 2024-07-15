#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i=0; i<N; i++){
        int temp;
        cin >> temp;

        if (maxHeap.empty() || temp <= maxHeap.top()){
            maxHeap.push(temp);
        } else {
            minHeap.push(temp);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        if (i % 2 == 0) {
            cout << maxHeap.top() << "\n";
        }
        else {
            cout << min(maxHeap.top(), minHeap.top()) << "\n";
        }
        
    }
    return 0;
}