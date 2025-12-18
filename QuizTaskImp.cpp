// Program: QuizTaskImp.cpp
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This source file implements the member functions of the QuizTask class defined in QuizTaskClass.h.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#include "QuizTaskClass.h"
using namespace std;

// Constructor
QuizTask::QuizTask(const string &title,
                   const string &description,
                   const string &dueDate,
                   int estimatedMinutes,
                   TaskPriority priority,
                   TaskStatus status,
                   const string &course,
                   const string &topic)
    : Task(title, description, dueDate, estimatedMinutes, priority, status),
      courseName(course), quizTopic(topic) {}

// Override getType
TaskType QuizTask::getType() const
{
    return TaskType::Quiz;
}

// Getters
const string &QuizTask::getCourseName() const
{
    return courseName;
}

const string &QuizTask::getQuizTopic() const
{
    return quizTopic;
}

// Print function
void QuizTask::print(ostream &os) const
{
    Task::print(os);
    os << "Course: " << courseName << "\n"
       << "Topic: " << quizTopic << "\n";
}