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


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
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
 * 神奇的小江鸟
 * https://www.luogu.com.cn/problem/P11312?contestId=183429
 * 
 * 思路：
 * 1. 如果所有的区间范围[l,r]长度都不小于k，那么答案一定存在(一个长度不小于k的区间中一定存在k能整除的数 k|x)
 * 2. 如果区间范围[l,r]长度最小的区间长度小于k(<=1000)
 *    - 那么就遍历这个区间内的所有元素，并记录所有因子 k * sqrt(V) k <= 1000，V <= 1e9
 *    - 然后对于每个因子，判断每个区间是否存在该因子的倍数
*/

int check2(int l, int r, int x) {
    int y = (l + x - 1) / x * x;
    if (y > r) return -1;
    return y;
}

int check(int l, int r, int x) {
    int y = r / x * x;
    if (y < l) return -1;
    return y;
}

void solve() {
    int n, k;
    cin >> n >> k;


    vector<pii> pr(n);
    for (int i = 0; i < n; i++) {
        cin >> pr[i].first >> pr[i].second;
    }
    auto pt = pr;

    sort(pr.begin(), pr.end(), [&](const auto& aa, const auto& bb) {
        if (aa.second - aa.first == bb.second - bb.first) {
            return aa.first < bb.first;
        }
        return aa.second - aa.first < bb.second - bb.first;
    });

    if (pr[0].second - pr[0].first >= k) {
        // 一定存在
        cout << "Yes" << "\n";
        for (auto& e : pt) {
            int l = e.first, r = e.second;
            cout << check(l, r, k) << " ";
        }
        cout << "\n";
        return;
    } else {
        // r - l < k
        set<int> st;
        for (int i = pr[0].first; i <= pr[0].second; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (i % j) continue;
                if (j >= k) st.insert(j);
                if (i / j >= k) st.insert(i / j);
            }
        }
        
        for (auto& e : st) {
            bool ok = true;
            for (auto& [l, r] : pt) {
                if (check(l, r, e) == -1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "Yes" << "\n";
                for (auto& [l, r] : pt) {
                    cout << check(l, r, e) << " ";
                }
                cout << "\n";
                return;
            }
        }
    }
    cout << "No" << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}




