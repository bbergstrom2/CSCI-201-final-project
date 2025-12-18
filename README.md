Flow State – Console-Based Study Task Planner
Author: Brooke Bergstrom
Course: CSCI 201
Date: December 2025

------------------------------------------------------------
DESCRIPTION
------------------------------------------------------------
Flow State is a C++ console-based study planner that allows
users to create and manage different types of academic tasks,
including readings, homework, projects, quizzes, and exams.
Each task stores a due date, estimated completion time,
priority level, and completion status.

------------------------------------------------------------
FILES INCLUDED
------------------------------------------------------------
- Main.cpp
- PlannerClass.h / PlannerImp.cpp
- TaskClass.h / TaskImp.cpp
- ReadingTaskClass.h / ReadingTaskImp.cpp
- HomeworkTaskClass.h / HomeworkTaskImp.cpp
- ProjectTaskClass.h / ProjectTaskImp.cpp
- QuizTaskClass.h / QuizTaskImp.cpp
- ExamTaskClass.h / ExamTaskImp.cpp
- Enums.h

------------------------------------------------------------
BUILD / COMPILE INSTRUCTIONS
------------------------------------------------------------
This program was developed and tested using:
- VS Code
- MinGW (g++)

To compile from the command line:

g++ -std=c++17 -Wall -Wextra -o FlowState main.cpp \
PlannerImp.cpp TaskImp.cpp \
ReadingTaskImp.cpp HomeworkTaskImp.cpp \
ProjectTaskImp.cpp QuizTaskImp.cpp ExamTaskImp.cpp

------------------------------------------------------------
HOW TO RUN
------------------------------------------------------------
After compiling:

./FlowState

Or run using the VS Code Run button.

------------------------------------------------------------
PROGRAM USAGE
------------------------------------------------------------
1. Select an option from the main menu.
2. Add tasks by choosing a task type and entering prompted data.
3. View tasks using the List Tasks option.
4. Update task status using Update Task.
5. Save a snapshot of tasks to a file using Save Tasks.
6. Load and view a saved snapshot using Load Tasks.
7. View a summary of tasks using View Summary.

------------------------------------------------------------
NOTES
------------------------------------------------------------
- Load displays a saved snapshot and does not overwrite
  the current task list.
- Task titles and descriptions are generated automatically.
- Invalid input is handled through validation and exceptions.

------------------------------------------------------------
ACKNOWLEDGEMENTS
------------------------------------------------------------
ChatGPT was used as a learning tool to ask questions, review
code, and receive suggestions. All code was written by the
author unless otherwise stated in comments.
