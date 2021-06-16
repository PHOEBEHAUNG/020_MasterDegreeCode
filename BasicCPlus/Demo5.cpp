#include <iostream>
#include <typeinfo>
/**
 * 標準程式庫中的識別字都定義在 std 命名空間中，
 * 因此使用標準程式庫的識別字需要加上 std::
 */

#define Prints(arg) std::cout << #arg 
#define F(n, a) int f##n() {return a;} /// ## 連結識別名稱
F(test, 0); /// ftest
F(function, 1); /// ffunction
F(rrr, 2); /// frrr
/**
 * 巨集取代簡單函式
 */

/**
 * #if expr
 * #ifdef expr
 * #ifndef expr
 * #elif expr
 * #else
 * #endif
 * #undef
 * 
 * #warning
 * #error
 * #pragma
 * #line
 */

/**
 * decltype 
 * const 
 * volatile : 使編譯器不要對所宣告變數
 * 進行最佳化，因為編譯器進行最佳化有可能導致某些非預期的結果
 * alignas :  C++11 新增的關鍵字，用來指定型態或物件的排列需求
 */

/**
 * typedef 
 * typedef int INTEGER;
 * INTEGER a = 22;
 */

/**
 * 組語支持
 * asm("assembly language");
 *  
 */

/**
 * 變數存在期 ： 自動、靜態、動態
 * auto : 在作用域 (scope) 結束時，跟著變數也會自動終止，
 * 像是宣告在函數 (function) 裡的變數就是
 * 自動存在期的區域變數 (local variable) ，
 * 效力僅限在於函數主體的大括弧中
 * 
 * register : 用來要求編譯器將這個變數放入處理器的暫存器之中
 * ，也是屬於自動存在期，已不被建議使用
 * 
 * static
 * 
 * extern : 用於外部連結的變數
 * thread_local : C++11 新增的關鍵字，用於執行緒 (thread) 的部分
 */

/**
 * 巢狀命名空間
 * 無名命名空間
 * inline 命名空間
 * using 關鍵字
 */

/**
 * using 後面接 namespace ，
 * 最後再接命名空間的名稱，
 * 這裡 std 為標準程式庫中的命名空間， 
 * demo 則是我們自行定義的命名空間
 */

/**
 * 關鍵字 inline 原本用在宣告特殊的 inline 函數， 
 * C++11 新增使 inline 也可用在宣告命名空間，
 * 用於設計程式庫 (library) 的地方。
 */

/// 只能有一個無名命名空間
namespace {
    class Demo {
    public:
        int a;
        int b;
        
        int do_something() {
            return a + b;
        }
    };
}

namespace demo {
    namespace demo2 {
        class Demo {
        public:
            int a;
            int b;
            
            int do_something() {
                return a + b;
            }
        };
    }
}

class TypeConversion
{
    public:
        /// bool/char => short => int => long => float => double
        void ImplicitTypeConversion()
        {
            char a = 'a';
            short b = 5;
            int c = 156;
            long d = 5;
            float e = 9.8;
            double f = 12.5;
            
            /// short to bool 
            if (b) 
            {
                std::cout << "short => bool, " << typeid(b).name() << std::endl;
            }

            std::cout << "char => int, " << (a / b) << ", " << typeid(a / b).name() << std::endl;
            std::cout << "short => long, " << (b * d) << ", " << typeid(b * d).name() << std::endl;
            std::cout << "int => float, " << (c / e) << ", " << typeid(c / e).name() << std::endl;
            std::cout << "double => int, " << (c = f) << ", " << typeid(c).name() << std::endl;
        }

        /// dynamic_cast
        /// const_cast
        /// static_cast
        ///reinterpret_cast
        void ForceConversion()
        {
            char a = 'a';
            int b = 97;
            
            std::cout << a << std::endl;
            std::cout << b << std::endl; 
            std::cout << static_cast<char>(b) << std::endl;
            std::cout << static_cast<int>(a) << std::endl;
        }
};

int main() {
    demo::demo2::Demo d;
    d.a = 33;
    d.b = 44;
    std::cout << d.do_something() << std::endl;
    
    return 0;
}