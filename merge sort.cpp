#include <iostream>
using namespace std;
#include <ctime>

template <class T>
T *merge(T *A, T *B, int a, int b);

template <class T>
T *sort(T *A, int a);

template <class T>
void print(T *A, int a)
{
    for (int i = 0; i < a; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int *arr = new int[5];
    char *chars = new char[5];

    arr[0] = 75;
    arr[1] = 4;
    arr[2] = 1004;
    arr[3] = 9;
    arr[4] = 90;

    chars[0] = 122;
    chars[1] = 100;
    chars[2] = 104;
    chars[3] = 97;
    chars[4] = 120;

    print(arr, 5);
    print(chars, 5);

    arr = sort(arr, 5);
    chars = sort(chars, 5);

    print(arr, 5);
    print(chars, 5);

    delete[] arr;
    delete[] chars;
    return 0;
}

template <class T>
T *merge(T *A, T *B, int a, int b)
{
    int sum = a + b;
    T *C = new T[sum];
    int i = 0, ai = 0, bi = 0;

    while (ai < a && bi < b)
    {
        if (A[ai] < B[bi])
        {
            C[i++] = A[ai];
            ai++;
        }
        else
        {
            C[i++] = B[bi];
            bi++;
        }
    }

    while (ai < a)
    {
        C[i++] = A[ai];
        ai++;
    }

    while (bi < b + (sum & 1))
    {
        C[i++] = B[bi];
        bi++;
    }

    return C;
}

template <class T>
T *sort(T *ARR, int a)
{
    if (a == 1)
        return ARR;

    T *A = new T[a / 2];
    T *B = new T[(a / 2) + (a & 1)];

    for (int i = 0; i < a / 2; i++)
    {
        A[i] = ARR[i];
    }

    for (int i = 0; i < a / 2 + (a & 1); i++)
    {
        B[i] = ARR[i + (a / 2)];
    }

    A = sort(A, a / 2);
    B = sort(B, a / 2 + (a & 1));

    return merge(A, B, a / 2, a / 2 + (a & 1));
}