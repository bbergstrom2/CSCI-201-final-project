// Program: HomeworkTaskImp.cpp
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This source file implements the member functions of the HomeworkTask class defined in HomeworkTaskClass.h.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#include "HomeworkTaskClass.h"
using namespace std;

// Constructor
HomeworkTask::HomeworkTask(const string &title,
                           const string &description,
                           const string &dueDate,
                           int estimatedMinutes,
                           TaskPriority priority,
                           TaskStatus status,
                           const string &course,
                           const string &assignment,
                           const string &details)
    : Task(title, description, dueDate, estimatedMinutes, priority, status),
      courseName(course), assignmentName(assignment), homeworkDetails(details) {}

// Override getType
TaskType HomeworkTask::getType() const
{
    return TaskType::Homework;
}

// Getters
const string &HomeworkTask::getCourseName() const
{
    return courseName;
}

const string &HomeworkTask::getAssignmentName() const
{
    return assignmentName;
}

const string &HomeworkTask::getHomeworkDetails() const
{
    return homeworkDetails;
}

// Print function
void HomeworkTask::print(ostream &os) const
{
    Task::print(os);
    os << "Course: " << courseName << "\n"
       << "Assignment: " << assignmentName << "\n"
       << "Details: " << homeworkDetails << "\n";
}