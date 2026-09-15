#include "Contact.h"


static char* copyString(const char* str)
{
    if (str == nullptr)
        return nullptr;
    size_t len = strlen(str);
    char* newStr = new char[len + 1];
    for (size_t i = 0; i <= len; ++i)
    {
        newStr[i] = str[i];
    }
    return newStr;
}


Contact::Contact() 
    : fullName(nullptr), homePhone("не вказано"), workPhone("не вказано"), mobilePhone("не вказано"), info("немає")
{
    fullName = copyString("Невідомо");
}


Contact::Contact(const char* name, const string& home, const string& work, const string& mobile, const string& extraInfo)
    : fullName(nullptr), homePhone(home), workPhone(work), mobilePhone(mobile), info(extraInfo)
{
    setFullName(name);
}


Contact::Contact(const Contact& other)
    : fullName(nullptr), homePhone(other.homePhone), workPhone(other.workPhone), mobilePhone(other.mobilePhone), info(other.info)
{
    fullName = copyString(other.fullName);
}


Contact& Contact::operator=(const Contact& other)
{
    if (this != &other)
    {
        delete[] fullName;
        fullName = copyString(other.fullName);
        homePhone = other.homePhone;
        workPhone = other.workPhone;
        mobilePhone = other.mobilePhone;
        info = other.info;
    }
    return *this;
}

// Деструктор
Contact::~Contact()
{
    delete[] fullName;
    fullName = nullptr;
}


void Contact::setFullName(const char* name)
{
    delete[] fullName;
    if (name != nullptr && strlen(name) > 0)
    {
        fullName = copyString(name);
    }
    else
    {
        fullName = copyString("Невідомо");
    }
}

// Вивід інформації про контакт
void Contact::Print() const
{
    cout << "---------------------------------------" << endl;
    cout << " ПІБ:                " << (fullName ? fullName : "Невідомо") << endl;
    cout << " Домашній телефон:   " << homePhone << endl;
    cout << " Робочий телефон:    " << workPhone << endl;
    cout << " Мобільний телефон:  " << mobilePhone << endl;
    cout << " Додаткова інфо:     " << info << endl;
    cout << "---------------------------------------" << endl;
}


void Contact::Input()
{
    char buffer[256];
    cout << "Введіть ПІБ: ";
    cin.getline(buffer, 256);
    setFullName(buffer);

    cout << "Введіть домашній телефон: ";
    getline(cin, homePhone);

    cout << "Введіть робочий телефон: ";
    getline(cin, workPhone);

    cout << "Введіть мобільний телефон: ";
    getline(cin, mobilePhone);

    cout << "Введіть додаткову інформацію: ";
    getline(cin, info);
}


void Contact::SaveToFile(ofstream& outFile) const
{
    outFile << (fullName ? fullName : "") << endl;
    outFile << homePhone << endl;
    outFile << workPhone << endl;
    outFile << mobilePhone << endl;
    outFile << info << endl;
}


void Contact::LoadFromFile(ifstream& inFile)
{
    string nameStr;
    if (getline(inFile, nameStr))
    {
        setFullName(nameStr.c_str());
        getline(inFile, homePhone);
        getline(inFile, workPhone);
        getline(inFile, mobilePhone);
        getline(inFile, info);
    }
}
