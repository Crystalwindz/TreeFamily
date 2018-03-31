#ifndef _TREE_UTILITY_H_
#define _TREE_UTILITY_H_

namespace treefamily {

	template <typename TREE, typename DATA>
	TREE& find_node(TREE& root, DATA& data) {
		if (root == nullptr)
			return root;
		
		if (root->data_ > data)
			return find_node(root->left_, data);
		else if (root->data_ < data)
			return find_node(root->right_, data);
		else
			return root;
	}

	template <typename TREE>
	TREE& find_min(TREE& root) {
		if (root == nullptr)
			return nullptr;
		
		if (root->left_ == nullptr)
			return root;
		else
			return find_min(root->left_);
	}

	template <typename TREE>
	TREE& find_max(TREE& root) {
		if (root == nullptr)
			return nullptr;

		if (root->right_ == nullptr)
			return root;
		else
			return find_max(root->right_);
	}

	template <typename TREE>
	void clear_tree(TREE root) {
		if (root->left_ != nullptr)
			clear_tree(root->left_);
		if (root->right_ != nullptr)
			clear_tree(root->right_);
		delete root;
	}

}

#endif // !_TREE_UTILITY_H_
