#include<iostream>
#include<vector>

using namespace std;

//약수의 합 구하기
vector<long long> find_div_number(int maxV) {
    vector<long long> f(maxV+1, 0);

    for (int i=1; i<=maxV; i++){
        for (int j=i; j<=maxV; j+=i){
            f[j] += i;
        }
    }
    return f;
}

//
vector<long long> cal_div_number(const vector<long long>&f){
    int max_size = f.size() -1;
    vector<long long> g(max_size+1, 0);

    for (int i=1; i<=max_size; i++){
        g[i] = g[i-1] + f[i];
    }
    return g;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    vector<int> N(T);
    
    int maxv = -1;
    for (int i=0; i<T; i++){
        int temp;
        cin >> temp;
        if (temp > maxv) {
            maxv = temp;
        }
        N[i] = temp;
    }   

    //f => 약수끼리의 함
    vector<long long> f = find_div_number(maxv);
    //g => 각 약수끼리의 합의 합
    vector<long long> g = cal_div_number(f);

    for (int i=0; i<T; i++){
        cout << g[N[i]] << "\n";
    }   
    return 0;
}