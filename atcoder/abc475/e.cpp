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
#define debug(x) cout << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

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

const int dir[4][2] = {{-1, 0}, {1,  0}, {0,  -1}, {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const string YES = "YES";
const string NO = "NO";

ll mod_add(ll& x, ll y) { x += (mod + y); x %= mod; return x; }

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}
struct Node {
    int ch[2] = {0, 0};
    int sz = 0;
};

int main() {
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    string T;
    cin >> T;

    vector<string> S(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<Node> trie;
    trie.reserve(N * (K + 1) + 5);
    trie.emplace_back(); // root = 0

    auto newNode = [&]() -> int {
        trie.emplace_back();
        return (int)trie.size() - 1;
    };

    vector<vector<int>> bits(N, vector<int>(K));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            bits[i][j] = (S[i][j] != T[j]);
        }
    }

    auto insert = [&](int id) {
        int v = 0;
        trie[v].sz++;

        for (int j = 0; j < K; j++) {
            int b = bits[id][j];

            if (trie[v].ch[b] == 0) {
                trie[v].ch[b] = newNode();
            }

            v = trie[v].ch[b];
            trie[v].sz++;
        }
    };

    auto erase = [&](int id) {
        int v = 0;
        trie[v].sz--;

        for (int j = 0; j < K; j++) {
            int b = bits[id][j];
            v = trie[v].ch[b];
            trie[v].sz--;
        }
    };

    for (int i = 0; i < N; i++) {
        insert(i);
    }

    auto check = [&](int id) -> bool {
        int v = 0;
        int rem = M;

        for (int j = 0; j < K; j++) {
            int correctChild = trie[v].ch[0];
            int correctCount = correctChild ? trie[correctChild].sz : 0;

            int b = bits[id][j];

            if (correctCount <= rem) {
                // 正确者晋级
                if (b == 0) return true;

                rem -= correctCount;

                // 错误者继续 undecided
                v = trie[v].ch[1];
                if (v == 0) return false;
            } else {
                // 错误者淘汰
                if (b == 1) return false;

                // 正确者继续 undecided
                v = trie[v].ch[0];
                if (v == 0) return false;
            }
        }

        return false;
    };

    int Q;
    cin >> Q;

    while (Q--) {
        int i, j;
        cin >> i >> j;
        --i;
        --j;

        erase(i);

        bits[i][j] ^= 1;
        S[i][j] = (bits[i][j] ? (T[j] == 'o' ? 'x' : 'o') : T[j]);

        insert(i);

        cout << (check(i) ? "Yes\n" : "No\n");
    }

    return 0;
}