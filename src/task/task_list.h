#ifndef TASK_LIST_H
#define TASK_LIST_H
#include "task_node.h"
#include <string>

class TaskList{
    private:
            TaskNode* head;
            int nextId;

    public:
            ~TaskList();;

            void addTask(std::string title, std::string status,
                  std::string startDate,
                  std::string endDate,
                  std::string timeline);

            void displayTasks();

};

#endif