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
#define debug(x) cout << (#x) << " = " << (x) << endl;
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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }
void mod_norm(ll& x, ll K) { x %= K; x += K; x %= K; }

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
 * 从数据量入手
*/


class Solution {
public:
    int longestSubarray(vector<int>& a, int K) {
        int n = a.size();
        // sum - 2 * a[i] = 0 (mod K)
        // sum = 2 * a[i] (mod K)

        int ans = 0, sum = 0;
        vector<int> first(3001, -1); first[0] = 0;
        vector<int> last(3001, -1); last[0] = 0;
        vector<vector<int>> pos(3001); pos[0].push_back(0);
        for (int i = 0; i < n; i++) {
            sum += a[i]; sum %= K; sum += K; sum %= K;
            int sub = 2 * a[i] % K; sub += K; sub %= K;
            pos[sub].push_back(i + 1);
            if (first[sum] == -1) {
                first[sum] = i + 1;
            }
            last[sum] = i + 1;
            if (first[sum] != -1) {
                ans = max(ans, i + 1 - first[sum]);
            }
        }

        for (int L = 0; L <= 3000; L++) {
            int l_idx = first[L]; if (l_idx == -1) continue;
            for (int R = 0; R <= 3000; R++) {
                int r_idx = last[R]; if (r_idx == -1) continue;
                // (l_idx, r_idx] 内是否存在 sum
                if (r_idx - l_idx <= ans) continue;
                int delta = (R - L + K) % K;
                int cnt = upper_bound(pos[delta].begin(), pos[delta].end(), r_idx) \
                        - upper_bound(pos[delta].begin(), pos[delta].end(), l_idx);
                if (cnt > 0) {
                    ans = max(ans, r_idx - l_idx);
                }
            }
        }

        return ans;
    }
};
    



