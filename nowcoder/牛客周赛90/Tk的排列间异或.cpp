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
    vector<pii> pr;
    for (int i = 0; i < n; i++) {
        pr.emplace_back(a[i], i);
    }
    sort(pr.begin(), pr.end());

    int Log = 32 - __builtin_clz(n);
    vector<vector<int> > v(Log, vector<int>(1 << Log));
    for (int d = 1; d <= n; d++) {
        int b = 0;
        for (int i = 0; i < Log; i++) {
            if (d >> i & 1) {
                b |= 1 << i;
            }
            v[i][b]++;
        }
    }

    vector<int> cnt(Log);
    for (int d = 1; d <= n; d++) {
        for (int i = 0; i < Log; i++) {
            if (d >> i & 1) {
                cnt[i]++;
            }
        }
    }
    
    vector<int> b(n);
    for (int i = 0; i < Log; i++) {
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++) {
            auto [dd, idx] = pr[j];
            if (dd >> i & 1) {

            } else {
                b[j] |= 1 << i;
            }
            mp[b[j]]++;
        }

        int one = cnt[i];
        int zero = n - cnt[i];
        if (one > zero) {
            // zero -> one
            for (auto& e : b) {
                if (e >> i & 1) {

                } else {
                    int tmp = e ^ (1 << i);
                    if (mp[tmp] < v[i][tmp]) {
                        mp[e]--;
                        e = tmp;
                        mp[tmp]++;
                    }
                }
            }
        } else if (one < zero) {
            // one -> zero
            for (auto& e : b) {
                if (e >> i & 1) {
                    int tmp = e ^ (1 << i);
                    if (mp[tmp] < v[i][tmp]) {
                        mp[e]--;
                        e = tmp;
                        mp[tmp]++;
                    }
                } else {

                }
            }
        } else {

        }
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        auto [_, idx] = pr[i];
        res[idx] = b[i];
    }

    for (auto& e : res) {
        cout << e << " ";
    }
    cout << "\n";

    return;
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}

/*
5 5 4 3 
0001 0010 0011 0100 0101 0110 0111 1000 1001 1010
0 110 14
0 101 13
0 100 12 
0 011 11 
1 010 10
1 001 9
1 000 8
0 111 7
0 010 6
0 001 5
*/









