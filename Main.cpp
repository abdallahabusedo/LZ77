#include "FileReader.cpp"
#include "encoding.cpp"
#include <iostream>

using namespace std;

int main()
{
    // string Encoding_File = ReadingFile::READ_INPUT("enwik8.txt");
    // ofstream ENCODED = ReadingFile::READ_OUTPUT("out");
    // ENCODING_LZ77::LZ77_ENC(Encoding_File, ENCODED);
    // ENCODED.close();
    string R_ENCODED = ReadingFile::READ_INPUT("out");
    ofstream DECODED = ReadingFile::READ_OUTPUT("final");
    ENCODING_LZ77::LZ77_DEC(R_ENCODED, DECODED);
    DECODED.close();
}