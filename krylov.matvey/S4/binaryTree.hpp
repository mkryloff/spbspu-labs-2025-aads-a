#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP
#include <cstddef>
#include "treeNode.hpp"
#include "treeConstIterators.hpp"

namespace krylov
{
  template< typename Key, typename T, typename Cmp >
  class ConstIterator;

  template< typename Key, typename T, typename Cmp >
  class BiTree
  {
    BiTree();
    BiTree(const BiTree< Key, T, Cmp >& rhs);
    BiTree(BiTree< Key, T, Cmp >&& rhs) noexcept;
    ~BiTree();
    BiTree< Key, T, Cmp >& operator=(const BiTree< Key, T, Cmp >& rhs);
    BiTree< Key, T, Cmp >& operator=(BiTree< Key, T, Cmp >&& rhs) noexcept;
    ConstIterator< Key, T, Cmp > cbegin() const noexcept;
    ConstIterator< Key, T, Cmp > cend() const noexcept;
    T& at(const Key & key);
    const T& at(const Key& key) const;
    T& operator[](const Key& key);
    ConstIterator< Key, T, Cmp > find(const Key& key) const;
    void clear() noexcept;
    void swap(BiTree< Key, T, Cmp >& rhs) noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
   private:
    BiTreeNode< Key, T > * fakeRoot_;
    BiTreeNode< Key, T > * fakeLeaf_;
    size_t size_;
    Cmp cmp_;
  };
}

#endif
