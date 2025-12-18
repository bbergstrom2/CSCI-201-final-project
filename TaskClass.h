// Program: TaskClass.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines the Task class, which serves as an abstract base class for different types of tasks in the project.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef TASKCLASS_H
#define TASKCLASS_H

#include <string>
#include <iostream>
#include "Enums.h"

class Task
{
protected:
    std::string title;
    std::string description;
    std::string dueDate;  // Format: YYYY-MM-DD
    int estimatedMinutes; // in minutes
    TaskPriority priority;
    TaskStatus status;

public:
    // Constructor
    Task(const std::string &title,
         const std::string &description,
         const std::string &dueDate,
         int estimatedMinutes,
         TaskPriority priority,
         TaskStatus status);

    // Destructor
    virtual ~Task() = default;

    // Getters
    const std::string &getTitle() const;
    const std::string &getDescription() const;
    const std::string &getDueDate() const;
    int getEstimatedMinutes() const;
    virtual TaskType getType() const = 0;
    TaskPriority getPriority() const;
    TaskStatus getStatus() const;

    // State updates
    void updateStatus(TaskStatus newStatus);
    void updatePriority(TaskPriority newPriority);
    bool isDone() const;

    // Operator overload
    bool operator<(const Task &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Task &task);

    // Print function
    virtual void print(std::ostream &os) const;
};

#endif