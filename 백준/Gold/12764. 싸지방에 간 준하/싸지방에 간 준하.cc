#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> People(N);
    for (int i = 0; i < N; i++) {
        int P, Q;
        cin >> P >> Q;
        People[i] = {P, Q};
    }

    // 시작 시간을 기준으로 정렬
    sort(People.begin(), People.end());

    // 종료 시간, 자리 번호를 저장하는 최소 힙
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 사용 가능한 자리 번호를 저장하는 set
    set<int> available_seats;
    vector<int> computer_usage;

    for (int i = 0; i < N; i++) {
        int start = People[i].first;
        int end = People[i].second;

        // 종료 시간이 지난 자리를 해제하고 available_seats에 추가
        while (!pq.empty() && pq.top().first <= start) {
            available_seats.insert(pq.top().second);
            pq.pop();
        }

        int seat;
        if (!available_seats.empty()) {
            seat = *available_seats.begin();
            available_seats.erase(available_seats.begin());
        } else {
            seat = computer_usage.size();
            computer_usage.push_back(0);
        }
        pq.push({end, seat});
        computer_usage[seat]++;
    }

    cout << computer_usage.size() << "\n";
    for (int i = 0; i < computer_usage.size(); i++) {
        cout << computer_usage[i] << " ";
    }
    cout << "\n";

    return 0;
}