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
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 4e6;
vector<int> prime;
bool is_prime[N];
bool fg = false;

void init(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) is_prime[i] = true;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            if ((long long)i * i > n) continue;
            for (int j = i * i; j <= n; j += i)
                // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
                // 的倍数开始，提高了运行速度
                is_prime[j] = false;  // 是 i 的倍数的均不是素数
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] >= 3) {
        cout << 2 << "\n";
        return;
    }

    unordered_set<int> yet;
    for (auto& e : a) yet.insert(e);

    // a[0] = 2;
    for (auto& e : prime) {
        if (!yet.count(e)) {
            cout << e << "\n";
            return;
        }
    }
}

int main() {
    if (!fg) {
        init(N);
    }

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}