#include <iostream>
#include <string>

/**
 * �غc���
 * ��Ȧ�C
 * explicit ���ܵ�
 * private ����
 * protected ����
 * �s����ƻP�ק���
 * this ����
 * friend ����
 * static ����
 * static const ����
 * const �������
 * mutable ����
 * �_�����O
 * Copy �غc���
 * �Ѻc���
 * �h���B��l
 * �~��
 * �h���~��
 * virtual ���
 * �����~��
 * /

/**
 * �~�Ӭ�����ɦV�{���]�p���S�ʤ��@�A
 * �l�����O (derived class) �i�H�ӱ���¦���O (base class) 
 * �� public �� protected �����A
 * �o�O���A��¦���O�z�L�~�ӴN�㦳�l�����O�� public �� protected �����C 
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

    /// �קK�����ഫ
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

    /// �h���B��l
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

    /// const �׹�����Ƥ���ק����O���������ܼ�
    /// ���i�ק�ŧi�� mutable �������ܼ�
    int get_sum() const {
        return a + b;
    }

    /// �ۤv�Φۤv���Ѽƪ�private �ܼƤ]�nfriend 
    friend int do_something(Demo& d) {
        return d.c + d.d;
    }
    /// ��demo2��@friend
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

/// �~�� Demo 1
class Demo3: Demo, Demo2 {
public:
    int do_something() {
        return a + b;
    }
};

/// ��ƫ���
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

    /// ��ƫ���
    void (*f1Ptr)(void) = fun1;
    int (*f2Ptr)(int) = fun2;
    
    f1Ptr();
    cout << f2Ptr(1) << endl;
    
    return 0;
}