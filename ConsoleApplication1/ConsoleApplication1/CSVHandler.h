#pragma once
#include <vector>
#include <string>
#include "Task.h"

class CSVHandler {
public:
    static void exportToCSV(const std::string& filename, const std::vector<Task>& tasks);
    static std::vector<Task> importFromCSV(const std::string& filename);
};