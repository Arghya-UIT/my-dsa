#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree *right, *left;
} tree;
int search(int num, int start, int end, int in[])
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == num)
        {
            return i;
        }
    }
}
tree *build(int in[], int pre[], int start, int end)
{
    static int a = 0;
    if (start > end)
    {
        return NULL;
    }
    tree *node = (tree *)malloc(sizeof(tree));
    node->data = pre[a];
    a++;
    if (start == end)
    {
        return node;
    }
    int s = search(node->data, start, end, in);
    node->left = build(in, pre, start, s - 1);
    node->right = build(in, pre, s + 1, end);
    return node;
}
void print_inorder(tree *node)
{
    if (node == NULL)
    {
        return;
    }
    print_inorder(node->left);
    print_inorder(node->right);
    printf("%d ,", node->data);
}
int main()
{
    int in[] = {1, 2, 3, 4, 5, 7, 8, 9, 11, 12, 13};
    int pre[] = {7, 3, 2, 1, 4, 5, 9, 8, 12, 11, 13};
    tree *root = build(in, pre, 0, 10);
    print_inorder(root);
}