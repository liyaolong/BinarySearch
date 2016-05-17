#pragma once

template<class K,class V>
struct BSTNode
{
	K _key;
	V _value;

	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;
	BSTNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template<class K,class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value)
	{
		return _Insert(_root,key, value);
	}
	bool _Insert(Node* root,const K& key, const V& value)
	{
		if (root == nullptr)
			root = new Node(key, value);
		if (root->_key > key)
			return _Insert(root->_left, key, value);
		else if (root->_key < key)
			return _Insert(root->_right, key, value);
		else
			return false;
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root;
};

void Test()
{
	BSTree<int, int> t;
	t.Insert(5, 5);
	t.Insert(3, 3);
	t.Insert(4, 4);
	t.Insert(1, 1);
	t.Insert(7, 7);
	t.Insert(8, 8);
	t.Insert(2, 2);
	t.Insert(6, 6);
	t.Insert(0, 0);
	t.Insert(9, 9);
	t.InOrder();
}