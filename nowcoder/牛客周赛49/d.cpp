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

// 写法一
//int main() {
//    ll T;
//    cin >> T;
//    while (T--) {
//        ll l, r;
//        cin >> l >> r;
//        ll ans = 0;
//        ll base = 2;
//        for (int i = 0; i < 62; i++) {
//            // 计算第i位有几个1
//            ll one = 0;
//            ll rc = (r + 1) / base;
//            ll rr = (r + 1) % base;
//            one += rc * (base >> 1) + max(0ll, rr - base / 2);
//
//            ll lc = l / base;
//            ll lr = l % base;
//            one -= lc * (base >> 1) + max(0ll, lr - base / 2);
//
//            if (one & 1) {
//                ans += (1ll << i);
//            }
//            base *= 2;
//        }
//        cout << ans << "\n";
//    }
//    return 0;
//}

// 写法二
//int main() {
//    ll T;
//    cin >> T;
//    while (T--) {
//        ll l, r;
//        cin >> l >> r;
//        ll ans = 0;
//        ll base = 2;
//        for (int i = 0; i < 62; i++) {
//            // 计算第i位有几个1
//            ll one = 0;
//            ll rc = (r + 1) / (1ll << (i + 1));
//            ll rr = (r + 1) % (1ll << (i + 1));
//            one += rc * (1ll << i) + max(0ll, rr - (1ll << i));
//
//            ll lc = l / (1ll << (i + 1));
//            ll lr = l % (1ll << (i + 1));
//            one -= lc * (1ll << i) + max(0ll, lr - (1ll << i));
//
//            if (one & 1) {
//                ans += (1ll << i);
//            }
//            base *= 2;
//        }
//        cout << ans << "\n";
//    }
//    return 0;
//}


// 写法三
//ll  cal(ll x, int i) {
//    // 为什么要加1?
//    ll c = (x + 1) / (1ll << (i + 1));
//    ll r = (x + 1) % (1ll << (i + 1));
//    // 第i位的1的数目
//    return c * (1ll << i) + max(0ll, r - (1ll << i));
//}
//
//int main() {
//    ll T;
//    cin >> T;
//    while (T--) {
//        ll l, r;
//        cin >> l >> r;
//        ll ans = 0;
//        for (int i = 0; i < 62; i++) {
//            // 计算第i位有几个1
//            ll one = 0;
//            one += cal(r, i);
//            one -= cal(l - 1, i);
//            if (one & 1) {
//                ans += (1ll << i);
//            }
//        }
//        cout << ans << "\n";
//    }
//    return 0;
//}

// 写法五
ll cal(ll x) {
    x++;
    if (x % 4 == 0) {
        return 0;
    } else if (x % 4 == 1) {
        return x;
    } else if (x % 4 == 2) {
        return 1;
    } else {
        return x + 1;
    }
}

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll l, r;
        cin >> l >> r;
        ll ans = cal(r) ^ cal(l - 1);
        cout << ans << "\n";
    }
    return 0;
}