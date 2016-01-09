#pragma once

template<typename E>
class BinNode {
public :
	virtual ~BinNode() {}

	virtual E& element() = 0;
	virtual void setElement(const E&) = 0;
	virtual BinNode* left() const = 0;
	virtual void setLeft(BinNode*) = 0;
	virtual BinNode* right() const = 0;
	virtual void setRight(BinNode*) = 0;
	virtual bool isLeaf() = 0;
};

template<typename Key, typename E>
class BSTNode : public BinNode<E> {
private :
	Key k;
	E it;
	BSTNode* lc;
	BSTNode* rc;
public :
	BSTNode() { lc = rc = nullptr; }
	BSTNode(const Key& K, const E& e, BSTNode* l = nullptr, BSTNode* r = nullptr) {
		k = K;
		it = e;
		lc = l;
		rc = r;
	}
	~BSTNode() {}

	E& element() { return it; }
	void setElement(const E& e) { it = e; }
	Key& key() { return k; }
	void setKey(const Key& K) { k = K; }

	inline BSTNode* left() const { return lc; }
	void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
	inline BSTNode* right() const { return rc; }
	void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }

	bool isLeaf() { return (lc == nullptr) && (rc == nullptr); }
};

template<typename E>
void preorder(BinNode<E>* root) {
	if (root == nullptr) return;
	visit(root);
	preorder(root->left());
	preorder(root->right());
}

template<typename E>
void postorder(BinNode<E>* root) {
	if (root == nullptr) return;
	postorder(root->left());
	postorder(root->right());
	visit(root);
}

template<typename E>
void inorder(BinNode<E>* root) {
	if (root == nullptr) return;
	inorder(root->left());
	visit(root);
	inorder(root->right());
}

template<typename E>
int count(BinNode<E>* root) {
	if (root == nullptr) return 0;
	return 1 + count(root->left())
			 + count(root->right());
}

template<typename Key, typename E>
bool checkBST(BSTNode<Key,E>* root, Key low, Key high) {
	if (root == nullptr) return true;
	Key rootkey = root->key();
	if ((rootkey < low) || (rootkey > high))
		return false;
	if (!checkBST<Key,E>(root->left(), low, rootkey))
		return false;
	return checkBST<Key,E>(root->right(), rootkey, high);
}

