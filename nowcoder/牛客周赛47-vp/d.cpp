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

bool check(ll x, ll n) {
    // x - 非好数
    // 1. mod 3 = 0
    ll a = x / 3;
    // 2. 最后一个数为3，没10个数里面存在一个
    ll b = x / 10;
    if (x % 10 >= 3) {
        b++;
    }
    // 3. mod 3 == 0 && 最后一个数是3
    ll c = x / 30;
    if (x % 30 >= 3) {
        c++;
    }

    return x - (a + b - c) >= n;
}

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ll l = 1, r = 1e15;
        ll ans = -1;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (check(mid, n)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}