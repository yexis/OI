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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
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
 * 
*/

void solve() {
    int n;
    cin >> n;
    vector<pii> pr(n);
    for (auto& [l, r] : pr) {
        cin >> l >> r; 
    }

    vector<int> ob;
    for (auto& [l, r] : pr) {
        ob.push_back(l);
        ob.push_back(r);
    }
    sort(ob.begin(), ob.end());
    ob.erase(unique(ob.begin(), ob.end()), ob.end());
    int m = ob.size();
    auto get = [&](int x) {
        return lower_bound(ob.begin(), ob.end(), x) - ob.begin();
    };
    
    vector<int> D(m + 1);
    for (int i = 0; i < pr.size(); i++) {
        auto [l, r] = pr[i];
        D[get(l)]++;
        D[get(r) + 1]--;
    }

    for (int i = 0; i < m; i++) {
        D[i] += (i - 1 >= 0 ? D[i - 1] : 0);
        if (D[i] > 2) {
            cout << -1 << "\n";
            return;
        }
    }

    using arr = array<int, 3>;
    vector<arr> pr2;
    for (int i = 0; i < n; i++) {
        auto [l, r] = pr[i];
        pr2.push_back({l, r, i});
    }
    sort(pr2.begin(), pr2.end(), [&](auto& aa, auto& bb) {
        if (aa[1] == bb[1]) {
            return aa[0] < bb[0];
        }
        return aa[1] < bb[1];
    });

    // 一定有解
    vector<int> res1;
    vector<int> res2;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; i++) {
        auto& [l, r, idx] = pr2[i];
        if (l <= mx1 && l <= mx2) {
            cout << -1 << "\n";
            return;
        } else if (l <= mx2) {
            res1.push_back(idx);
            mx1 = max(mx1, r);
        } else if (l <= mx1) {
            res2.push_back(idx);
            mx2 = max(mx2, r);    
        } else {
            res2.push_back(idx);
            mx2 = max(mx2, r);
        }
    }
    if (res1.size() < res2.size()) {
        res1.swap(res2);
    }
    cout << res1.size() << "\n";
    for (auto& e : res1) {
        cout << e + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









