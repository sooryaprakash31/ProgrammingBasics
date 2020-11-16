#include <iostream>
using namespace std;

template <typename S>

S Max(S x, S y)
{
    return x > y ? x : y;
}

int main()
{

    cout << "The biggest number between\n";
    cout << "i) 5 and 6 is " << Max<int>(5, 6)<<endl;

    cout << "ii) 5.7 and 4.7 is " << Max<float>(5.7, 4.7)<<endl;
    cout << "iii) a and b is "<<Max<char>('a', 'b')<<endl;

    return 0;
}