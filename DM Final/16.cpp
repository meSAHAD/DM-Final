#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new BST node
struct TreeNode *createNode(int item)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct TreeNode *insert(struct TreeNode *root, int item)
{
    // If the tree is empty, return a new node
    if (root == NULL)
    {
        return createNode(item);
    }

    // Otherwise, recur down the tree
    if (item < root->data)
    {
        root->left = insert(root->left, item);
    }
    else if (item > root->data)
    {
        root->right = insert(root->right, item);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to perform an inorder traversal of the BST
void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to construct a BST from a list of items
struct TreeNode *constructBST(int items[], int n)
{
    struct TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, items[i]);
    }
    return root;
}

int main()
{
    int items[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(items) / sizeof(items[0]);

    struct TreeNode *root = constructBST(items, n);

    printf("Inorder traversal of the constructed BST:\n");
    inorderTraversal(root);

    return 0;
}
