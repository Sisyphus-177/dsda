#include <stdio.h>
#include <stdbool.h>

#define SIZE 5  // Number of nodes in the graph

// Queue structure for BFS
struct Queue {
    int items[SIZE];
    int front, rear;
};

// Stack structure for DFS
struct Stack {
    int items[SIZE];
    int top;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
bool isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    if (q->rear == SIZE - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (isQueueEmpty(q))
        return -1;
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}

// BFS function
void bfs(int adj[SIZE][SIZE], int start) {
    int visited[SIZE] = {0};  // Mark all nodes as unvisited
    struct Queue q;
    initQueue(&q);

    printf("BFS Traversal: ");
    enqueue(&q, start);
    visited[start] = 1;

    while (!isQueueEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        for (int i = 0; i < SIZE; i++) {
            if (adj[node][i] && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is empty
bool isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack* s, int value) {
    if (s->top == SIZE - 1)
        return;
    s->items[++s->top] = value;
}

// Pop operation
int pop(struct Stack* s) {
    if (isStackEmpty(s))
        return -1;
    return s->items[s->top--];
}

// DFS function
void dfs(int adj[SIZE][SIZE], int start) {
    int visited[SIZE] = {0};  // Mark all nodes as unvisited
    struct Stack s;
    initStack(&s);

    printf("DFS Traversal: ");
    push(&s, start);
    visited[start] = 1;

    while (!isStackEmpty(&s)) {
        int node = pop(&s);
        printf("%d ", node);

        for (int i = SIZE - 1; i >= 0; i--) {  // Reverse order for stack-based DFS
            if (adj[node][i] && !visited[i]) {
                push(&s, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int adj[SIZE][SIZE] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int startNode = 0;  // Change this to start from any other node

    bfs(adj, startNode);  // Perform BFS
    dfs(adj, startNode);  // Perform DFS

    return 0;
}
