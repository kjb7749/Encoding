#include "pch.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>

using namespace std;


inline unsigned char HINIBBLE(unsigned char x) {
    return ((x >> 4) & 0x0f);
}
inline unsigned char LONIBBLE(unsigned char x) {
    return (x & 0x0f);
}

template<typename T>
void hexPrinter(T list) {
    auto printNibble = [](unsigned char value) {
        if (value < 10) {
            cout << (char)(value + '0');
        } else {
            cout << (char)(value + 'A' - 10);
        }
    };

    unsigned char* byte = (unsigned char*)list.c_str();
    int length = sizeof(T::value_type) * list.size();

    cout << length << endl;

    for (int i = 0; i < length; ++i) {
        unsigned char mark = byte[i];

        printNibble(HINIBBLE(mark));
        printNibble(LONIBBLE(mark));

        std::cout << " ";
    }
    std::cout << std::endl;
};


TEST(TextEncoding, TextEncoding) {

    std::string char_str = "가나다라마ABC";
    std::string u8char_str = u8"가나다라마ABC";
    std::wstring wchar_t_str = L"가나다라마ABC";
    std::u16string char16_t_str = u"가나다라마ABC";
    std::u32string char32_t_str = U"가나다라마ABC";

    hexPrinter(char_str);
    hexPrinter(u8char_str);
    hexPrinter(wchar_t_str);
    hexPrinter(char16_t_str);
    hexPrinter(char32_t_str);

    //_setmode(_fileno(stdout), _O_TEXT);
    //cout << char_str <<endl;

    //_setmode(_fileno(stdout), _O_U16TEXT);
    //wcout << char16_t_str.c_str() << endl;

    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << wchar_t_str << endl;

    EXPECT_TRUE(true);
}