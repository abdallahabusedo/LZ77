#include "FileReader.cpp"
#include "encoding.cpp"
#include <iostream>

using namespace std;

int main()
{
    wstring Encoding_File = ReadingFile::READ_INPUT("enwik83.txt");
    wofstream ENCODED = ReadingFile::READ_OUTPUT("7alwlw");
    ENCODING_LZ77::LZ77_ENC(Encoding_File, ENCODED);
    ENCODED.close();
    wstring R_ENCODED = ReadingFile::READ_INPUT("7alwlw");
    wofstream DECODED = ReadingFile::READ_OUTPUT("FINAL_DEC.txt");
    ENCODING_LZ77::LZ77_DEC(R_ENCODED, DECODED);
}
