	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:34:23 by iounejja          #+#    #+#             */
/*   Updated: 2021/09/19 17:13:02 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <stack>
#include "red_black_tree.hpp"
#include "utility.hpp"

typedef ft::RedBlackTree<ft::pair<int, int>, std::less<int> >::Node 	Node;
typedef ft::RedBlackTree<ft::pair<int, int>, std::less<int> >			Tree;

Node * prev;

Node* InOrderSuccessor(Tree * tree, Node * node) {
	if (node->left == tree->getTNULL())
		return node;
	return InOrderSuccessor(tree, node->left);
}

Node* InOrderPredeccessor(Tree * tree, Node * node) {
	if (node->right == tree->getTNULL())
		return node;
	return InOrderPredeccessor(tree, node->right);
}

Node*	getTheNextNode(Tree * tree, Node * node) {
	if (node == tree->lastElement())
		return tree->getTNULL();
	else if (node->right == tree->getTNULL()) {
		return node->parent;
	}
	else {
		return InOrderSuccessor(tree, node->right);
	}
}

Node*	getThePrevNode(Tree * tree, Node * node) {
	if (node->left->left == NULL && node->left->right == NULL) {
		if (prev != NULL)
			return prev->parent;
		return node->parent;
	}
	else {
		prev = node;
		return InOrderPredeccessor(tree, node->left);
	}
}

int		main(void) {
	Tree	root;

	root.insert(ft::pair<int, int>(10, 123));
	root.insert(ft::pair<int, int>(11, 123));
	root.insert(ft::pair<int, int>(12, 123));
	root.insert(ft::pair<int, int>(13, 123));
	root.insert(ft::pair<int, int>(14, 123));
	root.insert(ft::pair<int, int>(15, 123));
	root.insert(ft::pair<int, int>(16, 123));

	Node *current;

	root.del(10);
	// root.del(1);

	// root.print();

	prev = NULL;
	current = root.firstElement();

	while (1) {
		std::cout << current->data.first << std::endl;
		current = getTheNextNode(&root, current);

		if (current == root.getTNULL())
			break ;
	}


	// current = getThePrevNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// current = getThePrevNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// current = getThePrevNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// current = getThePrevNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// current = getThePrevNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// current = getThePrevNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// std::cout << "Length = " << root.size() << std::endl;

	return 0;
}