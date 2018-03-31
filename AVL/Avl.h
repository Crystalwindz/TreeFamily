#ifndef _AVL_H_
#define _AVL_H_

#include "../Utility/Tree_utility.h"

namespace treefamily {

	template <typename T>
	class Avl {
	public:
		struct Node;
		using Tree = Node * ;
		struct Node {
			T      data_;
			Tree   left_;
			Tree   right_;
			Tree   parent_;
			int	   height_;
		};

		Avl() : root_(nullptr) {}
		~Avl();
		Avl(const Avl&) = delete;
		Avl(const Avl&&) = delete;
		Avl& operator=(Avl&) = delete;
		Avl& operator=(Avl&&) = delete;

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
	Avl<T>::~Avl()
	{
		clear_tree(root_);
	}

	template<typename T>
	typename Avl<T>::Tree Avl<T>::Find(const T data) const
	{
		return find_node(root_, data);
	}

	template<typename T>
	typename Avl<T>::Tree Avl<T>::Insert(const T data)
	{
		return Tree();
	}

	template<typename T>
	void Avl<T>::Delete(const T data)
	{
	}

	template<typename T>
	void Avl<T>::Clear()
	{
		clear_tree(root_);
		root_ = nullptr;
	}

	template<typename T>
	void Avl<T>::Prelist() const
	{
		preorder_traversal(root_);
	}

	template<typename T>
	void Avl<T>::Postlist() const
	{
		postorder_traversal(root_);
	}

}

#endif // !_AVL_H_