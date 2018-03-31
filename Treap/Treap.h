#ifndef _TREAP_H_
#define _TREAP_H_

#include "../Utility/Tree_utility.h"

namespace treefamily {

	template <typename T>
	class Treap {
	public:
		struct Node;
		using Tree = Node * ;
		struct Node {
			T      data_;
			Tree   left_;
			Tree   right_;
		};

		Treap() : root_(nullptr) {}
		~Treap();
		Treap(const Treap&) = delete;
		Treap(const Treap&&) = delete;
		Treap& operator=(Treap&) = delete;
		Treap& operator=(Treap&&) = delete;

		Tree Find(const T data) const;
		Tree Insert(const T data);
		void Delete(const T data);
		void Clear();

	private:
		Node * root_;
	};

	template<typename T>
	Treap<T>::~Treap()
	{
		clear_tree(root_);
	}

	template<typename T>
	typename Treap<T>::Tree Treap<T>::Find(const T data) const
	{
		return find_node(root_, data);
	}

	template<typename T>
	typename Treap<T>::Tree Treap<T>::Insert(const T data)
	{
		return Tree();
	}

	template<typename T>
	void Treap<T>::Delete(const T data)
	{
	}

	template<typename T>
	void Treap<T>::Clear()
	{
		clear_tree(root_);
		root_ = nullptr;
	}

	template<typename T>
	void Treap<T>::Prelist() const
	{
		preorder_traversal(root_);
	}

	template<typename T>
	void Treap<T>::Postlist() const
	{
		postorder_traversal(root_);
	}

}

#endif // !_TREAP_H_