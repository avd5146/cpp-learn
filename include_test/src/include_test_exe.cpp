#include "include_test.h"

int main(int args, const char *argv[])
{
    typedef Utils::BinaryTreeNode<int> itree;

    itree *root = new itree(1);
    root->left = new itree(2);
    root->right = new itree(3);
    root->left->left = new itree(4);
    root->left->right = new itree(5);
    root->right->left = new itree(6);
    root->right->right = new itree(7);
}