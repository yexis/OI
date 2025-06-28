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
const int mod = 998244353;
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

static constexpr int maxn = 200010;
struct RMQ {
    int Log;
    int n;
    vector<vector<int>> st;
    // 采用vector<RMQ>时，可以将其改造成init方法
    RMQ(vector<int>& ob) {
        n = ob.size();
        // Log 存储n以内最大的二次幂指数，实在不行可以设置成最大 32
        Log = 32 - __builtin_clz(n);
        // 这里一定不能使用resize，resize不会更新已有范围
        st.assign(n, vector<int>(Log, -1));
        for (int i = 0; i < n; i++) {
            st[i][0] = ob[i];
        }

        for (int d = 1;  d < Log; d++) {
            for (int i = 0; i + (1 << (d - 1)) < n; i++) {
                st[i][d] = max(st[i][d - 1], st[i + (1 << (d - 1))][d - 1]);
            }
        }
    }

    int ask(int l, int r) {
        if (l > r) {
            return -1;
        }
        int d = 31 - __builtin_clz(r - l + 1);
        return max(st[l][d], st[r - (1 << d) + 1][d]);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& e : a) cin >> e;
    vector<int> b(m); for (auto& e : b) cin >> e;
    set<int> bb; for (auto& e : b) bb.insert(e);

    vector<int> index(n + 1);
    for (int i = 0; i < n; i++) {
        index[a[i]] = i;
    }
    

    stack<int> stk1;
    vector<int> L(n, -1); // 左侧第一个大于x的元素
    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (stk1.size() && a[stk1.top()] <= x) {
            stk1.pop();
        }
        if (stk1.size()) {
            L[i] = stk1.top();
        }
        stk1.push(i);
    }

    stack<int> stk2;
    vector<int> R(n, n); // 右侧第一个大于x的元素
    for (int i = n - 1; i >= 0; i--) {
        int x = a[i];
        while (stk2.size() && a[stk2.top()] <= x) {
            stk2.pop();
        }
        if (stk2.size()) {
            R[i] = stk2.top();
        }
        stk2.push(i);
    }
    
    vector<arr> P;
    for (int i = 0; i < m; i++) {
        P.push_back({L[index[b[i]]], index[b[i]], R[index[b[i]]]});
    }
    // for (auto& [l, i, r] : P) {
    //     cout << l << " " << i << " " << r << "\n";
    // } 
    // 特判两边
    if (P[0][0] != -1 || P.back()[2] != n) {
        cout << 0 << "\n";
        return;
    }
    ll ans = 1;
    for (int i = 0; i + 1 < m; i++) {
        auto [l1, i1, r1] = P[i];
        auto [l2, i2, r2] = P[i + 1];
        int l = max(i1, l2);
        int r = min(r1, i2);
        int cnt = max(0, r - l);
        ans *= cnt; ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}









