#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int ans = -1;
int n, m;
int map[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s.at(j) - '0';
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int dx = -n; dx < n; dx++) {
                for (int dy = -m; dy < m; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x, ny = y, num = 0;
                    while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        num = num * 10 + map[nx][ny];
                        nx += dx;
                        ny += dy;

                        int sqrtN = (int)sqrt((double)num);
                        if (sqrtN * sqrtN == num) {
                            ans = max(ans, num);
                        }
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}
