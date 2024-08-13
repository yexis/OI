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
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    int g[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    vector<int> nei[n * n];
    for (int i = 0; i < n; i++) {
        int left = -1;
        for (int j = 0; j <= n; j++) {
            if (j == n || g[i][j]) {
                if (left + 1 < j - 1) {
                    int ao = i * n + left + 1;
                    int bo = i * n + j - 1;
                    nei[ao].emplace_back(bo);
                    nei[bo].emplace_back(ao);
                }
                left = j;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        int up = -1;
        for (int i = 0; i <= n; i++) {
            if (i == n || g[i][j]) {
                if (up + 1 < i - 1) {
                    int ao = (up + 1) * n + j;
                    int bo = (i - 1) * n + j;
                    nei[ao].emplace_back(bo);
                    nei[bo].emplace_back(ao);
                }
                up = i;
            }
        }
    }
//    for (int i = 0; i < n * n; i++) {
//        cout << "i:" << i << "\n";
//        for (auto& v : nei[i]) {
//            cout << v << " ";
//        }
//        cout << "\n";
//    }

    auto check = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    };

    int dist[n][n];
    memset(dist, INF, sizeof(dist));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    dist[0][0] = 0;

    while (q.size()) {
        auto [d, o] = q.front();
        q.pop();

        int i = o / n, j = o % n;
        for (int di = 0; di < 4; di++) {
            int ni = i + dir[di][0];
            int nj = j + dir[di][1];
            int no = ni * n + nj;
            if (not check(ni, nj)) continue;
            if (dist[ni][nj] < INF) continue;
            if (g[ni][nj]) continue;
            if (ni == n - 1 && nj == n - 1) {
                cout << d + 1 << "\n";
                return 0;
            }
            q.emplace(d + 1, no);
            dist[ni][nj] = d + 1;
        }

        for (auto& no : nei[o]) {
            int ni = no / n, nj = no % n;
            if (not check(ni, nj)) continue;
            if (dist[ni][nj] < INF) continue;
            if (ni == n - 1 && nj == n - 1) {
                cout << d + 1 << "\n";
                return 0;
            }
            q.emplace(d + 1, no);
            dist[ni][nj] = d + 1;
        }
    }

    cout << -1 << "\n";
    return 0;
}