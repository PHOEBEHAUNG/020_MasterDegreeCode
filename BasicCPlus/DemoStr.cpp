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
    else if(0xd800 <= cp && cp <= 0xdfff) {} // 無效區塊
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

/// C++  wstring_convert (C++ 11 提供)
void CPlusWstringConvert()
{
    wstring_convert<codecvt_utf8<wchar_t>> utf8;
    wstring ws = L"黃琇貞";
    string s = utf8.to_bytes(ws);
    cout << s << endl; // 在 UTF-8 編碼終端機下可顯示中文
}


/**
 * wchar_t、char16_t、char32_t 與 char8_t，
 * string 標頭中對應的版本是 
 * wstring、u16string、u32string 與 u8string
 */
int main() { 
    string name = "caterpillar";
    for(auto ch : name) {
        cout << ch << endl;
    }

    string name2 = u8"黃琇貞";
    for(int i = 0; i < name2.length(); i += 3) {
        cout << name2.substr(i, 3) << endl;
    }

    // 在 UTF-8 終端機下會顯示正確中文
    wstring name3 = L"今年18歲";
    for(int i = 0; i < name3.length(); i++) {
        cout <<  toUTF8(name3[i]) << endl;
    }

    // CPlusWstringConvert
    CPlusWstringConvert();
    return 0; 
}