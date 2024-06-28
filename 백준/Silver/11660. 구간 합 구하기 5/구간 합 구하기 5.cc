#include <iostream>
using namespace std;

int main() {
    
    ios::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    
    
    int n, m;
    cin >> n >> m;
    int** map = new int*[n+1];
    int** sum = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        map[i] = new int[n+1]();
        sum[i] = new int[n+1]();
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + map[i][j];
        }
    }
    
    //구간합 질의 시작
    for (int i = 0; i < m; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        cout << sum[ex][ey] - sum[sx-1][ey] - sum[ex][sy-1] + sum[sx-1][sy-1] << '\n';
    }
    
    // 동적 할당 해제
    for (int i = 0; i <= n; i++) {
        delete[] map[i];
        delete[] sum[i];
    }
    delete[] map;
    delete[] sum;
    
    return 0;
}
