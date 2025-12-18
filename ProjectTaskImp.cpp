// Program: ProjectTaskImp.cpp
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This source file implements the member functions of the ProjectTask class defined in ProjectTaskClass.h.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#include "ProjectTaskClass.h"
using namespace std;

// Constructor
ProjectTask::ProjectTask(const string &title,
                   const string &description,
                   const string &dueDate,
                   int estimatedMinutes,
                   TaskPriority priority,
                   TaskStatus status,
                   const string &course,
                   const string &details)
    : Task(title, description, dueDate, estimatedMinutes, priority, status),
      courseName(course), projectDetails(details) {}

// Override getType
TaskType ProjectTask::getType() const
{
    return TaskType::Project;
}

// Getters
const string &ProjectTask::getCourseName() const
{
    return courseName;
}

const string &ProjectTask::getProjectDetails() const
{
    return projectDetails;
}

// Print function
void ProjectTask::print(ostream &os) const
{
    Task::print(os);
    os << "Course: " << courseName << "\n"
       << "Details: " << projectDetails << "\n";
}