#include <map>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

class Graph {
private:
    map<int, list<int>> adj;
public:
    void addEdge(int v, int w);
    void DFS(int v, const function<void(int)> &handler, map<int, bool> &visited);
    void DFS_iterative(int v, const function<void(int)> &handler);
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}


void Graph::DFS(int v, const function<void(int)> &handler, map<int, bool> &visited) {
    visited[v] = true;
    handler(v);
    for (const auto w: adj[v]) {
        if (!visited[w]) {
            DFS(w, handler, visited);
        }
    }
}

void Graph::DFS_iterative(int v, const function<void(int)> &handler) {
    map<int, bool> visited;
    stack<int> s;
    s.push(v);
    while (!s.empty()) {
        v = s.top();
        s.pop();
        visited[v] = true;
        handler(v);
        for (const auto w: adj[v]) {
            if (!visited[w]) {
                s.push(w);
            }
        }
    }
}

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(8, 9);

    map<int, bool> visited;
    g.DFS(1, [](auto n) {cout << n << " ";}, visited);
    cout << endl;
    g.DFS_iterative(1, [](auto n) {cout << n << " ";});
}