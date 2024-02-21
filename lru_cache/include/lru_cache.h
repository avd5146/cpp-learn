#include <iostream>
#include <list>

using namespace std;

class LRUCache
{
public:
    int cap_ = 0;
    int filled_ = 0;
    // int least_rank_ = 0;
    int max_rank_ = 0;

    struct Node
    {
        int key = 0;
        int val = 0;
        int rank = 0;
    };
    list<Node> v_;

    LRUCache(int capacity)
    {
        cap_ = capacity;
    }

    Node *getKey(const int &key)
    {
        for (auto &elem : v_)
        {
            if (elem.key == key)
            {
                return &elem;
            }
        }
        return nullptr;
    }

    Node *getLRU()
    {
        Node *out = &v_.front();
        int r = v_.front().rank;
        for (auto &elem : v_)
        {
            if (r > elem.rank)
            {
                r = elem.rank;
                out = &elem;
                // least_rank_++; // handle overflow
            }
        }
        return out;
    }

    int get(int key)
    {

        Node *p = getKey(key);
        if (p != nullptr)
        {
            // if (p->rank == least_rank_)
            //     least_rank_++;
            max_rank_ += 1;
            p->rank = max_rank_;
            return p->val;
        }
        return -1;
    }

    void put(int key, int value)
    {

        // if exists, update
        Node *p = getKey(key);
        if (p != nullptr)
        {
            // if (p->rank == least_rank_)
            //     least_rank_++;
            p->val = value;
            max_rank_ += 1;
            p->rank = max_rank_;
            return;
        }
        else if (filled_ < cap_)
        {
            // if (least_rank_ == 0)
            //     least_rank_ = 1;
            max_rank_++;
            v_.push_back({key, value, max_rank_});
            filled_++;
        } // else replace LRU
        else
        {
            Node *lru = getLRU();
            if (lru != nullptr)
            {
                lru->key = key;
                lru->val = value;
                max_rank_ += 1;
                lru->rank = max_rank_;
            }
        }
    }
};
