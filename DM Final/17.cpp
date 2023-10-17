#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int item) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insertIntoBST(struct Node *rootNode, int item) {
    if (rootNode == NULL) return createNode(item);
    if (item < rootNode->value) rootNode->left = insertIntoBST(rootNode->left, item);
    else if (item >= rootNode->value) rootNode->right = insertIntoBST(rootNode->right, item);
    return rootNode;
}

struct Node *search(struct Node *node, int item) {
    if (node == NULL || node->value == item) return node;
    if (item < node->value) return search(node->left, item);
    return search(node->right, item);
}

int main() {
    int n;
    scanf("%d", &n);
    int items[n];
    for (int i = 0; i < n; i++) scanf("%d", &items[i]);

    struct Node *rootNode = NULL;
    for (int i = 0; i < n; i++) {
        rootNode = insertIntoBST(rootNode, items[i]);
    }

    int target;
    scanf("%d", &target);
    struct Node *result = search(rootNode, target);
    if (result != NULL) printf("This item is in BST\n");
    else printf("This item isn't in BST\n");

    rootNode = insertIntoBST(rootNode, target);

    return 0;
}
