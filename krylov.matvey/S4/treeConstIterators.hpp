#ifndef TREECONSTITERATORS_HPP
#define TREECONSTITERATORS_HPP
#include "treeNode.hpp"
#include "binaryTree.hpp"

namespace krylov
{
  template< typename Key, typename T, typename Cmp >
  class BiTree;

  template< typename Key, typename T, typename Cmp >
  class ConstIterator
  {
  public:
    ConstIterator();
    ConstIterator(const ConstIterator< Key, T, Cmp >&) = default;
    ~ConstIterator() = default;
    ConstIterator< Key, T, Cmp >& operator=(const ConstIterator< Key, T, Cmp >&) = default;
    ConstIterator< Key, T, Cmp >& operator++();
    ConstIterator< Key, T, Cmp > operator++(int);
    ConstIterator< Key, T, Cmp >& operator--();
    ConstIterator< Key, T, Cmp > operator--(int);
    const std::pair< Key, T >& operator*() const;
    const std::pair< Key, T >* operator->() const;
    bool operator==(const ConstIterator< Key, T, Cmp >& rhs) const;
    bool operator!=(const ConstIterator< Key, T, Cmp >& rhs) const;
  private:
    BiTreeNode< Key, T >* node_;
    BiTreeNode< Key, T >* fakeLeaf_;
    friend class BiTree< Key, T, Cmp >;
    explicit ConstIterator(BiTreeNode< Key, T >* node, BiTreeNode< Key, T >* fakeLeaf);
  };
}

#endif
