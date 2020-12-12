#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string char_str = "Mago Mago~ 나를 위한 춤을 춰~ 밤은 틱탁틱탁";
    std::string u8char_str = u8"Mago Mago~ 나를 위한 춤을 춰~ 밤은 틱탁틱탁";

    std::wstring wchar_t_str = L"Mago Mago~ 나를 위한 춤을 춰~ 밤은 틱탁틱탁";

    std::u16string char16_t_str = u"Mago Mago~ 나를 위한 춤을 춰~ 밤은 틱탁틱탁";
    std::u32string char32_t_str = U"Mago Mago~ 나를 위한 춤을 춰~ 밤은 틱탁틱탁";

    std::u16string u16_str = u"🍑🍒";

    std::cout << char_str.size() << endl;
    std::cout << u8char_str.size() << endl;
    std::cout << wchar_t_str.size() << endl;
    std::cout << char16_t_str.size() << endl;
    std::cout << char32_t_str.size() << endl;
}