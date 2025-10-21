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

static constexpr int maxn = 100010;
struct RMQMAX {
    int Log;
    int n;
    vector<vector<ll>> st;
    // 采用vector<RMQ>时，可以将其改造成init方法
    RMQMAX(vector<ll>& ob) {
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
                st[i][d] = max(st[i][d - 1], st[i + (1 << (d - 1))][d - 1]);
            }
        }
    }

    ll ask(int l, int r) {
        if (l > r) {
            return -1;
        }
        int d = 31 - __builtin_clz(r - l + 1);
        return max(st[l][d], st[r - (1 << d) + 1][d]);
    }
};

struct RMQMIN {
    int Log;
    int n;
    vector<vector<ll>> st;
    // 采用vector<RMQ>时，可以将其改造成init方法
    RMQMIN(vector<ll>& ob) {
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
    // 0 -1 1 -1 1 1 -1
    long long maxSumTrionic(vector<int>& a) {
        int n = a.size();

        vector<ll> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + a[i];
        }
        
        RMQMAX rmq_max(sum);
        RMQMIN rmq_min(sum);

        vector<pii> dec;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && a[j] < a[j - 1]) {
                j++;
            }
            // [i, j - 1]
            if (j - 1 > i) {
                dec.push_back(pii(i, j - 1));
            }
            i = j - 1;
        }   
        
        cout << "dec:" << "\n";    
        for (auto& [l, r] : dec) {
            cout << l << " " << r << "\n";
        }

        vector<int> LI(n), RI(n);
        vector<ll> LV(n, -LLINF), RV(n, -LLINF);
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                LI[i] = LI[i - 1] + 1;
                LV[i] = max(LV[i - 1] + a[i], (ll)a[i - 1] + a[i]);
            } else {
                LI[i] = 1;
                LV[i] = 0;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                RI[i] = RI[i + 1] + 1;
                RV[i] = max(RV[i + 1] + a[i], (ll)a[i] + a[i + 1]);
            } else {
                RI[i] = 1;
                RV[i] = 0;
            }
        }

        ll ans = -LLINF;
        for (auto& [p, q] : dec) {
            if (p == 0 || q == n - 1) continue;
            if (LI[p] <= 1 || RI[q] <= 1) continue;

            int l = p - LI[p] + 1, r = q + RI[q] + 1;

            ll curr = sum[q + 1] - sum[p];
            int sum_p = sum[p], sum_q = sum[q];

            curr += sum[p + 1] - rmq_min.ask(l, p - 1);
            curr += rmq_max.ask(q + 1, r) - sum[q];

            curr -= a[p]; curr -= a[q];
            ans = max(ans, curr);
        }

        return ans;
    }
}









