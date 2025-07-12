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

typedef long long ll;

__int128 sqrt_int128(__int128 x) {
    if (x < 0) return -1;
    __int128 l = 0, r = x;
    __int128 ans = -1;
    while (l <= r) {
        __int128 mid = l + (r - l) / 2;
        if (mid <= 0 || mid <= x / mid) {
            __int128 mid_sq = mid * mid;
            if (mid_sq == x) {
                return mid;
            } else if (mid_sq < x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            r = mid - 1;
        }
    }
    if (ans * ans == x) return ans;
    return -1;
}

ll find_d_max(ll N) {
    __int128 target = 4 * (__int128)N;
    ll left = 1, right = 2e6;
    ll res = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        __int128 mid_cubed = (__int128)mid * mid * mid;
        if (mid_cubed <= target) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    ll d_max = find_d_max(N);
    for (ll d = 1; d <= d_max; ++d) {
        __int128 d_cubed = (__int128)d * d * d;
        __int128 temp = 4 * (__int128)N - d_cubed;
        if (temp < 0) continue;
        __int128 D = (__int128)3 * d * temp;
        __int128 s = sqrt_int128(D);
        if (s == -1) continue;
        __int128 numerator = s - (__int128)3 * d * d;
        if (numerator <= 0) continue;
        ll denominator = 6 * d;
        if (numerator % denominator != 0) continue;
        __int128 y = numerator / denominator;
        if (y <= 0) continue;
        __int128 x = y + d;
        __int128 x3 = x * x * x;
        __int128 y3 = y * y * y;
        if (x3 - y3 == (__int128)N) {
            cout << (ll)x << " " << (ll)y << endl;
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}