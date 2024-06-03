#include <iostream>
using namespace std;

int main()
{
  // list
  list<int> mylist = {1,2,3,4,5};
  mylist.push_back(6);
  mylist.push_front(0);
  mylist.pop_back();
  mylist.pop_front();
  for(auto it = mylist.begin(); it!=mylist.end(); ++it)
      cout<<*it<<" ";
  cout<<endl;

  // vector:
  std::vector<int> myVector = {1, 2, 3, 4, 5};
  myVector.push_back(6); 
  myVector.pop_back(); 
  cout << "Pierwszy element: " << myVector[0] << endl;
  cout << "Drugi element: " << myVector.at(1) << endl;
  for (auto it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << *it << " ";
  cout << endl;

  // set
  set<int> mySet = {3, 1, 4, 1, 5, 9};
  mySet.insert(2); 
  mySet.erase(3); 
  for (auto it = mySet.begin(); it != mySet.end(); ++it)
      cout << *it << " ";
  cout << endl;

  return 0;
}

