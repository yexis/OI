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

const int N = 1e6;
bool fg = false;
vector<int> prime;
bool not_prime[N + 1];

// 欧拉筛
void init() {
    for (int i = 2; i <= N; ++i) {
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        for (int p : prime) {
            if (i * p > N) break;
            not_prime[i * p] = true;
            if (i % p == 0) {
                // i % p == 0
                // 换言之，i 之前被 p 筛过了
                // 由于 prime 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定会被 p 的倍数筛掉
                // 就不需要在这里先筛一次，所以这里直接 break 掉就好了
                break;
            }
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
        init();
    }
    cout << prime.size() << "\n";

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}