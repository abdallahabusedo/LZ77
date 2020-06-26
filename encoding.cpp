#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
#define SEARCHBUFFER_SIZE 4096
#define LOCK_A_HEAD_SIZE 16
class ENCODING_LZ77
{

public:
    static void LZ77_ENC(wstring String_TOENC, wofstream &ENCODED_FILE)
    {
        wchar_t chars = String_TOENC[0];
        ENCODED_FILE.write(GET_CODE(chars), 2);
        int SEARCHBUFFER_REVERSE = 0, LOOK_A_HEAD_F = 1, LOOK_A_HEAD_M = 1, SEARCHBUFFER_FORWORD;
        int JUMP_COUNT = 0, LENGTH_COUNT = 0, CURRENT_LENGTH_COUNTER = 0, CURRENT_JUMP_COUNTER = 0, JUMPLENGTH;
        while (LOOK_A_HEAD_F < String_TOENC.size())
        {
            JUMP_COUNT = 0;
            LENGTH_COUNT = 0;
            SEARCHBUFFER_REVERSE = LOOK_A_HEAD_F;
            CURRENT_JUMP_COUNTER = 0;
            while (SEARCHBUFFER_REVERSE > 0 && CURRENT_JUMP_COUNTER < SEARCHBUFFER_SIZE)
            {
                CURRENT_JUMP_COUNTER++;
                SEARCHBUFFER_REVERSE--;
                if (String_TOENC[SEARCHBUFFER_REVERSE] == String_TOENC[LOOK_A_HEAD_F])
                {

                    CURRENT_LENGTH_COUNTER = 1;
                    SEARCHBUFFER_FORWORD = SEARCHBUFFER_REVERSE + 1;
                    LOOK_A_HEAD_M = LOOK_A_HEAD_F + 1;
                    while (CURRENT_LENGTH_COUNTER < LOCK_A_HEAD_SIZE)
                    {
                        if (String_TOENC[SEARCHBUFFER_FORWORD] != String_TOENC[LOOK_A_HEAD_M])
                        {
                            break;
                        }
                        CURRENT_LENGTH_COUNTER++;
                        SEARCHBUFFER_FORWORD++;
                        LOOK_A_HEAD_M++;
                    }
                    if (LENGTH_COUNT < CURRENT_LENGTH_COUNTER)
                    {
                        LENGTH_COUNT = CURRENT_LENGTH_COUNTER;
                        JUMP_COUNT = CURRENT_JUMP_COUNTER;
                    }
                }
                CURRENT_JUMP_COUNTER++;
            }
            if (LENGTH_COUNT == 0)
            {
                ENCODED_FILE.write(GET_CODE(String_TOENC[LOOK_A_HEAD_F]), 2);
                LOOK_A_HEAD_F++;
            }
            else
            {
                LOOK_A_HEAD_F += LENGTH_COUNT;
                ENCODED_FILE.write(GET_CODE(JUMP_COUNT, LENGTH_COUNT, String_TOENC[LOOK_A_HEAD_F]), 3);
                LOOK_A_HEAD_F++;
            }
        }
    }
    static void LZ77_DEC(wifstream &ENCODED_FILE, wostream &FINAL_OUTPUT)
    {
        cout << "DECODING start " << '\n';
        wchar_t TEMP_CODE[2];
        wchar_t CURRENT_BYTE[1];
        int MASTER = 0, AUX;
        wstring OUT_STRING;
        pair<int, int> J_L;
        while (ENCODED_FILE.read(CURRENT_BYTE, 1))
        {
            if (CURRENT_BYTE[0] == 0x00)
            {
                ENCODED_FILE.read(CURRENT_BYTE, 1);
                cout << CURRENT_BYTE[0];
                OUT_STRING.append(1, CURRENT_BYTE[0]);
                MASTER++;
            }
            else
            {
                TEMP_CODE[0] = CURRENT_BYTE[0];
                ENCODED_FILE.read(CURRENT_BYTE, 1);
                TEMP_CODE[1] = CURRENT_BYTE[0];
                J_L = GET_JUMP_LENGTH(TEMP_CODE);
                AUX = MASTER - J_L.first;
                for (int i = 0; i < J_L.second; i++)
                {
                    cout << OUT_STRING[AUX];
                    OUT_STRING.append(1, OUT_STRING[AUX++]);
                    MASTER++;
                }
                ENCODED_FILE.read(CURRENT_BYTE, 1);
                cout <<CURRENT_BYTE[0];
                OUT_STRING.append(1, CURRENT_BYTE[0]);
                MASTER++;
            }
        }
        // for (size_t i = 0; i < OUT_STRING.size(); i++)
        // {
        //     cout << (char)OUT_STRING[i] << '\n';
        // }
    }

    static wchar_t *GET_CODE(int JUMP, int LENGTH, wchar_t BYTE)
    {
        wchar_t *ARR = new wchar_t[3];
        uint16_t CODE = 0;
        JUMP = JUMP << 4;
        CODE = CODE | JUMP;
        CODE = CODE | LENGTH;
        ARR[0] = ((CODE >> 8) & 0xff);
        ARR[1] = CODE & 0xff;
        ARR[2] = BYTE;
        return ARR;
    }
    static wchar_t *GET_CODE(wchar_t BYTE)
    {
        wchar_t *ARR = new wchar_t[2];
        ARR[0] = 0x00;
        ARR[1] = BYTE;
        return ARR;
    }
    static pair<int, int> GET_JUMP_LENGTH(wchar_t *CODE)
    {
        uint8_t LENGTH = CODE[1] & 0x0f;
        uint16_t JUMP = CODE[0];
        JUMP = JUMP << 4;
        uint8_t TEMP = (CODE[1] >> 4) & 0x0f;
        JUMP |= TEMP;
        return make_pair(JUMP, LENGTH);
    }
};