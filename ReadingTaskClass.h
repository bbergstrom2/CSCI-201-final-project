// Program: ReadingTaskClass.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines the ReadingTask class, which is a derived class of Task representing reading assignments.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef READINGTASKCLASS_H
#define READINGTASKCLASS_H

#include "TaskClass.h"

class ReadingTask : public Task
{
private:
    std::string readingSource;
    int readingStartPage;
    int readingEndPage;

public:
    // Constructor
    ReadingTask(const std::string &title,
                const std::string &description,
                const std::string &dueDate,
                int estimatedMinutes,
                TaskPriority priority,
                TaskStatus status,
                const std::string &source,
                int startPage,
                int endPage);

    // Destructor
    ~ReadingTask() override = default;

    // Override getType
    TaskType getType() const override;

    // Getters
    const std::string &getReadingSource() const;
    int getReadingStartPage() const;
    int getReadingEndPage() const;

    // Print function
    void print(std::ostream &os) const override;
};

#endif
