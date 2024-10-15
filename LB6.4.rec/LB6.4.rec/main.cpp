#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

void create(int* arr, int SIZE, double MIN, double MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = (MAX - MIN) * rand() / RAND_MAX + MIN;
        create(arr, SIZE, MIN, MAX, i + 1);
    }
}

void Print(int* arr, const int SIZE, int i)
{
    cout << setw(10) << fixed << setprecision(2) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}

int findMaxModIndex(int* arr, int SIZE, int maxModIndex, int maxMod, int i)
{
    if (i < SIZE)
    {
        if (abs(arr[i]) > maxMod)
        {
            maxMod = abs(arr[i]);
            maxModIndex = i;
        }
        return findMaxModIndex(arr, SIZE, maxModIndex, maxMod, i + 1);
    }
    return maxModIndex;
}

int sumAfterFirstPositive(int* arr, int SIZE, int sum, bool foundPositive, int i)
{
    if (i < SIZE)
    {
        if (!foundPositive && arr[i] > 0)
        {
            foundPositive = true;
        }
        else if (foundPositive)
        {
            sum += arr[i];
        }
        return sumAfterFirstPositive(arr, SIZE, sum, foundPositive, i + 1);
    }
    return sum;
}

void copyArray(int* arr, int* tempArr, int SIZE, int i)
{
    if (i < SIZE)
    {
        arr[i] = tempArr[i];
        copyArray(arr, tempArr, SIZE, i + 1);
    }
}

void rearrangeArray(int* arr, int SIZE, int* tempArr, int a, int b, int inRangeIndex, int outRangeIndex, int i)
{
    if (i < SIZE)
    {
        int wholePart = static_cast<int>(arr[i]);
        if (wholePart >= a && wholePart <= b)
        {
            tempArr[inRangeIndex++] = arr[i];
        }
        else
        {
            tempArr[outRangeIndex++] = arr[i];
        }
        rearrangeArray(arr, SIZE, tempArr, a, b, inRangeIndex, outRangeIndex, i + 1);
    }
    else
    {
        copyArray(arr, tempArr, SIZE, 0);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE, a, b;
    cout << "Введіть розмір масиву (SIZE): ";
    cin >> SIZE;
    cout << "Введіть нижню межу інтервалу (a): ";
    cin >> a;
    cout << "Введіть верхню межу інтервалу (b): ";
    cin >> b;

    double MIN = -20, MAX = 20;
    int* arr = new int[SIZE];

    create(arr, SIZE, MIN, MAX, 0);
    Print(arr, SIZE, 0);
    cout << endl;

    cout << "Номер максимального за модулем елемента масиву: " << findMaxModIndex(arr, SIZE, 0, abs(arr[0]), 1) << endl;
    cout << "Сума елементів масиву, розташованих після першого додатного елементу: " << sumAfterFirstPositive(arr, SIZE, 0, false, 0) << endl;

    int* tempArr = new int[SIZE];
    rearrangeArray(arr, SIZE, tempArr, a, b, 0, 0, 0);

    cout << "\nМасив після перетворення:" << endl;
    Print(arr, SIZE, 0);

    delete[] arr;
    delete[] tempArr;
    return 0;
}