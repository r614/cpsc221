/**
 * @file queue.cpp
 * Implementation of the Queue class.
 *
 * Modify and turn in this file for the PA!
 *
 */

/*
 * stack_1 will be the "input" stack
 * stack_2 will be the "output" stack
 */

/**
 * Adds the parameter object to the back of the Queue.
 *
 * @param newItem object to be added to the Queue.
 */
template <class T>
void Queue<T>::enq(T const &newItem)
{
  stack_1.push(newItem);
}

/**
 * Removes the object at the front of the Queue, and returns it to the
 * caller.
 *
 * @return The object that used to be at the front of the Queue.
 */
template <class T>
T Queue<T>::deq()
{
  if (stack_2.empty())
  {
    while (!stack_1.empty())
    {
      stack_2.push(stack_1.pop());
    }
  }
  return stack_2.pop();
}

/**
 * Finds the object at the front of the Queue, and returns it to the
 * caller. Unlike deq(), this operation does not alter the queue.
 *
 * @return The item at the front of the queue.
 */
template <class T>
T Queue<T>::peek()
{
  if (stack_2.empty())
  {
    while (!stack_1.empty())
    {
      stack_2.push(stack_1.pop());
    }
  }
  return stack_2.peek();
}

/**
 * Determines if the Queue is empty.
 *
 * @return bool which is true if the Queue is empty, false otherwise.
 */
template <class T>
bool Queue<T>::empty() const
{
  return stack_1.empty() && stack_2.empty();
}
