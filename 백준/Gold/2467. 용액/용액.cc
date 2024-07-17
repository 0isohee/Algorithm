#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<climits>
using namespace std;

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<long long> materials(N);
    for (int i=0; i<N; i++){
        cin >> materials[i];
    }
    sort(materials.begin(), materials.end());

    int start_idx = 0;
    int end_idx = N-1;
    
    long long min_diff =  LONG_MAX;
    vector<long long> ans(2,0);

    while (end_idx > 0){

        if (start_idx == end_idx) break;
        if (abs(materials[start_idx] + materials[end_idx]) < min_diff) {
            min_diff = abs(materials[start_idx] + materials[end_idx]);
            ans[0] = materials[start_idx];
            ans[1] = materials[end_idx];
        }
        if (materials[start_idx] + materials[end_idx] > 0) {
            end_idx --;
        }
        else if (materials[start_idx] + materials[end_idx] < 0) {
            start_idx ++;
        }
        else {
            ans[0] = materials[start_idx];
            ans[1] = materials[end_idx];
            break;
        }
    }
    cout << ans[0]<< " " << ans[1] << "\n";
    return 0;
}