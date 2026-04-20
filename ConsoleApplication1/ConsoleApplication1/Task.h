#pragma once
#include <string>

struct Task {
    int id;
    std::string title;
    std::string description;
    std::string status; // active / done
};