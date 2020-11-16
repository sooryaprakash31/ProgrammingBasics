/*
Generics:

    - Generic programming allows to perform the same function/algorithm for
      all data types
    - Eliminates the need to create different functions for different data types
      to execute the same algorithm
    - Achieved using templates
        i) Function templates
        ii) Class templates

    Advantages:
        - Code Reusability
        - Avoid function overloading

*/

#include <iostream>
using namespace std;

//creates template functions Max
template <typename S>
S Max(S x, S y)
{
    //returns the maximum number
    return x > y ? x : y;
}

int main()
{

    cout << "The biggest number between\n";

    //performs Max for integers 5 and 6
    cout << "i) 5 and 6 is " << Max<int>(5, 6) << endl;

    //performs Max for float 5.7 and 4.7
    cout << "ii) 5.7 and 4.7 is " << Max<float>(5.7, 4.7) << endl;

    //performs Max for characters a and b
    cout << "iii) a and b is " << Max<char>('a', 'b') << endl;

    return 0;
}