#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <cstddef>

template< typename T >
class Queue
{
public:
  Queue();
  Queue(const Queue< T >& other);
  Queue(Queue< T >&& other);
  ~Queue();
  Queue< T >& operator=(const Queue< T >& other);
  Queue< T >& operator=(Queue< T >&& other);
  bool empty() const noexcept;
  size_t size() const noexcept;
  const T& front() const;
  const T& back() const;
  T& front();
  T& back();
  void push_back(const T& value);
  void pop_front() noexcept;
private:
  T* data;
  size_t size_;
  size_t capacity_;
};

#endif
