#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> number(11, 0);
	vector<int> sum(11, 0);
	for (int i = 1; i <= 10; i++) {
		cin >> number[i];
	}
	sum[1] = number[1];
	for (int i = 2; i < 11; i++) {
		sum[i] = sum[i - 1] + number[i];
	}

	int min_diff = 100000;
	int ans = 0;
	for (int i = 1; i < 11; i++) {
		int diff = abs(100 - sum[i]);
		if (diff < min_diff) {
			min_diff = diff;
			ans = sum[i];
		}
		else if (diff == min_diff) {
			if (sum[i] > ans) {
				ans = sum[i];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}