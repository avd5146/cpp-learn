#include <iostream>

using namespace std;

class listSum
{
public:
    listSum(){};
    ~listSum(){};

    // Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    /*
    ListNode *getTail(ListNode *head)
    {
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        return tail;
    }

    int extractNumber(ListNode *head)
    {
        int num = 0;
        int c = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            num = num + pow(10, c) * temp->val;
            temp = temp->next;
            c++;
        }
        return num;
    }

    ListNode *convertToList(int &s)
    {
        ListNode *head = new ListNode;
        ListNode *res = head;
        bool first = true;
        bool in = false;
        while (s > 9)
        {
            if (first)
            {
                res->val = s % 10;
                first = false;
            }
            else
            {
                res->next = new ListNode(s % 10);
                res = res->next;
            }

            s /= 10;
            in = true;
        }
        if (!in)
            res->next = new ListNode(s);
        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int l1_num = extractNumber(l1);
        int l2_num = extractNumber(l2);
        int sum = l1_num + l2_num;

        ListNode *res = convertToList(sum);
        return res;
    }
    */
    uint8_t carry_ = 0;

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode;
        ListNode *res = head;
        while (!(l1 == nullptr && l2 == nullptr))
        {
            uint8_t d = 0;
            if (l1 != nullptr)
            {
                d += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                d += l2->val;
                l2 = l2->next;
            }
            d += carry_;

            if (d > 9)
            {
                res->val = d % 10;
                carry_ = d / 10;
            }
            else
            {
                res->val = d;
                carry_ = 0;
            }
            if (l1 || l2)
            {
                res->next = new ListNode;
                res = res->next;
            }
            else if (carry_ != 0) // for leftover carry of 10
            {
                res->next = new ListNode;
                res = res->next;
                res->val = 1;
            }
        }
        carry_ = 0;
        res = nullptr;
        return head;
    }
};