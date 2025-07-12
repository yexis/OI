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
    vector<int> processQueries(int c, vector<vector<int>>& edges, vector<vector<int>>& qs) {
        int n = edges.size();

        DJ dj(c);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            dj.merge(x, y);
        }
        vector<set<int>> st(n);
        for (int i = 0; i < n; i++) {
            int r = dj.find(i);
            st[r].insert(i);
        }

        vector<int> online(n, 1); 
        vector<int> res;
        for (auto& q : qs) {
            int op = q[0], x = q[1];
            if (op == 0) {
                int r = dj.find(x);
                if (st[r].size() == 0) {
                    res.push_back(-1);
                } else {
                    res.push_back(*st[r].begin());
                }
            } else {
                online[x] = 0;
                int r = dj.find(x);
                st[r].erase(x);
            }
        }
        return res;
    }
};









