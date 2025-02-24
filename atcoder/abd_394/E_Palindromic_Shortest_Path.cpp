#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <iomanip>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    vector<vector<char>> g2(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g2[i][j] = g[j][i];
        }
    }
    
    vector<vector<int>> res(n, vector<int>(n, INF));
    int xx = -1, yy = -1;

    vector<vector<vector<int> > > v1(n, vector<vector<int>>(26));
    vector<vector<vector<int> > > v2(n, vector<vector<int>>(26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '-') continue;
            v1[i][g[i][j] - 'a'].push_back(j);
        }
        for (int j = 0; j < n; j++) {
            if (g2[i][j] == '-') continue;
            v2[i][g2[i][j] - 'a'].push_back(j);
        }
    }
    

    // 递归深度优先搜索函数
    auto dfs = [&](auto&& dfs, int x, int y, int len) {
        if (g[x][y] != '-') {
            res[xx][yy] = min(res[xx][yy], len + 1);
            return;
        }
        if (x == y) {
            res[xx][yy] = min(res[xx][yy], len);
            return;
        }
        if (len >= res[xx][yy]) {
            return;
        }

        auto& vv1 = v1[x];
        auto& vv2 = v2[y];
        for (int d = 0; d < 26; d++) {
            if (vv1[d].empty() || vv2[d].empty()) {
                continue;
            }
            for (int i = 0; i < vv1[d].size(); i++) {
                for (int j = 0; j < vv2[d].size(); j++) {
                    if (vv1[d][i] == x && vv2[d][j] == y) continue;
                    dfs(dfs, vv1[d][i], vv2[d][j], len + 2); 
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                res[i][j] = 0;
                continue;
            }
            xx = i, yy = j;
            dfs(dfs, i, j, 0);
            if (res[i][j] == INF) {
                res[i][j] = -1;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}
