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
using pii = pair<int, int>;

ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
        }
        x *= x;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll a, b, c;
    while (cin >> a >> b >> c) {
        if (c == 1) {
            ll res = b * power(3ll, a + 2);
            if (res % 100) {
                res += 100 - (res % 100);
            }
            res *= 3;
            cout << res << '\n';
        } else if (c == 0) {
            ll res = 4 * b * power(3ll, a + 2);
            if (res % 100) {
                res += 100 - (res % 100);
            }
            cout << res << '\n';
        }
    }
    return 0;
}