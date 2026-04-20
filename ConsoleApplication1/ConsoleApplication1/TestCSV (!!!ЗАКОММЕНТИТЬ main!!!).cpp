#include <iostream>
#include <vector>
#include "Task.h"
#include "CSVHandler.h"

void testExportImport() {
    std::vector<Task> original = {
        {1, "Test1", "Desc1", "active"},
        {2, "Test2", "Desc2", "done"}
    };

    // Экспорт
    CSVHandler::exportToCSV("test.csv", original);

    // Импорт
    std::vector<Task> loaded = CSVHandler::importFromCSV("test.csv");

    // Проверка
    if (loaded.size() != original.size()) {
        std::cout << "Error: Size does not match\n";
        return;
    }

    for (size_t i = 0; i < original.size(); i++) {
        if (loaded[i].title != original[i].title) {
            std::cout << "Error: Data does not match\n";
            return;
        }
    }

    std::cout << "The test was successfull!\n";
}

int main() {
    testExportImport();
    return 0;
}