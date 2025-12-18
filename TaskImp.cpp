// Program: TaskImp.cpp
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This source file implements the member functions of the Task class defined in TaskClass.h.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#include "TaskClass.h"
#include <stdexcept>
#include <string>
#include <cctype>
using namespace std;

// Helper function to validate date format YYYY-MM-DD
static bool isValidDate(const string &d)
{
    if (d.size() != 10)
        return false;
    if (d[4] != '-' || d[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(static_cast<unsigned char>(d[i])))
            return false;
    }
    return true;
}

// Helper function to rank priorities for comparison
static int priorityRank(TaskPriority p)
{
    switch (p)
    {
    case TaskPriority::High:
        return 3;
    case TaskPriority::Medium:
        return 2;
    case TaskPriority::Low:
        return 1;
    default:
        return 0;
    }
}

// Constructor
Task::Task(const string &title,
           const string &description,
           const string &dueDate,
           int estimatedMinutes,
           TaskPriority priority,
           TaskStatus status)
    : title(title), description(description), dueDate(dueDate),
      estimatedMinutes(estimatedMinutes), priority(priority), status(status)
{
    // Checks for valid time input
    if (estimatedMinutes <= 0)
    {
        throw invalid_argument("Estimated minutes cannot be less than or equal to zero.");
    }
    // Checks for valid date input
    if (!isValidDate(dueDate))
    {
        throw invalid_argument("Due date must be in YYYY-MM-DD format.");
    }
}

// Getters
const string &Task::getTitle() const
{
    return title;
}
const string &Task::getDescription() const
{
    return description;
}
const string &Task::getDueDate() const
{
    return dueDate;
}
int Task::getEstimatedMinutes() const
{
    return estimatedMinutes;
}
TaskPriority Task::getPriority() const
{
    return priority;
}
TaskStatus Task::getStatus() const
{
    return status;
}

// State updates
void Task::updateStatus(TaskStatus newStatus)
{
    status = newStatus;
}
void Task::updatePriority(TaskPriority newPriority)
{
    priority = newPriority;
}
bool Task::isDone() const
{
    return status == TaskStatus::Done;
}

// Operator overload
bool Task::operator<(const Task &other) const
{
    if (dueDate != other.dueDate)
    {
        return dueDate < other.dueDate;
    }
    else
    {
        return priorityRank(priority) > priorityRank(other.priority);
    }
}

// Print function
void Task::print(ostream &os) const
{
    os << "Title: " << title << "\n"
       << "Description: " << description << "\n"
       << "Due Date: " << dueDate << "\n"
       << "Estimated Minutes: " << estimatedMinutes << "\n"
       << "Priority: " << toString(priority) << "\n"
       << "Status: " << toString(status) << "\n";
}

// Friend function for ostream operator overload
ostream &operator<<(ostream &os, const Task &task)
{
    task.print(os);
    return os;
}
