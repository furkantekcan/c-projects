#include <iostream>
using namespace std;

wstring tetromino[7];
int fieldWidth = 12;
int fieldHeight = 18;

unsigned char *pField = nullptr;

int Rotate(int px, int py, int r)
{
    switch (r % 4)
    {
    // 0 degree:
    case 0:
        return py * 4 + px;
    // 90 degrees:
    case 1:
        return 12 + py - (px * 4);
    // 180 degrees:
    case 2:
        return 15 - (py * 4) - px;
    // 270 degrees:
    case 3:
        return 3 - py + (px * 4);
    }

    return 0;
}

int main()
{

    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    tetromino[1].append(L"..X.");
    tetromino[1].append(L".xX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");

    tetromino[2].append(L".X..");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");

    tetromino[3].append(L"..X.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");

    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");

    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"....");
    tetromino[6].append(L".XX.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    pField = new unsigned char[fieldWidth*fieldHeight];
    for(int x = 0; x < fieldWidth; x++)
    {
        for (int y = 0; y < fieldHeight; y++)
        {
            pField[y*fieldWidth + x] = (x==0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0 ;
        }
        
    }

    return 0;
}