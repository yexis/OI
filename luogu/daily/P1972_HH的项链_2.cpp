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
};

/*
 * 回滚莫队
 * 对于1e6的数据量，时间复杂度O(n*sqrt(q))会超时
*/

struct Query {
    int bid;
    int l, r;
    int qid;
    Query(int _bid, int _l, int _r, int _qid) : 
        bid(_bid), l(_l), r(_r), qid(_qid) {}
    bool operator<(const Query& that) const {
        if (bid == that.bid) {
            return r < that.r;
        }
        return bid < that.bid;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    int m; cin >> m;
    vector<int> res(m);
    int block_size = ceil(n / sqrt(2 * m));

    int now = 0;
    int cnt[1000010]; memset(cnt, 0, sizeof(cnt));
    auto add = [&](int x, int u) -> void {
        if (cnt[x] == 0) now++;
        cnt[x] += u;
        if (cnt[x] == 0) now--;
    };

    vector<Query> pr;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        // 大区间
        if (r - l + 1 > block_size) {
            pr.emplace_back(l / block_size, l, r, i);
            continue;
        }
        // 小区间
        for (int j = l; j <= r; j++) {
            add(a[j], 1);
        }
        res[i] = now;
        for (int j = l; j <= r; j++) {
            add(a[j], -1);
        }
    }

    sort(pr.begin(), pr.end());

    int r;
    for (int i = 0; i < pr.size(); i++) {
        auto& q = pr[i];
        int r_start = (q.bid + 1) * block_size;
        if (i == 0 || q.bid > pr[i - 1].bid) {
            r = r_start;
            fill(cnt, cnt + 1000010, 0);
            now = 0;
        }
        // 同一个块内，r单调递增
        for (; r <= q.r; r++) {
            add(a[r], 1);
        }

        int tmp_now = now;
        for (int j = q.l; j < r_start; j++) {
            add(a[j], 1);
        }
        res[q.qid] = now;
        
        for (int j = q.l; j < r_start; j++) {
            add(a[j], -1);
        }
        now = tmp_now;
    }

    for (auto& e : res) cout << e << "\n";
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









