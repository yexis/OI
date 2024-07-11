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
    int T;
    cin >> T;
    while (T--) {
        ll a1, b1, c1;
        ll a2, b2, c2;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        __int128 a = a1 * b2;
        __int128 b = a2 + b1 * b2;
        __int128 c = b2 * c1 + c2;
        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                    cout << "INF" << "\n";
                    continue;
                } else {
                    // c != 0
                    cout << 0 << "\n";
                    continue;
                }
            } else {
                // a == 0 && b != 0
            }
        } else {
            __int128 delta = b * b - 4 * a * c;
            if (delta > 0) {
                cout << 2 << "\n";
                continue;
            } else if (delta == 0) {
                cout << 1 << "\n";
                continue;
            }
            cout << 0 << "\n";
        }
    }

    return 0;
}