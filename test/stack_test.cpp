//
// Created by Makram Kamaleddine on 2017-02-11.
//

#include "gtest/gtest.h"
#include "../include/stack.hpp"

TEST(LinkedListTest, HandlesEmptyInsert) {
    theoden::front_linked_list<int> list;

    list.insert_front(1);

    ASSERT_EQ(list.front(), 1);
}

TEST(LinkedListTest, HandlesNonEmptyInsert) {
    theoden::front_linked_list<int> list;

    list.insert_front(1);
    list.insert_front(2);

    // list is 2 -> 1 -> null
    ASSERT_EQ(list.front(), 2);
    ASSERT_EQ(list.size(), 2);
}

TEST(LinkedListTest, HandlesNonEmptyPop) {
    theoden::front_linked_list<int> list;

    list.insert_front(1);

    ASSERT_EQ(list.front(), 1);

    list.pop_front();
    ASSERT_EQ(list.size(), 0);
}

TEST(LinkedListTest, HandlesNonEmptyPop2) {
    theoden::front_linked_list<int> list;

    list.insert_front(1);
    list.insert_front(2);

    ASSERT_EQ(list.front(), 2);

    list.pop_front();
    ASSERT_EQ(list.front(), 1);

    list.pop_front();
    ASSERT_EQ(list.size(), 0);
}