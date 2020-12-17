// 6.1.cpp - рекурсія

#include <iostream>
#include<iomanip>

using namespace std;

void print1(int* c, const int n, int i)
{
    cout << setw(3) << c[i];
    if (i < n - 1)
        print1(c, n, i + 1);
    else
        cout << '\n';
}

void format_mas(int* c, int n, int& sum, int& k, int i)
{
    if (i < n)
    {
        if (!(c[i] % 2 == 0) || c[i] % 13 == 0) // !(c[i] % 2 == 0) - крім парних; c[i] % 13 == 0 - з індексами, кратними 13
        {
            k++;
            sum += c[i];
            c[i] = 0;
        }
        format_mas(c, n, sum, k, i + 1);
    }
    else
    {
        cout << '\n';
        cout << "quantity - " << k << '\n';
        cout << "sum - " << setw(8) << sum << '\n';
        cout << '\n';
    }
}

void print0(int* c, const int n, int i)
{
    cout << setw(3) << c[i] ;
    if (i < n - 1)
        print0(c, n, i + 1);
    else
        cout << '\n';
}

void create(int* c, const int size, const int Low, const int High, int i)
{
    c[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        create(c, size, Low, High, i + 1);
}

int main()
{
    srand(unsigned(time(NULL))); // ініціалізація генератора випадкових чисел
    
    const int n = 21;
    int c[n]; 
    int sum = 0;
    int k = 0;
    create(c, n, 15, 85, 0); // створюємо масив
    
    cout << setw(3) << "c[] = ";
    print0(c, n, 0); // виводимо його
    format_mas(c, n, sum, k, 0); // опрацьовуємо

    cout << setw(3) << "c[] = ";
    print1(c, n, 0); // виводимо 
    
    getchar();
}