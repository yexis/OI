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

/*
 * 
*/

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

void solve() {

}

int main() {
    int n, k;
    cin >> n >> k;
    if (k > n + 1) {
        cout << -1 << "\n";
        return 0;
    }

    if (k == 0) {
        if (n <= 2) {
            cout << -1 << "\n";
            return 0;
        }

        for (int i = 1; i <= n; i++) {
            cout << i << " " << i << " ";
        }
        cout << "\n";
        return 0;
    }

    if (k == 1) {
        if (n == 1) {
            cout << -1 << "\n";
            return 0;
        } else if (n == 2) {
            cout << 1 << " " << 1 << " " << 2 << " " << 2 << "\n";
            return 0;
        }
    }

    // k == n + 1
    if (k == n + 1) {
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        return 0;
    }

    // k > 0 && k < n + 1
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    k--;

    int no = n - k;
    cout << no << "\n";
    if (k == 0) {
        a.insert(a.begin(), 1);
        for (int i = 2; i <= n; i++) {
            a.push_back(i);
        }
        for (auto& e : a) cout << e << " "; cout << "\n";
        return 0;
    }

    vector<int> h, g;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (int i = 0; i < no; i++) {
        int x = (2 + i) % (n + 1);
        if (x == 0) x++;
        h.push_back(x);
        st.erase(x);
    }

    for (auto& e : st) h.push_back(e);
    for (auto& e : h) a.push_back(e);
    for (auto& e : a) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}