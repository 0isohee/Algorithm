#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string extractSubstr (const string &word) { 
    string new_word;

    new_word = word.substr(4, word.length() - 8); 
    return new_word;
}

bool canRead(const string &word, int teach_word) {
    for (char c : word) {
        if (!(teach_word & (1 << (c - 'a')))) {
            return false;
        }
    }
    return true;
}

void dfs(int idx, int cnt, int K, int teach_word, const vector<string>& words, int& max_read) {
    if (cnt == K) {
        int read_count = 0;
        for (const string& word : words) {
            if (canRead(word, teach_word)) {
                ++read_count;
            }
        }
        max_read = max(max_read, read_count);
        return;
    }
    if (idx >= 26) return;

    if (!(teach_word & (1 << idx))) {
        dfs(idx + 1, cnt + 1, K, teach_word | (1 << idx), words, max_read);
    }
    dfs(idx + 1, cnt, K, teach_word, words, max_read);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<string> words(N);

    // 필수 글자 (a, c, i, n, t)를 미리 가르침
    int teach_word = 0;
    teach_word |= (1 << ('a'-'a'));
    teach_word |= (1 << ('c'-'a'));
    teach_word |= (1 << ('n'-'a'));
    teach_word |= (1 << ('t'-'a'));
    teach_word |= (1 << ('i'-'a'));
    K -= 5;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        words[i] = extractSubstr(word);
    }

    if (K < 0) {
        cout << 0 << "\n";
        return 0;
    }

    int max_read = 0;
    dfs(0, 0, K, teach_word, words, max_read);

    cout << max_read << "\n";
    return 0;
}
