#include <iostream>
#include "iter.hpp"

void square(int &x);
int main2();

int main()
{
    int arr[4] = {0, 2, 3, 4};
    for (int i = 0; i < 4; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    iter(arr, 4, square);
    for (int i = 0; i < 4; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "From checklist:" << std::endl;
    main2();
}

void square(int &x)
{
    x = x * x;
}

class Awesome
{
public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
private:
    int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main2() {
    int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];
    iter( tab, 5, print );
    iter( tab2, 5, print );
    return 0;
}