//
// Created by Makram Kamaleddine on 2017-02-11.
//

#ifndef THEODEN_STACK_HPP
#define THEODEN_STACK_HPP

namespace theoden {

    template<typename T>
    struct front_linked_list;

    template<typename T>
    struct front_node;

    template<typename T>
    struct stack {
    private:
        theoden::front_linked_list<T> list;
    public:
        stack() {}

        void push(T item) {
            list.insert_front(item);
        }

        T pop() {
            return list.pop_front();
        }

        T top() {
            return list.front();
        }
    };

    /**
     * The stack implementation will use a specially limited
     * linked list that will only let us do the following operations:
     * - insert_front: insert an item to the front of the linked list
     * - pop_front: remove and return the item at the front of the linked list
     * - front: return the item at the front of the linked list
     */
    template<typename T>
    struct front_linked_list {
        front_node <T> *_front;
        size_t _size;

        front_linked_list()
                : _front(nullptr),
                  _size(0)
        {

        }

        void insert_front(T item) {
            auto node = new front_node<T>;
            node->item = item;
            node->next = _front;
            _front = node;
            ++_size;
        }

        T pop_front() {
            auto item = _front->item;
            auto tmp = _front->next;
            delete _front;
            _front = tmp;
            --_size;
            return item;
        }

        T front() const {
            return _front->item;
        }

        size_t size() const {
            return _size;
        }
    };

    template<typename T>
    struct front_node {
        T item;
        front_node *next;
    };
}

#endif //THEODEN_STACK_HPP
