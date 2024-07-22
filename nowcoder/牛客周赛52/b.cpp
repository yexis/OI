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
    int T;
    cin >> T;
    while (T--) {
        ll a, b, n;
        cin >> a >> b >> n;
        ll s = 1ll * a * 2 + 1ll * b * 3;
        if (s < 2ll * n) {
            cout << "NO" << "\n";
            continue;
        }
        if (1ll * a * 2 >= 2ll * n) {
            cout << "YES" << "\n";
            continue;
        }

        // b even
        if (b & 1) b--;
        ll sb = b * 3ll;

        ll com = 2 * n;
        while (com) {
            if (com % 3 == 0 && (com / 3) % 2 == 0) {
                break;
            }
            com--;
        }
        sb = min(sb, com);
        ll sa = 2ll * n - sb;

        if (2ll * a >= sa) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }


    return 0;
}