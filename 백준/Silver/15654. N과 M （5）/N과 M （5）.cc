#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used, int M) {
    if (temp.size() == M) {
        for (int i = 0; i < M; ++i) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, temp, used, M);
            temp.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<int> temp;
    vector<bool> used(N, false);

    backtrack(nums, temp, used, M);

    return 0;
}
