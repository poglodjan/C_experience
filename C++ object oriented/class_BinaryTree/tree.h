#include <complex>
#include <list
#include "exceptionTree.h"
#include "exception.h"
using namespace std;

template<typename T>
class Tree;

template<typename T = int>
class Node
{
	friend Tree<T>;
	T* data;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	Node* parent = nullptr;
public:
	Node(T* data) : data(data) {}
	T* getData() {return data;}
}

template<typename T = int>
class Tree
{
public:
	Node<T>* root;
	unsigned count;
public:
	Tree() : root(nullptr), count(0) {};
	~Tree() {clear();}
	bool isEmpty() const {return !root;};
	unsigned size() const {return count;};
	T* getRoot() const;
	bool add(T* data);
	void clear();

	template<typename T>
	friend ostream& operator<<(ostream& out, counst Tree& tree);
	list<Node<T>*> preorder(Node<T>* n, list<Node<T>*> list) const;

	void removeLeaf(Node<T>* n);
	void removeNode(Node<T>* n);

	void showExampleTree();
	void removeExampleTree();
	Node<T>* getRootNode() {return root;};
}

template<typename T>
void Tree<T>::showExampleTree()
{
	std::cout << "   " << *root->data << std::endl;
	std::cout << " " << *root->leftChild->data << "   " << *root->rightChild->data << std::endl;
	std::cout << *root->leftChild->leftChild->data << " " << *root->leftChild->rightChild->data << " ";
	std::cout << *root->rightChild->leftChild->data << " " << *root->rightChild->rightChild->data << std::endl;
}

template<typename T>
void Tree<T>::removeExampleTree()
{
	removeNode(root->leftChild);
	removeNode(root->rightChild);
}


template<typename T>
T* Tree<T>::getRoot() const {
	if (!root) throw "Puste drzewo - brak korzenia";
	return root->data;
}

template<typename T>
bool Tree<T>::add(T* data) {
	Node<T>* node = new Node<T>(data);
	if (node == nullptr) return false;
	if (!root) {
		root = node;
		count++;
		return true;
	}

	Node<T>* subroot = root;
	while (true) {
		if (*data <= *subroot->getData()) {
			if (subroot->leftChild == nullptr) {
				node->parent = subroot;
				subroot->leftChild = node;
				count++;
				return true;
			}
			subroot = subroot->leftChild;
		}
		else {
			if (subroot->rightChild == nullptr) {
				node->parent = subroot;
				subroot->rightChild = node;
				count++;
				return true;
			}
			subroot = subroot->rightChild;
		}
	}
}

template<typename T>
void Tree<T>::removeLeaf(Node<T>* n) {
	if (n == nullptr) {
		throw TreeException("Wezel nie istnieje");
	}
	if (n->leftChild != nullptr || n->rightChild != nullptr) {
		throw NotALeafException<T>(n);
	}
	if (n->parent == nullptr) {
		root = nullptr;
	}
	else {
		if (n == n->parent->leftChild) {
			n->parent->leftChild = nullptr;
		}
		if (n == n->parent->rightChild) {
			n->parent->rightChild = nullptr;
		}
	}
	count--;
	delete n->data;
	delete n;
}

template<typename T>
void Tree<T>::removeNode(Node<T>* n) {
	if (n == nullptr) {
		throw TreeException("Wezel nie istnieje");
	}
	if (n->leftChild != nullptr) removeNode(n->leftChild);
	if (n->rightChild != nullptr) removeNode(n->rightChild);
	removeLeaf(n);
}

template<typename T>
void Tree<T>::clear() {
	try {
		removeNode(root);
	}
	catch (TreeException& e) {
		e.info();
	}
}

template<typename T>
std::list<Node<T>*> Tree<T>::preorder(Node<T>* n, std::list<Node<T>*> lista) const {
	lista.push_back(n);
	if (n->leftChild != nullptr) lista = preorder(n->leftChild, lista);
	if (n->rightChild != nullptr) lista = preorder(n->rightChild, lista);
	return lista;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, const Tree<T>& tree) {
	std::list<Node<T>*> lista;
	lista = tree.preorder(tree.root, lista);
	for (Node<T>* n : lista) {
		out << (*(n->getData())) << " ";
	}
	return out;
}


