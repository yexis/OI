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

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        int ans = 0;
        int ca = a / 3, ra = a % 3;
        int cb = b / 3, rb = b % 3;
        int cc = c / 3, rc = c % 3;
        ans = ca + cb + cc + min({ra, rb, rc});
        if (ca > 0 && ra == 0) ca--, ra = 3;
        if (cb > 0 && rb == 0) cb--, rb = 3;
        if (cc > 0 && rc == 0) cc--, rc = 3;
        ans = max(ans, ca + cb + cc + min({ra, rb, rc}));

        cout << ans << '\n';
    }
    return 0;
}