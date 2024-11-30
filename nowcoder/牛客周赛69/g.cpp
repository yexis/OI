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
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

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

/*
 * 双数组选数，要么选a[i]，要么选b[i]
*/

// 从a中选k个数，从b中选n-k个数，求最大和
int select(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    // 先全部选b
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i];
    }
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        diff.emplace_back(a[i] - b[i]);
    }
    sort(diff.begin(), diff.end(), greater());
    for (int i = 0; i < k; i++) {
        sum += diff[i];
    }
    return sum;
}


// 从a中选k个数，从b中选n-k个数，求最大和
int select2(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    int sum = 0;
    vector<pair<int, int> > diff;
    for (int i = 0; i < n; i++) {
        diff.emplace_back(a[i] - b[i], i);
    }
    // 按照delta_i从大到小排序，前k个选a，后n-k个选b
    sort(diff.begin(), diff.end(), greater());
    for (int i = 0; i < n; i++) {
        auto [df, ii] = diff[i];
        if (i < k) {
            sum += b[ii] + df;
        } else {
            sum += b[ii];
        }
    }
    return sum;
}


void solve() {
    vector<int> a = {8, 4, 2, 3, 1, 6};
    vector<int> b = {7, 2, 3, 4, 5, 6};
    int k = 2;
    cout << select(a, b, k) << " " << select2(a, b, k) << "\n";
}

int main() {
    solve();
    return 0;
}




