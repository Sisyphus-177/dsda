#include <iostream>
#include <vector>

#define SIZE 5  // Number of nodes in the graph

class Queue {
private:
    int items[SIZE];
    int front, rear;
public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) return;
        if (front == -1) front = 0;
        items[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int item = items[front];
        if (front == rear) front = rear = -1;
        else front++;
        return item;
    }
};

class Stack {
private:
    int items[SIZE];
    int top;
public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top == SIZE - 1) return;
        items[++top] = value;
    }

    int pop() {
        if (isEmpty()) return -1;
        return items[top--];
    }
};

void bfs(int adj[SIZE][SIZE], int start) {
    std::vector<bool> visited(SIZE, false);
    Queue q;

    std::cout << "BFS Traversal: ";
    q.enqueue(start);
    visited[start] = true;

    while (!q.isEmpty()) {
        int node = q.dequeue();
        std::cout << node << " ";

        for (int i = 0; i < SIZE; i++) {
            if (adj[node][i] && !visited[i]) {
                q.enqueue(i);
                visited[i] = true;
            }
        }
    }
    std::cout << "\n";
}

void dfs(int adj[SIZE][SIZE], int start) {
    std::vector<bool> visited(SIZE, false);
    Stack s;

    std::cout << "DFS Traversal: ";
    s.push(start);
    visited[start] = true;

    while (!s.isEmpty()) {
        int node = s.pop();
        std::cout << node << " ";

        for (int i = SIZE - 1; i >= 0; i--) {
            if (adj[node][i] && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    std::cout << "\n";
}

int main() {
    int adj[SIZE][SIZE] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int startNode = 0;
    bfs(adj, startNode);
    dfs(adj, startNode);

    return 0;
}
