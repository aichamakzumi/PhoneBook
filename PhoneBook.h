#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

// Клас ьелефонна книга для управління масивом абонентів
class PhoneBook
{
private:
    Contact* contacts;  
    int count;          
    int capacity;       

    
    void resize(int newCapacity);

public:
    // Конструктор та деструктор
    PhoneBook();
    ~PhoneBook();

    // Операції з абонентами
    void AddContact(const Contact& contact);
    bool DeleteContact(int index);
    void SearchByName(const char* name) const;
    void ShowAll() const;

   
    void SaveToFile(const string& filename) const;
    void LoadFromFile(const string& filename);

    
    inline int getCount() const
    {
        return count;
    }
};

#endif 
