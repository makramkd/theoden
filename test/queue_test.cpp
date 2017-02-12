//
// Created by Makram Kamaleddine on 2017-02-11.
//

#include "gtest/gtest.h"
#include "../include/queue.hpp"

TEST(Queue, HandlesEmptyEnqueue) {
    theoden::queue<int> q;

    ASSERT_TRUE(q.empty());

    q.enqueue(1);

    ASSERT_EQ(q.size(), 1);
    ASSERT_EQ(q.front(), 1);
    ASSERT_EQ(q.back(), 1);
}

TEST(Queue, HandlesNonEmptyEnqueue) {
    theoden::queue<int> q;

    q.enqueue(1);
    q.enqueue(2);

    ASSERT_EQ(q.back(), 2);
    ASSERT_EQ(q.front(), 1);
    ASSERT_EQ(q.size(), 2);
}

TEST(Queue, HandlesNonEmptyDequeue) {
    theoden::queue<int> q;

    q.enqueue(1);

    ASSERT_EQ(q.front(), 1);
    ASSERT_EQ(q.back(), 1);

    // perform the dequeue
    auto item = q.dequeue();
    ASSERT_EQ(item, 1);
    ASSERT_TRUE(q.empty());
}

TEST(Queue, HandlesNonEmptyDequeue2) {
    theoden::queue<int> q;

    for (int i = 0; i < 10; ++i) {
        q.enqueue(i);
    }

    ASSERT_EQ(q.size(), 10);

    auto item = q.dequeue();
    ASSERT_EQ(item, 0);
    item = q.dequeue();
    ASSERT_EQ(item, 1);
    item = q.dequeue();
    ASSERT_EQ(item, 2);
}

TEST(Queue, HandlesEmpty) {
    theoden::queue<int> q;

    ASSERT_TRUE(q.empty());

    q.enqueue(1);

    ASSERT_FALSE(q.empty());
}

TEST(Queue, HandlesSize) {
    theoden::queue<int> q;

    for(int i = 0; i < 20; ++i) {
        q.enqueue(i);
    }

    ASSERT_EQ(q.size(), 20);

    q.dequeue();

    ASSERT_EQ(q.size(), 19);
}