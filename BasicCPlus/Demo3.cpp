#include <iostream>
#include <string>

/**
 * 建構函數
 * 初值串列
 * explicit 指示詞
 * private 成員
 * protected 成員
 * 存取函數與修改函數
 * this 指標
 * friend 成員
 * static 成員
 * static const 成員
 * const 成員函數
 * mutable 成員
 * 巢狀類別
 * Copy 建構函數
 * 解構函數
 * 多載運算子
 * 繼承
 * 多重繼承
 * virtual 函數
 * 虛擬繼承
 * /

/**
 * 繼承為物件導向程式設計的特性之一，
 * 衍生類別 (derived class) 可以承接基礎類別 (base class) 
 * 的 public 或 protected 成員，
 * 這是說，基礎類別透過繼承就具有衍生類別的 public 或 protected 成員。 
 */

using namespace std;
class Demo
{
    private:
        int c;
        int d;
        string *a_ptr;

    protected:
        int e;
        int f;

    public:
        int a;
        int b;
        mutable int i;
    Demo()
    {
        cout << "Constructor" << endl;
        a_ptr = new string;
    }

    /// 避免隱性轉換
    explicit Demo(int ap) : c(ap)
    {
        cout << "Constructor : " << c << endl;
        a_ptr = new string;
    }

    Demo(int month, int day)
    {
        cout << "Constructor" << endl;
        this->a = month;
        this->b = day;
        a_ptr = new string;
    }

    Demo(int year, int month, int day)
    {
        cout << "Constructor" << endl;
        this->a = month;
        this->b = day;

        this->c = year;
        a_ptr = new string;
    }

    Demo(string s) {
        cout << "constructor" << endl;
        a_ptr = new string;
        *a_ptr = s;
    }
    
    /// Copy Constructure
    Demo(const Demo& obj) {
        cout << "copy constructor" << endl;
        a_ptr = new string;
        *a_ptr = *obj.a_ptr;
    }

    /// 多載運算子
    Demo operator+(const Demo& p) {
        Demo demo;
        demo.a = this->a + p.a;
        demo.b = this->b + p.b;    
        return demo;
    }

    void set_a(string s) {
        *a_ptr = s;  
    }

    string get_a() {
        return *a_ptr;
    }

    int do_something() 
    {
        return this->a + this->b;
    }

    /// const 修飾的函數不能修改類別中的成員變數
    /// 但可修改宣告為 mutable 的成員變數
    int get_sum() const {
        return a + b;
    }

    /// 自己用自己的參數的private 變數也要friend 
    friend int do_something(Demo& d) {
        return d.c + d.d;
    }
    /// 把demo2當作friend
    friend class Demo2;

    ~Demo()
    {
        cout << "Deconstructor" << endl;
        delete a_ptr;
    }
};

//int Demo2::count = 0;
class Demo2 
{
    private:
        static int count;
        static const int days = 30;

    public:
        Demo2() 
        {
            cout << "constructor" << endl;
            count++;
        }

        int do_something2(Demo& d) 
        {
            return d.a + d.b;
        }

        static int get_count() 
        {
            return count;
        }
};

/// 繼承 Demo 1
class Demo3: Demo, Demo2 {
public:
    int do_something() {
        return a + b;
    }
};

/// 函數指標
void fun1(void) {
    cout << "fun1" << endl;
}

int fun2(int n) {
    return 0;
}

int main() 
{
    Demo d(2);
    //cout << d.do_something() << endl;

    /// Copy Constructure
    Demo d1("Demo 1");

    for(auto ch : d1.get_a()) {
        cout << ch;
    }
    cout << endl;
    
    Demo d2 = d1;
    d2.set_a("Demo 2");
    for(auto ch : d2.get_a()) {
        cout << ch;
    }
    cout << endl;

    for(auto ch : d1.get_a()) {
        cout << ch;
    }
    cout << endl;

    /// 函數指標
    void (*f1Ptr)(void) = fun1;
    int (*f2Ptr)(int) = fun2;
    
    f1Ptr();
    cout << f2Ptr(1) << endl;
    
    return 0;
}