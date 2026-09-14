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

/*
 * 二叉Trie树
 * 二叉前缀树
*/
int M; // 题目相关

struct Node {
    int val;
    vector<Node*> child;
    Node() {
        val = 0;
        child.resize(2);
    }
};
struct Trie {
    Node* root;
    Trie() {
        root = new Node();
    }
    void add(vector<int>& masks) {
        int n = masks.size();
        auto p = root;
        for (int i = 0; i < n; i++) {
            int bit = masks[i];
            if (p->child[bit] == nullptr) {
                p->child[bit] = new Node();
            }
            p = p->child[bit];
            p->val++;
        }
    }
    void del(vector<int>& masks) {
        int n = masks.size();
        auto p = root;
        for (int i = 0; i < n; i++) {
            int bit = masks[i];
            p = p->child[bit];
            p->val--;
        }
    }

    bool check(vector<int>& masks) {
        int n = masks.size(), rem = M;
        
        auto p = root;
        for (int i = 0; i < n; i++) {
            int corr = (p->child[1] != nullptr ? p->child[1]->val : 0);
            int bit = masks[i];
            
            if (corr <= rem) { // 已晋级 + 正确 <= rem
                // 当前masks正确，直接晋级
                if (bit == 1) return true;
                rem -= corr;
                // 错误者不确定，继续深入
                p = p->child[0];
                if (p == nullptr) return false;
            } else { // 已晋级 + 正确 > rem
                // 直接淘汰
                if (bit == 0) return false;
                
                // rem不变

                // 回答错的被淘汰，回答对的人继续深入
                p = p->child[1];
                if (p == nullptr) return false; 
            }
        }
        return false;
    }
};

void solve() {
    int n, m, K; cin >> n >> m >> K; 
    M = m;

    string T; cin >> T;
    vector<string> S(n); for (int i = 0; i < n; i++) cin >> S[i];

    vector<int> bits[n]; for (int i = 0; i < n; i++) bits[i].resize(K);
    for (int i = 0; i < n; i++) for (int k = 0; k < K; k++) {
        if (S[i][k] == T[k]) bits[i][k] = 1;
        else bits[i][k] = 0;
    }

    // 二叉Trie
    Trie trie; for (int i = 0; i < n; i++) trie.add(bits[i]);

    int Q; cin >> Q;
    while (Q--) {
        int i, j; cin >> i >> j; --i, --j;
        trie.del(bits[i]);
        bits[i][j] ^= 1;
        S[i][j] = (S[i][j] == 'x' ? 'o' : 'x');
        trie.add(bits[i]);
        
        bool fg = trie.check(bits[i]); 
        if (fg) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);

    int T = 1; 
    // cin >> T;
    while (T--) {
    	solve();
    }
    return 0;
}

