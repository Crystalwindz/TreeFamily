#ifndef _TREAP_H_
#define _TREAP_H_

#include "../Utility/Tree_utility.h"
#include <random>
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
			int    size_;
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
		int get_size() {
			static std::random_device r;
			static std::default_random_engine dr(r);
			static std::uniform_int_distribution<int> dis(0, 99999999);
			return dis(dr);
		}
		int size(Tree root) {
			return root == nullptr ? 999999999 : root->size_;
		}
		void l_rotate(Tree& root) {
			Tree rchild = root->right_;
			root->right_ = rchild->left_;
			rchild->left_ = root;
			root = rchild;
		}
		void r_rotate(Tree& root) {
			Tree lchild = root->left_;
			root->left_ = lchild->right_;
			lchild->right_ = root;
			root = lchild;
		}
		Tree true_insert(Tree& root, Tree node) {
			if (node->data_ < root->data_)
				root->left_ = true_insert(root->left_, node);
			else if (node->data > root->data_)
				root->right_ = true_insert(root->right_, node);
			else
				return node;

			if (size(root) > size(root->left_))
				r_rotate(root);
			else if (size(root) > size(root->right_))
				l_rotate(root);
			return root;
		}

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
		Tree& pos = find_node(root_, data);
		if (pos != nullptr)
			return nullptr;

		pos = new Node{ data, nullptr, nullptr, get_size() };
		true_insert(root_, pos);
		return pos;
	}

	template<typename T>
	void Treap<T>::Delete(const T data)
	{
		Tree& pos = find_node(root_, data);
		if (pos == nullptr)
			return;

		Tree* ptr = &pos;
		while ((*ptr)->right_ && (*ptr)->left_) {
			if (size((*ptr)->left_) < size((*ptr)->right_)) {
				r_rotate(*ptr);
				ptr = &((*ptr)->right_);
			}
			else {
				l_rotate(*ptr);
				ptr = &((*ptr)->left_);
			}
		}
		if ((*ptr)->left_ == nullptr) {
			Tree del = *ptr;
			(*ptr) = (*ptr)->right_;
			delete del;
		}
		else {
			Tree del = *ptr;
			(*ptr) = (*ptr)->left_;
			delete del;
		}
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