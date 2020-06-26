#include "FileReader.cpp"
#include "encoding.cpp"
#include <iostream>

using namespace std;

int main()
{
    // wstring s = ReadingFile::READ_INPUT("tee.txt");
    // wofstream ENCODED = ReadingFile::READ_OUTPUT("7alwlw");
    // ENCODING_LZ77::LZ77_ENC(s, ENCODED);
    // ENCODED.close();
    wifstream DENCODED = ReadingFile::READ_INPUT2("7alwlw");
    wofstream DECODED = ReadingFile::READ_OUTPUT("FINAL_DEC.txt");
    ENCODING_LZ77::LZ77_DEC(DENCODED, DECODED);
}
