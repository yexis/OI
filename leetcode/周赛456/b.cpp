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

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

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
    vector<Node*> child;
    set<int> st;
    Node() {
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
    
    void add(string s, int j) {
        int n = s.size();
        auto p = root;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (p->child[idx] == nullptr) {
                p->child[idx] = new Node();
            }
            p = p->child[idx];
            p->st.insert(j);
            // p->len = i + 1;
            // p->idx = j;
        }
    }
    
    void del(string& s) {
        int n = s.size();
        auto p = root;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            p = p->child[idx];
            p->cnt--;
        }
    }
    
    pii ask(string s, int j) {
        int n = s.size();
        auto p = root;
        pii res = pii(0, 0);
        auto& [a, b] = res;

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (p->child[idx] == nullptr)  {
                return res;
            }
            p = p->child[idx];
            if (p->st.count(j - 1)) {
                b = max(b, i + 1);        
            }
            if (p->st.count(j - 2)) {
                a = max(a, i + 1);        
            }
            
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        Trie tr;
        int n = words.size();

        vector<int> last2(n), last1(n);
        for (int j = 0; j < n; j++) {
            tr.add(words[j], j);
        }

        for (int i = 0; i < n; i++) {
            cout << last2[i] << "\n";
        }
        for (int i = 0; i < n; i++) {
            cout << last1[i] << "\n";
        }

        multiset<int> ms;
        for (int i = 1; i < n; i++) {
            ms.insert(last1[i]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) {
                ms.erase(ms.find(last1[i]));
            }
            if (i + 1 < n) {
                ms.erase(ms.find(last1[i + 1]));
            } 
            ms.insert(last2[i + 1]);
            
            res[i] = ms.empty() ? 0 : *ms.rbegin();

            if (i - 1 >= 0) {
                ms.insert(last1[i]);
            }
            if (i + 1 < n) {
                ms.insert(last1[i + 1]);
            } 
            ms.erase(ms.find(last2[i + 1]));
        }

        return res;
    }
};








