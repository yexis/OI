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
    int n, m;
    cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int inf = 0x3f3f3f3f;
    auto bfs = [&](int r, int c, int lim) -> int {
        int dis[n][m][2];
        memset(dis, inf, sizeof(dis));
        queue<array<int, 3>> q;
        q.push({0, 0, 0});
        dis[0][0][0] = 0;

        while (q.size()) {
            auto [i, j, v] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                if (d == lim) continue;
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                if (!valid(ni, nj)) continue;
                if (g[ni][nj] == 'X') {
                    if (v == 0 && lim != -1) {
                        if (dis[ni][nj][1] < dis[i][j][v] + 1) {
                            continue;
                        }
                        dis[ni][nj][1] = dis[i][j][v] + 1;
                        q.push({ni, nj, 1,});
                    } else {

                    }
                } else {
                    if (dis[ni][nj][v] < dis[i][j][v] + 1) {
                        continue;
                    }
                    dis[ni][nj][v] = dis[i][j][v] + 1;
                    q.push({ni, nj, v});
                }
            }
        }
        return min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
    };

    int aa = bfs(0, 0, -1);
    int bb = bfs(0, 0, 0);
    int dd = bfs(0, 0, 2);
    int ans = min({aa, bb, dd});
    if (ans == inf) {
        cout << -1  << "\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}