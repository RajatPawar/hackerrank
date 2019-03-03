#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    struct ListNode *next;
    int dest;
};

struct AdjList {
    struct ListNode *head;
};


class Graph {
    int vertices;
    struct AdjList *array;
    
    public:

    Graph(int vertices): vertices(vertices) {
        array = new struct AdjList[vertices];
        for(int i = 0; i < vertices; i++) {
            array[i].head = NULL;
        }
    }

    void edge(int src, int dest) {
        struct ListNode *temp = new struct ListNode;
        temp->next = array[src].head;
        temp->dest = dest;
        array[src].head = temp;
    }

    void print() {
        for(int i = 0; i < vertices; i++) {
            cout<<endl<<"Node "<<i<<": ";
            struct ListNode *itr = array[i].head;
            while(itr) {
                cout<<itr->dest<<" ";
                itr = itr->next;
            }
        }
    }

    bool find_route(int src, int dest) {
        queue<int> bfs;
        bfs.push(src);
        struct ListNode *itr = NULL;

        while(!bfs.empty()) {
            int node = bfs.front();
            bfs.pop();

            if(node == dest) return true;

            itr = array[node].head;
            while(itr) {
                bfs.push(itr->dest);
                itr = itr->next;
            }
            
        }

        return false;
    }
};

int main() {
    Graph g(5);
    g.edge(0, 1);
    g.edge(3, 4);
    g.edge(4, 1);
    g.edge(2, 4);
    g.print();

    cout<<endl<<"Route from 0 to 4: "<<g.find_route(0, 4);

    return 0;
}
