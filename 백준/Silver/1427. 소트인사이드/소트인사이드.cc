#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int number;
    cin >> number;
    
    vector<int> nums;
    
    while (number > 0) {
        nums.push_back(number % 10);
        number /= 10;
    }
    
    sort(nums.rbegin(), nums.rend());
    
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    return 0;
}
