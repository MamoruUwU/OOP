#pragma once
#include <iostream>

class Employee {
protected:
    std::string name;

public:
    Employee(const std::string& name) : name(name) {}
    virtual double calculateSalary() const = 0;
    virtual void print() const {
        std::cout << "Name: " << name << "\n";
    }
    virtual ~Employee() {}
};

// Службовець із погодинною оплатою
class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee(const std::string& name, double hours, double rate)
        : Employee(name), hoursWorked(hours), hourlyRate(rate) {}

    double calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }

    void print() const override {
        Employee::print();
        std::cout << "Hourly employee, Salary: " << calculateSalary() << "\n";
    }
};

// Службовець у штаті (фіксована зарплата)
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(const std::string& name, double salary)
        : Employee(name), monthlySalary(salary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void print() const override {
        Employee::print();
        std::cout << "Salaried employee, Salary: " << calculateSalary() << "\n";
    }
};

// Службовець із процентною ставкою
class CommissionEmployee : public Employee {
private:
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(const std::string& name, double sales, double rate)
        : Employee(name), salesAmount(sales), commissionRate(rate) {}

    double calculateSalary() const override {
        return salesAmount * commissionRate;
    }

    void print() const override {
        Employee::print();
        std::cout << "Commission employee, Salary: " << calculateSalary() << "\n";
    }
};