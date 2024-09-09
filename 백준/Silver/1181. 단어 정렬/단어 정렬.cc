#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

bool compare(const string &a, const string &b) {
    if (a.length() == b.length()) {
        return a < b; 
    }
    return a.length() < b.length();
}

int main() {
    int n;
    cin >> n;
    set<string> unique_words; 

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        unique_words.insert(word); 
    }
    
    vector<string> words(unique_words.begin(), unique_words.end());
    sort(words.begin(), words.end(), compare); 

    for (const string &word : words) {
        cout << word << "\n";
    }

    return 0;
}
