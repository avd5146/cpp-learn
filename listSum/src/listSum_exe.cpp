#include "listSum.h"

int main(int args, const char *argv[])
{
    listSum o;
    listSum::ListNode *l1 = new listSum::ListNode;
    listSum::ListNode *l2 = new listSum::ListNode;

    l1->val = 2;
    l1->next = new listSum::ListNode(4);
    l1->next->next = new listSum::ListNode(3);

    l2->val = 5;
    l2->next = new listSum::ListNode(6);
    l2->next->next = new listSum::ListNode(4);
    // l2->next->next->next = new listSum::ListNode(9);

    o.addTwoNumbers(l1, l2);
}