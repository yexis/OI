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
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> res(n);
    set<int> st1, st2{0};
    function<void(int, int)> dfs = [&](int u, int k) -> void {
        for (auto& v : g[u]) {
            if (st1.count(v)) {
                continue;
            }
            if (v > k) {
                st2.insert(v);
            } else {
                // v <= k
                st1.insert(v);
                if (st2.count(v)) {
                    st2.erase(v);
                }
                dfs(v, k);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (!st2.count(i)) {
            res[i] = -1;
            continue;
        }
        st2.erase(i);
        st1.insert(i);
        dfs(i, i);
        if (st1.size() != i + 1) {
            res[i] = -1;
            continue;
        }
        res[i] = st2.size();
    }
    for (auto& e : res) {
        cout << e << "\n";
    }
    
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









