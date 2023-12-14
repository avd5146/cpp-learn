#include "linked_list.h"

int main(int args, const char *argv[])
{
    LinkedList ll;
    ll.insertHead(1);
    ll.insertHead(2);
    ll.insertHead(3);
    ll.insertHead(4);
    ll.insertHead(5);
    ll.insertTail(6);
    ll.insertTail(7);

    cout << ll.get(0) << endl;
    cout << ll.get(1) << endl;
    cout << ll.get(2) << endl;
    cout << ll.get(3) << endl;
    cout << ll.get(4) << endl;
    cout << ll.get(5) << endl;
    cout << ll.get(6) << endl;
    cout << ll.get(7) << endl;

    // ["insertTail", 1, "insertTail", 2, "get", 1, "remove", 1, "insertTail", 2, "get", 1, "get", 0]

    // ll.insertTail(1);
    // ll.insertTail(2);
    // ll.get(1);
    // ll.remove(1);
    // ll.insertTail(2);
    // ll.get(1);
    // ll.get(0);

    ll.printLL();
}