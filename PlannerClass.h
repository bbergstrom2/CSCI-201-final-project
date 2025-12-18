// Program: PlannerClass.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines the Planner class, which controls a collection of tasks and provides functionality to add, list, update, save, and load tasks.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef PLANNERCLASS_H
#define PLANNERCLASS_H

#include "TaskClass.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

class Planner
{
private:
    // Containers
    std::vector<std::unique_ptr<Task>> tasks;
    std::map<TaskType, int> typeCounts;

    // Menu functions
    void mainMenu();
    void addTaskMenu();
    void listTasksMenu() const;
    void updateTaskMenu();
    void saveMenu() const;
    void loadMenu();
    void summaryMenu() const;

    // Helper functions
    void addTask(std::unique_ptr<Task> t);
    void sortTasks();
    int promptInt(const std::string& prompt, int minValue, int maxValue) const;
    std::string promptNonEmptyLine(const std::string &prompt) const;
    TaskPriority promptPriority() const;
    TaskType promptTaskType() const;
    bool tasksEmpty() const;
    void pause() const;

    // File operations
    bool saveToFile(const std::string &filename) const;
    bool loadFromFile(const std::string &filename);

public:
    // Main loop
    void run();
};

#endif
