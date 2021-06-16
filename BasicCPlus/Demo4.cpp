#include <iostream>

/**
 * 函數樣板
 * 類別樣板
 * 樣板別名
 */

template <typename T1, typename T2> T1 do_something(const T1& a, const T2& b) {
    return a + b;
}

template <typename T> class Demo 
{
    public:
        Demo(const T& a, const T& b) 
        {
            this->a = a;
            this->b = b;
        }
        
        T do_something() 
        {
            return a + b;
        }
        
    private:
        T a;
        T b;
};

template <typename T> using D = Demo<T>;

int main() {
    std::cout << do_something(1, 10) << std::endl;
    std::cout << do_something(1, 10.5) << std::endl;
    std::cout << do_something(2.5, 6.32) << std::endl;
    
    Demo<int> d1(20, 25);
    std::cout << d1.do_something() << std::endl;
    Demo<double> d2(5.2, 3.95);
    std::cout << d2.do_something() << std::endl;
    Demo<char> d3('1', '2');
    std::cout << d3.do_something() << std::endl;

    return 0;
}