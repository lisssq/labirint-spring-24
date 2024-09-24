#include"labirint.h"


Labirint::Labirint(const string& filepath)
{
    ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error. Failed to open file: " << filepath << std::endl;
        labirint = nullptr;
        return;
    }

    file >> *this;

    file.close();
}

Labirint::~Labirint()           //деструктор освобождает память выделенную для хранения лабиринта
{
    if (labirint == nullptr) 
    {
        return;
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            delete[] labirint[i][j];
        }
        delete[] labirint[i];
    }
    delete[] labirint;
}

Labirint::Labirint(const Labirint& other)       //копирование игры 
{
    h = other.h;
    w = other.w;
    person = other.person;
    labirint = new AbstractCell * *[h];      //выделение памяти
    for (int i = 0; i < h; i++)
    {
        labirint[i] = new AbstractCell * [w];
        for (int j = 0; j < w; j++)
        {
            labirint[i][j] = other.labirint[i][j];    //копирование
        }
    }
}


enum class CellType 
{
    EmptyCell,
    WallCell,
    CoinCell,
    MonsterCell,
    PersonCell,
    ExitCell
};

CellType defineCellType(char c)
{
    switch (c) {
    case 'P':
        return CellType::PersonCell;
    case '#':
        return CellType::WallCell;
    case '$':
        return CellType::CoinCell;
    case '@':
        return CellType::MonsterCell;
    case 'X':
        return CellType::ExitCell;
    case '.':
        return CellType::EmptyCell;
    }
}


istream& operator>>(istream& in, Labirint& labirint)
{
    in >> labirint.w >> labirint.h;

    labirint.labirint = new AbstractCell * *[labirint.h];

    for (int y = 0; y < labirint.h; y++) 
    {
        labirint.labirint[y] = new AbstractCell * [labirint.w];
        for (int x = 0; x < labirint.w; x++) 
        {
            char c;
            in >> c;

            CellType cellType = defineCellType(c);

            switch (cellType) 
            {
            case CellType::PersonCell:
                labirint.person = Person(x, y);
                labirint.labirint[y][x] = new PersonCell();
                labirint.start_x = x;
                labirint.start_y = y;
                break;

            case CellType::WallCell:
                labirint.labirint[y][x] = new WallCell();
                break;

            case CellType::CoinCell:
                labirint.labirint[y][x] = new CoinCell();
                break;

            case CellType::MonsterCell:
                labirint.labirint[y][x] = new MonsterCell();
                break;

            case CellType::ExitCell:
                labirint.labirint[y][x] = new ExitCell();
                break;

            case CellType::EmptyCell:
                labirint.labirint[y][x] = new EmptyCell();
                break;
            }
        }
    }

    return in;
}