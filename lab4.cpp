// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <sstream> 
#include <cstdlib> 
#include <Windows.h>
using namespace std;

int drp1[21][21] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
int drp_copy[21][21];
int drp_copy1[21][21];
int drp[21][21];
char symbol_1 = '#';
char symbol_0 = '.';

void vv()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (drp[i][j] == 0)
                cout << symbol_0 << "  ";
            if (drp[i][j] == 1)
                cout << symbol_1 << "  ";
        }
        cout << "\n";
    }

}

void vv1()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (drp1[i][j] == 0)
                cout << symbol_0 << "  ";
            if (drp1[i][j] == 1)
                cout << symbol_1 << "  ";
        }
        cout << "\n";
    }

}

void game()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            int neighbours = 0;
            if (i > 0 && drp[i - 1][j] == 1)
                neighbours++;
            if (i > 0 && j > 0 && drp[i - 1][j - 1] == 1)
                neighbours++;
            if (i > 0 && j < 20 && drp[i - 1][j + 1] == 1)
                neighbours++;
            if (i < 20 && drp[i + 1][j] == 1)
                neighbours++;
            if (j > 0 && drp[i][j - 1] == 1)
                neighbours++;
            if (j < 20 && drp[i][j + 1] == 1)
                neighbours++;
            if (j > 0 && i < 20 && drp[i + 1][j - 1] == 1)
                neighbours++;
            if (i < 20 && j < 20 && drp[i + 1][j + 1] == 1)
                neighbours++;
            if (drp[i][j] == 1)
            {
                if (neighbours == 2 || neighbours == 3)
                    drp_copy[i][j] = 1;
                else
                    drp_copy[i][j] = 0;
            }
            else
            {
                if (neighbours == 3)
                    drp_copy[i][j] = 1;
                else
                    drp_copy[i][j] = 0;
            }
        }
    }
}

void game1()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            int neighbours = 0;
            if (i > 0 && drp1[i - 1][j] == 1)
                neighbours++;
            if (i > 0 && j > 0 && drp1[i - 1][j - 1] == 1)
                neighbours++;
            if (i > 0 && j < 20 && drp1[i - 1][j + 1] == 1)
                neighbours++;
            if (i < 20 && drp1[i + 1][j] == 1)
                neighbours++;
            if (j > 0 && drp1[i][j - 1] == 1)
                neighbours++;
            if (j < 20 && drp1[i][j + 1] == 1)
                neighbours++;
            if (j > 0 && i < 20 && drp1[i + 1][j - 1] == 1)
                neighbours++;
            if (i < 20 && j < 20 && drp1[i + 1][j + 1] == 1)
                neighbours++;
            if (drp1[i][j] == 1)
            {
                if (neighbours == 2 || neighbours == 3)
                    drp_copy1[i][j] = 1;
                else
                    drp_copy1[i][j] = 0;
            }
            else
            {
                if (neighbours == 3)
                    drp_copy1[i][j] = 1;
                else
                    drp_copy1[i][j] = 0;
            }
        }
    }
}

void copy()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            drp[i][j] = drp_copy[i][j];
            drp_copy[i][j] = 0;
        }
    }
}

void copy1()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            drp1[i][j] = drp_copy1[i][j];
            drp_copy1[i][j] = 0;
        }
    }
}

void file_loading(int argc, char* argv[])
{
    ifstream file;
    string file_load;
    if (argc > 1)
        file_load = argv[1];
    file.open(file_load);
    if (!file.is_open())
    {
        if (argc != 1)
            cout << file_load << " Looking for a file.." << endl;
        do
        {
            cout << "Enter file name: \n";
            getline(cin, file_load);
            file.open(file_load);
        } while (!file.is_open());

    }
    cout << file_load << " file is open\n";
    {
        if (file)
            for (int i = 0; i < 21; i++)
            {
                for (int j = 0; j < 21; j++)
                {
                    file >> drp[i][j];
                    if (file.eof())
                        break;
                }
            }
    }
}


int main(int argc, char* argv[])
{
    cout << "hello!\n";
    cout << "task 1: \n";
    vv1();
    cout << "task 2: \n";
    game1();
    copy1();
    vv1();
    char key;
    int keyToInt;
    string a;
    file_loading(argc, argv);
    vv();
    for (;;)
    {
    AGAIN: cout << "Number of iteration: " << endl;
        key = _getch();
        if (key == 27)
        {
            return 0;
        }
        else
            keyToInt = key - '0';
        try
        {
            if ((int)key > 57 || (int)key < 48)
                throw 1;
        }
        catch (int)
        {
            system("cls");
            goto AGAIN;
        }
        for (int i = 0; i < keyToInt; i++)
        {
            std::cout << "Iteration: " << i << std::endl;
            game();
            copy();
            vv();
        }
        //game();
        //copy();
        //vv();
        cout << "The end\n";

    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
