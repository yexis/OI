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
    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    vector<int> Q(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> Q[i];
    }
    vector<int> RQ(N + 1);
    for (int i = 1; i <= N; i++) {
        RQ[Q[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        int p = RQ[i];
        int p1 = P[p];
        cout << Q[p1] << " ";
    }
    cout << "\n";
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    solve();
    return 0;
}