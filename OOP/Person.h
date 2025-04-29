#pragma once
#include <iostream>
#include <string>

class Person
{
protected:
    std::string name;
    int age;

public:
    Person(std::string name = "", int age = 0)
        : name(name), age(age) {}

    Person(const Person& other)
    {
        name = other.name;
        age = other.age;
    }

    Person& operator=(const Person& other)
    {
        if (this != &other)
        {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& p)
    {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Person& p)
    {
        std::cout << "Enter name: ";
        std::getline(is, p.name);
        std::cout << "Enter age: ";
        is >> p.age;
        is.ignore();
        return is;
    }

    virtual ~Person() {}
};

class Teacher : public Person
{
private:
    std::string subject;

public:
    Teacher(std::string name = "", int age = 0, std::string subject = "")
        : Person(name, age), subject(subject) {}

    Teacher(const Teacher& other)
        : Person(other)
    {
        subject = other.subject;
    }

    Teacher& operator=(const Teacher& other)
    {
        if (this != &other)
        {
            Person::operator=(other);
            subject = other.subject;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Teacher& t)
    {
        os << static_cast<const Person&>(t) << ", Subject: " << t.subject;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Teacher& t)
    {
        is >> static_cast<Person&>(t);
        std::cout << "Enter subject: ";
        std::getline(is, t.subject);
        return is;
    }

    ~Teacher() {}
};