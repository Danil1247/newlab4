#include "gtest.h"
#include "Queue.h"

TEST(TQueue, can_create_ArrList_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> queue(4));
}

TEST(TQueue, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue<int> queue(-1));
}

TEST(TQueue, can_get_size)
{
  TQueue<int> queue(3);

  queue.Push(1);

  queue.Push(2);

  queue.Push(3);

  EXPECT_EQ(3, queue.GetSize());
}

TEST(TQueue, can_create_copied_queue)
{
  TQueue<int> queue(3);

  ASSERT_NO_THROW(TQueue<int> queue1(queue));
}

TEST(TQueue, can_push_item_into_queue)
{
  TQueue<int> queue(4);

  ASSERT_NO_THROW(queue.Push(3));
}

TEST(TQueue, can_get_item_from_queue)
{
  TQueue<int> queue(3);
  queue.Push(1);
  queue.Push(2);
  queue.Push(3);
  ASSERT_NO_THROW(queue.Top());
}

TEST(TQueue, can_check_for_emptiness)
{
  TQueue<int> queue(4);
  EXPECT_EQ(queue.IsEmpty(), true);
}

TEST(TQueue, can_check_for_fullness)
{
  TQueue<int> queue(3);
  queue.Push(1);
  queue.Push(2);
  queue.Push(3);
  EXPECT_EQ(queue.IsFull(), true);
}

TEST(TQueue, cant_get_item_from_empty_queue)
{
  TQueue<int> queue(4);
  ASSERT_ANY_THROW(queue.Top());
}

TEST(TQueue, cant_push_item_into_full_queue)
{
  TQueue<int> queue(3);
  queue.Push(1);
  queue.Push(2);
  queue.Push(3);
  ASSERT_ANY_THROW(queue.Push(5));
}

TEST(TQueue, cant_delete_item_from_empty_queue)
{
  TQueue<int> queue(4);
  ASSERT_ANY_THROW(queue.Pop());
}