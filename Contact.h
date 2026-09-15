#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Клас що описує абонента телефонної книги
class Contact
{
private:
    char* fullName;       
    string homePhone;     
    string workPhone;    
    string mobilePhone;   
    string info;          

public:
     
    Contact();

    
    Contact(const char* name, const string& home, const string& work, const string& mobile, const string& extraInfo);

    
    Contact(const Contact& other);

    
    Contact& operator=(const Contact& other);

   
    ~Contact();

    
    void setFullName(const char* name);

   
    inline const char* getFullName() const
    {
        return (fullName != nullptr) ? fullName : "";
    }

    inline void setHomePhone(const string& home)
    {
        homePhone = home;
    }

    inline string getHomePhone() const
    {
        return homePhone;
    }

    inline void setWorkPhone(const string& work)
    {
        workPhone = work;
    }

    inline string getWorkPhone() const
    {
        return workPhone;
    }

    inline void setMobilePhone(const string& mobile)
    {
        mobilePhone = mobile;
    }

    inline string getMobilePhone() const
    {
        return mobilePhone;
    }

    inline void setInfo(const string& extraInfo)
    {
        info = extraInfo;
    }

    inline string getInfo() const
    {
        return info;
    }

    
    void Print() const;
    void Input();

    
    void SaveToFile(ofstream& outFile) const;
    void LoadFromFile(ifstream& inFile);
};

#endif 
