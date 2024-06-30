#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

// 세그먼트 트리 초기화
void init(vector<int> &heights, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
    } else {
        int mid = (start + end) / 2;
        init(heights, tree, node*2, start, mid);
        init(heights, tree, node*2 + 1, mid + 1, end);
        tree[node] = (heights[tree[node*2]] < heights[tree[node*2 + 1]]) ? tree[node*2] : tree[node*2 + 1];
    }
}

// 범위에서 최솟값의 인덱스를 찾는 함수
int query(vector<int> &heights, vector<int> &tree, int node, int start, int end, int L, int R) {
    if (R < start || L > end) return -1;
    if (L <= start && end <= R) return tree[node];
    int mid = (start + end) / 2;
    int leftMin = query(heights, tree, node*2, start, mid, L, R);
    int rightMin = query(heights, tree, node*2 + 1, mid + 1, end, L, R);
    if (leftMin == -1) return rightMin;
    if (rightMin == -1) return leftMin;
    return (heights[leftMin] < heights[rightMin]) ? leftMin : rightMin;
}

// 가장 큰 직사각형 넓이를 찾는 함수
long long largestRectangle(vector<int>& heights, vector<int>& tree, int start, int end) {
    if (start > end) return 0;
    int minIndex = query(heights, tree, 1, 0, heights.size() - 1, start, end);
    long long area = (long long)heights[minIndex] * (end - start + 1);
    long long leftArea = largestRectangle(heights, tree, start, minIndex - 1);
    long long rightArea = largestRectangle(heights, tree, minIndex + 1, end);
    return max(area, max(leftArea, rightArea));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        int tree_size = 1 << ((int)ceil(log2(n)) + 1);
        vector<int> tree(tree_size);
        init(heights, tree, 1, 0, n - 1);

        cout << largestRectangle(heights, tree, 0, n - 1) << '\n';
    }

    return 0;
}