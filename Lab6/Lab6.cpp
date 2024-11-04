#include <iostream>
#include <string>
#include <array>
#include "employee.h"

using namespace std;

int main() {
    Employee empManager;

    // Додаємо співробітників
    empManager.addEmployee(30, "John Doe", "Manager");
    empManager.addEmployee(25, "Jane Smith", "Developer");

    // Виводимо список співробітників
    empManager.printEmployees();
    cout << "\n";

    // Видаляємо співробітника
    empManager.removeEmployee("John Doe");

    // Виводимо список співробітників після видалення
    empManager.printEmployees();

    return 0;
}
