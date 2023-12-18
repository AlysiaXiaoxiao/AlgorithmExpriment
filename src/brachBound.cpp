#include <bits/stdc++.h>

using namespace std;

struct Item {
    int w, v, id;
};

struct Node {
    int ne, totW, totV;
    double upV;
    vector<int> items; //���ڴ��ѡ����Щ��Ʒ

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
    
    //�����Ͻ�
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
        Node r = {0, 0, 0, bound(0, 0, 0), {}};
        priority_queue<Node> q;
        q.push(r);

        Node bestNode;  
        int ans = 0;
        while(q.top().upV > ans) {
            auto t = q.top();
            q.pop();

            if(t.ne == n) {
                if(t.totV > ans) {
                    ans = t.totV;
                    bestNode = t; 
                }
            } else {
                Node t2 = t;
                if(t.totW + g[t.ne].w <= m) {
                    t.upV = bound(t.ne, t.totW, t.totV);//ѡȡ��ǰ��Ʒ
                    if(t.upV > ans) {
                        t.totV += g[t.ne].v;
                        t.totW += g[t.ne].w;
                        t.items.push_back(g[t.ne].id);  
                        t.ne ++;
                        q.push(t);
                    }
                }
                t2.upV = (t2.ne + 1, t2.totW, t2.totV);//��ѡ��ǰ��Ʒ
                if(t.upV > ans ) {
                    t2.ne ++;
                    q.push(t2);
                }
            }
        }

        cout << "��֧�޽���01��������\n\n";
        cout << "��Ʒ������" << n << ' ' << "����������" << m << "\n\n";

        for(int i = 0; i < n; i ++) {
            cout << "��Ʒ" << i + 1 << "�������ֵ��" << g[i].w << ' ' << g[i].v << '\n';
        }
        cout << '\n';

        vector<bool> selected(n);
        for(int id : bestNode.items) {
            selected[id] = true;
        }

        cout << "����ֵΪ��" << ans << '\n';
        
        cout << "������Ϊ��";
        for(auto c : selected) cout << c << ' ';
        cout << '\n';
    };

    bfs();

    return 0;
}
