#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>

namespace ft
{
	// AVL tree: é um jeito de manter nossa arvore em equilibrio, utilizando das rotações entre filhos e pais para conseguir um equilibrio entre os
	// galhos, e não ficar com um galho maior que o outro
	// https://www.freecodecamp.org/news/avl-tree-insertion-rotation-and-balance-factor/
	template <class Pair>
	struct BSTNode
	{

		BSTNode *parent;
		BSTNode *left;
		BSTNode *right;
		Pair value;
		// height: The maximum number of nodes that can be visited starting at the tree's root and moving only downward. An an empty tree has height 0.
		int height;

		explicit BSTNode() : parent(NULL), left(NULL), right(NULL), value(), height(0){};

		explicit BSTNode(const Pair &data) : parent(NULL), left(NULL), right(NULL), value(data), height(0){};

		~BSTNode(){};

		BSTNode(const BSTNode &x) { *this = x; }

		BSTNode &operator=(const BSTNode &x)
		{
			if (this != &x)
			{
				parent = x.parent;
				left = x.left;
				right = x.right;
				value = x.value;
				height = x.height;
			}
			return *this;
		}

		//acha o menor item da lista
		BSTNode *findMin(BSTNode *node)
		{
			if (!node)
				return NULL;
			while (node->left)
				node = node->left;
			return node;
		}

		//acha o maior item da lista
		BSTNode *findMax(BSTNode *node)
		{
			if (!node)
				return NULL;
			while (node->right)
				node = node->right;
			return node;
		}

		// next node in inorder traversal
		BSTNode *sucessor()
		{
			BSTNode *tmp = this;

			// case 1: Node has right subtree
			if (tmp->right)
				return findMin(tmp->right);

			// case 2: não existir um node na esquerda
			// subir a hierarquia com o pai, até o filho parar de ser o direito e se tornar o esquerdo, quando isso acontecer,
			// significa que o pai é o sucessor
			BSTNode *tmp_parent = tmp->parent;

			while (tmp_parent && tmp == tmp_parent->right)
			{
				tmp = tmp_parent;
				tmp_parent = tmp_parent->parent;
			}
			return tmp_parent;
		}

		// retorna o node antecessor 
		BSTNode *predecessor()
		{
			BSTNode *tmp = this;

			// case 1: existir um node na esquerda
			//rodar o findmax até achar o numero antecessor
			if (tmp->left)
				return findMax(tmp->left);

			// case 2: não existir um node na esquerda
			// subir a hierarquia com o pai, até o filho parar de ser o esquerdo e se tornar o direito, quando isso acontecer,
			// significa que o pai é o antecessor
			BSTNode *tmp_parent = tmp->parent;
			while (tmp_parent && tmp == tmp_parent->left)
			{
				tmp = tmp_parent;
				tmp_parent = tmp_parent->parent;
			}
			return tmp_parent;
		}
	};

}

#endif
