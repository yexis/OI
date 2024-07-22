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
#include <climits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));

    const int inf = 1e9 + 100;
    int mx = -inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            mx = max(mx, g[i][j]);
        }
    }
    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    };
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto check = [&](int dist) {
        if (g[0][0] > dist) {
            return false;
        }

        queue<pair<int, int>> q;
        int vis[n][n];
        q.emplace(0, 0);
        vis[0][0] = true;
        memset(vis, 0, sizeof(vis));
        while (q.size()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                if (!valid(nr, nc)) continue;
                if (vis[nr][nc]) continue;
                if (g[nr][nc] > dist) continue;
                if (nr == n - 1 && nc == n - 1) {
                    return true;
                }
                q.emplace(nr, nc);
                vis[nr][nc] = true;

            }
        }
        return false;
    };

    int ans = mx;
    int l = 1, r = mx;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";


    return 0;
}