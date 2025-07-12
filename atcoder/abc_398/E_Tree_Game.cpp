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
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        b >>= 1;
    }
    return ans;
}

/*
 * 
*/

void solve() {
    int n;
    cin >> n;
    vector<int> g[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    int dist[101][101];
    memset(dist, -1, sizeof(dist));
    auto bfs = [&](int s) -> void {
        queue<int> q;
        q.push(s);
        dist[s][s] = 0;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (auto& v : g[u]) {
                if (dist[s][v] != -1) {
                    continue;
                }
                dist[s][v] = dist[s][u] + 1;
                q.push(v);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        bfs(i);
    }

    int cnt = 0;
    set<pii> pr;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((dist[i][j] & 1) && dist[i][j] > 1) {
                cnt++;
                pr.insert(pii(i + 1, j + 1));
            }
        }
    }


    auto output = [&]() -> void {
        cout << pr.begin()->first << " " << pr.begin()->second << endl;
        pr.erase(pr.begin());
    };

    if (cnt & 1) {
        cout << "First" << endl;
        output();
        int i, j;
        while (cin >> i >> j) {
            if (i == -1 && j == -1) {
                return;
            }
            if (i > j) swap(i, j);
            pr.erase(pii(i, j));
            output();
        }
    } else {
        cout << "Second" << endl;
        int i, j;
        while (cin >> i >> j) {
            if (i == -1 && j == -1) {
                return;
            }
            if (i > j) swap(i, j);
            pr.erase(pii(i, j));
            output();
        }
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}



/*
5
1 2
2 3
3 4
4 5

*/





