#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Find height by going to the left */
int getLeftHeight(struct TreeNode* root)
{
    int height = 0;

    while (root != NULL)
    {
        height++;
        root = root->left;
    }

    return height;
}

/* Find height by going to the right */
int getRightHeight(struct TreeNode* root)
{
    int height = 0;

    while (root != NULL)
    {
        height++;
        root = root->right;
    }

    return height;
}

/* Count nodes in complete binary tree */
int countNodes(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = getLeftHeight(root);
    int rightHeight = getRightHeight(root);

    /* If both heights are same, tree is perfect */
    if (leftHeight == rightHeight)
    {
        return (1 << leftHeight) - 1;
    }

    /* Otherwise count left and right subtrees */
    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

/* Create a new node */
struct TreeNode* createNode(int value)
{
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Create the example complete tree */
int main()
{
    /*
              1
             / \
            2   3
           / \  /
          4   5 6
    */

    struct TreeNode* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);

    printf("Number of nodes = %d\n", countNodes(root));

    return 0;
}