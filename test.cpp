#include <iostream>
using namespace std;

struct Node {
    int v;
    int v2;
    Node operator+(const Node& b) {
        Node res;
        Node a = *this;
        res.v = a.v + b.v;
        return res;
    }
};
Node e() {
    return Node(0);
}
Node tr[1000];

int main() {
    Node a(1, 2);
    cout << a.v << " " << a.v2 << "\n";
    Node b(2);
    Node c = a + b;
    cout << c.v << "\n";
    return 0;
}
