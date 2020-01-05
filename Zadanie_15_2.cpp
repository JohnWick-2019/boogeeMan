

#include <iostream>
#include <ctime>
using namespace std;

void OutMass(int*& arr, int size);
void FilinMass(int*& arr, int size);

int MaxMass(int*& arrA, int*& arrB, int size);
int MinMass(int*& arrA, int*& arrB, int size);
int AvgArr(int*& arrA, int*& arrB, int size);
int Action(int*& ptrArrA, int*& ptrArrB, int size, int (*Func)(int*&, int*&, int));

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int menu = 0;
    const int SIZE = 5;

    int arrA[SIZE];
    int arrB[SIZE];
    int* ptrArrA = arrA;
    int* ptrArrB = arrB;


    FilinMass(ptrArrA, SIZE);
    FilinMass(ptrArrB, SIZE);

    cout << "Вывод массива А:" << endl << endl;
    cout << "\t| ";
    OutMass(ptrArrA, SIZE);

    cout << endl << endl;
    cout << "Вывод массива B:" << endl << endl;
    cout << "\t| ";
    OutMass(ptrArrB, SIZE); // 
    cout << endl << endl;


    cout << "1) Максимальное число из двух массивов;" << endl;
    cout << "2) Минимальное число из двух массивов;" << endl;
    cout << "3) Среднее арефметическое из двух массивов;" << endl << endl;
    cout << "Введите номер меню: "; cin >> menu;
    cout << endl;

    switch (menu)
    {
    case 1:

        cout << "Максимальное число из двух массивов: " << Action(ptrArrA, ptrArrB, SIZE, MaxMass) << endl;

        break;

    case 2:

        cout << "Минимальное число из двух массивов: " << Action(ptrArrA, ptrArrB, SIZE, MinMass) << endl;

        break;

    case 3:

        cout << "Среднее арефметическое из двух массивов: " << Action(ptrArrA, ptrArrB, SIZE, AvgArr) << endl;

        break;
    default:
        cout << "Введено неверное число";
        break;
    }


}

void OutMass(int*& arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " | ";
    }
}
void FilinMass(int*& arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 - 50;
}

int MaxMass(int*& arrA, int*& arrB, int size)
{
    int tempA = arrA[0];
    int tempB = arrB[0];

    for (int i = 0; i < size; i++)
    {
        if (tempA < arrA[i])
        {
            tempA = arrA[i];
        }
        if (tempB < arrB[i])
        {
            tempB = arrB[i];
        }
    }
    if (tempA > tempB)
    {
        return tempA;
    }
    else
    {
        return tempB;
    }
}
int MinMass(int*& arrA, int*& arrB, int size)
{
    int tempA = arrA[0];
    int tempB = arrB[0];

    for (int i = 0; i < size; i++)
    {
        if (tempA > arrA[i])
        {
            tempA = arrA[i];
        }
        if (tempB > arrB[i])
        {
            tempB = arrB[i];
        }
    }
    if (tempA < tempB)
    {
        return tempA;
    }
    else
    {
        return tempB;
    }
}
int AvgArr(int*& arrA, int*& arrB, int size)
{
    int summ = 0, avg;

    for (int i = 0; i < size; i++)
    {
        summ += arrA[i] + arrB[i];
    }

    avg = summ / size;

    return avg;
}
int Action(int*& ptrArrA, int*& ptrArrB, int size, int(*Func)(int*&, int*&, int))
{
    return  Func(ptrArrA, ptrArrB, size);
}

