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
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
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
 * 
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    ll sum = 0;
    priority_queue<int> pq1;
    vector<ll> L(n, LLINF);
    for (int i = 0; i < k; i++) {
        pq1.emplace(a[i]);
        sum += a[i];
    }
    L[k - 1] = sum;
    for (int i = k; i < n; i++) {
        if (a[i] < pq1.top()) {
            sum -= pq1.top();
            sum += a[i];
            pq1.pop();
            pq1.push(a[i]);
        }
        L[i] = sum;
    }
    
    sum = 0;
    priority_queue<int> pq2;
    vector<ll> R(n, LLINF);
    for (int i = n - 1; i >= n - k; i--) {
        pq2.emplace(b[i]);
        sum += b[i];
    }
    R[n - k] = sum;
    for (int i = n - k - 1; i >= 0; i--) {
        if (b[i] < pq2.top()) {
            sum -= pq2.top();
            sum += b[i];
            pq2.pop();
            pq2.push(b[i]);
        }
        R[i] = sum;
    }

    ll ans = LLINF;
    for (int i = k - 1; i < n - k; i++) {
        ans = min(ans, L[i] + R[i + 1]);
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









