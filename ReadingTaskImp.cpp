// Program: ReadingTaskImp.cpp
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This source file implements the member functions of the ReadingTask class defined in ReadingTaskClass.h.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#include "ReadingTaskClass.h"
#include <stdexcept>
using namespace std;

// Constructor
ReadingTask::ReadingTask(const string &title,
                         const string &description,
                         const string &dueDate,
                         int estimatedMinutes,
                         TaskPriority priority,
                         TaskStatus status,
                         const string &source,
                         int startPage,
                         int endPage)
    : Task(title, description, dueDate, estimatedMinutes, priority, status),
      readingSource(source), readingStartPage(startPage), readingEndPage(endPage)
{
    // Checks for valid page range
    if (readingStartPage <= 0 || readingEndPage <= 0 || readingEndPage < readingStartPage)
    {
        throw invalid_argument("Invalid reading page range.");
    }
}

// Override getType
TaskType ReadingTask::getType() const
{
    return TaskType::Reading;
}

// Getters
const string &ReadingTask::getReadingSource() const
{
    return readingSource;
}

int ReadingTask::getReadingStartPage() const
{
    return readingStartPage;
}

int ReadingTask::getReadingEndPage() const
{
    return readingEndPage;
}

// Print function
void ReadingTask::print(ostream &os) const
{
    Task::print(os);
    os << "Source: " << readingSource << "\n"
       << "Pages: " << readingStartPage << " to " << readingEndPage << "\n";
}