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
    string s;
    cin >> s;

    bool fg = (s[0] == '1');
    int x = 0;
    for (int i = 1; i < 32; i++) {
        x += (s[i] - '0') * (1 << (31 - i));
    }

    if (x == 0) {
        cout << "00000000000000000000000000000000" << '\n';
        return 0;
    }

    if (!fg) {
        cout << s << '\n';
        return 0;
    }

    if (fg) {
        x ^= -1;
        x++;
        cout << "x:" << x << '\n';
        string t = "1";
        for (int i = 30; i >= 0; i--) {
            if (x & (1 << i)) {
                t += '1';
            } else {
                t += '0';
            }
        }
        cout << t << '\n';
    }


    return 0;
}