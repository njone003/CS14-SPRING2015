// Nicolas Jones
// 861169228
// 4/13/15

#include <iostream>
#include <list>
#include <forward_list>
#include <cmath>
#include "lab2.h"

using namespace std;

bool isPrime(int i)
{
    if (i == 0 || i == 1) // 1 and 0 are not prime numbers
    {
        return false;
    }
    if (i % 2 == 0 && i != 2) // even numbers (except 2) are not prime
    {
        return false;
    }
    
    // test for prime number: divide i by all numbers from 3 to sqrt(i) (rounded up)
    // if i is divisible by any of these numbers, then it is not prime
    for (int j = 3; j <= sqrt(i) + 1; ++j)
    {
        if (i % j == 0)
        {
            return false;
        }
    }
    
    return true; // if "i" passes all tests, then it is prime
}

int primeCount(forward_list<int> lst)
{
    if (lst.empty())
    {
        return 0; // if list is empty there are no prime numbers
    }
    else
    {
        if (isPrime(lst.front())) // call isPrime helper function on 1st element
        {
            lst.pop_front();
        
            return 1 + primeCount(lst);
        }
        else
        {
            lst.pop_front();
        
            return primeCount(lst);
        }
    }
}

template <typename Type>
List<Type>::List()
{
    head = 0;
    tail = 0;
}

template <typename Type>
List<Type>::~List()
{
    while (head != 0)
    {
        pop_front();
    }
}

template <typename Type>
void List<Type>::elementSwap(int pos) // ???
{
    // if requested position is at the last element in list (or greater)
    // then return original list (nothing at "pos" + 1)
    if (pos >= this->size() - 1)
    {
        cout << "Requested position in list has no adjacent element. "
            << "Valid positions: 0 - " << this->size() - 2 << endl;
        return;
    }
    
    // If list is empty or there is only one node in list
    if (head == 0 || head->next == 0)
    {
        return;
    }
    
    if (pos != 0 && this->size() >= 4)
    {
        // Node<Type> *prev;
        Node<Type> *curr = head->next;
        
        // find node at requested position
        for (int i = 0; i <= pos; ++i)
        {
            // if (i == pos - 1)
            // {
            //     prev = curr; // after loop, prev will be before desired node
            // }
            curr = curr->next; // after loop. curr will be desired node
        }
        
        // Node<Type> *nxt = curr->next; // "nxt" is node at pos + 1
        // Node<Type> *after_next = nxt->next; // node after nxt
        
        // prev->next = nxt;
        // curr->next = after_next;
        // nxt->next = curr;
        
    }
}
template <typename Type>
void List<Type>::push_back(Type value)
{
    Node<Type>* back = new Node<Type>(value); // create new node
    
    if (tail == 0)
    {
        tail = back;
    
        if (head == 0)
        {
            head = back;
        }
        return;
    }
    
    tail->next = back;
    tail = back;
}

template <typename Type>
int List<Type>::size()
{
    if (head == 0)
    {
        return 0; // empty list ... return size of 0
    }
    
    int sz = 0;
    Node<Type>* i = head;
    
    for (i = head; i != 0; i = i->next)
    {
        ++sz; // increment sz variable for every node that is reached
    }
    
    return sz + 1;
}

template <typename Type>
void List<Type>::pop_front()
{
    if (head == 0) // makes sure there's not an empty list to begin with
    {
        return;
    }
    
    Node<Type>* temp = head; // temporary pointer to head (avoid dangling pointer)
    head = head->next;
    delete temp; // first node in list is now deleted
    
    if (head == 0)
    {
        tail = 0; // makes sure tail isn't a dangling pointer
    }
}

template <typename Type>
void List<Type>::display()
{
    if (head == 0)
    {
        return; // return nothing if list is empty
    }
    
    Node<Type>* curr = head; // temporary node to traverse list
    for (curr = head; curr != 0; curr = curr->next)
    {
        cout << curr->data << ' ';
    }
}

template <typename Type>
void listCopy(forward_list <Type> L, forward_list <Type>& P)
{
    // reversal
    L.reverse();
    
    // concatenation
    P.merge(L);
}

template <typename Type>
void printLots(forward_list<Type> L, forward_list<int> P)
{
    int tracker = 0; // keep track of position in list L
    for (auto itP = P.begin(); itP != P.end(); ++itP)
    {
        for (auto itL = L.begin(); itL != L.end(); ++itL)
        {
            if (tracker == *itP)
            {
                cout << *itL << ' ';
                tracker = 0; // reset tracker
                break; // break out of inner for loop for every value reached
            }
            ++tracker;
        }
    }
}
