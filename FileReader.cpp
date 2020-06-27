#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadingFile
{
public:
    static string READ_INPUT(const string &_Input_File_Name_)
    {
        ifstream INPUT_FILE(_Input_File_Name_, ios::in | ios::binary);
        string FILE_String;
        if (INPUT_FILE)
        {
            INPUT_FILE.seekg(0, ios::end);
            FILE_String.resize(INPUT_FILE.tellg());
            INPUT_FILE.seekg(0, ios::beg);
            INPUT_FILE.read((char *)FILE_String.c_str(), FILE_String.size());
            INPUT_FILE.close();
        }
        return FILE_String;
    }
    static ofstream READ_OUTPUT(string _OUTPUT_FILE_NAME_)
    {
        ofstream OUTPUT_FILE(_OUTPUT_FILE_NAME_, ios::binary | ios::out);
        return OUTPUT_FILE;
    }
    static ifstream READ_INPUT2(const string &_Input_File_Name_)
    {
        ifstream INPUT_FILE(_Input_File_Name_, ios::in | ios::binary);
        return INPUT_FILE;
    }
};