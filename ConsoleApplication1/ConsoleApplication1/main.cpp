#include <iostream>
#include <vector>
#include <limits>
#include "Task.h"
#include "CSVHandler.h"

std::vector<Task> tasks;
int nextId = 1;

// Добавить задачу
void addTask() {
    Task t;
    t.id = nextId++;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Name: ";
    getline(std::cin, t.title);

    std::cout << "Description: ";
    getline(std::cin, t.description);

    t.status = "active";

    tasks.push_back(t);
    std::cout << "Task added!\n";
}

// Показать задачи
void showTasks() {
    if (tasks.empty()) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "\n--- Task List ---\n";
    for (const auto& t : tasks) {
        std::cout << t.id << " | "
            << t.title << " | "
            << t.description << " | "
            << t.status << "\n";
    }
}

// Завершить задачу
void completeTask() {
    int id;
    std::cout << "Task ID: ";
    std::cin >> id;

    for (auto& t : tasks) {
        if (t.id == id) {
            t.status = "done";
            std::cout << "Task is Done!\n";
            return;
        }
    }

    std::cout << "Task not found.\n";
}

// Экспорт
void exportCSV() {
    CSVHandler::exportToCSV("tasks.csv", tasks);
}

// Импорт
void importCSV() {
    tasks = CSVHandler::importFromCSV("tasks.csv");

    // обновляем nextId
    nextId = 1;
    for (const auto& t : tasks) {
        if (t.id >= nextId) {
            nextId = t.id + 1;
        }
    }
}

// Меню
void menu() {
    int choice;

    do {
        std::cout << "\n=== TO-DO MENU ===\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Show Tasks\n";
        std::cout << "3. End Task\n";
        std::cout << "4. Export in CSV\n";
        std::cout << "5. Import from CSV\n";
        std::cout << "0. Exit\n";
        std::cout << "Option: ";

        std::cin >> choice;

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            showTasks();
            break;
        case 3:
            completeTask();
            break;
        case 4:
            exportCSV();
            break;
        case 5:
            importCSV();
            break;
        case 0:
            std::cout << "Logging out...\n";
            break;
        default:
            std::cout << "Wrong option!\n";
        }

    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}