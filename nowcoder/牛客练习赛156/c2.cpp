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
 
void solve(int n, int D, int K) {
    // n >= 2
    // int n, D, K; cin >> n >> D >> K;
     
    // 只能有两个点
    if (K == 1 || D == 1) {
        if (n == 2) cout << 1 << " " << 2 << "\n";
        else cout << -1 << "\n";
        return;
    }
 
    // 链
    if (K == 2) {
        if (D + 1 >= n) {
            for (int i = 2; i <= n; i++) cout << i - 1 << " " << i << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }
 
    // 菊花图
    if (D == 2) {
        if (K + 1 >= n) {
            for (int i = 2; i <= n; i++) cout << 1 << " " << i << "\n";
        } else {
            cout << -1 << "\n";            
        }
        return;
    }
 
    // D >= 3 && K >= 3
    vector<pii> edges;
    auto print = [&]() -> void {
        for (auto& [u, v] : edges) cout << u << " " << v << "\n"; 
    };
     
    int h = (D >> 1);
    if (D & 1) {
        // 奇数
        // 2 + 2 * (K - 1) + ... + 2 * (K - 1)^h
        ll tot = 0;
        for (ll hi = 0, b = 2; hi <= h; hi++) {
            tot += b; b *= (K - 1);
            if (tot >= n) break;
        }
        if (tot < n) {
            cout << -1 << "\n";
            return;
        }
        // 一定能构造
        queue<int> q; q.push(1); q.push(2);
        edges.push_back(pii(1, 2)); 
        int curr = 3;
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto u = q.front(); q.pop();
                if (curr > n) break;
                int c = K - 1; 
                while (c--) {
                    q.push(curr);
                    edges.push_back(pii(u, curr));
                    if (++curr > n) {
                        break;
                    }
                }
            }
        }
        print();
    } else {
        // 偶数
        // 1 + K + K * (K - 1) + ... + K * (K - 1)^(h-1)
        ll tot = 1;
        for (int hi = 0, b = K; hi <= h - 1; hi++) {
            tot += b; b *= (K - 1);
            if (tot >= n) break;
        }
        if (tot < n) {
            cout << -1 << "\n";
            return;
        }
        // 一定能构造
        queue<int> q; q.push(1);
         
        int curr = 2, level = 0;
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto u = q.front(); q.pop();
                if (curr > n) break; 
                int c = K - 1;
                if (level == 0) c = K;
                while (c--) {
                    q.push(curr);
                    edges.push_back(pii(u, curr));
                    if (++curr > n) {
                        break;
                    }
                }
            }
            level++;
        }
        print();
    }
}
int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
        for (int n = 2; n <= 80; n++) {
            for (int d = 1; d <= n; d++) {
                for (int k = 1; k <= n; k++) {
                    cout << "n,d,k:" << n << " " << d << " " << k << "\n";
                    solve(n, d, k);
                }
            }
        }
    }
    return 0;
}









