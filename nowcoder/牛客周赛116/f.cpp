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
 * https://ac.nowcoder.com/acm/contest/120553/F
 * 
 * - 该区间的两个端点不能与任意其他区间的端点重合
 * - 找出覆盖当前点的区间的左端点的最大值
*/

struct Node {
    int len;
    int sum;
    int z;
    Node() {
        len = 0, sum = 0, z = -1;
    }
    Node(int u, int l) {
        sum = u * l, len = l, z = u;
    }
    Node operator+(const Node& b) const {
        Node res;
        res.len = len + b.len;
        res.sum = sum + b.sum;
        res.z = -1;
        return res;
    }
};
struct Seg {
    Node tr[800100];
    Seg() {

    }
    void push_up(int o) {
        tr[o] = tr[o * 2] + tr[o * 2 + 1];
    }
    void push_down(int o) {
        if (tr[o].z != -1) {
            tr[o * 2].sum = tr[o].z * tr[o * 2].len;
            tr[o * 2].z = tr[o].z;
            tr[o * 2 + 1].sum = tr[o].z * tr[o * 2 + 1].len;
            tr[o * 2 + 1].z = tr[o].z;
            tr[o].z = 0;
        }
    }
    void build(int o, int l, int r) {
        if (l == r) {
            tr[o] = Node();
            tr[o].len = 1;
            tr[o].z = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(o * 2, l, m);
        build(o * 2 + 1, m + 1, r);
        push_up(o);
    }
    void add(int o, int l, int r, int L, int R, int u) {
        if (l >= L && r <= R) {
            int len = r - l + 1;
            tr[o] = Node(len * u, len);
            return;
        }
        push_down(o);
        int m = (l + r) >> 1;
        if (L <= m) {
            add(o * 2, l, m, L, R, u);
        }
        if (R > m) {
            add(o * 2 + 1, m + 1, r, L, R, u);
        }
        push_up(o);
    }
    Node ask(int o, int l, int r, int L, int R) {
        if (l > r) return Node();
        if (l >= L && r <= R) {
            return tr[o];
        }
        push_down(o);
        Node ans;
        int m = (l + r) >> 1;
        if (L <= m) {
            ans = ans + ask(o * 2, l, m, L, R);
        }
        if (R > m) {
            ans = ans + ask(o * 2 + 1, m + 1, r, L, R);
        }
        return ans;
    }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<pii> v(n);
    for (auto& e : v) cin >> e.first >> e.second;
    
    // 按照左端点排序，以左端点<=i判断是否将区间[l,r]加入队列
    sort(v.begin(), v.end());

    // 记录点i是否为某个区间左端点
    int is_left[m + 1]; 
    memset(is_left, 0, sizeof(is_left));
    for (auto [l, r] : v) {
        is_left[l] = 1;
    }

    // 记录所有右端点在点i的区间
    vector<vector<pii >> L(m + 1); 
    for (int i = 0; i < n; i++) {
        auto [l, r] = v[i];
        L[r].push_back(pii(l, i));
    }

    Seg seg; seg.build(1, 1, m);

    ll ans = 0;
    // 包含当前点的区间
    // (0, -1) 表示表示覆盖[0, m]的虚拟区间
    // 这样点i不被任何点覆盖时，方便计算答案
    multiset<pii> ms; ms.insert(pii(0, -1));

    for (int i = 1, j = 0; i <= m; i++) {
        seg.add(1, 1, m, i, i, 1);
        while (j < v.size() && v[j].first <= i) {
            ms.insert(pii(v[j].first, j));
            j++;
        }
        
        if (L[i].size()) {
            for (auto [l, j] : L[i]) {
                seg.add(1, 1, m, l, i, 0);
                ms.erase(ms.find(pii(l, j)));
            }
        }
        
        // 不是任意一个端点
        if (L[i].empty() && !is_left[i]) {
            auto [lst, _] = *ms.rbegin();
            if (lst + 1 <= i) {
                Node tr_ans = seg.ask(1, 1, m, lst + 1, i);
                ans += tr_ans.sum;                
            } 
        }
    }

    cout << ans << "\n";
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









