#include<iostream>
#include<vector>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T;
    cin >> T;
    for (int test_case = 1; test_case<=T; test_case++){
        int N;
        cin >> N;

        vector<int> array(N,0);
        for (int i=0; i<N; i++){
            cin >> array[i];
        }

        int max_end = array[0];
        int max_far = array[0];
     
        for (int i=1; i<N; i++){
            max_end = max(array[i], max_end+array[i]);
            max_far = max(max_end, max_far);
        }
        cout << max_far << "\n";
    }
    return 0;
}