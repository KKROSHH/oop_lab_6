#include <iostream>
#include <string>
#include <array>
#include "employee.h"

using namespace std;

int main() {
    Employee empManager;

    // Додаємо співробітників
    empManager.addEmployee();
    empManager.addEmployee();

    // Виводимо список співробітників
    empManager.printEmployees();
    cout << "\n";

    // Видаляємо співробітника
    empManager.removeEmployee("John Doe");

    // Виводимо список співробітників після видалення
    empManager.printEmployees();

    return 0;
}
