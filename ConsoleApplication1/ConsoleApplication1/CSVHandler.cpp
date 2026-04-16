#include "CSVHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

void CSVHandler::exportToCSV(const std::string& filename, const std::vector<Task>& tasks) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error opening file\n";
        return;
    }

    file << "id,title,description,status\n";

    for (const auto& task : tasks) {
        file << task.id << ","
            << task.title << ","
            << task.description << ","
            << task.status << "\n";
    }

    file.close();
    std::cout << "Export is Done!\n";
}

std::vector<Task> CSVHandler::importFromCSV(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error opening file\n";
        return tasks;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        Task task;

        getline(ss, item, ',');
        task.id = std::stoi(item);

        getline(ss, task.title, ',');
        getline(ss, task.description, ',');
        getline(ss, task.status, ',');

        tasks.push_back(task);
    }

    file.close();
    std::cout << "Import is Done!\n";
    return tasks;
}