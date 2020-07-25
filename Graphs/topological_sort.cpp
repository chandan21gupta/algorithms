#include <iostream>
#include <stack>
#include "graph.h"

void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

void dfs_traversal(Node *nodes[], int n, int visited[], int index, stack<int> s) {
    Node *t = nodes[index]->next;
    while(t != NULL) {
        if(visited[t->data] != true) {
            visited[t->data] = true;
            dfs_traversal(nodes, n, visited, t->data, s);
        }
        t = t->next;
    }
    s.push(index);
}

void DFS(Node *nodes[], int n, int source) {
    stack <int> s;
    int visited[n];
    visited[source] = true;
    dfs_traversal(nodes, n, visited, source, s);

    for(int i = 0; i < n; i++) {
        if(visited[i] != true) {
            visited[i] = true;
            dfs_traversal(nodes, n, visited, i, s);
        }
    }
    showstack(s);
}


int main() {

    int n = 6;
    Node *nodes[n];
    initialise(nodes,n);
    addEdge(nodes,5,2);
    addEdge(nodes,5,0);
    addEdge(nodes,4,0);
    addEdge(nodes,4,1);
    addEdge(nodes,2,3);
    addEdge(nodes,3,1);
   
    DFS(nodes,n, 0);

    return 0;
}