#include <iostream>
#include <string>
#include <limits>

// Базовий клас Car
class Car {
protected:
    std::string brand;
    std::string model;

public:
    // Конструктор базового класу
    Car(const std::string& brand = "", const std::string& model = "")
        : brand(brand), model(model) {}

    // Методи для вводу даних
    void input() {
        std::cout << "Введіть марку автомобіля: ";
        std::cin >> brand;

        std::cout << "Введіть модель автомобіля: ";
        std::cin >> model;
    }

    // Метод для виводу даних
    void display() const {
        std::cout << "Марка: " << brand << ", Модель: " << model;
    }
};

// Дочірній клас CarDetails
class CarDetails : public Car {
private:
    int year;

public:
    // Конструктор дочірнього класу
    CarDetails(const std::string& brand = "", const std::string& model = "", int year = 0)
        : Car(brand, model), year(year) {}

    // Метод для вводу даних
    void input() {
        Car::input(); // Виклик методу вводу базового класу

        while (true) {
            std::cout << "Введіть рік випуску автомобіля: ";
            std::cin >> year;

            // Валідація року
            if (std::cin.fail() || year < 1886 || year > 2024) {
                std::cout << "Некоректний рік. Спробуйте ще раз.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
    }

    // Метод для виводу даних
    void display() const {
        Car::display(); // Виклик методу виводу базового класу
        std::cout << ", Рік випуску: " << year << '\n';
    }
};

int main() {
    // Створення об'єкта дочірнього класу
    CarDetails car;

    std::cout << "Введіть дані про автомобіль:\n";
    car.input(); // Введення даних користувачем

    std::cout << "\nВведені дані автомобіля:\n";
    car.display(); // Вивід даних на екран

    return 0;
}