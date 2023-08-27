#include <list>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Graph {
private:
    size_t V;
    vector<list<int>> adj;

public:
    explicit Graph(size_t V);

    void addEdge(int v, int w);

    void topologicalSortHelper(int v, stack<int> &result, vector<bool> &visited);

    void topologicalSort();
};

Graph::Graph(size_t V) : V{V} {
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::topologicalSortHelper(int v, stack<int> &result, vector<bool> &visited) {
    visited[v] = true;

    for (const int w: adj[v]) {
        if (!visited[w]) {
            topologicalSortHelper(w, result, visited);
        }
    }

    result.push(v);
}

void Graph::topologicalSort() {
    stack<int> result;
    vector<bool> visited(V, false);

    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            topologicalSortHelper(i, result, visited);
        }
    }

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
}

// Driver Code
int main() {
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given "
            "graph \n";

    // Function Call
    g.topologicalSort();

    return 0;
}
