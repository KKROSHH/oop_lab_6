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
    empManager.addEmployee();
    empManager.addEmployee();
    empManager.addEmployee();

    // Виводимо список співробітників
    empManager.printEmployees();
    cout << "\n";

    // Видаляємо співробітника
    empManager.removeEmployee("John Doe");

    // Виводимо список співробітників після видалення
    empManager.printEmployees();

    empManager.swapEmployees(0, 1);
    empManager.printEmployees();
    cout << "\n";

    empManager.insertEmployee(5);
    empManager.printEmployees();
    cout << "\n";



    return 0;
}
