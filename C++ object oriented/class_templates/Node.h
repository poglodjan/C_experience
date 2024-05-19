#pragma once

template <typename T>
class LList;

template <typename T>
class LNode
{
	friend class LList<T>;
public:
	LNode(T data) : data(data), next(nullptr) {};
	T getData() { return data; }
private:
	T data;
	LNode* next;
};

