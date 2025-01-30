#include <iostream>
using namespace std;

struct Node {
    string value;  // Condition or operator (^)
    Node* left;
    Node* right;

    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};
Node* buildTree() {
    // Leaf nodes (conditions)
    Node* A = new Node("Age >= 18");  // condition A
    Node* B = new Node("Healthy == True");  // condition B
    Node* C = new Node("DrivingHours >= 25");  // condition C
    Node* D = new Node("PassDrivingTest == True");  // condition D

    // XOR operations
    Node* AB = new Node("^");  AB->left = A;  AB->right = B;
    Node* ABC = new Node("^"); ABC->left = AB; ABC->right = C;
    Node* root = new Node("^"); root->left = ABC; root->right = D;

    return root; // Return the root node of the tree
}

int evaluateTree(Node* node, int age, bool healthy, int drivingHours, bool passDrivingTest) {
    if (!node) return 0;  // Base case: Null node
    
    // Evaluate conditions based on inputs
    if (node->value == "Age >= 18") return (age >= 18) ? 1 : 0;
    if (node->value == "Healthy == True") return healthy ? 1 : 0;
    if (node->value == "DrivingHours >= 25") return (drivingHours >= 25) ? 1 : 0;
    if (node->value == "PassDrivingTest == True") return passDrivingTest ? 1 : 0;
    
    // If the node is the XOR operator (^), evaluate both subtrees and return XOR of the results
    int leftVal = evaluateTree(node->left, age, healthy, drivingHours, passDrivingTest);
    int rightVal = evaluateTree(node->right, age, healthy, drivingHours, passDrivingTest);

    return leftVal ^ rightVal;  // XOR operation
}

int main() {
    // Input values
    int age = 19;            // Example input: age is 19
    bool healthy = false;    // Example input: unhealthy (Healthy is false)
    int drivingHours = 30;   // Example input: 30 hours of driving
    bool passDrivingTest = true;  // Example input: Passed the driving test

    // Build the tree
    Node* root = buildTree();

    // Evaluate the tree based on the input
    int result = evaluateTree(root, age, healthy, drivingHours, passDrivingTest);

    // Output result
    if (result == 1)
        cout << "Driving Test Pass" << endl;
    else
        cout << "Driving Test Fail" << endl;

    return 0;
}
