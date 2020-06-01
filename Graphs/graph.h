#include <iostream>

using namespace std;

class Node {

    public:
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void initialise(Node *graph[], int n) {
    for(int i = 0; i < n; i++) {
        graph[i] = new Node(i);
        graph[i]->next = NULL;
    }
}

void addEdge(Node *graph[], int x, int y) {
    Node *t = graph[x];
    while(t->next != NULL) {
        t = t->next;
    }
    t->next = new Node(y);
}

void printGraph(Node *graph[], int n) {
    for(int i = 0; i < n; i++) {
        Node *t = graph[i];
        while(t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
}
