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

// Function to search for an item in the BST
struct TreeNode *search(struct TreeNode *root, int item)
{
    // Base cases: root is null or the item is found at the root
    if (root == NULL || root->data == item)
    {
        return root;
    }

    // If the item is greater than the root's data, recur on the right subtree
    if (root->data < item)
    {
        return search(root->right, item);
    }

    // If the item is smaller than the root's data, recur on the left subtree
    return search(root->left, item);
}

// Function to locate or add an item in the BST
struct TreeNode *locateOrAdd(struct TreeNode *root, int item)
{
    // Search for the item in the BST
    struct TreeNode *result = search(root, item);

    // If the item is not found, insert it into the BST
    if (result == NULL)
    {
        root = insert(root, item);
    }

    // Return the updated root
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

int main()
{
    struct TreeNode *root = NULL;

    // Insert elements into the BST
    root = locateOrAdd(root, 50);
    root = locateOrAdd(root, 30);
    root = locateOrAdd(root, 70);
    root = locateOrAdd(root, 20);
    root = locateOrAdd(root, 40);
    root = locateOrAdd(root, 60);
    root = locateOrAdd(root, 80);

    printf("Inorder traversal of the BST:\n");
    inorderTraversal(root);

    return 0;
}
