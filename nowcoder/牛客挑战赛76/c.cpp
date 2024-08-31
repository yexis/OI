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

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7;

// not pass
struct DJ {
    vector<int> fa;
    int n;
    DJ(int nn) {
        n = nn;
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        fa[ry] = rx;
    }
};

const int mxn = 4e5 + 5;
ll fac[mxn], inv[mxn];
ll get_inv(ll x) {
    ll ans = 1;
    int p = mod - 2;
    while (p) {
        if (p & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        p >>= 1;
    }
    return ans;
}

void init_comb() {
    memset(fac, 0, sizeof(fac));
    memset(inv, 0, sizeof(inv));
    fac[0] = inv[0] = 1;
    for (int i = 1; i < mxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = get_inv(fac[i]);
    }
}

ll C(int n, int m) {
    if (n < 0 || m < 0 || n < m) {
        return 0;
    }
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void cal(vector<int>& po, vector<pair<int, int>>& edges) {
    sort(po.begin(), po.end());
    for (auto& e : po) cout << e << " "; cout << "\n";

    unordered_map<int, int> mp;
    for (int i = 0; i < po.size(); i++) {
        mp[po[i]] = i;
    }
    for (auto& [x, y] : edges) {
        x = mp[x];
        y = mp[y];
    }
    int n = po.size();
    DJ dj(n);
    for (auto& [x, y] : edges) {
        dj.merge(x, y);
    }

    vector<int> g[n];
    vector<int> deg(n);
    for (auto& [x, y] : edges) {
        g[x].push_back(y);
        deg[y]++;
    }

    // topo
    vector<ll> cnt(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.emplace(i);
            cnt[i] = 1;
        }
    }

    ll all_cnt = 0, all_res = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto& v : g[u]) {
            cnt[v] += cnt[u];
            all_res *= C(cnt[v], cnt[u]);
            all_res %= mod;

            if (--deg[v] == 0) {
                q.emplace(v);
                cnt[v]++;
            }
        }
    }

    // 收敛
    for (int i = 0; i < n; i++) {
        cnt[dj.find(i)] = max(cnt[dj.find(i)], cnt[i]);
    }

    for (int i = 0; i < n; i++) {
        if (dj.find(i) == i) {
            all_cnt += cnt[i];
            all_res *= C(all_cnt, cnt[i]);
            all_res %= mod;
        }
    }
    cout << all_res << "\n";
}

void solve() {
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<pair<int, int> >> level;
    vector<int> po;
    vector<pair<int, int> > edges;

    vector<pair<int, int>> pr;
    for (int i = 0; i < n; i++) {
        pr.emplace_back(i, s[i] - '0');
    }

    while (pr.size()) {
        bool find = false;
        vector<int> del(pr.size());
        vector<pair<int, int> > v;
        for (int i = 0; i + 3 < pr.size(); i++) {
            auto [i0, d0] = pr[i];
            auto [i1, d1] = pr[i + 1];
            auto [i2, d2] = pr[i + 2];
            auto [i3, d3] = pr[i + 3];
            if (d0 == 0 && d1 == 0 && d2 == 1 && d3 == 1) {
                del[i] = del[i + 1] = del[i + 2] = del[i + 3] = 1;
                v.emplace_back(i0, i3);
                find = true;
                i = i + 3;
            } else {

            }
        }

        if (not find) {
            cout << 0 << "\n";
            return;
        }

        // delete
        vector<pair<int, int>> cpr;
        for (int i = 0; i < pr.size(); i++) {
            if (not del[i]) {
                cpr.emplace_back(pr[i]);
            }
        }
        pr = cpr;

        // 加点
        for (auto& e : v) po.emplace_back(e.first);

        // 加边
        level.emplace_back(v);
        if (level.size() >= 2) {
            auto& up = level[level.size() - 2];
            auto& down = level[level.size() - 1];
            for (int i = 0; i < down.size(); i++) {
                for (int j = 0; j < up.size(); j++) {
                    if (up[j].first > down[i].first && up[j].second < down[i].second) {
                        edges.emplace_back(up[j].first, down[i].first);
                    }
                }
            }
        }
    }
    cal(po, edges);
}
int main() {
    init_comb();
    cout << C(5, 0) << "\n";

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
 * 000100111001100110100111000100111000011001101101100110001000110111000110011100111010001101110011001100110011001100110011
 */