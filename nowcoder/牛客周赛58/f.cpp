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

const int N = 100010;
struct Node {
    int ls, rs;
    int val;
} tr[N * 40];
int root[N]{};
int tot = 0;

void add(int pre, int& now, int l, int r, int pos, int val) {
    if (!now) now = ++tot;
    if (l == r) {
        tr[now].val = tr[pre].val + val;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) {
        tr[now].rs = tr[pre].rs;
        add(tr[pre].ls, tr[now].ls, l, m, pos, val);
    } else {
        tr[now].ls = tr[pre].ls;
        add(tr[pre].rs, tr[now].rs, m + 1, r, pos, val);
    }
    tr[now].val = tr[tr[now].ls].val + tr[tr[now].rs].val;
}

int ask(int pre, int now, int l, int r, int k) {
    if (l == r) {
        return l;
    }
    int m = (l + r) >> 1;
    int sum = tr[tr[now].ls].val - tr[tr[pre].ls].val;
    if (k <= sum) {
        return ask(tr[pre].ls, tr[now].ls, l, m, k);
    } else {
        return ask(tr[pre].rs, tr[now].rs, m + 1, r, k - sum);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        add(root[i], root[i + 1], 1, n, a[i], 1);
    }
    int L = 1, R = n;
    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        if (k == 0) {
            // all > ans
            int x = ask(l, r + 1, 1, n, 1);
            cout << x << "\n";
            R = min(R, x - 1);
        } else {
            int x = ask(l, r + 1, 1, n, k);
            cout << x << "\n";
            L = max(L, x);
        }
    }
    if (L > R) {
        cout << 0 << "\n";
        return;
    }
    if (L == R) {
        cout << 1 << " " << L << "\n";
        return;
    }
    cout << power(R - L + 1, mod - 2) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}