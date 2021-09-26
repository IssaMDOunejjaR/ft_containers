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

ft::RedBlackTree<ft::pair<int, int>, std::less<int> >::Node * MorrisTraversal(ft::RedBlackTree<ft::pair<int, int>, std::less<int> > root, ft::RedBlackTree<ft::pair<int, int>, std::less<int> >::Node *current)
{
    ft::RedBlackTree<ft::pair<int, int>, std::less<int> >::Node *pre;
 
    // if (current == root.getTNULL())
    //     return current;
 
    // current = root.getRoot();
    while (current != root.getTNULL()) {
 
		// std::cout << current->data.first << std::endl;
        if (current->left == root.getTNULL()) {
            // printf("%d ", current->data.first);
			// return current;
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != root.getTNULL()
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == root.getTNULL()) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = root.getTNULL();
				// return current;
                // printf("%d ", current->data.first);
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
	return current;
}

void inOrderTraversal(ft::RedBlackTree<ft::pair<int, int>, std::less<int> > root)
{
	// Create an empty stack.
	std::stack<ft::RedBlackTree<ft::pair<int, int>, std::less<int> >::Node*> stack;

	// Start from the root node.
	ft::RedBlackTree<ft::pair<int, int>, std::less<int> >::Node *curr = root.getRoot();

	// If the current node is null and stack is also empty, the algorithm terminates.
	while (!stack.empty() || curr != root.getTNULL())
	{
    // Push the current node to the stack and set current=current->left.
		if (curr != root.getTNULL())
		{
			stack.push(curr);
			curr = curr->left;
		}
		else // If the curr node is NULL.
		{
			curr = stack.top(); 
			stack.pop(); // Pop the node on top of stack.
			std::cout << curr->data.first << " "; // Print it.
			curr = curr->right; 
		}
	}
}

typedef ft::RedBlackTree<ft::pair<int, int>, std::less<int> >::Node 	Node;
typedef ft::RedBlackTree<ft::pair<int, int>, std::less<int> >					Tree;

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

Node* getTheNextNode(Tree * tree, Node * node) {
	if (node == tree->lastElement())
		return tree->getTNULL();
	else if (node->right == tree->getTNULL())
		return node->parent;
	else
		return InOrderSuccessor(tree, node->right);
}

Node* getThePrevNode(Tree * tree, Node * node) {
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

	// root.del(2);
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