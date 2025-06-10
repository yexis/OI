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

const int N = 300000;
struct CountIntervals {
    map<int, int> mp;
    int cnt;
    // 存储方式: pair<R, L> 
    // first表示右端点，second表示左端点
    set<arr> st;
    CountIntervals() {
        cnt = 0;
    }
    void add(int left, int right, int x) {
        // 设即将add的区间为 I0[L, R]
        int L = left, R = right;
        vector<arr> ts;
        // 找到第一个 右端点 >= L 的区间 I1(ll, rr)
        auto it = st.lower_bound(arr{L, -1, -1});
        while (it != st.end()) {
            auto [rr, ll, xx] = *it;
            if (ll >= R + 1) {
                break;
            }
            it = st.erase(it);
            mp[xx] -= (rr - ll + 1);
            if (mp[xx] == 0) mp.erase(xx);
            
            // 两个区间存在四种关系
            if (ll >= L && rr <= R) {
                // 关系1
                // 区间I1 被 区间I0 完全覆盖
                // L <= ll <= rr <= R
                // L ... ll ... rr ... R
            } else if (ll <= L && rr >= R) {
                // 关系2
                // 区间I0 被 区间I1 完全覆盖
                // ll <= L <= R <= rr
                // ll ... L ... R ... rr
                if (ll <= L - 1) {
                    ts.push_back(arr{L - 1, ll, xx});
                    mp[xx] += (L - 1 - ll + 1);
                }
                if (rr >= R + 1) {
                    ts.push_back(arr{rr, R + 1, xx});
                    mp[xx] += (rr - (R + 1) + 1);
                }
            } else {
                // 关系3
                // 不完全包含的关系，部分覆盖
                // ll <= L <= rr <= R
                // ll ... L ... rr ... R
                if (ll <= L && L <= rr) {
                    if (ll <= L - 1) {
                        ts.push_back(arr{L - 1, ll, xx});
                        mp[xx] += (L - 1 - ll + 1);
                    }
                } else if (ll <= R && rr >= R) {
                    // 关系4
                    // 不完全包含的关系，部分覆盖
                    // L <= ll <= R <= rr
                    // L ... ll ... R ... rr
                    if (R + 1 <= rr) {
                        ts.push_back(arr{rr, R + 1, xx});
                        mp[xx] += (rr - (R + 1) + 1);
                    }
                }
            }   
        }
        int i = 0;
        while (i < ts.size()) {
            auto [rr, ll, xx] = ts[i];
            st.insert(ts[i]);
            i++;
        }
        st.insert(arr{R, L, x});
        mp[x] += (R - L + 1);
    }
    int count() {
        return (int)mp.size();
    }
};

void solve() {
    CountIntervals ci;
    ci.add(0, 1e9, 0);

    int ans = 0;
    int q; cin >> q;
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        ci.add(l, r, x);
        cout << ci.count() << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









