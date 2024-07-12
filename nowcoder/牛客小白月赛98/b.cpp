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

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            odd++;
        } else {
            even++;
        }
    }

    int v = 0;#include <iostream>
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

    const int mod = 998244353;
    ll inv(ll x) {
        ll p = mod - 2;
        ll ans = 1;
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

    int main() {
        int q;
        cin >> q;
        while (q--) {
            ll a, x;
            cin >> a >> x;
            if (x == 1) {
                cout << a * x % mod << "\n";
            } else {
                // x > 1
                ll ans = 0;
                // a * a * (1 + 2 + .... + x - 1)
                ans = a * a % mod * (x * (x - 1) % mod * inv(2) % mod) % mod;
                cout << ans << "\n";
            }
        }
        return 0;
    }
    if (odd <= even) {
        v = odd * 2;
    } else {
        // odd > even
        v += 2 * even;
        odd -= even;
        v += ((odd & 1) ? odd - 1 : odd);
    }
    cout << n - v << "\n";
    return 0;
}