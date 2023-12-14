#include "trees.h"

int main(int args, const char *argv[])
{
    trees o;
    itree *root = new itree(1);
    root->left = new itree(2);
    root->right = new itree(3);
    root->left->left = new itree(4);
    root->left->right = new itree(5);
    root->right->left = new itree(6);
    root->right->right = new itree(7);

    root->right->right->left = new itree(8);
    // root->right->right->right = new itree(9);
    root->left->right->left = new itree(9);

    // o.printTreeDFSInorder(root);
    // std::cout << std::endl;
    // o.printTreeDFSPreorder(root);
    // std::cout << std::endl;
    // o.printTreeDFSPostorder(root);
    // std::cout << std::endl;
    // o.printBT("", root, false);

    std::vector<itree *> in = {root};
    o.printTreeBFS(in);

    // int l = 0;
    // int d = 0;
    // o.treeLengthDiameter(root, l, d);
    // std::cout << "length is " << l << std::endl;
    // std::cout << "diameter is " << d << std::endl;

    // o.invertBinaryTree(root);
    // o.printTreeBFS(in);

    // o.lowestCommonAncestor(root, 8, 6);

    Utils::printV(o.rightSideView(root));
}