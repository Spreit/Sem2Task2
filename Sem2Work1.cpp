﻿// Sem2Work1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// 1. Массив с интами
// 2. Пустой массив такого же размера
// 
// Если количество интов нечетное, то перенести все числа кроме последнего при помощи дабл
// Перенести последний элемент при помощи инт
// 

#include <iostream>

const int N = 9;
int mas_a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int mas_b[N] = { 0 };

double * double_origin = (double*) & mas_a;
double * double_dest   = (double*) & mas_b;

int main()
{
    char size_difference = sizeof(double) / sizeof(mas_a[0]);
    int leftover = N % size_difference;
    int copy_size = (N - leftover) / size_difference;

    //Так быстрее (наверное) за счет переноса 2 int за раз в одном double
    ///*
    for (int i = 0; i < copy_size; ++i) {
        *(double_dest + i) = *(double_origin + i);
    }
    ///* Если не удалось полностью заполнить double полностью
    for (int i = 0; i < leftover; ++i) {
        mas_b[copy_size * size_difference + i] = mas_a[copy_size * size_difference + i];
        std::cout << "Leftover" << std::endl;
    }
    //*/
    //*mas_a = 10;
    //std::cout << mas_a[0] << std::endl;

    //std::cout << double_origin << std::endl;
    //std::cout << copy_size << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << mas_b[i] << " ";
    }

}

/*
Можно просто memcpy???
const int N = 21;
int mas_a[N] = { 1, 2, 3, 4, 5 };
int mas_b[N] = { 0 };

double* double_origin = (double*)&mas_a;
double* double_dest   = (double*)&mas_b;


int main()
{
    //Сколько double
    int half_size = (N - N % 2) / 2;

    //Так быстрее (наверное) за счет переноса 2 int за раз в одном double
    for (int i = 0; i < half_size; ++i) {
        *(double_dest + i) = *(double_origin + i);
    }

    if (N % 2 == 1) {
        mas_b[N - 1] = mas_a[N - 1];
        std::cout << "Leftover" << std::endl;
    }

    std::cout << half_size << std::endl;

    std::cout << mas_b[N - 1] << std::endl;


*/


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
