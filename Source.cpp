// Lab 6.4 rec
// Кулик Олег ІК-11
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace  std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i] << ",";
    if (i < size - 1)
        Print(a, size, i + 1);
}


int min_i(int* a, int n, int id = 0, int cur_min = 0, int cur_id = 0)
{
    if (id == 0)
    {
        cur_min = a[0];
        cur_id = 0;
    }
    if (id == n)return cur_id;
    if (a[id] < cur_min)
    {
        cur_min = a[id];
        cur_id = id;
    }
    return min_i(a, n, id + 1, cur_min, cur_id);
}


int sum(int* a, int n, int id = 0, int cur_sum = 0, int seen = 0)
{
    if (id == n)return cur_sum;
    if (seen && a[id] < 0)return cur_sum;
    if (!seen && a[id] < 0)return sum(a, n, id + 1, cur_sum, 1);
    if (!seen && a[id] > 0)return sum(a, n, id + 1, cur_sum, 0);
    return sum(a, n, id + 1, cur_sum, seen) + a[id];
}


void convert(int* a, int n, int id = 0, int cur_to_put = 0)
{
    if (id == n)return;
    if (abs(a[id]) <= 1) {
        swap(a[id], a[cur_to_put]);
        cur_to_put++;
    }
    convert(a, n, id + 1, cur_to_put);
}

int main()
{

    int n;
    cout << "n = ";
    cin >> n;
    int* a = new int[n];

    int Low;
    int High;
    cout << "Low = "; cin >> Low;
    cout << "High = "; cin >> High;

    Create(a, n, Low, High, 0);
    cout << "a[" << n << "] = {";
    Print(a, n, 0);
    cout << "}"; cout << endl;

    int min_id = min_i(a, n);
    cout << "Number of minimal element: " << min_id << '\n';
    int summ = sum(a, n);
    cout << "sum of array elements between two negative elements = " << summ << endl;

    cout << "a[" << n << "] = {";
    convert(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << "}"; cout << endl;


}
