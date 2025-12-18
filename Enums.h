// Program: Enums.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines various enumerations used throughout the project.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef ENUMS_H
#define ENUMS_H

#include <string>

// Enumeration for task types
enum class TaskType
{
    Reading,
    Homework,
    Project,
    Quiz,
    Exam
};

enum class TaskPriority
{
    Low,
    Medium,
    High
};

enum class TaskStatus
{
    ToDo,
    InProgress,
    Done
};

// Function to convert TaskType enum to string
inline std::string toString(TaskType type)
{
    switch (type)
    {
    case TaskType::Reading:
        return "Reading";
    case TaskType::Homework:
        return "Homework";
    case TaskType::Project:
        return "Project";
    case TaskType::Quiz:
        return "Quiz";
    case TaskType::Exam:
        return "Exam";
    default:
        return "Unknown";
    }
}

// Function to convert TaskPriority enum to string
inline std::string toString(TaskPriority priority)
{
    switch (priority)
    {
    case TaskPriority::Low:
        return "Low";
    case TaskPriority::Medium:
        return "Medium";
    case TaskPriority::High:
        return "High";
    default:
        return "Unknown";
    }
}

// Function to convert TaskStatus enum to string
inline std::string toString(TaskStatus status)
{
    switch (status)
    {
    case TaskStatus::ToDo:
        return "To Do";
    case TaskStatus::InProgress:
        return "In Progress";
    case TaskStatus::Done:
        return "Done";
    default:
        return "Unknown";
    }
}
#endif