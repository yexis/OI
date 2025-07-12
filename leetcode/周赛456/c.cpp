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

class Solution {
public:
    int minXor(vector<int>& a, int K) {
        int n = a.size();

        vector<vector<int>> xo(n, vector<int>(n));      
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = i; j < n; j++) {
                xo[i][j] = t ^ a[j];
            }
        }

        int ans = 0;
        int mi = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());

        auto dfs = [&](this auto&& dfs, int idx, int k, int lim) -> bool {
            if (idx == n) {
                if (k == K) return true;
                return false;
            }
            bool ok = false;
            for (int idx2 = idx; idx2 < n; idx2++) {
                if (xo[idx][idx2] <= lim) {
                    if (dfs(idx2 + 1, k + 1, lim)) {
                        return true;
                    }
                }
            }
            return false;
        };

        auto check = [&](int mid) {
            if (dfs(0, 0, mid)) {
                return true;
            }
            return false;
        };


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
    }
};









