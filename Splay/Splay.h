#ifndef _SPLAY_H_
#define _SPLAY_H_

#include "../Utility/Tree_utility.h"

namespace treefamily {

	template <typename T>
	class Splay {
	public:
		struct Node;
		using Tree = Node * ;
		struct Node {
			T      data_;
			Tree   left_;
			Tree   right_;
			Tree   parent_;
		};

		Splay() : root_(nullptr) {}
		~Splay();
		Splay(const Splay&) = delete;
		Splay(const Splay&&) = delete;
		Splay& operator=(Splay&) = delete;
		Splay& operator=(Splay&&) = delete;

		Tree Find(const T data) const;
		Tree Insert(const T data);
		void Delete(const T data);
		void Clear();

	private:
		Node * root_;
	};

	template<typename T>
	Splay<T>::~Splay()
	{
		clear_tree(root_);
	}

	template<typename T>
	typename Splay<T>::Tree Splay<T>::Find(const T data) const
	{
		return find_node(root_, data);
	}

	template<typename T>
	typename Splay<T>::Tree Splay<T>::Insert(const T data)
	{
		return Tree();
	}

	template<typename T>
	void Splay<T>::Delete(const T data)
	{
	}

	template<typename T>
	void Splay<T>::Clear()
	{
		clear_tree(root_);
		root_ = nullptr;
	}

	template<typename T>
	void Splay<T>::Prelist() const
	{
		preorder_traversal(root_);
	}

	template<typename T>
	void Splay<T>::Postlist() const
	{
		postorder_traversal(root_);
	}

}

#endif // !_SPLAY_H_