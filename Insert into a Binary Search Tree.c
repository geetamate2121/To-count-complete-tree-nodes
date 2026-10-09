#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    if (root == NULL)
    {
        struct TreeNode* newNode =
            (struct TreeNode*)malloc(sizeof(struct TreeNode));

        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Preorder: Root -> Left -> Right
void preorder(struct TreeNode* root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct TreeNode* root = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertIntoBST(root, value);
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    root = insertIntoBST(root, value);

    printf("Preorder after insertion: ");
    preorder(root);

    return 0;
}