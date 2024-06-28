#include <iostream>
using namespace std;

int main (){
    int N;
    cin >> N;
    
    int start_idx = 1;
    int end_idx = 1;
    int cnt = 1;
    int sum = 1;
    
    while (end_idx != N) {
        if (sum < N) {
            end_idx++;
            sum += end_idx;
        } else if (sum > N){
            sum -= start_idx;
            start_idx ++;
        } else {
            cnt ++;
            end_idx ++;
            sum += end_idx;
        }
    }
    cout << cnt << '\n';
}