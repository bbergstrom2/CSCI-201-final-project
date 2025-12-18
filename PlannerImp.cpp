// Program: PlannerImp.cpp
// Author: Brooke Bergstrom
// Date (last updated): 12/17/2025
// Description: This source file implements the member functions of the Planner class defined in PlannerClass.h.
// Note: I used ChatGPT as a learning tool to ask questions, review my code, and receive suggestions for improvements. I wrote all code myself unless explicitly stated otherwise in a comment above the relevant section.

#include "PlannerClass.h"
#include "ReadingTaskClass.h"
#include "HomeworkTaskClass.h"
#include "ProjectTaskClass.h"
#include "QuizTaskClass.h"
#include "ExamTaskClass.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <stdexcept>
using namespace std;

void Planner::run()
{
    bool running = true;
    while (running)
    {
        mainMenu();
        int choice = promptInt("Select an option (1-6, 0 to exit): ", 0, 6);
        switch (choice)
        {
        case 1:
            addTaskMenu();
            break;
        case 2:
            listTasksMenu();
            break;
        case 3:
            updateTaskMenu();
            break;
        case 4:
            saveMenu();
            break;
        case 5:
            loadMenu();
            break;
        case 6:
            summaryMenu();
            break;
        case 0:
            running = false;
            cout << "Exiting the planner. Thanks for using Flow State! Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }
    // Pause before program ends so that output can be read before the window closes
    // Written with the help of ChatGPT
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Helper functions
void Planner::addTask(std::unique_ptr<Task> t)
{
    if (!t)
        return;

    typeCounts[t->getType()]++;
    tasks.push_back(std::move(t));
    sortTasks();
}

void Planner::sortTasks()
{
    std::sort(tasks.begin(), tasks.end(),
              [](const std::unique_ptr<Task> &a, const std::unique_ptr<Task> &b)
              {
                  return *a < *b;
              });
}

int Planner::promptInt(const std::string &prompt, int minValue, int maxValue) const
{
    int value;

    while (true)
    {
        std::cout << prompt;
        if (!(std::cin >> value))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid number.\n";
        }
        else if (value < minValue || value > maxValue)
        {
            std::cout << "Please enter a number between "
                      << minValue << " and " << maxValue << ".\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

string Planner::promptNonEmptyLine(const std::string &prompt) const
{
    while (true)
    {
        cout << prompt;
        string line;
        getline(cin, line);
        bool allSpace = true;
        for (char c : line)
        {
            if (!isspace(static_cast<unsigned char>(c)))
            {
                allSpace = false;
                break;
            }
        }

        if (!line.empty() && !allSpace)
            return line;

        cout << "Input cannot be empty. Please try again.\n";
    }
}

TaskPriority Planner::promptPriority() const
{
    cout << "\nSelect priority:\n"
         << "1. Low\n"
         << "2. Medium\n"
         << "3. High\n";

    int choice = promptInt("Choice: ", 1, 3);

    switch (choice)
    {
    case 1:
        return TaskPriority::Low;
    case 2:
        return TaskPriority::Medium;
    case 3:
        return TaskPriority::High;
    default:
        return TaskPriority::Low;
    }
}

TaskType Planner::promptTaskType() const
{
    cout << "\nSelect task type:\n"
         << "1. Reading\n"
         << "2. Homework\n"
         << "3. Project\n"
         << "4. Quiz\n"
         << "5. Exam\n";

    int choice = promptInt("Choice: ", 1, 5);

    switch (choice)
    {
    case 1:
        return TaskType::Reading;
    case 2:
        return TaskType::Homework;
    case 3:
        return TaskType::Project;
    case 4:
        return TaskType::Quiz;
    case 5:
        return TaskType::Exam;
    default:
        return TaskType::Reading;
    }
}

bool Planner::tasksEmpty() const { return tasks.empty(); }

void Planner::pause() const
{
    cout << "\nPress Enter to return to the main menu...";
    cin.get();
}

// Menu functions
void Planner::mainMenu()
{
    cout << "\n--- Flow State Study Planner ---\n"
         << "1. Add Task\n"
         << "2. List Tasks\n"
         << "3. Update Task\n"
         << "4. Save Tasks to File\n"
         << "5. Load Tasks from File\n"
         << "6. View Summary\n"
         << "0. Exit\n";
}

void Planner::addTaskMenu()
{
    cout << "\n--- Add Task ---\n";

    TaskType type = promptTaskType();

    // Common fields for all tasks
    string dueDate = promptNonEmptyLine("Due date (YYYY-MM-DD): ");
    int minutes = promptInt("Estimated minutes to complete: ", 1, 10000);
    TaskPriority priority = promptPriority();
    TaskStatus status = TaskStatus::ToDo;

    try
    {
        std::unique_ptr<Task> task;

        switch (type)
        {
        case TaskType::Reading:
        {
            string source = promptNonEmptyLine("Source (book/article/etc.): ");
            int startPage = promptInt("Start page: ", 1, 10000);
            int endPage = promptInt("End page: ", startPage, 10000);

            string title = "Reading: " + source;
            string description = "Read pages " + std::to_string(startPage) +
                                 " to " + std::to_string(endPage) +
                                 " from " + source + ".";

            task = make_unique<ReadingTask>(
                title, description, dueDate,
                minutes, priority, status,
                source, startPage, endPage);
            break;
        }

        case TaskType::Homework:
        {
            string course = promptNonEmptyLine("Course: ");
            string assignment = promptNonEmptyLine("Assignment name: ");
            string details = promptNonEmptyLine("Details: ");

            string title = "Homework: " + assignment;
            string description = course + ": " + details;

            task = make_unique<HomeworkTask>(
                title, description, dueDate,
                minutes, priority, status,
                course, assignment, details);
            break;
        }

        case TaskType::Project:
        {
            string course = promptNonEmptyLine("Course: ");
            string details = promptNonEmptyLine("Project details: ");

            string title = "Project: " + course;
            string description = details;

            task = make_unique<ProjectTask>(
                title, description, dueDate,
                minutes, priority, status,
                course, details);
            break;
        }

        case TaskType::Quiz:
        {
            string course = promptNonEmptyLine("Course: ");
            string topic = promptNonEmptyLine("Quiz topic: ");

            string title = "Quiz: " + course;
            string description = "Topic: " + topic;

            task = make_unique<QuizTask>(
                title, description, dueDate,
                minutes, priority, status,
                course, topic);
            break;
        }

        case TaskType::Exam:
        {
            string course = promptNonEmptyLine("Course: ");
            string topic = promptNonEmptyLine("Exam topic: ");
            string location = promptNonEmptyLine("Location: ");

            string title = "Exam: " + course;
            string description = "Topic: " + topic + " (Location: " + location + ")";

            task = make_unique<ExamTask>(
                title, description, dueDate,
                minutes, priority, status,
                course, topic, location);
            break;
        }
        }

        addTask(std::move(task));
        cout << "Task added successfully!\n";
        pause();
    }
    catch (const invalid_argument &e)
    {
        cout << "Error adding task: " << e.what() << "\n";
        cout << "Task addition failed.\n";
        pause();
    }
}

void Planner::listTasksMenu() const
{
    if (tasksEmpty())
    {
        cout << "No tasks available to list.\n";
        pause();
        return;
    }

    cout << "\n--- List Tasks ---\n";

    int i = 1;
    for (const auto &task : tasks)
    {
        cout << "\n[" << i++ << "]\n";
        cout << *task << "\n";
    }
    pause();
}

void Planner::updateTaskMenu()
{
    if (tasksEmpty())
    {
        cout << "No tasks available to update.\n";
        pause();
        return;
    }

    cout << "\n--- Update Task ---\n";

    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << "\n[" << (i + 1) << "] " << tasks[i]->getTitle()
             << " (Due: " << tasks[i]->getDueDate()
             << ", Status: " << toString(tasks[i]->getStatus()) << ")\n";
    }

    int taskNum = promptInt("Enter the task number to update (0 to cancel): ", 0, static_cast<int>(tasks.size()));
    if (taskNum == 0)
    {
        pause();
        return;
    }

    cout << "\nSet new status:\n"
         << "1. To Do\n"
         << "2. In Progress\n"
         << "3. Done\n";

    int statusChoice = promptInt("Choice: ", 1, 3);

    TaskStatus newStatus = TaskStatus::ToDo;
    if (statusChoice == 2)
        newStatus = TaskStatus::InProgress;
    else if (statusChoice == 3)
        newStatus = TaskStatus::Done;

    tasks[taskNum - 1]->updateStatus(newStatus);

    cout << "Task updated!\n";
    pause();
}

void Planner::saveMenu() const
{
    if (tasksEmpty())
    {
        cout << "No tasks to save.\n";
        pause();
        return;
    }

    string filename = promptNonEmptyLine("Enter filename to save to: ");
    if (saveToFile(filename))
        cout << "Saved tasks to \"" << filename << "\".\n";
    else
        cout << "Save failed.\n";

    pause();
}

void Planner::loadMenu()
{
    string filename = promptNonEmptyLine("Enter filename to load from: ");
    if (loadFromFile(filename))
    {
        cout << "Loaded tasks from \"" << filename << "\".\n";
        cout << "(Note: Load displays a saved snapshot; it does not overwrite current tasks.)\n";
    }
    else
        cout << "Load failed.\n";

    pause();
}

void Planner::summaryMenu() const
{
    cout << "\n--- Summary ---\n";

    if (tasksEmpty())
    {
        cout << "No tasks available.\n";
        pause();
        return;
    }

    cout << "Total tasks: " << tasks.size() << "\n\n";

    cout << "Tasks by type:\n";
    cout << "  Reading : " << (typeCounts.count(TaskType::Reading) ? typeCounts.at(TaskType::Reading) : 0) << "\n";
    cout << "  Homework: " << (typeCounts.count(TaskType::Homework) ? typeCounts.at(TaskType::Homework) : 0) << "\n";
    cout << "  Project : " << (typeCounts.count(TaskType::Project) ? typeCounts.at(TaskType::Project) : 0) << "\n";
    cout << "  Quiz    : " << (typeCounts.count(TaskType::Quiz) ? typeCounts.at(TaskType::Quiz) : 0) << "\n";
    cout << "  Exam    : " << (typeCounts.count(TaskType::Exam) ? typeCounts.at(TaskType::Exam) : 0) << "\n";

    pause();
}

// File operations
bool Planner::saveToFile(const std::string &filename) const
{
    std::ofstream out(filename);
    if (!out)
        return false;

    out << "Flow State - Saved Tasks\n";
    out << "========================\n\n";

    if (tasks.empty())
    {
        out << "No tasks.\n";
        return true;
    }

    for (size_t i = 0; i < tasks.size(); ++i)
    {
        out << "[" << (i + 1) << "] " << toString(tasks[i]->getType()) << "\n";
        out << *tasks[i] << "\n";
    }

    return true;
}

bool Planner::loadFromFile(const std::string &filename)
{
    std::ifstream in(filename);
    if (!in)
        return false;

    cout << "\n--- Loaded File: " << filename << " ---\n\n";

    std::string line;
    while (std::getline(in, line))
        cout << line << "\n";

    return true;
}
