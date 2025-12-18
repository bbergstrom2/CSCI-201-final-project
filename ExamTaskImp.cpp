// Program: ExamTaskImp.cpp
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This source file implements the member functions of the ExamTask class defined in ExamTaskClass.h.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#include "ExamTaskClass.h"
using namespace std;

// Constructor
ExamTask::ExamTask(const string &title,
                   const string &description,
                   const string &dueDate,
                   int estimatedMinutes,
                   TaskPriority priority,
                   TaskStatus status,
                   const string &course,
                   const string &topic,
                   const string &location)
    : Task(title, description, dueDate, estimatedMinutes, priority, status),
      courseName(course), examTopic(topic), examLocation(location) {}

// Override getType
TaskType ExamTask::getType() const
{
    return TaskType::Exam;
}

// Getters
const string &ExamTask::getCourseName() const
{
    return courseName;
}

const string &ExamTask::getExamTopic() const
{
    return examTopic;
}

const string &ExamTask::getExamLocation() const
{
    return examLocation;
}

// Print function
void ExamTask::print(ostream &os) const
{
    Task::print(os);
    os << "Course: " << courseName << "\n"
       << "Topic: " << examTopic << "\n"
       << "Location: " << examLocation << "\n";
}