#include <locale>
#include <codecvt>
#include <string>
#include <iostream>

using namespace std; 
string toUTF8(int cp);

string toUTF8(int cp) {
    char ch[5] = {0x00};
    if(cp <= 0x7F) { 
        ch[0] = cp; 
    }
    else if(cp <= 0x7FF) { 
        ch[0] = (cp >> 6) + 192; 
        ch[1] = (cp & 63) + 128; 
    }
    else if(0xd800 <= cp && cp <= 0xdfff) {} // �L�İ϶�
    else if(cp <= 0xFFFF) { 
        ch[0] = (cp >> 12) + 224; 
        ch[1]= ((cp >> 6) & 63) + 128; 
        ch[2]= (cp & 63) + 128; 
    }
    else if(cp <= 0x10FFFF) { 
        ch[0] = (cp >> 18) + 240; 
        ch[1] = ((cp >> 12) & 63) + 128; 
        ch[2] = ((cp >> 6) & 63) + 128; 
        ch[3]= (cp & 63) + 128; 
    }
    return string(ch);
}

/// C++  wstring_convert (C++ 11 ����)
void CPlusWstringConvert()
{
    wstring_convert<codecvt_utf8<wchar_t>> utf8;
    wstring ws = L"���q�s";
    string s = utf8.to_bytes(ws);
    cout << s << endl; // �b UTF-8 �s�X�׺ݾ��U�i��ܤ���
}


/**
 * wchar_t�Bchar16_t�Bchar32_t �P char8_t�A
 * string ���Y�������������O 
 * wstring�Bu16string�Bu32string �P u8string
 */
int main() { 
    string name = "caterpillar";
    for(auto ch : name) {
        cout << ch << endl;
    }

    string name2 = u8"���q�s";
    for(int i = 0; i < name2.length(); i += 3) {
        cout << name2.substr(i, 3) << endl;
    }

    // �b UTF-8 �׺ݾ��U�|��ܥ��T����
    wstring name3 = L"���~18��";
    for(int i = 0; i < name3.length(); i++) {
        cout <<  toUTF8(name3[i]) << endl;
    }

    // CPlusWstringConvert
    CPlusWstringConvert();
    return 0; 
}