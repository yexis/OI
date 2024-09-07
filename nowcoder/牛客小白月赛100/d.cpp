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
const int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    auto get = [&](int r, int c) -> pii {
        return {2 * x - r, 2 * y - c};
    };
    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    int dp[n][m][2][2];
    memset(dp, 0, sizeof(dp));

    queue<array<int, 5>> q;
    q.push({x, y, 0, 0, 0});
    dp[x][y][0][0] = 1;

    while (q.size()) {
        auto [r, c, left1, left2, step] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int t1 = left1, t2 = left2;

            int nr = r + dir[d][0], nc = c + dir[d][1];
            if (!t1 && !valid(nr, nc)) continue;
            auto [rnr, rnc] = get(nr, nc);
            if (!t2 && !valid(rnr, rnc)) continue;
            if (!t1 && g[nr][nc] == '#') continue;
            if (!t2 && g[rnr][rnc] == '#') continue;

            if (!t1 && g[nr][nc] == '@') {
                t1 = true;
            }
            if (!t2 && g[rnr][rnc] == '@') {
                t2 = true;
            }
            if (t1 && t2) {
                cout << step + 1 << "\n";
                return 0;
            }

            if (dp[nr][nc][t1][t2]) continue;
            dp[nr][nc][t1][t2] = true;
            q.push({nr, nc, t1, t2, step + 1});
        }
    }
    cout << "-1" << "\n";
    return 0;
}