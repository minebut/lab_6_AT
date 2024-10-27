#include <iostream>
#include <chrono>
#include <Windows.h>
using namespace std;

unsigned long long int Factorial(int n) {
    if (n == 1) return 1;
    return n * Factorial(n - 1);
}


int pow(int x, int n);
double calc(int x, int n) {
    return static_cast<double>(pow(x, n)) / Factorial(n); 
}

int pow(int x, int n) {
    if (n == 1) return x;
    return x * pow(x, n - 1);
}

int maxInArray(int* arr, int size, int index = 0, int maxVal = INT_MIN) {
    if (index == size) return maxVal;
    if (arr[index] > maxVal) maxVal = arr[index];
    return maxInArray(arr, size, index + 1, maxVal);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть значення n для обчислення факторіалу: ";
    cin >> n;

    auto start = chrono::high_resolution_clock::now();
    unsigned long long int factorialResult = Factorial(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> factorialDuration = end - start;

    cout << "Факторіал числа " << n << " дорівнює: " << factorialResult << endl;
    cout << "Час виконання для факторіалу: " << factorialDuration.count() << " секунд" << endl;


    int x;
    cout << "\nВведіть значення x для обчислення x^n / n!: ";
    cin >> x;
    double resultCalc = calc(x, n);
    cout << "Результат x^" << n << " / " << n << "! дорівнює: " << resultCalc << endl;

    int arr[] = { 3, 5, 1, 8, 2 }; 
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxElement = maxInArray(arr, size);
    cout << "\nМаксимальне значення в масиві: " << maxElement << endl;

    int num1, num2;
    cout << "\nВведіть два числа для обчислення їх НСД: ";
    cin >> num1 >> num2;
    int gcdResult = gcd(num1, num2);
    cout << "НСД чисел " << num1 << " і " << num2 << " дорівнює: " << gcdResult << endl;

    cout << "\nВведіть значення x для побудови ряду Фібоначчі: ";
    cin >> x;
    cout << "Ряд чисел Фібоначчі до значення " << x << ":\n";
    int i = 0;
    while (true) {
        int fib = Fibonacci(i);
        if (fib > x) break;
        cout << fib << " ";
        i++;
    }
    cout << endl;

    return 0;
}
