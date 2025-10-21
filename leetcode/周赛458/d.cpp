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
#define debug(x) cerr << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

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
using arr = array<int, 4>;
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

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 
*/

class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string s) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        queue<arr> q;
        for (int i = 0; i < n; i++) {
            q.push(arr{1 << i, i, i, 1});
        }
        
        for (auto& e :edges) {
            int x = e[0], y = e[1];
            if (s[x] == s[y]) {
                q.push(arr{1 << x | 1 << y, x, y, 2});
            }
        }
        
        int ans = 1;
        while (q.size()) {
            auto [mask, u, v, d] = q.front();
            ans = max(ans, d);
            q.pop();
            for (auto& next_u : g[u]) {
                if (mask >> next_u & 1) continue;
                for (auto& next_v : g[v]) {
                    if (mask >> next_v & 1) continue;
                    if (next_v == next_u) continue;
                    if (s[next_u] != s[next_v]) continue;
                    q.push(arr{mask | (1 << next_u) | (1 << next_v), next_u, next_v, d + 2});
                }
            }
        }
        return ans;
    }
};








©leetcode