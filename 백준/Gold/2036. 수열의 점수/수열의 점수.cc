#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<ll> pos, neg;
    int n, num;
    int one_n, zero_n;
    ll sum;
    one_n = zero_n = sum = 0;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        
        if(num == 0) zero_n++;
        else if(num == 1) one_n++;
        else if(num < 0) neg.push_back(num);
        else pos.push_back(num);
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end(), greater<int>());
    int pos_size = pos.size();
    int neg_size = neg.size();

    for(int i=0; i<neg_size - 1; i+=2)
    {
        sum += neg[i] * neg[i+1];
    }
    if(neg.size() % 2 == 1 && !zero_n) sum += neg.back();

    for(int i=0; i<pos_size - 1; i+=2)
    {
        sum += pos[i] * pos[i+1];
    }
    if(pos.size() % 2 == 1) sum += pos.back();
    sum += one_n;

    cout<<sum;
    return 0;
}