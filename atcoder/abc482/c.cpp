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
#define debugE(x) cerr << (#x) << " = " << (x) << endl;

template<typename... Args> void debug_print(const char* names, Args&&... args) { cout << names << " = "; ((cout << args << " "), ...); cout << endl; }
template<typename... Args> void debug_err_print(const char* names, Args&&... args) { cerr << names << " = "; ((cerr << args << " "), ...); cerr << endl; }
#define debugs(...) debug_print(#__VA_ARGS__, __VA_ARGS__)
#define debugsE(...) debug_err_print(#__VA_ARGS__, __VA_ARGS__)

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

void solve() {
    int h, w, n, q; cin >> h >> w >> n >> q;
    
    vector<pii> pls;
    vector<int> ob, ob2;
    for (int i = 0; i < n; i++) {
        int r, c; cin >> r >> c;
        ob.push_back(r);
        ob2.push_back(c);
        pls.push_back({r, c});
    }

    vector<arr> qs;
    for (int i = 0; i < q; i++) {
        int op, x, y; cin >> op >> x >> y;
        qs.push_back({op, x, y});
        if (op == 1) {
            ob.push_back(x);
            ob.push_back(y);
        } else if (op == 2) {
            ob2.push_back(x);
            ob2.push_back(y);
        }
    }

    sort(ob.begin(), ob.end());
    ob.erase(unique(ob.begin(), ob.end()), ob.end());
    auto get1 = [&](int r) -> int {
        return lower_bound(ob.begin(), ob.end(), r) - ob.begin();
    };
    int m1 = ob.size();
    // for (auto& e : ob) cout << e << " "; cout << "\n";
    
    sort(ob2.begin(), ob2.end());
    ob2.erase(unique(ob2.begin(), ob2.end()), ob2.end());
    auto get2 = [&](int r) -> int {
        return lower_bound(ob2.begin(), ob2.end(), r) - ob2.begin();
    };
    int m2 = ob2.size();
    
    vector<int> cnt1(m1), sum1(m1 + 1);
    vector<int> cnt2(m2), sum2(m2 + 1);
    for (auto [r, c] : pls) {
        cnt1[get1(r)]++, cnt2[get2(c)]++;
    }
    for (int i = 0; i < m1; i++) sum1[i + 1] = sum1[i] + cnt1[i];
    for (int i = 0; i < m2; i++) sum2[i + 1] = sum2[i] + cnt2[i];

    for (auto[op, x, y] : qs) {
        if (op == 1) {
            int k2 = get1(y);
            int k1 = get1(x);
            cout << sum1[k2 + 1] - sum1[k1] << "\n";
        } else if (op == 2) {
            int k2 = get2(y);
            int k1 = get2(x);
            cout << sum2[k2 + 1] - sum2[k1] << "\n";
        }
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









