#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int vertices;
    vector<int> *graph;

    public:

    Graph(int vertices) : vertices(vertices), graph(new vector<int>[vertices]) {}

    void add_edge(int source, int dest) {
        graph[source].push_back(dest);
        graph[dest].push_back(source);
    }

    void print_graph() {
        for(int i = 0; i < vertices; i++) {
            cout<<"\n Vertex "<<i<<": ";
            for(auto x: graph[i])
                cout<<" "<<x;
        }
    }
};

int main() {
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.print_graph();
    return 0;
}
