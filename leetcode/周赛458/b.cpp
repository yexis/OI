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

struct DJ {
    vector<int> fa;
    vector<int> ra;
    vector<int> cnt; // 每个连通分量的大小
  	int v; // 联通块的总数
    int n;
    DJ(int _n) {
        n = _n;
      	v = _n;
        fa.resize(n);
        ra.resize(n);
        cnt.resize(n);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return;
        }
        if (ra[rx] < ra[ry]) {
            swap(rx, ry);
        }
      	v--;
        fa[ry] = rx;
        cnt[rx] += cnt[ry];
        if (ra[rx] == ra[ry]) {
            ra[rx]++;
        }
    }

  	bool conn(int x, int y) {
    	return find(x) == find(y);
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int K) {
        int mx = 0;
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            mx = max(mx, w);
        }

        auto check = [&](int mid) -> bool {
            DJ dj(n);
            for (auto& e : edges) {
                int x = e[0], y = e[1], w = e[2];
                if (w > mid) {
                    continue;
                }
                dj.merge(x, y);
            }
            return dj.v <= K;
        };

        int ans = 0;
        int l = 0, r = mx;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};









