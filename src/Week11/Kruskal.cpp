#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class edge {
public:
    int vert1, vert2, weight;
    edge(int v1, int v2, int w) : vert1(v1), vert2(v2), weight(w) {}
};

bool cmp(const edge& a, const edge& b) { return a.weight < b.weight; }

class Kruskal {
private:
    int number_vert, number_edge;             
    vector<edge> edges;                       
    vector<int> parent, size;                 

    void makeSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i; 
    }

    int find(int vert) {
        if (vert == parent[vert]) return vert;
        return parent[vert] = find(parent[vert]); 
    }

    bool unite(int vert1, int vert2) {
        int root1 = find(vert1);
        int root2 = find(vert2);
        if (root1 == root2) return false; 

        if (size[root1] < size[root2]) swap(root1, root2);
        parent[root2] = root1;
        size[root1] += size[root2];
        return true;
    }
public:
    void input() {
        cin >> number_vert >> number_edge;
        for (int i = 0; i < number_edge; ++i) {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            edges.emplace_back(v1, v2, w);
        }
    }

    void runKruskal() {
        makeSet(number_vert); 

        sort(edges.begin(), edges.end(), cmp);

        vector<edge> mst;     
        int weight_mst = 0;   

        for (const auto& edge : edges) {
            if (unite(edge.vert1, edge.vert2)) {
                mst.push_back(edge);
                weight_mst += edge.weight;
                if (mst.size() == number_vert - 1) break;
            }
        }

        if (mst.size() != number_vert - 1) cout << "Do thi khong lien thong!" << endl;
        else {
            cout << "Tong trong so cua MST: " << weight_mst << endl;
            cout << "Cac canh trong MST:" << endl;
            for (const auto& edge : mst) cout << edge.vert1 << " " << edge.vert2 << " " << edge.weight << endl;
        }
    }
};

int main() {
    Kruskal kruskal;
    kruskal.input();
    kruskal.runKruskal();
    return 0;
}
