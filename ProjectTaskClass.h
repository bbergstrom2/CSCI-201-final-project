// Program: ProjectTaskClass.h
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This header file defines the ProjectTask class, which is a derived class of Task representing Project assignments.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#ifndef PROJECTTASKCLASS_H
#define PROJECTTASKCLASS_H

#include "TaskClass.h"

class ProjectTask : public Task
{
private:
    std::string courseName;
    std::string projectDetails;

public:
    // Constructor
    ProjectTask(const std::string &title,
                const std::string &description,
                const std::string &dueDate,
                int estimatedMinutes,
                TaskPriority priority,
                TaskStatus status,
                const std::string &course,
                const std::string &details);

    // Destructor
    ~ProjectTask() override = default;

    // Override getType
    TaskType getType() const override;

    // Getters
    const std::string &getCourseName() const;
    const std::string &getProjectDetails() const;

    // Print function
    void print(std::ostream &os) const override;
};

#endif