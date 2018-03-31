#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "../Utility/Tree_utility.h"

namespace treefamily {

	template <typename T>
	class Rbtree {
	public:
		struct Node;
		using Tree = Node * ;
		enum Color {
			RED,
			BLACK,
		};
		struct Node {
			T      data_;
			Tree   left_;
			Tree   right_;
			Tree   parent_;
			Color  color_;
		};

		Rbtree() : root_(nullptr) {}
		~Rbtree();
		Rbtree(const Rbtree&) = delete;
		Rbtree(const Rbtree&&) = delete;
		Rbtree& operator=(Rbtree&) = delete;
		Rbtree& operator=(Rbtree&&) = delete;

		Tree Find(const T data) const;
		Tree Insert(const T data);
		void Delete(const T data);
		void Clear();

		void Prelist()  const;
		void Postlist() const;

	private:
		Tree root_;
	};

	template<typename T>
	Rbtree<T>::~Rbtree()
	{
		clear_tree(root_);
	}

	template<typename T>
	typename Rbtree<T>::Tree Rbtree<T>::Find(const T data) const
	{
		return find_node(root_, data);
	}

	template<typename T>
	typename Rbtree<T>::Tree Rbtree<T>::Insert(const T data)
	{

	}

	template<typename T>
	void Rbtree<T>::Delete(const T data)
	{
	}

	template<typename T>
	void Rbtree<T>::Clear()
	{
		clear_tree(root_);
		root_ = nullptr;
	}

	template<typename T>
	void Rbtree<T>::Prelist() const
	{
		preorder_traversal(root_);
	}

	template<typename T>
	void Rbtree<T>::Postlist() const
	{
		postorder_traversal(root_);
	}

}

#endif // !_RBTREE_H_