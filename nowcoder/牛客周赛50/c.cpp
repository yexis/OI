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

int cal(int x, int y, int op) {
    if (op == 0) {
        return x + y;
    } else {
        return x * y;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    // + +
    ans = max(ans, cal(cal(a, b, 0), c, 0));
    // * *
    ans = max(ans, cal(cal(a, b, 1), c, 1));

    // + *
    ans = max(ans, cal(cal(a, b, 0), c, 1));
    ans = max(ans, cal(a, cal(b, c, 1), 0));

    // * +
    ans = max(ans, cal(cal(a, b, 1), c, 0));
    ans = max(ans, cal(a, cal(b, c, 0), 1));
    cout << ans << '\n';
    return 0;
}