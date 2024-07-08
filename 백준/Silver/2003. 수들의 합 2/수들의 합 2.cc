#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> number(n+1, 0);

	cin >> number[1];
	for (int i = 2; i <= n; i++){
		int temp;
		cin >> temp;
		number[i] = number[i - 1] + temp;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (number[j] - number[i - 1] == m) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}