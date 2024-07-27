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

// 横：1 3 8 0
// 纵：8 0 2 5
// 横 + 纵：8 0
const int mod = 1e9 + 7;
ll power(ll x, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    ll row = power(4, n);
    ll col = power(4, n / 2);
    if (n & 1) {
        col *= 2;
        col %= mod;
    }

    ll rep = power(2, n / 2);
    if (n & 1) {
        rep *= 2;
        rep %= mod;
    }
    cout << (row + col - rep + mod) % mod << "\n";
    return 0;
}