//
// Created by Makram Kamaleddine on 2017-02-11.
//

#ifndef THEODEN_QUEUE_HPP
#define THEODEN_QUEUE_HPP

#include <cstddef>

namespace theoden {

    template<typename T>
    struct q_node;

    template<typename T>
    struct q_linked_list;

    template<typename T>
    struct queue {
    private:
        q_linked_list<T> list;
    public:
        void enqueue(T item) {
            list.insert_back(item);
        }

        T dequeue() {
            return list.pop_front();
        }

        bool empty() const {
            return list.empty();
        }

        size_t size() const {
            return list.size();
        }

        T front() const {
            return list.front_item();
        }

        T back() const {
            return list.back_item();
        }
    };

    /**
     * A linked list that provides the following operations, specially
     * designed for a queue ADT:
     * - insert_back: insert an item to the back of the list.
     * - pop_front: remove and return the item at the front of the list
     * - empty/size: whether the list is empty/the size of the list
     */
    template<typename T>
    struct q_linked_list {
        q_node<T> *front;
        q_node<T> *back;
        size_t _size;

        q_linked_list()
        : front(nullptr),
          back(nullptr),
          _size(0)
        {

        }

        void insert_back(T item) {
            auto node = new q_node<T>;
            node->item = item;
            if (back) {
                back->next = node;
                back = node;
            } else {
                front = back = node;
            }
            ++_size;
        }

        T pop_front() {
            auto tmp = front;
            auto item = tmp->item;
            front = tmp->next;
            if (!front) {
                back = nullptr;
            }
            delete tmp;
            --_size;
            return item;
        }

        bool empty() const {
            return _size == 0;
        }

        size_t size() const {
            return _size;
        }

        T front_item() const {
            return front->item;
        }

        T back_item() const {
            return back->item;
        }
    };

    template<typename T>
    struct q_node {
        T item;
        q_node *next;
    };
}

#endif //THEODEN_QUEUE_HPP
