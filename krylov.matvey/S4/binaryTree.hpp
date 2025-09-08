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

  template< typename Key, typename T, typename Cmp >
  BiTree< Key, T, Cmp >::BiTree():
    fakeRoot_(new BiTreeNode< Key, T >{ std::pair< Key, T >{}, nullptr, nullptr, nullptr }),
    fakeLeaf_(new BiTreeNode< Key, T >{ std::pair< Key, T >{}, nullptr, nullptr, nullptr }),
    size_(0),
    cmp_(Cmp{})
  {
    fakeLeaf_->parent = fakeRoot_;
    fakeRoot_->left = fakeLeaf_;
    fakeRoot_->right = fakeLeaf_;
  }

  template< typename Key, typename T, typename Cmp >
  BiTree< Key, T, Cmp >::BiTree(BiTree< Key, T, Cmp >&& rhs) noexcept:
    fakeRoot_(rhs.fakeRoot_),
    fakeLeaf_(rhs.fakeLeaf_),
    size_(rhs.size_),
    cmp_(rhs.cmp_)
  {
    rhs.fakeRoot_ = new BiTreeNode< Key, T >{ std::pair< Key, T >{}, nullptr, nullptr, nullptr };
    rhs.fakeLeaf_ = new BiTreeNode< Key, T >{ std::pair< Key, T >{}, nullptr, nullptr, rhs.fakeRoot_ };
    rhs.fakeRoot_->left = rhs.fakeLeaf_;
    rhs.fakeRoot_->right = rhs.fakeLeaf_;
    rhs.size_ = 0;
  }

  template< typename Key, typename T, typename Cmp >
  size_t BiTree< Key, T, Cmp >::size() const noexcept
  {
    return size_;
  }

  template< typename Key, typename T, typename Cmp >
  bool BiTree< Key, T, Cmp >::empty() const noexcept
  {
    return size_ == 0;
  }

  template< typename Key, typename T, typename Cmp >
  void BiTree< Key, T, Cmp >::swap(BiTree< Key, T, Cmp >& rhs) noexcept
  {
    std::swap(fakeRoot_, rhs.fakeRoot_);
    std::swap(fakeLeaf_, rhs.fakeLeaf_);
    std::swap(size_, rhs.size_);
  }

}

#endif
