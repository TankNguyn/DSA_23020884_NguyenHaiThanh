#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Dijkstra {
private:
    int number_vert, number_edge, start, end;
    vector<pair<int, int>> adj[1000];
    int pre[1000];

public:
    void input() {
        cin >> number_vert >> number_edge >> start;

        for (int i = 0; i < number_vert; ++i) pre[i] = -1;
        for (int i = 0; i < number_edge; ++i) {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].emplace_back(w, y);
        }
    }

    void runDijkstra() {
        vector<long long> d(number_vert, 1e9);
        d[start] = 0;
        pre[start] = start;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.push({0, start});

        while (!Q.empty()) {
            pair<int, int> top = Q.top();
            Q.pop();
            int u = top.second;
            int len = top.first;

            if (len > d[u]) continue;

            for (auto it: adj[u]) {
                int v = it.second;
                int w = it.first;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pre[v] = u;
                    Q.push({d[v], v});
                }
            }
        }
        for (int i = 0; i < number_vert; ++i) cout << d[i] << " ";
        cout << endl;
    }

    void roadmap(int end) {
        if (pre[end] == -1) {
            cout << "No path from " << start << " to " << end << endl;
            return;
        }
        if (end == start) {
            cout << start << " ";
            return;
        }
        roadmap(pre[end]);
        cout << end << " ";
    }
};

int main() {
    Dijkstra dijkstra;
    dijkstra.input();
    dijkstra.runDijkstra();
    int end; cin >> end;
    dijkstra.roadmap(end);
    return 0;
}