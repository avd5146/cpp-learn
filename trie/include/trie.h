#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:

    struct Node {
        vector<char> val{};
        Node* next = nullptr;
        bool isword = false;
        Node(){};
        Node(const char& c) {
            val.push_back(c);
        } 
    };
    
    Node* root_ = nullptr;

    bool has(const char& c, const Node* root) {
        
        for(auto n : root->val) {
            if (n == c)
                return true;
        }
        return false;
    }
    
    Trie() {
        root_ = new Node();
    }

    void printTrie(Node* root)
    {
        
        Node* temp = root;
        while(temp!=nullptr) {
            
            for(auto c : temp->val) {
                cout<<c;
            }
            
            temp = temp->next;
        }

    }
    
    void insert(string word) {
        
        Node* temp = root_;
        
        for(auto c : word) {
            if ((temp->val).empty())
                (temp->val).push_back(c);
            else {
                if (!has(c, temp))
                {                    
                    (temp->val).push_back(c);   
                }
            }
            // THIS was the issue 1 (order of check and assignment of next)
            if (temp->next == nullptr) temp->next = new Node();
            temp = temp->next;
        }
        temp->val.push_back('-');
        temp->isword = true;
        //printTrie(root_);
        
    }
    
    bool search(string word) {
        Node* temp = root_;
        for(auto c : word) {
            if (has(c, temp))
                temp = temp->next;
            else
                return false;
        }
        if(temp->isword)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root_;
        bool out = false;
        for(auto c : prefix) {
            if (has(c, temp)) {
                out = true;
                temp = temp->next;
            } else {
                return false;
            }
        }
        return out;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */