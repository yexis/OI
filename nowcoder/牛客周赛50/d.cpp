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


// 方法一
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO" << "\n";
            continue;
        }

        // -b1 / a1
        // -b2 / a2
        ll d = sqrt(delta);
        if (d * d != delta) {
            cout << "NO" << "\n";
            continue;
        }
        ll a1 = 2 * a;
        ll b1 = -b + d;
        ll a2 = 2 * a;
        ll b2 = -b - d;

        ll g1 = gcd(a1, b1);
        ll g2 = gcd(a2, b2);

        a1 /= g1;
        b1 /= g1;
        a2 /= g2;
        b2 /= g2;

        if (a % abs(a1 * a2)) {
            cout << "NO" << "\n";
            continue;
        }
        ll z = a / a1 / a2;
        a1 *= z;
        b1 *= z;
        cout << -a1 << " " << b1 << " " << -a2 << " " << b2 << "\n";
    }
    return 0;
}


// 方法二
//int main() {
//
//    auto cal = [&](int a1, int b1, int a2, int b2, int b) -> bool {
//        if (a1 * b2 + a2 * b1 == b) {
//            cout << a1 << " " << b1 << " " << a2 << " " << b2 << '\n';
//            return true;
//        }
//        return false;
//    };
//    int T;
//    cin >> T;
//    for (int i = 0; i < T; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//
//        vector<int> aa, cc;
//        int mx = max(abs(a), abs(c));
//        for (int d = 1; d * d <= mx; d++) {
//            if (a % d == 0) {
//                aa.emplace_back(d);
//                aa.emplace_back(a / d);
//            }
//            if (c % d == 0) {
//                cc.emplace_back(d);
//                cc.emplace_back(c / d);
//            }
//        }
//        if (c == 0) cc = {0};
//
//        bool find = false;
//        for (int j = 0; j < aa.size(); j++) {
//            int a1 = aa[j];
//            int a2 = a / a1;
//            if (c == 0) {
//                if (b % a1 == 0) {
//                    cout << a1 << " " << 0 << " " << a2 << " " << b / a1 << '\n';
//                    find = true;
//                } else if (b % a2 == 0) {
//                    cout << a1 << " " << b % a2 << " " << a2 << " " << 0 << '\n';
//                    find = true;
//                }
//                break;
//            }
//            // a != 0 && c != 0
//            for (int k = 0; k < cc.size(); k++) {
//                int c1 = cc[k];
//                int c2 = c / c1;
//
//                int e, f, s, t;
//                e = a1, f = c1, s = a2, t = c2;
//                find = cal(e, f, s, t, b);
//                if (find) {
//                    break;
//                }
//
//                e = a1, f = -c1, s = a2, t = -c2;
//                find = cal(e, f, s, t, b);
//                if (find) {
//                    break;
//                }
//
//                e = -a1, f = c1, s = -a2, t = c2;
//                find = cal(e, f, s, t, b);
//                if (find) {
//                    break;
//                }
//
//                e = -a1, f = -c1, s = -a2, t = -c2;
//                find = cal(e, f, s, t, b);
//                if (find) {
//                    break;
//                }
//
//            }
//            if (find) break;
//        }
//
//        if (not find) {
//            cout << "NO" << '\n';
//        }
//    }
//    return 0;
//}