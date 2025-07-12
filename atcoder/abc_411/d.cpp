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

void solve() {
    int n, q;
    cin >> n >> q;

    struct OP {
        // 0 replace
        // 1 append
        int index;
        int op;
        int pre;
        string s;
        OP(int _index, int _op, int _pre, string _s) {
            index = _index;
            op = _op;
            pre = _pre;
            s = _s;
        }
    };

    // n 表示 server
    vector<vector<OP> > ops(n + 1);
    
    int tot = 0;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            // s -> p
            int p; cin >> p; p--;
            ops[p].push_back(OP(tot++, 0, n, ""));
        } else if (op == 2) {
            // append p
            int p; cin >> p; p--;
            string s; cin >> s;
            ops[p].push_back(OP(tot++, 1, -1, s));
        } else if (op == 3) {
            // p -> s
            int p; cin >> p; p--;
            ops[n].push_back(OP(tot++, 0, p, ""));
        }
    }

    if (ops[n].size() == 0) {
        cout << "" << "\n";
        return;
    }

    vector<string> res;
    int p = ops[n].back().pre, idx = ops[n].back().index;
    while (true) {
        while (ops[p].size() > 0 && ops[p].back().index > idx) {
            ops[p].pop_back();
        }
        if (ops[p].size() == 0) {
            break;
        }
        OP op = ops[p].back();
        idx = op.index;
        ops[p].pop_back();
        if (op.op == 0) {
            p = op.pre;
        } else if (op.op == 1) {
            res.push_back(op.s);
        }
    }
    reverse(res.begin(), res.end());

    string ans;
    for (string& r : res) {
        ans += r;
    }
    cout << ans << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









