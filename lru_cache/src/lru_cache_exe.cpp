#include "lru_cache.h"

int main(int args, const char *argv[])
{
    // LRUCache *obj = new LRUCache(2);
    // obj->put(1, 1);
    // obj->put(2, 2);
    // cout << obj->get(1) << endl;
    // obj->put(3, 3);
    // cout << obj->get(2) << endl;
    // obj->put(4, 4);
    // cout << obj->get(1) << endl;
    // cout << obj->get(3) << endl;
    // cout << obj->get(4) << endl;

    LRUCache *obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(3, 2);
    cout << obj->get(3) << endl;
    cout << obj->get(2) << endl;
    obj->put(4, 3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
}