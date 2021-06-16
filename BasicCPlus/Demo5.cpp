#include <iostream>
#include <typeinfo>
/**
 * �зǵ{���w�����ѧO�r���w�q�b std �R�W�Ŷ����A
 * �]���ϥμзǵ{���w���ѧO�r�ݭn�[�W std::
 */

#define Prints(arg) std::cout << #arg 
#define F(n, a) int f##n() {return a;} /// ## �s���ѧO�W��
F(test, 0); /// ftest
F(function, 1); /// ffunction
F(rrr, 2); /// frrr
/**
 * �������N²��禡
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
 * volatile : �ϽsĶ�����n��ҫŧi�ܼ�
 * �i��̨ΤơA�]���sĶ���i��̨ΤƦ��i��ɭP�Y�ǫD�w�������G
 * alignas :  C++11 �s�W������r�A�Ψӫ��w���A�Ϊ��󪺱ƦC�ݨD
 */

/**
 * typedef 
 * typedef int INTEGER;
 * INTEGER a = 22;
 */

/**
 * �ջy���
 * asm("assembly language");
 *  
 */

/**
 * �ܼƦs�b�� �G �۰ʡB�R�A�B�ʺA
 * auto : �b�@�ΰ� (scope) �����ɡA����ܼƤ]�|�۰ʲפ�A
 * ���O�ŧi�b��� (function) �̪��ܼƴN�O
 * �۰ʦs�b�����ϰ��ܼ� (local variable) �A
 * �ĤO�ȭ��b���ƥD�骺�j�A����
 * 
 * register : �Ψӭn�D�sĶ���N�o���ܼƩ�J�B�z�����Ȧs������
 * �A�]�O�ݩ�۰ʦs�b���A�w���Q��ĳ�ϥ�
 * 
 * static
 * 
 * extern : �Ω�~���s�����ܼ�
 * thread_local : C++11 �s�W������r�A�Ω����� (thread) ������
 */

/**
 * �_���R�W�Ŷ�
 * �L�W�R�W�Ŷ�
 * inline �R�W�Ŷ�
 * using ����r
 */

/**
 * using �᭱�� namespace �A
 * �̫�A���R�W�Ŷ����W�١A
 * �o�� std ���зǵ{���w�����R�W�Ŷ��A 
 * demo �h�O�ڭ̦ۦ�w�q���R�W�Ŷ�
 */

/**
 * ����r inline �쥻�Φb�ŧi�S�� inline ��ơA 
 * C++11 �s�W�� inline �]�i�Φb�ŧi�R�W�Ŷ��A
 * �Ω�]�p�{���w (library) ���a��C
 */

/// �u�঳�@�ӵL�W�R�W�Ŷ�
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