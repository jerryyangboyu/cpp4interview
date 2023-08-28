#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;


class NotDAGException : public exception {
private:
    string message;
public:
    explicit NotDAGException(string msg) : message{std::move(msg)} {};

    [[nodiscard]] const char *what() const noexcept override {
        return message.c_str();
    }
};


class Graph {
private:
    size_t V;
    vector<list<int>> adj;

public:
    explicit Graph(size_t V);

    void addEdge(int v, int w);

    vector<int> topologicalSort();
};

Graph::Graph(size_t V) : V{V} {
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    if (v >= adj.size()) {
        adj.resize(v + 1);
        V = v;
    }
    adj[v].push_back(w);
}

vector<int> Graph::topologicalSort() {
    vector<int> in_degree(V, 0);
    for (int v = 0; v < V; ++v) {
        for (const int w: adj[v]) {
            in_degree[w]++;
        }
    }

    queue<int> q;
    for (int v = 0; v < V; ++v) {
        if (in_degree[v] == 0) {
            q.push(v);
        }
    }

    int i = 0;
    vector<int> order(V, 0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        order[i++] = v;
        for (const int w: adj[v]) {
            in_degree[w]--;
            if (in_degree[w] == 0) {
                q.push(w);
            }
        }
    }

    if (i != V) {
        ostringstream oss;
        oss << "Graph is not a DAG: ";
        copy(order.begin(), order.end(), ostream_iterator<int>(oss, " "));
        oss << endl;
        throw NotDAGException(oss.str());
    }

    return order;
}

int main() {
    Graph g(3);
//    g.addEdge(0, 1);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Function Call
    try {
        cout << "Following is a Topological Sort of the given graph \n";
        auto r = g.topologicalSort();
        copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    } catch (const NotDAGException &err) {
        cerr << err.what() << endl;
    }

    return 0;
}