#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    private:
        int V;
        vector<int> *E;
        vector<int> *stats;
        // [0]kolor: 0-BIAŁY; 1-SZARY; 2-CZARNY
        // [1]odległość: -1-nieskończoność
        // [2]ojciec: 0-NULL
    public:
        Graph(int V, vector<int> *E);
        void printGraph();
        void BFS(int s);
        void printStats();
};

Graph::Graph(int V, vector<int> *E) {
    this->V = V;
    this->E = E;
    stats = new vector<int>[V+1];
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

void Graph::BFS(int s) {
    for (int i=1; i<V+1; i++) {
        stats[i].clear();
    }
    for (int i=1; i<V+1; i++) {
        stats[i].push_back(0);
        stats[i].push_back(-1);
        stats[i].push_back(0);
    }
    stats[s][0] = 1;
    stats[s][1] = 0;
    stats[s][2] = 0;
    queue<int> queue;
    queue.push(s);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int i=0; i<E[u].size(); i++) {
            if (stats[E[u][i]][0] == 0) {
                stats[E[u][i]][0] = 1;
                stats[E[u][i]][1] = stats[u][1] + 1;
                stats[E[u][i]][2] = u;
                queue.push(E[u][i]);
            }
        }
        stats[u][0] = 2;
    }
    return;
}

void Graph::printStats() {
    for (int i=1; i<V+1; i++) {
        cout << i << "-> kolor: " << stats[i][0] << " odległość: " << stats[i][1] << " ojciec: " << stats[i][2] << "\n";
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
    G.BFS(1);
    G.printStats();

    return 0;
}