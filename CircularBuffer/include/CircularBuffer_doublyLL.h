/**
 * @file CircularBuffer_doublyLL.h
 * @author your name (you@domain.com)
 * @brief Circular buffer with only push_back support. Underlying DS is linked list
 * @version 0.1
 * @date 2024-04-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;

template<typename T>
class CircularBuffer
{
public:

    /**
     * @brief Construct a new Circular Buffer object
     * Default constructor explicitly deleted because capacity is required.
     * 
     */
    CircularBuffer() = delete;

    /**
     * @brief Construct a new Circular Buffer object
     * 
     * @param capacity Capacity of the buffer
     */
    CircularBuffer(size_t&& capacity) : _capacity(capacity)
    {
        if(capacity > T{}) {
            _begin = _end = new Node();
            Node* temp = _begin;
            for(size_t i = T{}; i < _capacity - 1; i++) {
                temp->next = new Node();
                // Node* hold = temp;
                temp = temp->next;
                // temp->prev = hold;
            }
        }
    }

    /**
     * @brief Construct a new Circular Buffer object
     * 
     * @param capacity Capacity of the buffer
     * @param initializer Initialization value
     */
    CircularBuffer(size_t&& capacity, T&& initializer) : _capacity(capacity), _size(_capacity)
    {
        if(capacity > T{}) {
            _begin = _end = new Node(initializer);
            Node* temp = _begin;
            for(size_t i = T{}; i < _capacity - 1; i++) {
                temp->next = new Node(initializer);
                // Node* hold = temp;
                temp = temp->next;
                // temp->prev = hold;
            }
            _end = temp; // differentiator
        } else {
            // ?
        }
    }

    /**
     * @brief Operator[]
     * 
     * @param index 
     * @return T Value at index
     */
    T operator[](size_t&& index)
    {
        if (index < _size || _full) {
            Node* temp = _begin;
            for(size_t i = T{}; i < index; i++) {
                temp = temp->next;
            }
            return temp->val;
        } else {
            // ?
            // compiles without a return statement :O
        }
    }

    /**
     * @brief Push elements to buffer
     * 
     * @param value Value to push
     */
    void push_back(T&& value)
    {
        if(_size < _capacity) {
            _end->val = value;
            _end = _end->next;
            ++_size;
        } else {
            _full = true;
            _size = T{} + 1; // bad hack
            _begin->val = value;
            _end = _begin->next;
        }
    }

    /**
     * @brief Destroy the Circular Buffer object
     * 
     */
    ~CircularBuffer(){};

private:

    struct Node {
        T val;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node() : val(T{}), prev(nullptr), next(nullptr) {};
        Node(const T& v) : val(v), prev(nullptr), next(nullptr) {};
        ~Node(){};
    };

    Node* _begin = nullptr;
    Node* _end = nullptr;
    size_t _size = T{};
    size_t _capacity = T{};
    bool _full = false;

};