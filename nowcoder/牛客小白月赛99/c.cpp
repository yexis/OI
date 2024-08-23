#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
#include <limits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int n, m;
    cin >> n >> m;
    char g[n][m];

    int si, sj, ei, ej;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                si = i, sj = j;
            }
            if (g[i][j] == 'E') {
                ei = i, ej = j;
            }
        }
    }


    auto check = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    auto bfs = [&](int ti, int tj, vector<int>& row, vector<int>& col) {
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.emplace(ti, tj);
        vis[ti][tj] = true;
        row[ti] = true;
        col[tj] = true;
        while (q.size()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                if (not check(nr, nc)) continue;
                if (vis[nr][nc]) continue;
                if (g[nr][nc] == '#') continue;
                vis[nr][nc] = true;
                row[nr] = true;
                col[nc] = true;
                q.emplace(nr, nc);
            }
        }
    };

    vector<int> row_s(n), col_s(m);
    vector<int> row_e(n), col_e(m);
    bfs(si, sj, row_s, col_s);
    bfs(ei, ej, row_e, col_e);

    for (int i = 0; i < n; i++) {
        if (row_s[i]) {
            if (i - 1 >= 0 && row_e[i - 1]) {
                cout << "YES" << "\n";
                return 0;
            }
            if (row_e[i]) {
                cout << "YES" << "\n";
                return 0;
            }
            if (i + 1 < n && row_e[i + 1]) {
                cout << "YES" << "\n";
                return 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (col_s[j]) {
            if (j - 1 >= 0 && col_e[j - 1]) {
                cout << "YES" << "\n";
                return 0;
            }
            if (col_e[j]) {
                cout << "YES" << "\n";
                return 0;
            }
            if (j + 1 < m && col_e[j + 1]) {
                cout << "YES" << "\n";
                return 0;
            }
        }
    }

    cout << "NO" << "\n";
    return 0;
}