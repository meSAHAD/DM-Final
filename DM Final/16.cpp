#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    
    Node(int item) {
        value = item;
        left = nullptr;
        right = nullptr;
    }
};

Node *insertIntoBST(Node *rootNode, int item) {
    if (rootNode == nullptr) return new Node(item);
    if (item < rootNode -> value) rootNode -> left = insertIntoBST(rootNode -> left, item);
    else if (item >= rootNode -> value) rootNode -> right = insertIntoBST(rootNode -> right, item);
    return rootNode;
}

void printInOrder(Node *rootNode) {
    if (rootNode == nullptr) return;
    printInOrder(rootNode -> left);
    cout << rootNode -> value << " ";
    printInOrder(rootNode -> right);
}

int main() {
    int n; 
    scanf("%d", &n);
    int items[n];
    for (int i = 0; i < n; i++) scanf("%d", &items[i]);
    
    Node *rootNode = nullptr;
    for (int i = 0; i < n; i++) {
        rootNode = insertIntoBST(rootNode, items[i]);
    }
    
    printf("In-order traversal of the constructed BST: ");
    printInOrder(rootNode);
    printf("\n");
    
    return 0;
}
