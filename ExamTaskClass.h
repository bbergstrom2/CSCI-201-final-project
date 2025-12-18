// Program: ExamTaskClass.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines the ExamTask class, which is a derived class of Task representing Exam assignments.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef EXAMTASKCLASS_H
#define EXAMTASKCLASS_H

#include "TaskClass.h"

class ExamTask : public Task
{
private:
    std::string courseName;
    std::string examTopic;
    std::string examLocation;

public:
    // Constructor
    ExamTask(const std::string &title,
             const std::string &description,
             const std::string &dueDate,
             int estimatedMinutes,
             TaskPriority priority,
             TaskStatus status,
             const std::string &course,
             const std::string &topic,
             const std::string &location);

    // Destructor
    ~ExamTask() override = default;

    // Override getType
    TaskType getType() const override;

    // Getters
    const std::string &getCourseName() const;
    const std::string &getExamTopic() const;
    const std::string &getExamLocation() const;

    // Print function
    void print(std::ostream &os) const override;
};

#endif