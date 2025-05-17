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
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()
#define debug(x) cerr << (#x) << " = " << (x) << endl;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

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
    int n; cin >> n;
    if (n == 1 || n == 2) {
        cout << -1 << "\n";
        return;
    }
    cout << 1 << " ";
    for (int i = n; i > 1; i--) {
        cout << i << " ";
    }
    cout << "\n";
    
    // 2 : 0 -> 1 1
    // 3 : 1 -> 1 2 -> 2 1 3
    // 4 : 2 -> 0 2 -> 1 1 3 -> 3 2 1 4
    // 5 : 3 -> 0 3 -> x 1 4 -> x x 1 5
    // 6: 4 -> 0 4(2) -> 5(3) -> 6(4) -> 6
    // 6: 5 -> 0 5(2) -> 1 1 6(3)

//     vector<int> a = {1, 2, 3, 4, 5, 6};
//     do {
//         auto b = a;
//         while (b.size() > 1) {
//             vector<int> c;
//             for (int i = 1; i < b.size(); i++) {
//                 c.push_back(abs(b[i] - b[i - 1]));
//             }
//             b = c;
//         }
//         if (b[0] == 4) {
//             for (auto& e : a) cout << e << " "; cout << "\n";
//             cout << b[0] << "\n";            
//         }

//     } while (next_permutation(a.begin(), a.end()));
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









