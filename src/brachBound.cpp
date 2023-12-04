#include <bits/stdc++.h>

using namespace std;

struct Item {
    int w, v, id;
};

struct Node {
    int ne, totW, totV;
    double upV;

    bool operator < (const Node &T) const {
        return upV < T.upV;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Item> g(n);

    for(int i = 0; i < n; i++) cin >> g[i].w;
    for(int i = 0; i < n; i++) cin >> g[i].v, g[i].id = i;

    ranges::sort(g, [](const Item &a, const Item &b) {
        return 1.0 * a.v / a.w > 1.0 * b.v / b.w;
    });

    auto bound = [&](int x, int curW, int curV) {
        int Wleft = m - curW;
        double upv = curV;

        while(x < n && g[x].w <= Wleft) {
            Wleft -= g[x].w;
            upv += g[x].v;
            x ++;
        }

        if(x < n) {
            upv += (1.0 * g[x].v / g[x].w) * Wleft;
        }

        return upv;
    };

    auto bfs = [&] {
        Node r = {0, 0, 0,bound(0, 0, 0)};
        priority_queue<Node> q;
        q.push(r);

        int ans = 0;
        while(q.top().upV > ans) {
            auto t = q.top();
            q.pop();

            if(t.ne == n) {
                ans = max(ans, t.totV);
            } else {
                Node t2 = t;
                if(t.totW + g[t.ne].w <= m) {
                    t.upV = bound(t.ne, t.totW, t.totV);
                    if(t.upV > ans) {
                        t.totV += g[t.ne].v;
                        t.totW += g[t.ne].w;
                        t.ne ++;
                        q.push(t);
                    }
                }
                t2.upV = (t2.ne + 1, t2.totW, t2.totV);
                if(t.upV > ans ) {
                    t2.ne ++;
                    q.push(t2);
                }
            }
        }
        return ans;
    };

    cout << bfs() << '\n';

    return 0;
}