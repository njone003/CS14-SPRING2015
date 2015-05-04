// Nicolas Jones
// 861169228
// 5/3/15
// incremental compilation

#include <iostream>
#include <cstdlib>
#include "lab4.h"

using namespace std;

int main(int argc, char *argv[])
{
    printpreorder(atoi(argv[1]));
    
    cout << endl;
    
    printpostorder(atoi(argv[1]));
    
    cout << endl;
    
    printsorted(atoi(argv[1]));
    
    return 0;
}
