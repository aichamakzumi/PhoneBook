#include "PhoneBook.h"

// Конструктор
PhoneBook::PhoneBook() : contacts(nullptr), count(0), capacity(0)
{
}

// Деструктор 
PhoneBook::~PhoneBook()
{
    delete[] contacts;
    contacts = nullptr;
}


void PhoneBook::resize(int newCapacity)
{
    Contact* newContacts = new Contact[newCapacity];
    for (int i = 0; i < count; ++i)
    {
        newContacts[i] = contacts[i];
    }
    delete[] contacts;
    contacts = newContacts;
    capacity = newCapacity;
}

// Додавання нового абонента
void PhoneBook::AddContact(const Contact& contact)
{
    if (capacity == 0)
    {
        resize(4);
    }
    else if (count == capacity)
    {
        resize(capacity * 2);
    }
    contacts[count] = contact;
    count++;
    cout << "Абонента успішно додано!" << endl;
}

// Видалення абонента за порядковим номером
bool PhoneBook::DeleteContact(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "Помилка: некоректний індекс!" << endl;
        return false;
    }

    for (int i = index; i < count - 1; ++i)
    {
        contacts[i] = contacts[i + 1];
    }
    count--;
    cout << "Абонента успішно видалено!" << endl;
    return true;
}

// Пошук абонентів за ПІБ
void PhoneBook::SearchByName(const char* name) const
{
    if (count == 0)
    {
        cout << "Телефонна книга порожня." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (strstr(contacts[i].getFullName(), name) != nullptr)
        {
            cout << "\nЗнайдено абонента #" << (i + 1) << ":" << endl;
            contacts[i].Print();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Абонента з ПІБ \"" << name << "\" не знайдено." << endl;
    }
}

// Відображення всіх абонентів
void PhoneBook::ShowAll() const
{
    if (count == 0)
    {
        cout << "Телефонна книга порожня." << endl;
        return;
    }

    cout << "\n========== СПИСОК АБОНЕНТІВ (" << count << ") ==========" << endl;
    for (int i = 0; i < count; ++i)
    {
        cout << "№ " << (i + 1) << ":" << endl;
        contacts[i].Print();
    }
}


void PhoneBook::SaveToFile(const string& filename) const
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }

    outFile << count << endl;
    for (int i = 0; i < count; ++i)
    {
        contacts[i].SaveToFile(outFile);
    }

    outFile.close();
    cout << "Дані успішно збережено у файл \"" << filename << "\"!" << endl;
}


void PhoneBook::LoadFromFile(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        cout << "Помилка відкриття файлу для читання (можливо, файл ще не існує)." << endl;
        return;
    }

    int loadCount = 0;
    if (!(inFile >> loadCount))
    {
        inFile.close();
        return;
    }
    inFile.ignore();

    delete[] contacts;
    count = 0;
    capacity = (loadCount > 0) ? loadCount : 4;
    contacts = new Contact[capacity];

    for (int i = 0; i < loadCount; ++i)
    {
        Contact c;
        c.LoadFromFile(inFile);
        contacts[i] = c;
        count++;
    }

    inFile.close();
    cout << "Дані успішно завантажено з файлу \"" << filename << "\" (завантажено " << count << " записів)!" << endl;
}
