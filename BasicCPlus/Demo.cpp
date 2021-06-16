//// Data type
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <typeinfo>

/**
 * 布林
 * 字元
 * 整數
 * 浮點數
 * 算術運算
 * 遞增、遞減運算
 * 關係運算
 * 邏輯運算
 * 位元運算
 * sizeof 運算
 * typeid 運算
 * alignof 運算
 * 指派運算
 * 條件運算
 * if 陳述
 * else 陳述
 * switch 陳述
 * for 陳述
 * while 陳述
 * do-while 陳述
 * break 陳述
 * continue 陳述
 * goto 陳述
 * try throw catch 陳述
 * catch (...) 陳述
 * 關於 noexcept
 */

using namespace std;
/// 此系列基礎語法參考；http://kaiching.org/pydoing/cpp/cpp-manual.html

struct BadValue : public std::exception {};
    
double divide(double a, double b) {
    if (b == 0) {
        throw BadValue();
    }    
    return a / b;
}

int main(void)
{
    string m("There is no spoon.");
    cout << endl << m << endl << endl << endl;

    /// iostream
    ios state(nullptr);
    cout << "The answer in decimal is: " << 42 << endl;
    state.copyfmt(cout); // save current formatting
    cout << "In hex: 0x" // now load up a bunch of formatting modifiers
        << hex
        << uppercase
        << setw(8)
        << setfill('0')
        << 42            // the actual value we wanted to print out
        << endl
        << endl
        << endl;
    // cout.copyfmt(state); // restore previous formatting

    /// char & string
    // char, wchar_t     C++11 => char19_t, char32_t
    // signed, unsigned
    cout << "char: " << sizeof(char) << endl;
    cout << "wchar_t: " << sizeof(wchar_t) << endl;
    cout << "char16_t: " << sizeof(char16_t) << endl;
    cout << "char32_t: " << sizeof(char32_t) << endl;

    /// 基本內建型態大小確認
    std::cout << "bool: " << sizeof(bool) << std::endl;
    // long long 為 C++11 新增格式
    std::cout << "================================整數================================"<< std::endl;
    std::cout << "short : " << sizeof(short) << std::endl;
    std::cout << "short int : " << sizeof(short int) << std::endl;
    std::cout << "signed short : " << sizeof(signed short) << std::endl;
    std::cout << "signed short int : " << sizeof(signed short int) << std::endl;
    std::cout << "unsigned short : " << sizeof(unsigned short) << std::endl;
    std::cout << "unsigned short int : "  << sizeof(unsigned short int) << std::endl;
    std::cout << "int : " << sizeof(int) << std::endl;
    std::cout << "signed : " << sizeof(signed) << std::endl;
    std::cout << "signed int : " << sizeof(signed int) << std::endl;
    std::cout << "unsigned : " << sizeof(unsigned) << std::endl;
    std::cout << "unsigned int : " << sizeof(unsigned int) << std::endl;
    std::cout << "long : " << sizeof(long) << std::endl;
    std::cout << "long int : " << sizeof(long int) << std::endl;
    std::cout << "signed long : " << sizeof(signed long) << std::endl;
    std::cout << "signed long int : " << sizeof(signed long int) << std::endl;
    std::cout << "unsigned long : " << sizeof(unsigned long) << std::endl;
    std::cout << "unsigned long int : " << sizeof(unsigned long int) << std::endl;
    std::cout << "long long : " << sizeof(long long) << std::endl;
    std::cout << "long long int : " << sizeof(long long int)  << std::endl;
    std::cout << "signed long long : " << sizeof(signed long long) << std::endl;
    std::cout << "signed long long int: " << sizeof(signed long long int) << std::endl;
    std::cout << "unsigned long long : " << sizeof(unsigned long long)  << std::endl;
    std::cout << "unsigned long long int: " << sizeof(unsigned long long int)  << std::endl;

    std::cout << "================================浮點數================================"<< std::endl;
    std::cout << "float: " << sizeof(float) << std::endl;
    std::cout << "double: " << sizeof(double) << std::endl;
    std::cout << "long double: " << sizeof(long double) << std::endl;
    
    string name = "caterpillar";
    char str[] = "Justin";
    name = str;

    /// c math 函式庫
    int a = -99;
    int b = abs(a);
    
    std::cout << "a: " << a << std::endl;
    std::cout << "abs(a): " << b << std::endl;

    /// 位元運算
    int c = 192;
    int d = 64;
    
    std::cout << (~c) << std::endl;
    std::cout << (d << 2) << std::endl;
    std::cout << (d >> 2) << std::endl;
    std::cout << (c & d) << std::endl;
    std::cout << (c | d) << std::endl;
    std::cout << (c ^ d) << std::endl;

    /// typeid 
    std::cout << "bool : " << typeid(bool).name() << std::endl;
    std::cout << "short : " << typeid(short).name() << std::endl;
    std::cout << "int : " << typeid(int).name() << std::endl;
    std::cout << "double : " << typeid(double).name() << std::endl;

    /// char ascii 
    char t = 'T';
    std::cout << "before: " << t << std::endl;
    t = t + 32;
    std::cout << "after : " << t << std::endl;

    /// char 印出26個英文字母
    char letter = 'a';
    while(letter <= 'z')
    {
        cout << "Print Letter : " << letter << endl;
        letter = letter + 1;
    }

    char name[] = {'P', 'H', 'O', 'E', 'B', 'E'};
    int letterCnts[] = {0};

    switch(name[0])
    {
        case 'P':
            cout << "Happy" << endl;
            break;
        default:
            cout << "Cry" << endl;

    }

    /// label Test 
    goto label_one;
    
    label_one: 
    {
        std::cout << "Label One" << std::endl;
        goto label_two;
    }
    
    label_two:
    {
        std::cout << "Label Two" << std::endl;
        goto label_three;
    }
    
    label_three:
    {
        std::cout << "Label Three" << std::endl;
    }

    /// try-catch
    int i = -1; 
    // 1
    try {
        if (i < 0) {
            throw "something wrong...";
        }
    }
    catch (const char* message) {
        std::cout << message << std::endl;
    }

    // 2
    try {
        std::cout << divide(20, 5) << std::endl;
        std::cout << divide(20, 4) << std::endl;
        std::cout << divide(20, 3)  << std::endl;
        std::cout << divide(20, 2) << std::endl;
        std::cout << divide(20, 1) << std::endl;
        std::cout << divide(20, 0) << std::endl;
    }
    catch (BadValue e) {
        std::cout << "something wrong..."  << std::endl;
    }
    catch (...) {
        std::cout << "something wrong" << std::endl;
    }

    // 3
    try {
        if (i > 0) {
            throw 0;
        }
        throw 2.0;
    }
    catch (const int e) {
        std::cout << e << std::endl;
    }
    catch (...) {
        std::cout << "something wrong" << std::endl;
    }
    return 0;
}