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

unordered_map<ll, ll> dp;
ll dfs(ll x) {
    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }
    if (dp.count(x)) {
        return dp[x];
    }
    ll ans = 0;
    ans = 1 + 2 * dfs(x / 2);
    return dp[x] = ans;
}
int main() {
    ll h;
    cin >> h;
    ll ans = dfs(h);
    cout << ans << "\n";
    return 0;
}