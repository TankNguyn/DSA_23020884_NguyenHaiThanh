#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>

using namespace std;

class Prim {
private:

    class edge {
    public:
        int vert1, vert2, weight;
        edge(int v1, int v2, int w) : vert1(v1), vert2(v2), weight(w) {}
    };
    
    int numberVert, numberEdge;
    vector<pair<int, int>> adj[1000];
    bool used[1000];
    int parent[1000], minWeightToVert[1000];

public:
    void input() {
        cin >> numberVert >> numberEdge;
        for (int i = 0; i < numberEdge; ++i) {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            adj[v1].emplace_back(v2, w);
            adj[v2].emplace_back(v1, w);
        }
        for (int i = 0; i < numberVert; ++i) used[i] = false;
        for (int i = 0; i < numberVert; ++i) minWeightToVert[i] = INT_MAX;

    }

    void runPrim(int start) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        vector<edge> mst;

        int sumWeight = 0;
        Q.push({0, start});

        while (!Q.empty()) {
            pair<int, int> top = Q.top();
            Q.pop();
            
            if (used[top.second]) continue;
            sumWeight += top.first;
            used[top.second] = true;
            if (start != top.second) mst.push_back({top.second, parent[top.second], top.first});

            for (auto it : adj[top.second]) {
                int v = it.first, w = it.second;
                if (!used[v] && w < minWeightToVert[v]) {
                    Q.push({w, v});
                    minWeightToVert[v] = w;
                    parent[v] = top.second;
                }
            }
        }
        cout << "Tong trong so cua MST: " << sumWeight << endl;
        cout << "Cac canh trong MST: " << endl;
        for (auto it : mst) {
            cout << it.vert1 << " " << it.vert2 << " " << it.weight << endl;
        }
    }

};

int main () {
    Prim prim;
    prim.input();
    prim.runPrim(0);
    return 0;
}