#include <iostream>
#include "../../common_custom_headers/general.h"

typedef Utils::BinaryTreeNode<int> itree;
using namespace std;

class trees : public Utils::BinaryTreeNode<int>
{
public:
    trees(){};
    ~trees(){};

    void printTreeDFSInorder(const itree *root)
    {
        if (root == nullptr)
            return;

        printTreeDFSInorder(root->left);
        std::cout << root->val << " ";
        printTreeDFSInorder(root->right);
    };

    void printTreeDFSPreorder(const itree *root)
    {
        if (root == nullptr)
            return;

        std::cout << root->val << " ";
        printTreeDFSPreorder(root->left);
        printTreeDFSPreorder(root->right);
    };

    void printTreeDFSPostorder(const itree *root)
    {
        if (root == nullptr)
            return;

        printTreeDFSPostorder(root->left);
        printTreeDFSPostorder(root->right);
        std::cout << root->val << " ";
    };

    void printTreeBFS(std::vector<itree *> curr)
    {
        if (curr.empty())
            return;
        std::vector<itree *> next;
        for (auto node : curr)
        {
            if (node != nullptr)
            {
                std::cout << node->val << " ";
                next.push_back(node->left);
                next.push_back(node->right);
            }
        }
        std::cout << std::endl;
        printTreeBFS(next);
    };

    // from bing ai
    void printBT(const std::string &prefix, const itree *node, bool isLeft)
    {
        if (node != nullptr)
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├──" : "└──");
            std::cout << node->val << std::endl;
            printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
            printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }

    /* My logic for diameter was to look for 2 longest depths from root.
    The solution from online is find the max left+right length at each node.*/
    void treeLengthDiameter(const itree *root, int &length, int &diameter)
    {
        if (root == nullptr)
            return;
        ++length;
        int length_left = 0;
        int length_right = 0;
        treeLengthDiameter(root->left, length_left, diameter);
        treeLengthDiameter(root->right, length_right, diameter);
        length += std::max(length_left, length_right);
        diameter = std::max((length_left + length_right), diameter);
    };

    void invertBinaryTree(itree *root)
    {
        if (root == nullptr)
            return;
        itree *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }

    /*
    string arg gives error without const. why?
    Another approach for find node specifically for BST would be to use BST properties.
    Left val < right val
    */
    void findNode(const itree *root, const int &in, const string &side, list<pair<string, int>> &out, bool &found)
    {
        if (root == nullptr || found)
            return;

        out.push_back({side, root->val});
        if (root->val == in)
            found = true;

        findNode(root->left, in, "left", out, found);
        findNode(root->right, in, "right", out, found);
        if (!found)
            out.pop_back();
    }

    // itree *lowestCommonAncestor(itree *root, itree *p, itree *q)
    itree *lowestCommonAncestor(itree *root, const int &p, const int &q)
    {
        itree *out = new itree();
        list<pair<string, int>> out_p;
        list<pair<string, int>> out_q;
        bool found = false;
        findNode(root, p, "root", out_p, found);
        found = false;
        findNode(root, q, "root", out_q, found);

        uint8_t loop_length = min(out_p.size(), out_q.size());
        int res = -1;

        auto p_it = out_p.begin();
        auto q_it = out_q.begin();

        while (p_it != out_p.end() && q_it != out_q.end())
        {
            if (p_it->first == q_it->first)
            {
                res = p_it->second;
            }
            else
            {
                break;
            }
            p_it++;
            q_it++;
        }
        cout << "common lowest ancestor: " << res << endl;
        return out;
    }

    // Right side view of a tree
    void rightSideViewBFS(const vector<itree *> &input, vector<int> &res)
    {

        if (input.empty())
            return;

        if (input.back() != nullptr)
            res.push_back(input.back()->val);

        vector<itree *> children;
        for (auto child : input)
        {
            if (child != nullptr)
            {
                if (child->left != nullptr)
                    children.push_back(child->left);
                if (child->right != nullptr)
                    children.push_back(child->right);
            }
        }
        rightSideViewBFS(children, res);
    }

    vector<int> rightSideView(itree *root)
    {

        vector<int> res;

        if (root == nullptr)
            return res;

        vector<itree *> input({root});
        rightSideViewBFS(input, res);

        return res;
    }
};