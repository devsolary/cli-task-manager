#ifndef TASK_NODE_H
#define TASK_NODE_H
#include "task.h"

class TaskNode {
    public:
            Task task;
            TaskNode* next;

            TaskNode(Task t);
};
#endif