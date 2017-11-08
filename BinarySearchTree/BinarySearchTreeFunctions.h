#ifndef __BINARY__SEARCH__TREE__FUNCTIONS__HEADER__INCLUDED__
#define __BINARY__SEARCH__TREE__FUNCTIONS__HEADER__INCLUDED__

#include <iostream>
#include "BinarySearchTree.h"

template <class TYPE>
inline BinarySearchTree<TYPE>::BinarySearchTree()
	:root(NULL)
{}

template <class TYPE>
inline BinarySearchTree<TYPE>::~BinarySearchTree()
{
	clean(root);
}

template<class TYPE>
inline void BinarySearchTree<TYPE>::add(const TYPE & key)
{
	addHelper(root, key);
}

template<class TYPE>
inline bool BinarySearchTree<TYPE>::remove(const TYPE & key)
{
	if (search(key))
	{
		removeHelper(root, key);
		return true;
	}
	else
		return false;
}

template<class TYPE>
inline bool BinarySearchTree<TYPE>::search(const TYPE & key)
{
	return searchHelper(root, key);
}

template<class TYPE>
inline void BinarySearchTree<TYPE>::addHelper(node *& root, const TYPE & key)
{
	if (!root)
	{
		root = new node(key);
	}
	else if (key <= root->key)
	{
		addHelper(root->leftChild, key);
	}
	else //(key > root->key)
	{
		addHelper(root->rightChild, key);
	}
}

template<class TYPE>
inline void BinarySearchTree<TYPE>::removeHelper(node *& root, const TYPE & key)
{
	if (root->key < key)
		removeHelper(root->rightChild, key);
	else if (root->key > key)
		removeHelper(root->leftChild, key);
	else
	{
		if (root->leftChild && root->rightChild)
		{
			node * replace = minKey(root->rightChild);
			root->key = replace->key;
			removeHelper(root->rightChild, replace->key);
		}
		else
		{
			node * destroyer = root;
			if (root->leftChild)
				root = root->leftChild;
			else
				root = root->rightChild;
			delete destroyer;
		}
	}
}

template<class TYPE>
inline bool BinarySearchTree<TYPE>::searchHelper(node *& root, const TYPE & key)
{
	if (!root)
		return false;
	else if (root->key > key)
		searchHelper(root->leftChild, key);
	else if (root->key < key)
		searchHelper(root->rightChild, key);
	else
		return true;
}

template <class TYPE>
inline void BinarySearchTree<TYPE>::clean(node *& root)
{
	if (root)
	{
		clean(root->leftChild);
		clean(root->rightChild);
		delete root;
	}
}

#endif // !__BINARY__SEARCH__TREE__FUNCTIONS__HEADER__INCLUDED__
