// Nicolas Jones
// 861169228
// 5/3/15

#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <map>
#include <queue>

using namespace std;

// PART 1 -------
void preorderRecursion(int m, int n, int maxSum) // HELPER FUNCTION
{
    int child1_m = (2 * m) - n; // first child "m" value
    int child2_m = (2 * m) + n; // second child "m" value
    int child3_m = m + (2 * n); // third child "m" value
    
    if (m + n < maxSum) // if node values' sum is less than inputted max sum
    {
        cout << m << ' ' << n << endl;
    
        preorderRecursion(child1_m, m, maxSum);
        preorderRecursion(child2_m, m, maxSum);
        preorderRecursion(child3_m, n, maxSum);
    }
}

void printpreorder(int k) //print tree in preorder
{
    cout << "pre-order" << endl;
    preorderRecursion(2, 1, k);
    preorderRecursion(3, 1, k);
}
// END PART 1 ------

// PART 2 -------
void postorderRecursion(int m, int n, int maxSum) // HELPER FUNCTION
{
    int child1_m = (2 * m) - n; // first child "m" value
    int child2_m = (2 * m) + n; // second child "m" value
    int child3_m = m + (2 * n); // third child "m" value
    
    if (m + n < maxSum) // if node values' sum is less than inputted max sum
    {
        postorderRecursion(child1_m, m, maxSum);
        postorderRecursion(child2_m, m, maxSum);
        postorderRecursion(child3_m, n, maxSum);
        cout << m << ' ' << n << endl;
    }
}

void printpostorder(int k) //print tree in preorder
{
    cout << "post-order" << endl;
    postorderRecursion(2, 1, k);
    postorderRecursion(3, 1, k);
}
// END PART 2 --------

// PART 3 -------
void sortingFunction(int m, int n, int maxSum, priority_queue<pair<int, int> > sorted)
{
    pair<int, int> p;
    if (m + n < maxSum)
    {
        p.first = m;
        p.second = n;
        sorted.push(p);
    }
    
    int child1_m = (2 * m) - n; // first child "m" value
    int child2_m = (2 * m) + n; // second child "m" value
    int child3_m = m + (2 * n); // third child "m" value
    
    // print out queue elements
    for (unsigned i = 0; i < sorted.size(); ++i)
    {
        cout << sorted.top().first << ' ' << sorted.top().second << endl;
        sorted.pop();
    }
    
    if (m + n < maxSum) // if node values' sum is less than inputted max sum
    {
        preorderRecursion(child1_m, m, maxSum);
        preorderRecursion(child2_m, m, maxSum);
        preorderRecursion(child3_m, n, maxSum);
    }
}

void printsorted(int k)
{
    priority_queue<pair<int, int> > sorted;
    cout << "sorted" << endl;
    sortingFunction(2, 1, k, sorted);
    sortingFunction(3, 1, k, sorted);
}
// END PART 3 ---------

#endif
