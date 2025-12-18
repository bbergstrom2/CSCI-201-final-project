// Program: QuizTaskClass.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines the QuizTask class, which is a derived class of Task representing Quiz assignments.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef QUIZTASKCLASS_H
#define QUIZTASKCLASS_H

#include "TaskClass.h"

class QuizTask : public Task
{
private:
    std::string courseName;
    std::string quizTopic;

public:
    // Constructor
    QuizTask(const std::string &title,
             const std::string &description,
             const std::string &dueDate,
             int estimatedMinutes,
             TaskPriority priority,
             TaskStatus status,
             const std::string &course,
             const std::string &topic);

    // Destructor
    ~QuizTask() override = default;

    // Override getType
    TaskType getType() const override;

    // Getters
    const std::string &getCourseName() const;
    const std::string &getQuizTopic() const;

    // Print function
    void print(std::ostream &os) const override;
};

#endif