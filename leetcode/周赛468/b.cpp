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

static constexpr int maxn = 100010;
struct RMQ {
    int Log;
    int n;
    vector<vector<ll>> st;
    // 采用vector<RMQ>时，可以将其改造成init方法
    RMQ(vector<ll>& ob) {
        n = ob.size();
        // Log 存储n以内最大的二次幂指数，实在不行可以设置成最大 32
        Log = 32 - __builtin_clz(n);
        // 这里一定不能使用resize，resize不会更新已有范围
        st.assign(n, vector<ll>(Log, -1));
        for (int i = 0; i < n; i++) {
            st[i][0] = ob[i];
        }

        for (int d = 1;  d < Log; d++) {
            for (int i = 0; i + (1 << (d - 1)) < n; i++) {
                st[i][d] = min(st[i][d - 1], st[i + (1 << (d - 1))][d - 1]);
            }
        }
    }

    ll ask(int l, int r) {
        if (l > r) {
            return -1;
        }
        int d = 31 - __builtin_clz(r - l + 1);
        return min(st[l][d], st[r - (1 << d) + 1][d]);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& a, int K) {
        int n = a.size();

        ll mx = 0;
        RMQ rmq(a);

        stack<int> stk1, stk2;
        vector<int> L(n, -1), R(n, n);
        for (int i = 0; i < n; i++) {
            while (stk1.size() && a[stk1.top()] <= a[i]) {
                stk1.pop();
            }
            if (stk1.size()) {
                L[i] = stk1.top();
            }
            stk1.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (stk2.size() && a[stk2.top()] <= a[i]) {
                stk2.pop();
            }
            if (stk2.size()) {
                R[i] = stk2.top();
            }
            stk2.push(i);
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int l = L[i] + 1;
            int r = R[i] - 1;
            if (r < l) continue;
            ans = max(ans, K * rmq.ask(l, r));
        }
        return ans;
    }
};









