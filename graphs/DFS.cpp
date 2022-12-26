#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    private:
        int V;
        vector<int> *E;
        vector<int> *stats;
        int time;
        // [0]kolor: 0-BIAŁY; 1-SZARY; 2-CZARNY
        // [1]ojciec: 0-NULL
        // [2]czas początkowy
        // [3]czas końcowy
        void DFSVisit(int u);
    public:
        Graph(int V, vector<int> *E);
        void printGraph();
        void DFS();
        void printStats();
};

Graph::Graph(int V, vector<int> *E) {
    this->V = V;
    this->E = E;
    this->stats = new vector<int>[V+1];
}

void Graph::printGraph() {
    for (int i=1; i<V+1; i++) {
        cout << i << "->";
        for (int j=0; j<E[i].size(); j++) {
            cout << E[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

void Graph::DFSVisit(int u) {
    time++;
    stats[u].push_back(time);
    stats[u][0] = 1;
    for (int i=0; i<E[u].size(); i++) {
        if (stats[E[u][i]][0] == 0) {
            stats[E[u][i]][1] = u;
            DFSVisit(E[u][i]);
        }
    }
    stats[u][0] = 2;
    time++;
    stats[u].push_back(time);
    return;
}

void Graph::DFS() {
    for (int i=1; i<V+1; i++) {
        stats[i].push_back(0);
        stats[i].push_back(0);
    }
    time = 0;
    for (int i=1; i<V+1; i++) {
        if (stats[i][0] == 0) {
            DFSVisit(i);
        }
    }
    return;
}

void Graph::printStats() {
    for (int i=1; i<V+1; i++) {
        cout << i << "-> kolor: " << stats[i][0] << " ojciec: " << stats[i][1] << " czas początkowy: " << stats[i][2] << " czas końcowy: " << stats[i][3] << "\n";
    }
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> *E = new vector<int>[n+1];

    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    Graph G = Graph(n, E);
    G.printGraph();
    G.DFS();
    G.printStats();

    return 0;
}