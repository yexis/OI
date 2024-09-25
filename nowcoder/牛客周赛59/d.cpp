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

/*
 * 
*/

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

void solve() {
    ll s, n, k;
    cin >> s >> n >> k;

    if (n < k) {
        cout << NO << "\n";
        return;
    }

    if (k == 0) {
        if (s < n) {
            cout << NO << "\n";
            return;
        }

        // s >= n
        cout << YES << "\n";
        while (n > 1) {
            cout << 1 << " ";
            n--;
            s--;
        }
        cout << s << "\n";
        return;
    }

    if (k == 1) {
        if (s == 1) {
            cout << NO << "\n";
            return;
        }

        if (n == 1 && s != 0) {
            cout << NO << "\n";
            return;
        }
        cout << YES << "\n";
        while (n > 1) {
            cout << 0 << " ";
            n--;
        }
        cout << s << "\n";
        return;
    }

    // k >= 2
    // n > k
    vector<ll> a;
    for (int i = 0; i < k; i++) {
        a.push_back(i);
        s -= i;
        n--;
    }
    if (n < 0 || s < 0) {
        cout << NO << "\n";
        return;
    }

    if (n > 0) {
        if (s > k || s < k) {
            a.push_back(s);
            n--;
            while (n) {
                a.push_back(0);
                n--;
            }
        } else if (s == k) {
            if (n < 2) {
                cout << NO << "\n";
                return;
            }
            a.push_back(1);
            a.push_back(k - 1);
            n -= 2;
            while (n) {
                a.push_back(0);
                n--;
            }
        }
    } else {
        if (s != 0) {
            cout << NO << "\n";
            return;
        }
    }

    cout << YES << "\n";
    for (auto&e : a) cout << e << " ";
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}