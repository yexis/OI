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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

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
// b:最大的v的二进制位数 例如v=8,b=3
int b;
struct Node {
    int val;
    vector<Node*> child;
    Node() {
        val = 0;
        child.resize(2);
    }
};

struct Trie {
    Node* root;
    int sm;
    Trie() {
        sm = 0;
        root = new Node();
    }
    void add(int v, int m) {
        auto p = root;
        for (int i = m; i >= 0; i--) {
            int bit = v >> i & 1;
            if (p->child[bit] == nullptr) {
                p->child[bit] = new Node();
            }
            p = p->child[bit];
            p->val++;
            if (p->val == 1) sm++;
        }
    }
    void del(int v, int m) {
        auto p = root;
        for (int i = m; i >= 0; i--) {
            int bit = v >> i & 1;
            p = p->child[bit];
            p->val--;
            if (p->val == 0) sm--;
        }
    }
    int sum() {
        return sm;
    }
    int ask(int v) {
        int ans = 0;
        auto p = root;
        for (int i = b; i >= 0; i--) {
            int bit = v >> i & 1;
            if (p->child[1 ^ bit] && p->child[1 ^ bit]->val > 0) {
                ans |= 1 << i;
                bit ^= 1;
            }
            p = p->child[bit];
        }
        return ans;
    }
};

void solve() {
    int q; cin >> q;
    
    b = 20;
    Trie tr;

    auto cal = [&](string& t) -> int {
        int m = t.size();
        int mask = 0;
        for (int i = 0; i < m; i++) {
            if (t[i] == '1') mask = (mask << 1) + 1;
        }
        return mask;
    };
    while (q--) {
        char op; cin >> op;
        if (op == '+') {
            string t; cin >> t;
            int v = cal(t);
            tr.add(v, t.size());
        } else if (op == '-') {
            string t; cin >> t;
            int v = cal(t);
            tr.del(v, t.size());
        }
        cout << tr.sum() << "\n";
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









