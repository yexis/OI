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
    // C++打印doubl类型小数时，设置精度
    cout << fixed << setprecision(10);
    // 或者在打印的时候使用
    // 默认保留小数点后6位有效数字
    // printf("%lf\n", ans);
    // 还可以自定义
    // printf("%20lf\n", ans);

    double x, y, t;
    double a, b, c;
    cin >> x >> y >> t;
    cin >> a >> b >> c;
    if (x == 100) {
        printf("%lf\n", 0);
        return 0;
    }

    if (x <= t) {
        // 超级充电
        printf("%lf\n", (100 - x) / c);
    } else {
        // x > t
        double ans = min((100 - x) / b, (x - t) / y + (100 - t) / c);
        printf("%lf\n", ans);
    }
    return 0;
}