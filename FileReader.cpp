#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadingFile
{
public:
    static wstring READ_INPUT(const string &_Input_File_Name_)
    {
        wifstream INPUT_FILE(_Input_File_Name_, ios::in | ios::binary);
        wstring FILE_String;
        if (INPUT_FILE)
        {
            INPUT_FILE.seekg(0, ios::end);
            FILE_String.resize(INPUT_FILE.tellg());
            INPUT_FILE.seekg(0, ios::beg);
            INPUT_FILE.read((wchar_t *)FILE_String.c_str(), FILE_String.size());
            INPUT_FILE.close();
        }
        return FILE_String;
    }
    static wofstream READ_OUTPUT(string _OUTPUT_FILE_NAME_)
    {
        wofstream OUTPUT_FILE(_OUTPUT_FILE_NAME_, ios::binary | ios::out);
        return OUTPUT_FILE;
    }
    static wifstream READ_INPUT2(const string &_Input_File_Name_)
    {
        wifstream INPUT_FILE(_Input_File_Name_, ios::in | ios::binary);
        return INPUT_FILE;
    }
};