#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

template<typename L>
void selectionsort(L &l)
{
    // DOES NOT WORK WITH ANY KIND OF LIST CONTAINING PAIRS
    
    // output non-sorted
    cout << "pre: ";
    typename L::iterator pre;
    for (pre = l.begin(); pre != l.end(); ++pre)
    {
        cout << *pre << ' ';
    }
    cout << endl;
    
    // sort
    typename L::iterator min;
    typename L::iterator j;
    // int moves = 0;
  
    for(typename L::iterator i = l.begin(); i != l.end(); ++i)
    {
        min = i;
        j = i;
        ++j;
        for(; j != l.end(); ++j)
        {
            if(*j < *min)
            {
                min = j;
            }
        }  
        
        swap(*i, *min);
        // ++moves;
    }
    
    // output sorted
    cout << "post: ";
    typename L::iterator post;
    for (post = l.begin(); post != l.end(); ++post)
    {
        cout << *post << ' ';
    }
    cout << endl;
    
    // only for list containing pairs ...
    
    // if (!l.empty())
    // {
    //     cout << "0 copies and " << moves * 3 << " moves" << endl;
    // }
}

#endif
