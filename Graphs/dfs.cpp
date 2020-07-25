#include <iostream>
#include "graph.h"

void dfs_traversal(Node *nodes[], int n, int visited[], int index) {
    cout << index << " ";
    Node *t = nodes[index]->next;
    while(t != NULL) {
        if(visited[t->data] != true) {
            visited[t->data] = true;
            dfs_traversal(nodes, n, visited, t->data);
        }
        t = t->next;
    }
}

void DFS(Node *nodes[], int n, int source) {
    int visited[n];
    visited[source] = true;
    dfs_traversal(nodes, n, visited, source);

    for(int i = 0; i < n; i++) {
        if(visited[i] != true) {
            visited[i] = true;
            dfs_traversal(nodes, n, visited, i);
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
   
    DFS(nodes,n, 2);

    return 0;
}