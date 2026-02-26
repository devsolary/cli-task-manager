#include "task_list.h"
#include "task.h"
#include <iostream>
#include <string>
#include <sstream>

TaskList::~TaskList()
{
    head = nullptr;
    nextId = 1;
};

void TaskList::addTask(std::string title,
                       std::string status,
                       std::string startDate,
                       std::string endDate,
                       std::string timeline)
{
    Task newTask(nextId++, title, status, startDate, endDate, timeline);
    TaskNode *newNode = new TaskNode(newTask);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    TaskNode *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
};

void TaskList::displayTasks(){
    TaskNode* temp = head;

    while (temp != nullptr){
        std::cout << temp-> task.taskInfo() << std::endl;
        temp = temp->next; 
    }
}