#ifndef _BST_H_
#define _BST_H_

#include "Utility/Tree_utility.h"

namespace treefamily {

	template <typename T>
	class Bst {
	public:
		struct Node;
		using Tree = Node * ;
		struct Node {
			T      data_;
			Tree   left_;
			Tree   right_;
		}

		Bst() : root_(nullptr) {}
		~Bst();
		Bst(const Bst&)  = delete;
		Bst(const Bst&&) = delete;
		Bst& operator=(Bst& ) = delete;
		Bst& operator=(Bst&&) = delete;

		Tree Find(T data) const;
		Tree Insert(T data);
		void Delete(T data);
		void Clear();

	private:
		Tree root_;
	};

	template<typename T>
	Bst<T>::~Bst()
	{
		clear_tree(root_);
	}

	template<typename T>
	Bst<T>::Tree Bst<T>::Find(T data) const
	{
		return find_node(root_, data);
	}

	template<typename T>
	Bst<T>::Tree Bst<T>::Insert(T data)
	{
		Tree& pos = find_node(root_, data);
		if (pos == nullptr) {
			pos = new Node{ data, nullptr, nullptr };
			return pos;
		}
		else
			return nullptr;
	}

	template<typename T>
	void Bst<T>::Delete(T data)
	{
		Tree& pos = find_node(root_, data);
		if (pos == nullptr)
			return;
		
		if (pos->right_ == nullptr) {
			Tree del = pos;
			pos = pos->right_;
			delete del;
		} 
		else {
			min = find_min(pos->right_);
			pos->data_ = min->data_;
			Tree del = min;
			min = min->right_;
			delete del;
		}
	}

	template<typename T>
	void Bst<T>::Clear()
	{
		clear_tree(root_);
	}

}

#endif // !_BST_H_