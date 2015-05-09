// Nicolas Jones
// 861169228
// 4/13/15

#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

// copies list L into list P in reverse order
template <typename Type>
void listCopy(forward_list <Type> L, forward_list <Type>& P);
 
// print elements in L that are in positions specified by P
template <typename Type>
void printLots (forward_list<Type> L, forward_list<int> P);

template <typename Type>
struct Node
{
    Type data;
    Node *next;
    Node(Type data)
    : data(data), next(0) 
    {}
};

template <typename Type>
class List
{
    private:
      Node<Type>* head;
      Node<Type>* tail;
    public:
      List(); // default constructor
      ~List(); // destructor
      
      // swaps two adjacent elements in list
      void elementSwap(int pos);
      
      // push_back function to add values into List object
      void push_back(Type value);
      
      // pop_front function for deleting list nodes
      void pop_front();
      
      // function to display list
      void display();
      
    private:
      int size(); // gets and returns size of List object
};
