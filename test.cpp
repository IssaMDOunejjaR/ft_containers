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

// Node* InOrderSuccessor(Tree * tree, Node * node) {
// 	if (node->left == tree->getTNULL())
// 		return node;
// 	return InOrderSuccessor(tree, node->left);
// }

// Node* InOrderPredeccessor(Tree * tree, Node * node) {
// 	if (node->right == tree->getTNULL())
// 		return node;
// 	return InOrderPredeccessor(tree, node->right);
// }

// std::stack<Node *>	stack;


// Node*	getThePrevNode(Tree * tree, Node * current) {
// 	Node* tmp;

// 	if (current != tree->firstElement()) {
// 		if (current->left != tree->getTNULL()) {
// 			current = current->left;

// 			while (current->right != tree->getTNULL())
// 				current = current->right;
// 		}
// 		else {
// 			tmp = current->parent;
// 			while (tmp != tree->getTNULL() && current == tmp->left) {
// 				current = tmp;
// 				tmp = tmp->parent;
// 			}
// 			current = tmp;
// 		}
// 	}
// 	else
// 		current = tree->getTNULL();

// 	return current;
// }

// Node*	getTheNextNode(Tree * tree, Node * current) {
// 	Node* tmp;

// 	if (current != tree->lastElement()) {
// 		if (current->right != tree->getTNULL()) {
// 			current = current->right;

// 			while (current->left != tree->getTNULL())
// 				current = current->left;
// 		}
// 		else {
// 			tmp = current->parent;
// 			while (tmp != tree->getTNULL() && current == tmp->right) {
// 				current = tmp;
// 				tmp = tmp->parent;
// 			}
// 			current = tmp;
// 		}
// 	}
// 	else
// 		current = tree->getTNULL();

// 	return current;
// }

int		main(void) {
	Tree	root;

	root.insert(ft::pair<int, int>(10, 123));
	root.insert(ft::pair<int, int>(11, 123));
	root.insert(ft::pair<int, int>(12, 123));
	root.insert(ft::pair<int, int>(13, 123));
	root.insert(ft::pair<int, int>(14, 123));
	root.insert(ft::pair<int, int>(15, 123));
	root.insert(ft::pair<int, int>(16, 123));

	root.del(10);

	root.print();

	// Node* curr = root.firstElement();

	// std::cout << curr->data.first << std::endl;

	// std::cout << stack.top()->data.first << std::endl;
	// stack.pop();
	// std::cout << stack.top()->data.first << std::endl;

	// Node *current = root.firstElement();

	// std::cout << current->data.first << std::endl;

	// current = getTheNextNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// current = getThePrevNode(&root, current);
	// std::cout << current->data.first << std::endl;

	// while (current != root.getTNULL()) {
	// 	std::cout << current->data.first << std::endl;
	// 	current = getThePrevNode(&root, current);
	// }

	return 0;
}