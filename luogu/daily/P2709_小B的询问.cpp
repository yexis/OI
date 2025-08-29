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
 * 莫队算法
 * 普通莫队
*/

struct Query {
    int bid;
    int l, r;
    int qid;

    Query(int _bid, int _l, int _r, int _qid) : bid(_bid), l(_l), r(_r), qid(_qid) {}

    bool operator<(const auto& that) const {
        if (bid == that.bid) {
            return r < that.r;
        }
        return bid < that.bid;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n); for (auto& e : a) cin >> e;
    vector<vector<int>> qs(m);
    for(auto& q : qs) {
        q.resize(2);
        cin >> q[0] >> q[1];
        q[0]--, q[1]--;
    }

    int block_size = n / sqrt(2 * m);

    ll sum = 0;
    unordered_map<int, int> cnt;
    auto add = [&](int x){
        sum -= (ll)cnt[x] * cnt[x];
        cnt[x]++;
        sum += (ll)cnt[x] * cnt[x];
    };
    auto del = [&](int x) {
        sum -= (ll)cnt[x] * cnt[x];
        cnt[x]--;
        sum += (ll)cnt[x] * cnt[x];
    };

    vector<ll> res(m);
    vector<Query> pr;
    for (int i = 0; i < m; i++) {
        int l = qs[i][0], r = qs[i][1];
        // 大区间
        if (r - l + 1 > block_size) {
            pr.emplace_back(l / block_size, l, r, i);
            continue;
        }
        // 小区间
        for (int j = l; j <= r; j++) {
            add(a[j]);
        }
        res[i] = sum;
        for (int j = l; j <= r; j++) {
            del(a[j]);
        }
    }
    sort(pr.begin(), pr.end());

    // [l, r]
    int curr_l = 0, curr_r = -1;
    for (int i = 0; i < pr.size(); i++) {
        auto& q = pr[i];
        while (curr_l < q.l) del(a[curr_l++]);
        while (curr_l > q.l) add(a[--curr_l]);

        while (curr_r < q.r) add(a[++curr_r]);
        while (curr_r > q.r) del(a[curr_r--]);
        res[q.qid] = sum;
    }
    
    for (auto& e : res) {
        cout << e << "\n";
    }
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









