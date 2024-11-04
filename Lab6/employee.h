#include <string>
#include <array>
#include <iostream>

using namespace std;

const int SIZE = 100;

struct employee_s_t {
    int age;
    std::string name;
    std::string position;
};

class Employee {
    private:
    std::array<employee_s_t, SIZE> employees; // Масив співробітників
     int employeeCount = 0; // Лічильник кількості співробітників

    public:
    // Конструктор за замовчуванням
    Employee() {
        // Ініціалізація за замовчуванням
        for (int i = 0; i < SIZE; ++i) {
            employees[i] = {0, "No Name", "No Position"};
        }
    }

    

    // Конструктор, який приймає масив співробітників
    Employee(const std::array<employee_s_t, SIZE>& empArray) {
        for (int i = 0; i < SIZE; ++i) {
            employees[i] = empArray[i]; // Копіюємо значення з переданого масиву
        }
    }

     // Метод для додавання співробітника
    bool addEmployee(int age, const std::string& name, const std::string& position) {
        if (employeeCount < SIZE) {
            for (int i = 0; i < SIZE; ++i) {
                if (employees[i].name == "No Name") { // Знаходимо перше вільне місце
                    employees[i] = {age, name, position};
                    employeeCount++;
                    return true;
                }
            }
        }
        cout << "Array is full, cannot add more employees." << endl;
        return false; // Якщо масив заповнений
    }


     // Метод для видалення співробітника за іменем
    bool removeEmployee(const std::string& name) {
        for (int i = 0; i < SIZE; ++i) {
            if (employees[i].name == name) { // Якщо знайдений співробітник
                employees[i] = {0, "No Name", "No Position"}; // Очищуємо запис
                employeeCount--;
                return true;
            }
        }
        cout << "Employee not found." << endl;
        return false; // Якщо співробітника не знайдено
    }

    // Метод для виведення інформації про співробітників
    void printEmployees() const {
        for (int i = 0; i < SIZE; ++i) {
            if (employees[i].name != "No Name") {
                cout << "Employee " << i + 1 << ": " << employees[i].name 
                     << ", Age: " << employees[i].age 
                     << ", Position: " << employees[i].position << endl;
            }
        }
    }
};
