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
 * 
*/

class Node {
    public:
        // 节点下标，唯一性标记
        // 一般依赖节点唯一性的时候会用到
        // 比如使用set记录时
        int idx;
        // 出现次数
        int cnt;
        // 节点深度，即前缀长度
        int len;
        
        int ii;

        vector<Node*> child;
        Node() {
            ii = 0;
            idx = 0;
            cnt = 0;
            len = 0;
            child = vector<Node*>(26);
        }
    };
    
    class Trie {
    public:
        int cnt;
        Node* root;
        Trie() : cnt(0) {
            root = new Node();
            root->idx = ++cnt;
        }
        
        void add(string s, int ii, int c) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                    p->child[idx]->idx = ++cnt;
                }
                p = p->child[idx];
                p->len = i + 1;
            }
            p->cnt += c;
            p->ii = ii;
        }
      
        int ask(string s) {
            int n = s.size();
            auto p = root;
            
            Node* q;
            int ans = -1;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr)  {
                    break;
                }
                p = p->child[idx];
                if (p->cnt > 0) {
                    q = p;
                    ans = p->ii;
                }
            }

            if (q != nullptr) q->cnt--;
            return ans;
        }
    };

void solve() {
    int n, q; cin >> n >> q;
    vector<string> S(n);
    vector<int> C(n);
    for (int i = 0; i < n; i++) cin >> S[i] >> C[i];

    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.add(S[i], i + 1, C[i]);
    }

    while (q--) {
        string t; cin >> t;
        int tmp = trie.ask(t);
        if (tmp == -1) {
            cout << 0 << "\n";
        } else {
            cout << tmp << "\n";
        }
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









