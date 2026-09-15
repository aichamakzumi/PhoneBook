#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <limits>
#include "PhoneBook.h"

using namespace std;


void showMenu()
{
    cout << "\n================ МЕНЮ ================" << endl;
    cout << "1. Додати нового абонента" << endl;
    cout << "2. Видалити абонента" << endl;
    cout << "3. Шукати абонента за ПІБ" << endl;
    cout << "4. Показати всіх абонентів" << endl;
    cout << "5. Зберегти інформацію у файл" << endl;
    cout << "6. Завантажити інформацію з файлу" << endl;
    cout << "0. Вихід" << endl;
    cout << "======================================" << endl;
    cout << "Оберіть пункт: ";
}

int main()
{
   
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    PhoneBook book;
    const string filename = "phonebook.txt";
    int choice = -1;

    do
    {
        showMenu();
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Некоректне введення! Спробуйте ще раз." << endl;
            continue;
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n'); 

        switch (choice)
        {
        case 1:
        {
            cout << "\n--- Додавання нового абонента ---" << endl;
            Contact newContact;
            newContact.Input();
            book.AddContact(newContact);
            break;
        }
        case 2:
        {
            cout << "\n--- Видалення абонента ---" << endl;
            book.ShowAll();
            if (book.getCount() > 0)
            {
                cout << "Введіть номер абонента для видалення (1-" << book.getCount() << "): ";
                int num;
                if (cin >> num)
                {
                    book.DeleteContact(num - 1);
                }
                else
                {
                    cin.clear();
                    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                    cout << "Некоректний номер!" << endl;
                }
            }
            break;
        }
        case 3:
        {
            cout << "\n--- Пошук абонента за ПІБ ---" << endl;
            char searchName[256];
            cout << "Введіть ПІБ (або його частину) для пошуку: ";
            cin.getline(searchName, 256);
            book.SearchByName(searchName);
            break;
        }
        case 4:
        {
            book.ShowAll();
            break;
        }
        case 5:
        {
            book.SaveToFile(filename);
            break;
        }
        case 6:
        {
            book.LoadFromFile(filename);
            break;
        }
        case 0:
            cout << "Завершення роботи програми." << endl;
            break;
        default:
            cout << "Невідомий пункт меню! Спробуйте ще раз." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
