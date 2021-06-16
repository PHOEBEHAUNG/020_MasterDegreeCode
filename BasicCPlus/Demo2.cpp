/// Data type 
#include <iostream>
#include <cstring> 

/**
 * �Ѧ�
 * �C�|
 * �}�C
 * ����
 * ���c
 * �p�X
 */
using namespace std;
enum class Color {RED, GREEN, BLUE};

enum class ColorC: char {
    RED = 'r',
    GREEN = 'g',
    BLUE = 'b',
};

/// ���c�w�]�O public
struct Demo {
    int member1;
    char *member2; /// �r��
    float member3;

    void member4();
};

void Demo::member4()
{
    cout << "Do something here." << endl;
}

int main() {
    enum Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    enum {apple, banana = 11, orange, peach = 5}; /// �ΦW�C�|

    int a = 22;
    int& a_ref = a;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "a_ref: "<< a_ref << std::endl;
    
    a_ref = 11;
    std::cout << "a: " << a << std::endl;
    std::cout << "a_ref: " << a_ref << std::endl;
    
    /// enum 
    std::cout << "Sunday: " << Sunday << std::endl;
    std::cout << "Monday: " << Monday << std::endl;
    std::cout << "Tuesday: " << Tuesday << std::endl;
    std::cout << "Wednesday: " << Wednesday << std::endl;
    std::cout << "Thursday: " << Thursday << std::endl;
    std::cout << "Friday: " << Friday << std::endl;
    std::cout << "Saturday: " << Saturday << std::endl;
    
    Day today = Wednesday;
    std::cout << today << std::endl;

    /// Class enum
    ColorC r;
    r = ColorC::RED;
    ColorC g;
    g = ColorC::GREEN;
    ColorC b;
    b = ColorC::BLUE;
    
    std::cout << "RED: " << static_cast<char>(r) << std::endl;
    std::cout << "GREEN: " << static_cast<char>(g) << std::endl;
    std::cout << "BLUE: " << static_cast<char>(b) << std::endl;

    /// Array
    int c[5];
    int d[] = {1, 2, 3, 4, 5};
    int e[2][3] = {{1, 2, 3}, {4, 5, 6}};

    /// point 
    int k = 0;
    int *k_ptr = &k;
    cout << k << endl;
    cout << k_ptr << endl;

    int test = 10;
    memcpy(k_ptr, &test, sizeof(test));
    cout << k << endl;
    cout << k_ptr << endl;

    cout << "d[0] : " << *(d) << endl;
    cout << "d[3] : " << *(d + 3) << endl;
    
    // nullptr 
    int n = 22;
    std::cout << "n: " << n << std::endl;
    int* p = &n;
    std::cout << "p: " << p << std::endl;
    p = nullptr; // NULL
    std::cout << "p: " << p << std::endl;

    return 0;
}