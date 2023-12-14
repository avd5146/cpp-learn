#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int value_;
    Node *next_node_;
    Node()
    {
        value_ = 0;
        next_node_ = nullptr;
    };
    Node(int val)
    {
        value_ = val;
        next_node_ = nullptr;
    }
};

class LinkedList
{
private:
    Node *head_;

public:
    LinkedList()
    {
        head_ = nullptr;
    };

    void insertHead(int val)
    {
        Node *temp = new Node;
        temp->value_ = val;
        temp->next_node_ = this->head_;
        this->head_ = temp;
    };

    Node *geti(int index)
    {
        if (index == 0)
            return this->head_;
        int i = 0;
        Node *temp = this->head_;
        while (temp != nullptr && i < index)
        {
            temp = temp->next_node_;
            i = i + 1;
        }
        return temp;
    }

    int get(int index)
    {

        Node *temp = geti(index);
        if (temp != nullptr)
        {
            return temp->value_;
        }
        else
        {
            return -1;
        }
    }

    void insertTail(int val)
    {
        if (this->head_ == nullptr)
            this->head_ = new Node;
        Node *curr = this->head_;
        while (curr->next_node_ != nullptr)
        {
            curr = curr->next_node_;
        }
        Node *temp = new Node(val);
        curr->next_node_ = temp;
    }

    bool remove(int index)
    {
        Node *temp = geti(index);
        if (temp == nullptr)
        {
            return false;
        }
        else
        {
            if (temp->next_node_ != nullptr)
            {
                temp->next_node_ = temp->next_node_->next_node_;
            }
            else
            {
                // do nothing. element doesnt exist
            }
            return true;
        }
    }

    vector<int> getValues()
    {
        return {};
    }

    ~LinkedList(){};

    void printLL()
    {
        Node *temp = this->head_;
        int i = 0;
        while (temp != nullptr)
        {
            cout << i << " : " << temp->value_ << endl;
            temp = temp->next_node_;
            i++;
        }
    };
};