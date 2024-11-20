// Створити лінійний односпрямований список із дійсних чисел. Видалити зі списку
//елемент перед кожним елементом, який має значення 55


#include <iostream>
#include <forward_list>
#include <iomanip> 
#include <windows.h> 
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    forward_list<double> numberList = { 10.1, 55.0, 12.5, 19.8, 8.4, 4.7, 1.5, 55.0, 79.3 };
    cout << "Створити лінійний односпрямований список із дійсних чисел. Видалити зі списку елемент перед кожним елементом, який має \nзначення 55";
    cout << endl;
    cout << "\nСписок дійсних чисел: ";
    for (double number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    auto Previous = numberList.before_begin();
    auto prev = numberList.begin();
    auto curr = next(prev);

    while (curr != numberList.end()) {
        if (*curr == 55) {
            numberList.erase_after(Previous);
            prev = curr;
        }
        else {
            Previous = prev;
            prev = curr;                      
        }
        curr = next(curr); 
    }

    cout << "Оновлений список: ";
    for (double number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}



