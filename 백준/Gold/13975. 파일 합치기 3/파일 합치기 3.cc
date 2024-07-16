#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        priority_queue<long long, vector<long long>, greater<long long> > pq; // 최소 힙 선언
        for (int i = 0; i < K; i++) {
            int file_size;
            cin >> file_size;
            pq.push(file_size); // 파일 크기를 최소 힙에 삽입
        }

        long long total_cost = 0; // 총 비용

        while (pq.size() > 1) {
            long long first = pq.top(); pq.pop(); // 가장 작은 파일 크기
            long long second = pq.top(); pq.pop(); // 두 번째로 작은 파일 크기
            long long merged_file = first + second; // 두 파일을 합침
            total_cost += merged_file; // 합치는 비용을 총 비용에 더함
            pq.push(merged_file); // 합친 파일을 다시 힙에 삽입
        }

        cout << total_cost << "\n"; // 총 비용 출력
    }
    return 0;
}