#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
#include <queue>
#include <deque>
#include <map>
#include <stack>

namespace Utils
{

    using namespace std;

    // Print vector
    template <class T>
    void printV(const vector<T> &in)
    {
        for (auto iter : in)
        {
            cout << iter << endl;
        }
    }

    // Singly linked list base struct
    template <typename T>
    struct SingleListNode
    {
        T val;
        SingleListNode *next;
        SingleListNode()
        {
            // val = default;
            next = nullptr;
        };
        SingleListNode(const T&& in)
        {
            val = in;
            next = nullptr;
        };
        void print()
        {
            SingleListNode* temp = this;
            while(temp) {
                cout<<temp->val<<" ";
                temp = temp->next;
            }
        }
    };

    // Doubly linked list base struct
    template <typename T>
    struct DoubleListNode
    {
        T val;
        DoubleListNode *next, *prev;
        DoubleListNode()
        {
            // val = default;
            next = prev = nullptr;
        };
    };

    // Binary tree base struct
    template <typename T>
    struct BinaryTreeNode
    {
        T val;
        BinaryTreeNode *left, *right;

        BinaryTreeNode()
        {
            // val = default; // throws error
            left = right = nullptr;
        };
        BinaryTreeNode(T in)
        {
            val = in;
            left = right = nullptr;
        };
        ~BinaryTreeNode(){};
    };

} // namespace Utils