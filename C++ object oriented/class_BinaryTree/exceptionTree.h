#pragma once
#include <iostream>
#include <string>
#include "tree.h"

template<typename T>
class Node;

class TreeException
{
protected:
	std::string what;
public:
	TreeException(std::string what) : what(what) {}
	void info() const {
		std::cout << what << '\n';
	}
};

template<typename T>
class NotALeafException : public TreeException
{
	Node<T>* node;
public:
	NotALeafException(Node<T>* node)
		: TreeException(""), node(node) {
		this->what = "Wezel zawierajacy: ";
		this->what += (*(node->getData())) + " nie jest lisciem";
	}
};
