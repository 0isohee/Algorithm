#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> numbers(n,0);

    for (int i=0; i<n; i++){
        cin >> numbers[i];    
    }
    sort(numbers.begin(), numbers.end());

    int s = 0;
    int e = n-1;
    long long minv = LONG_MAX;
    int idx_s = 0;
    int idx_e = 0;
    while (s < e){
        if (numbers[s] + numbers[e] > 0) {
            if (abs(numbers[s] + numbers[e]) < minv) {
                minv = abs(numbers[s] + numbers[e]);
                idx_s = s;
                idx_e = e;
            }
            e -= 1;
        } else if (numbers[s] + numbers[e] < 0) {
            if (abs(numbers[s] + numbers[e]) < minv) {
                minv = abs(numbers[s] + numbers[e]);
                idx_s = s;
                idx_e = e;
            }
            s += 1;
        } else {
            idx_s = s;
            idx_e = e;
            break;
        }
        
    }
    cout << numbers[idx_s] << " " << numbers[idx_e] << "\n";
    return 0;
}