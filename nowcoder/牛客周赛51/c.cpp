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

int main() {
    double x, y, t;
    double a, b, c;
    cin >> x >> y >> t;
    cin >> a >> b >> c;
    if (x == 100) {
        cout << 0 << "\n";
        return 0;
    }

    if (x <= t) {
        // 超级充电
        cout << (100.0 - x) / c << "\n";
    } else {
        // x > t
        double ans = (100.0 - x) / b;
        double i = 0;
        while (x > t) {
            if (x - y > t) {
                x -= y;
                i += 1.0;
                continue;
            }
            // x - y <= t
            i += (x - t) / y;
            x = t;
        }
        ans = min(ans, i + (100.0 - x) / c);
        cout << ans << "\n";
    }
    return 0;
}