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
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    auto p = a;
    
    vector<pii> pr;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            pr.emplace_back(a[i], i);
        }
        if (i + 1 < n && a[i] && a[i + 1] && 
                abs(a[i] - a[i + 1]) != 1) {
            cout << -1 << "\n";
            return;
        } 
    }

    // 全0
    if (pr.size() == 0) {
        int lst = 0;
        for (int i = 0; i < n; i++) {
            p[i] = lst + 1;
            lst = p[i];
        }
        for (auto& e : p) cout << e << " "; cout << "\n";
        return;
    }

    // 左侧
    if (pr[0].second > 0) {
        auto [x2, idx2] = pr[0];
        int l = 0, r = idx2 - 1;
        int j = r;
        while (j >= l) {
            p[j] = p[j + 1] + 1;
            j--;
        }
    }
    // 右侧
    if (pr.back().second < n - 1) {
        auto [x1, idx1] = pr.back();
        int l = idx1 + 1, r = n - 1;
        int j = l;
        while (j <= r) {
            p[j] = p[j - 1] + 1;
            j++;
        }   
    }
    
    for (int i = 1; i < pr.size(); i++) {
        auto [x1, idx1] = pr[i - 1];
        auto [x2, idx2] = pr[i];
        int mx = max(x1, x2);
        int l = idx1 + 1, r = idx2 - 1;      
        // 先使得两边相等
        int len = r - l + 1;
        int need = abs(x2 - x1 - 1);
        // cout << len << " " << need << "\n";
        
        if (len < need) {
            cout << -1 << "\n";
            return;
        }
        if ((len + need) & 1) {
            cout << -1  << "\n";
            return;
        }
        // len > need
        if (x1 <= x2) {
            int j = l, fg = 1;
            while (j <= r && need > 0) {
                p[j] = p[j - 1] + 1;
                j++;
                need--;
            }
            while (j <= r) {
                if (fg) p[j] = p[j - 1] + 1;
                else p[j] = p[j - 1] - 1;
                j++;
            }
        } else {
            int j = r, fg = 1;
            while (j >= l && need > 0) {
                p[j] = p[j + 1] + 1;
                j--;
                need--;
            }
            while (j >= l) {
                if (fg) p[j] = p[j + 1] + 1;
                else p[j] = p[j + 1] - 1;
                j--;
            }
        }
        
    }

    for (auto& e : p) {
        cout << e << " ";
    }
    cout << "\n";

}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









