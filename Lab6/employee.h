#include <string>
#include <array>
#include <iostream>
#include <limits>

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
    bool addEmployee() {
    if (employeeCount < SIZE) {
        for (int i = 0; i < SIZE; ++i) {
            if (employees[i].name == "No Name") { // Знаходимо перше вільне місце
                
                // Введення імені
                std::string name;
                do {
                    std::cout << "Enter employee's name: ";
                    getline(std::cin, name);
                    if (name.empty()) {
                        std::cout << "Name cannot be empty. Please try again." << std::endl;
                    }
                } while (name.empty());
                employees[i].name = name;

                // Введення віку
                int age = 0;
                do {
                    std::cout << "Enter employee's age: ";
                    std::cin >> age;
                    if (std::cin.fail() || age < 18 || age > 65) {
                        std::cout << "Invalid age. Please enter a valid age (18-65)." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                } while (true);
                employees[i].age = age;

                // Введення посади
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистити буфер
                std::string position;
                do {
                    std::cout << "Enter employee's position: ";
                    getline(std::cin, position);
                    if (position.empty()) {
                        std::cout << "Position cannot be empty. Please try again." << std::endl;
                    }
                } while (position.empty());
                employees[i].position = position;
                std::cout << "New employee successfully created!" << endl;

                employeeCount++;
                return true;
            }
        }
    }
    std::cout << "Array is full, cannot add more employees." << std::endl;
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

    // Метод для обміну місцями співробітників
    bool swapEmployees(int index1, int index2) {
        if (index1 >= 0 && index1 < SIZE && index2 >= 0 && index2 < SIZE) {
            std::swap(employees[index1], employees[index2]);
            return true;
        }
        std::cout << "Invalid indices. Swap failed." << std::endl;
        return false;
    }

    // Метод для вставки співробітника у конкретну позицію
bool insertEmployee(int position) {
    if (position < 0 || position >= SIZE || employeeCount >= SIZE) {
        std::cout << "Invalid position or array is full. Insert failed." << std::endl;
        return false;
    }
    if (employees[position].name != "No Name") {
        std::cout << "Position already occupied. Insert failed." << std::endl;
        return false;
    }

    // Введення даних нового співробітника
    std::string name;
    do {
        std::cout << "Enter employee's name: ";
        getline(std::cin, name);
        if (name.empty()) {
            std::cout << "Name cannot be empty. Please try again." << std::endl;
        }
    } while (name.empty());

    int age = 0;
    do {
        std::cout << "Enter employee's age: ";
        std::cin >> age;
        if (std::cin.fail() || age <= 0 || age > 120) {
            std::cout << "Invalid age. Please enter a valid age (1-120)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистити буфер
    std::string positionStr;
    do {
        std::cout << "Enter employee's position: ";
        getline(std::cin, positionStr);
        if (positionStr.empty()) {
            std::cout << "Position cannot be empty. Please try again." << std::endl;
        }
    } while (positionStr.empty());

    // Додати співробітника до вказаної позиції
    employees[position] = {age, name, positionStr};
    employeeCount++;
    return true;
}

};
