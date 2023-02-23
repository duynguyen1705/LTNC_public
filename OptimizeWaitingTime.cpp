#include<iostream>

using namespace std;

int init();
int * initArray(int len);
long long sumTime(int * Array, int len);

int main()
{
    int n = init();
    int * arr = initArray(n);

    cout << sumTime(arr, n);

    return 0;
}

int init()
{
    int num;

    cin >> num;

    return num;
}

int * initArray(int len)
{
    int * arr = new int[len];
    for (int i = 0; i < len; i++){
        cin >> arr[i];
    }

    return arr;
}

void Swap (int * a, int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}

void bubbleSort(int * Array, int len)
{
    for (int i = 0; i < len - 1; i++)
        for(int j = 0; j < len - i - 1; j++)
            if(Array[j] > Array[j + 1])
                Swap(&Array[j], &Array[j+1]);
}

long long sum(int* Array, int len)
{
    long long sum = 0;
    for (int i = 0; i < len; i++)
        sum += Array[i];

    return sum;
}
long long sumTime(int* Array, int len)
{
    long long Sum = 0;

    bubbleSort(Array, len);
    for(int i = 0; i < len; i++)
        Sum += sum(Array, i);

    return Sum;
}

