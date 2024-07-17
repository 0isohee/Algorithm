#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    
    int N = sequence.size();
    int start = 0, end = 0;
    long long current_sum = 0;
    int min_length = INT_MAX;
    
    vector<int> result(2);
    
    while (end < N){
        current_sum += sequence[end];
        
        while (current_sum >= k) {
            if (current_sum == k) {
                if (end - start < min_length) {
                    min_length = end - start;
                    result[0] = start;
                    result[1] = end;
                }
            }
            current_sum -= sequence[start];
            start ++;
        }
        end ++;
    }
    return result;
}