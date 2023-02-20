#include<iostream>

using namespace std;

int * initArray (int m);
int init();
bool checkSuit (int * Array1, int * Array2);
int countNumber(int *Array1, int * Array2, int len1, int len2);
int getGcd(int * Array, int len);
int getLcd(int * Array, int len);

int main()
{
    int m = init();
    int n = init();
    int * A1 = initArray(m);
    int * A2 = initArray(n);

    cout << countNumber(A1, A2, m, n);

    return 0;

}

int init()
{
    int number;

    cin >> number;

    return number;
}

int * initArray (int m)
{
    int * Array = new int[m];

    for (int i = 0; i < m; i++){
        cin >> *(Array + i);
    }

    return Array;
}

int Gcd(int a, int b)
{
    if (a % b == 0) return b;
    int r = a % b;
    return Gcd(b, r);
}

int getGcd(int* Array, int len)
{
    int gcd = Gcd(*(Array), *(Array + 1));
    for(int i = 2; i < len; i++){
        gcd = Gcd(gcd, *(Array + i));
    }
    return gcd;
}

int Lcd(int a, int b)
{
    return a * b / Gcd(a, b);
}

int getLcd(int* Array, int len)
{
    int lcd = Lcd(*(Array), *(Array + 1));
    for (int i = 2; i < len; i++){
        lcd = Lcd(lcd, *(Array + i));
    }
    return lcd;
}

int countNumber(int *Array1, int * Array2, int len1, int len2)
{
    int count = 0;
    int gcd_Array2 = getGcd( Array2, len2);
    int lcd_Array1 = getLcd( Array1, len1);

    if (gcd_Array2 % lcd_Array1 != 0) return count;
    while(lcd_Array1 <= gcd_Array2)
    {
        if (gcd_Array2 % lcd_Array1 == 0) count++;
        lcd_Array1 += lcd_Array1;
    }

    return count;
}


