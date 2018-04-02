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
		int Max(int a, int b) {
			return a > b ? a : b;
		}
		int Height(Tree root) {
			return (root == nullptr ? 0 : root->height_);
		}
		int Balance_factor(Tree root) {
			return Height(root->right_) - Height(root->left_);
		}

		Tree Lrotate(Tree root) {
			Tree node = root->right_;
			left_rotate(node);
			node->left_->height_ = Max(Height(node->left_->left_),
				                   Height(node->left_->right_)) + 1;
			node->height_ = Max(Height(node->left_),
				                   Height(node->right_)) + 1;
			return node;
		}
		Tree Rrotate(Tree root) {
			Tree node = root->left_;
			right_rotate(node);
			node->right_->height_ = Max(Height(node->right_->left_),
				                   Height(node->right_->right_)) + 1;
			node->height_ = Max(Height(node->left_),
				                Height(node->right_)) + 1;
			return node;
		}
		Tree LRrotate(Tree root) {
			root->left_ = Lrotate(root->left_);
			return Rrotate(root);
		}
		Tree RLrotate(Tree root) {
			root->right_ = Rrotate(root->right_);
			return Lrotate(root);
		}
		Tree Fix(Tree root) {
			if (Balance_factor(root) > 0) {
				if (Balance_factor(root->right_) > 0)
					root = Lrotate(root);
				else
					root = RLrotate(root);
			}
			else {
				if (Balance_factor(root->left_) < 0)
					root = RLrotate(root);
				else
					root = LRrotate(root);
			}
			return root;
		}

		Tree true_insert(Tree node, Tree root) {
			if (root == node)
				;
			else if (node->data_ < root->data_) {
				root->left_ = true_insert(node, root->left_);
				if (Balance_factor(root) <= -2)
					root = Fix(root);
			}
			else if (node->data_ > root->data_) {
				root->right_ = true_insert(node, root->right_);
				if (Balance_factor(root) >= 2)
					root = Fix(root);
			}
			root->height_ = Max(Height(root->left_),
				           Height(root->right_)) + 1;
			return root;
		}
		Tree true_delete(Tree node, Tree root) {
			Tree tmp;
			if (node->data_ < root->data_)
				root->left_ = true_delete(node, root->left_);
			else if (node->data_ > root->data_)
				root->right_ = true_delete(node, root->right_);
			else if (root->left_ && root->right_) {
				tmp = find_min(root->right_);
				root->data_ = tmp->data_;
				root->right_ = true_delete(tmp, root->right_);
			}
			else {
				tmp = root;
				if (root->left_ == nullptr)
					root = root->right_;
				else
					root = root->left_;

				delete tmp;
			}

			root->height_ = Max(Height(root->left_), 
				Height(root->right_)) + 1;
			if (Balance_factor(root) >= 2 || Balance_factor(root) <= -2) {
				root = Fix(root);
				root->height_ = Max(Height(root->left_),
					Height(root->right_)) + 1;
			}
			
			return root;
		}

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
		auto pos = find_node_parent(root_, data);
		if (pos.first != nullptr)
			return nullptr;

		pos.first = new Node{ data, nullptr, nullptr, pos.second, 1 };
		true_insert(pos.first, root_);
		return pos.first;
	}

	template<typename T>
	void Avl<T>::Delete(const T data)
	{
		auto pos = find_node_parent(root_, data);
		if (pos.first == nullptr)
			return;

		true_delete(pos.first, root_);
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