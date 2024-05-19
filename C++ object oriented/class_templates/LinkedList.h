#include <iostream>
#include <complex>
#include "Node.h"
using namespace std;

// Headers
template <typename T>
void selection_sort(T arr, int n);
template <>
void selection_sort(complex<double>* arr, int n);

template <typename T>
void my_swap(T& a, T& b);

template <typename T>
void print_array(T arr, int n);

template <typename T, int N = 5>
void print_array(T(&arr)[N]);


int main()
{
	// Sorting

	int int_arr[] = { 5,4,3,2,1 };
	string string_arr[] = { "Ee","Dd","Cc","Bb","Aa" };
	complex<double> cmplx_arr[] = { complex<double>(2.5,3) , complex<double>(2.5,1), complex<double>(1.5,3), complex<double>(1.5,1), complex<double>(0.5,0) };

	// Sorting - non template/template

	print_array(int_arr, 5);
	selection_sort(int_arr, 5);
	print_array(int_arr);

	// Sorting -  template

	print_array<string*>(string_arr, 5);
	selection_sort<>(string_arr, 5);
	print_array(string_arr, 5);

	print_array<complex<double>*>(cmplx_arr, 5);
	selection_sort(cmplx_arr, 5);
	print_array(cmplx_arr, 5);


	cout << endl << endl;

	// LList/LinkedList
	const int size = 8;
	int arr[size] = { 32, 42, 45, 18, 41, 81, 15, 54 };
	complex<double> arr_cplx[size] = { complex<double>(2.5,3) , complex<double>(2.5,1), complex<double>(1.5,3), complex<double>(1.5,1), complex<double>(0.5,0), complex<double>(5.5,3) , complex<double>(2.5,5), complex<double>(0,0) };

	// LList - non template
	LList<> intLList1;
	cout << intLList1;

	for (int i = 0; i < size; )
	{
		intLList1.insertBegin(arr[i++]);
		intLList1.insertEnd(arr[i++]);
	}

	cout << intLList1;
	intLList1.sort();
	cout << intLList1;
	cout << endl << endl;

	/*
	// LinkedList - non template
	LinkedList intList1;
	cout << intList1;

	for (int i = 0; i < size; )
	{
		intList1.insertBegin(arr[i++]);
		intList1.insertEnd(arr[i++]);
	}

	cout << intList1;
	intList1.sort();
	cout << intList1;
	cout << endl << endl;

	// using iterators
	LinkedList::Iterator it = intList1.begin();
	std::cout << (*it *= 2) << " ";
	do
	{
		++it;
		std::cout << (*it *= 2) << " ";

	} while (it != intList1.end());

	std::cout << std::endl << std::endl;

	LinkedList::ConstIterator cit = intList1.begin();
	std::cout << *cit << " ";
	do
	{
		cit++;
		std::cout << *cit << " ";

	} while (cit != intList1.end());

	std::cout << std::endl;
	*/

	return 0;
}

// Implementations

template <typename T>
void selection_sort(T arr, int n)
{
	// Selection sort
	for (int i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		// Swap the found minimum element with the first element
		my_swap(arr[min_idx], arr[i]);
	}
}

template <>
void selection_sort(complex<double>* arr, int n)
{
	// Selection sort
	for (int i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (abs(arr[j]) < abs(arr[min_idx]))
				min_idx = j;
		// Swap the found minimum element with the first element
		my_swap(arr[min_idx], arr[i]);
	}
}

template <typename T>
void my_swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void print_array(T arr, int n)
{
	//cout << "Array of " << sizeof(arr)/sizeof(int) << " elements: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	//for (int i : arr) { //range-based-for loop doesn't work
	//	cout << i << " ";
	//}
	cout << endl;
}

template <typename T, int N>
void print_array(T(&arr)[N])
{
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << "Array of " << sizeof(arr)/sizeof(int) << " elements: ";
	for (T i : arr) { //range-based-for loop works
		cout << i << " ";
	}
	cout << endl;
}


