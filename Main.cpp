#include "FileReader.cpp"
#include "encoding.cpp"
#include <iostream>

using namespace std;

int main()
{
    wstring s = ReadingFile::READ_INPUT("enwik83.txt");
    wofstream ENCODED = ReadingFile::READ_OUTPUT("7alwlw");
    ENCODING_LZ77::LZ77_ENC(s, ENCODED);
    //ENCODED.write((wchar_t *)s.c_str(), s.size());
    // wchar_t array[1];
    // for (int i = 0; i < s.size(); i++)
    // {
    //     array[0] = s[i];
    //     ENCODED.write(array, 1);
    // }
}
