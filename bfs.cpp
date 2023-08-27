#include <vector>
#include <list>
#include <iostream>
#include <queue>

using namespace std;

class Graph {
private:
    size_t V{0};
    vector<list<int>> adj;
public:
    explicit Graph(int V);

    void addEdge(int v, int w);

    void BFS(int v, const function<void(int)> &handler);
};

Graph::Graph(int V) {
    this->V = V;
    this->adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int v, const function<void(int)> &handler) {
    vector<int> visited(V, false);
    queue<int> q;

    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        handler(v);
        q.pop();

        for (const auto w: adj[v]) {
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(0, [](auto n) { cout << n << " "; });
}