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
 * logtrick
 * 按位与 和 按位或 的异或和
*/

// ands: 记录子数组的的按位与结果 以及拥有相同值子数组右端点的最小值
// ands的长度最大为32，可直接进行遍历
vector<pair<int, int> > ands;
// ors: 记录子数组的的按位或结果 以及拥有相同值子数组右端点的最小值
vector<pair<int, int> > ors;
// xors: 记录 ands ^ xors
vector<pair<int, int> > xors;


void test_1(vector<int>& a) {
    int n = a.size();
    int m_or, m_and, m_xor;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            m_or = m_and = a[i];
        } else {
            m_or |= a[i];
            m_and &= a[i];
        }
        m_xor = m_or ^ m_and;
        cout << m_and << " " << m_or << " " << m_xor << "\n";
    }
}

static constexpr int maxn = 100010;
struct RMQAND {
    int Log;
    int n;
    vector<vector<int>> st;
    RMQAND(vector<int>& ob) {
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
                st[i][d] = st[i][d - 1] & st[i + (1 << (d - 1))][d - 1];
            }
        }
    }

    int ask(int l, int r) {
        if (l > r) {
            return -1;
        }
        int d = 31 - __builtin_clz(r - l + 1);
        return st[l][d] & st[r - (1 << d) + 1][d];
    }
};

struct RMQOR {
    int Log;
    int n;
    vector<vector<int>> st;
    RMQOR(vector<int>& ob) {
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
                st[i][d] = st[i][d - 1] | st[i + (1 << (d - 1))][d - 1];
            }
        }
    }

    int ask(int l, int r) {
        if (l > r) {
            return -1;
        }
        int d = 31 - __builtin_clz(r - l + 1);
        return st[l][d] | st[r - (1 << d) + 1][d];
    }
};

void solve() {
    int n; cin >> n;
    vector<int> nums(n); for (int i = 0; i < n; i++) cin >> nums[i];

    RMQAND rmq_and(nums);
    RMQOR rmq_or(nums);
    
    ands.clear();
    ors.clear();

    ll dp[n + 1]; memset(dp, 0, sizeof(dp));
    
    for (int i = n - 1; i >= 0; i--) {
        int num = nums[i];
        ands.emplace_back(num, i);
        ors.emplace_back(num, i);

        int k = 0;
        for (int j = 0; j < ands.size(); j++) {
            ands[j].first &= num;
            if (ands[k].first == ands[j].first) {
                ands[k].second = ands[j].second;
            } else {
                ands[++k] = ands[j];
            }
        }
        ands.resize(k + 1);

        int k2 = 0;
        for (int j = 0; j < ors.size(); j++) {
            ors[j].first |= num;
            if (ors[k2].first == ors[j].first) {
                ors[k2].second = ors[j].second;
            } else {
                ors[++k2] = ors[j];
            }
        }
        ors.resize(k2 + 1);

        // 合并
        // xors就是将ands 和 ors 进行合并
        // ands = [5,3,0]
        // ors = [4,2,1,0]
        // xors = [5,4,3,2,1,0]
        int k3 = 0;
        vector<pii> xors; 
        xors.emplace_back(
            pii(ands[0].first ^ ors[0].first, max(ands[0].second, ors[0].second)));
        auto upd = [&](int x, int j) -> void {
            xors.emplace_back(pii(x, j));
        };
        int j1 = 0, j2 = 0;
        for (;j1 < ands.size() && j2 < ors.size();) {
            auto [v1, i1] = ands[j1];
            auto [v2, i2] = ors[j2];
            upd(v1 ^ v2, max(i1, i2));
            if (i1 > i2) {
                j1++;
            } else if (i1 < i2) {
                j2++;
            } else {
                j1++, j2++;
            }
        }
//         cout << "i:" << i << "\n";
//         for (auto& e : ands) cout << e.first << " " << e.second << " -- "; cout << endl;
//         for (auto& e : ors) cout << e.first << " " << e.second << " -- "; cout << endl;
//         for (auto& e : xors) cout << e.first << " " << e.second << " -- "; cout << endl;
//         cout << "----------------------------------------------------------------" << endl;
         
        // 去重
        for (int j = 0; j < xors.size(); j++) {
            if (xors[k3].first == xors[j].first) {
                xors[k3].second = xors[j].second;
            } else {
                xors[++k3] = xors[j];
            }
        }
        xors.resize(k3);

        for (int j = 0; j < xors.size(); j++) {
            auto [v1, i1] = xors[j];
            dp[i] = max(dp[i], v1 + dp[i1 + 1]);
        }
    }
    cout << dp[0] << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}









