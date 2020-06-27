#include "FileReader.cpp"
#include "encoding.cpp"
#include <iostream>

using namespace std;

int main()
{
    string Encoding_File = ReadingFile::READ_INPUT("new.txt");
    ofstream ENCODED = ReadingFile::READ_OUTPUT("7alwlw");
    ENCODING_LZ77::LZ77_ENC(Encoding_File, ENCODED);
    // ENCODED.close();
    // string R_ENCODED = ReadingFile::READ_INPUT("7alwlw");
    // ofstream DECODED = ReadingFile::READ_OUTPUT("FINAL_DEC.txt");
    // ENCODING_LZ77::LZ77_DEC(R_ENCODED, DECODED);
}
