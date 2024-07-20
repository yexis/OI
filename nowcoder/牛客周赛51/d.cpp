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
    // 打印double类型小数时，设置精度
    cout << fixed << setprecision(10);

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
        cout << (100 - x) / c << "\n";
    } else {
        // x > t
        double ans = min((100 - x) / b, (x - t) / y + (100 - t) / c);
        cout << ans << "\n";
    }
    return 0;
}