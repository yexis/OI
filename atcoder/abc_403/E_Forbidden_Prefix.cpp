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
 * https://atcoder.jp/contests/abc403/tasks/abc403_e
 * 字典树
 * 带回溯字典树
*/

class Node {
    public:
        int sub;
        int val;
        vector<Node*> child;
    
        Node() {
            sub = 0;
            val = 0;
            child = vector<Node*>(26);
        }
    };
    
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        
        void add(string& s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr) {
                    p->child[idx] = new Node();
                }
                p = p->child[idx];
                p->sub += 1;
            }
            p->val += 1;
        }
        
        // x是几个y的前缀
        int ask(string& s) {
            int n = s.size();
            auto p = root;
            int ans = 0;
            vector<Node*> pr;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr)  {
                    return 0;
                }
                p = p->child[idx];
                pr.emplace_back(p);
                if (p->sub == 0) {
                    return 0;
                }
            }

            ans = p->sub;
            while (pr.size()) {
                Node* no = pr.back();
                no->sub -= ans;
                pr.pop_back();
            }
            return ans;
        }

        // x中是否存在y的前缀
        int ask2(string& s) {
            int n = s.size();
            auto p = root;
            for (int i = 0; i < n; i++) {
                int idx = s[i] - 'a';
                if (p->child[idx] == nullptr)  {
                    return 0;
                }
                p = p->child[idx];
                if (p->val) {
                    return 1;
                }
            }
            return 0;
        }
    };

void solve() {
    int q; cin >> q;

    int cur = 0;
    Trie tr1, tr2;
    while (q--) {
        int t; cin >> t;
        string s; cin >> s;
        if (t == 1) {
            int ans = tr2.ask(s);
            cur -= ans;
            tr1.add(s);
        } else if (t == 2) {
            int ans = tr1.ask2(s);
            if (ans == 0) {
                cur++;
                tr2.add(s);
            }
        }
        cout << cur << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}









