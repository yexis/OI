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

// 方法一
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> g(n, vector<char>(m));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> g[i][j];
//        }
//    }
//
//    vector<int> cost(m);
//    for (int i = 0; i < m; i++) {
//        cin >> cost[i];
//    }
//
//    auto valid = [&](int r, int c) {
//        return r >= 0 && r < n && c >= 0 && c < m;
//    };
//
//    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//    priority_queue<tuple<int, int, int, array<int, 101> >, vector<tuple<int, int, int, array<int, 101> >>, greater<> > pq;
//    int dist[n][m][2];
//    memset(dist, 0x3f3f3f3f, sizeof(dist));
//    pq.emplace(0, 0, 0, array<int, 101>{});
//    dist[0][0][0] = 0;
//    while (pq.size()) {
//        auto [d, i, j, c] = pq.top();
//        pq.pop();
//        int ch = c[j];
//        if (dist[i][j][ch] < d) {
//            continue;
//        }
//        for (int k = 0; k < 4; k++) {
//            int ni = i + dir[k][0];
//            int nj = j + dir[k][1];
//            if (!valid(ni, nj)) continue;
//            if (g[ni][nj] == '.') {
//                int dd = 0;
//                if (d + dd < dist[ni][nj][c[nj]]) {
//                    dist[ni][nj][c[nj]] = d + dd;
//                    pq.emplace(dist[ni][nj][c[nj]], ni, nj, c);
//                }
//            } else if (g[ni][nj] == '#') {
//                int dd = 0, used = 0;
//                if (c[nj] == 0) {
//                    dd = cost[nj];
//                    used = 1;
//                }
//                if (d + dd < dist[ni][nj][1]) {
//                    if (used) c[nj] = 1;
//                    dist[ni][nj][1] = d + dd;
//                    pq.emplace(dist[ni][nj][1], ni, nj, c);
//                    if (used) c[nj] = 0;
//                }
//            }
//        }
//    }
//    cout << min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]) << "\n";
//    return 0;
//}


// 方法二：建图
//int to(int r, int c, int ch) {
//    return (r << 8) + (c << 1) + ch;
//}
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> g(n, vector<char>(m));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> g[i][j];
//        }
//    }
//    vector<int> cost(m);
//    for (int i = 0; i < m; i++) {
//        cin >> cost[i];
//    }
//
//    auto valid = [&](int r, int c) {
//        return r >= 0 && r < n && c >= 0 && c < m;
//    };
//
//    // 100 * 100 * 2
//    // 2 ^ 7 > 100
//    int dir[4][2] ={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//    vector<vector<pair<int, int>>> gg(1 << 15);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            for (int d = 0; d < 4; d++) {
//                int ni = i + dir[d][0];
//                int nj = j + dir[d][1];
//                if (!valid(ni, nj)) continue;
//                for (int ch1 = 0; ch1 < 2; ch1++) {
//                    for (int ch2 = 0; ch2 < 2; ch2++) {
//                        if (g[i][j] == '#' && ch1 == 0) continue;
//                        if (g[ni][nj] == '#' && ch2 == 0) continue;
//                        int x = to(i, j, ch1);
//                        int y = to(ni, nj, ch2);
//                        int dd = 0;
//                        if (ch2 == 1) {
//                            if (ch1 == 0 || j != nj) {
//                                dd = cost[nj];
//                            }
//                        }
//                        gg[x].push_back({y, dd});
//                    }
//                }
//            }
//        }
//    }
//
//    vector<int> dis(1 << 15, INT_MAX / 2);
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//    pq.emplace(0, 0);
//    dis[0] = 0;
//    while (pq.size()) {
//        auto [d, u] = pq.top();
//        pq.pop();
//        if (dis[u] < d) {
//            continue;
//        }
//        for (auto& [v, w] : gg[u]) {
//            if (d + w < dis[v]) {
//                dis[v] = d + w;
//                pq.emplace(dis[v], v);
//            }
//        }
//    }
//
//    cout << min(dis[to(n - 1, m - 1, 0)], dis[to(n - 1, m - 1, 1)]) << "\n";
//    return 0;
//}


// 方法三：加点、虚拟点
// 主要原理：对于每一列增加一个点，这个点c[j]到c[j]到j列的每个点距离都是0
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<int> cost(m);
    for (int i = 0; i < m; i++) {
        cin >> cost[i];
    }

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };


    vector<tuple<int, int, int>> path[n + 1][m];
    int dir[4][2] ={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                path[i][j].emplace_back(n, j, cost[j]);
            } else {
                path[i][j].emplace_back(n, j, 0);
            }
            path[n][j].emplace_back(i, j, 0);

            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                if (!valid(ni, nj)) continue;
                if (g[ni][nj] == '.') {
                    path[i][j].emplace_back(ni, nj, 0);
                } else {
                    path[i][j].emplace_back(n, nj, cost[nj]);
                }
            }
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    int dis[n + 1][m];
    memset(dis, 0x3f, sizeof(dis));
    pq.emplace(0, 0, 0);
    dis[0][0] = 0;
    while (pq.size()) {
        auto [d, i, j] = pq.top();
        pq.pop();
        if (dis[i][j] < d) {
            continue;
        }
        for (auto& [ni, nj, w] : path[i][j]) {
            if (d + w < dis[ni][nj]) {
                dis[ni][nj] = d + w;
                pq.emplace(dis[ni][nj], ni, nj);
            }
        }
    }
    cout << dis[n - 1][m - 1] << "\n";
    return 0;
}