#include <iostream>
#include "graph.h"
#include <queue>

void BFS(Node *nodes[], int n, int visited[], queue<int> q) {
    while(q.size() > 0) {
        cout << q.front() << " ";
        Node *t = nodes[q.front()]->next;
        q.pop();
        while(t != NULL) {
            if(visited[t->data] == 0) {
                visited[t->data] = 1;
                q.push(t->data);
            }
            t = t->next;
        }
    }
}

void bfs_traversal(Node *nodes[], int n, int start) {
    int visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    queue <int> q;
    q.push(start);
    visited[start] = 1;
    BFS(nodes,n,visited,q);
    for(int i = 0; i < n; i++) {
        int data = nodes[i]->data;
        if(visited[data] == 0) {
            visited[data] = 1;
            q.push(data);
            BFS(nodes,n,visited,q);
            cout << endl;
        }
    }
    cout << endl;
}

int main() {

    int n = 4;
    Node *nodes[n];
    initialise(nodes,n);
    addEdge(nodes,0,1);
    addEdge(nodes,0,2);
    addEdge(nodes,1,2);
    addEdge(nodes,2,0);
    addEdge(nodes,2,3);
    addEdge(nodes,3,3);
   
    bfs_traversal(nodes,n,2);

    return 0;
}