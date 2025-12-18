// Program: HomeworkTaskClass.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines the HomeworkTask class, which is a derived class of Task representing Homework assignments.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef HOMEWORKTASKCLASS_H
#define HOMEWORKTASKCLASS_H

#include "TaskClass.h"

class HomeworkTask : public Task
{
private:
    std::string courseName;
    std::string assignmentName;
    std::string homeworkDetails;

public:
    // Constructor
    HomeworkTask(const std::string &title,
                 const std::string &description,
                 const std::string &dueDate,
                 int estimatedMinutes,
                 TaskPriority priority,
                 TaskStatus status,
                 const std::string &course,
                 const std::string &assignment,
                 const std::string &details);

    // Destructor
    ~HomeworkTask() override = default;

    // Override getType
    TaskType getType() const override;

    // Getters
    const std::string &getCourseName() const;
    const std::string &getAssignmentName() const;
    const std::string &getHomeworkDetails() const;

    // Print function
    void print(std::ostream &os) const override;
};

#endif