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

