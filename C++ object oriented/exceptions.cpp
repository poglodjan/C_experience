#include <exceptions>

// bad_alloc exp
try
{
  int input = -1;
  int* new_value = new int [input];
  delete[] new_value;
}
catch(bad_alloc& exp) 
{
  cout<< "exception encountered: " << exp.what(); 
}
catch(...)
{
  cout<<"Not known exception"
}

// string len error
try
{
    string("abc").substr(10);
}
catch(const exception& e)
{
  cout<< e.what();  // length_error but can also catch bad_alloc
}

// throw
try
{
  if(divisor == 0)
    throw "Dividing by 0!";
}

try
{
  if(milk_glasses <= 4)
    throw donuts;
}
catch(int e)
{
  cerr << e << " donuts, and no milk"; //cerr - output stream for errors
}

// example
class Stack
{
  int st[3];
  int top;
public:
  class Full {}; //empty classes
  class Empty {}; 
  void push(int var) // putting on the stack
  {
    if(top>=3)
      throw Full();
    st[++top] = var;
  }
  int pop() // take of the stack
  {
    if(top < 0)
      throw Empty();
    return st[top--];
  }
}
// then:

Stack s1;
try
{
  s1.push(1); s1.push(2); s1.push(3); s1.push(4);
}
catch(Stack::Full) { cout << "Stack full"; }
catch(Stack::Empty) { cout << "Stack Empty"; }




