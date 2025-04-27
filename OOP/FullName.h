#pragma once
#include <iostream>
#include <map>
#include <string>

enum class CodeError {
    OK,
    NOT_FOUND
};

class FullName {
public:
    std::string lastName;
    std::string firstName;
    std::string middleName;

    FullName() = default;
    FullName(const std::string& last, const std::string& first, const std::string& middle)
        : lastName(last), firstName(first), middleName(middle) {}

    friend std::ostream& operator<<(std::ostream& os, const FullName& name) {
        os << name.lastName << " " << name.firstName << " " << name.middleName;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, FullName& name) {
        is >> name.lastName >> name.firstName >> name.middleName;
        return is;
    }
};

class StudentGroup {
private:
    std::map<int, FullName> data;
    CodeError error = CodeError::OK;

public:
    void add(int index, const FullName& name) {
        data[index] = name;
    }

    FullName operator[](int index) {
        if (data.count(index)) {
            error = CodeError::OK;
            std::cout << data[index] << std::endl;
            return data[index];
        }
        else {
            error = CodeError::NOT_FOUND;
            return FullName();
        }
    }

    FullName operator()(int index) {
        return (*this)[index];
    }

    CodeError getError() const {
        return error;
    }

    friend std::ostream& operator<<(std::ostream& os, const StudentGroup& group) {
        for (const auto& pair : group.data) {
            os << pair.first << ": " << pair.second << std::endl;
        }
        return os;
    }


    friend std::istream& operator>>(std::istream& is, StudentGroup& group) {
        int count;
        std::cout << "Enter number of students: ";
        is >> count;
        int index = 0;
        for (int i = 0; i < count; i++) {
            FullName name;
            std::cout << "Enter student index and full name (Last First Middle): ";
            is >> name;
            group.add(index++, name);
        }
        return is;
    }
    void print() const {
		for (const auto& pair : data) {
			std::cout << pair.first << ": " << pair.second << std::endl;
		}
	}
};
