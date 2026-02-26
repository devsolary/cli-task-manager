#include "task_list.h"
#include "task.h"
#include <iostream>
#include <string>
#include <sstream>


TaskList::TaskList()
{
    head = nullptr;
    nextId = 1;
}

TaskList::~TaskList()
{
    TaskNode* temp = head;

    while (temp != nullptr) {
        TaskNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

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

void TaskList::removeTask(int id)
{
    if (head == nullptr) {
        std::cout << "List is empty.\n";
        return;
    }

    // Case 1: removing the head
    if (head->task.getId() == id) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
        std::cout << "Task removed.\n";
        return;
    }

    // Case 2: removing non-head node
    TaskNode* current = head;

    while (current->next != nullptr &&
           current->next->task.getId() != id)
    {
        current = current->next;
    }

    if (current->next == nullptr) {
        std::cout << "Task not found.\n";
        return;
    }

    TaskNode* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;

    std::cout << "Task removed.\n";
}

void TaskList::displayTasks(){
    TaskNode* temp = head;
    std::cout << "Head pointer: " << head << std::endl;

    while (temp != nullptr){
        std::cout << temp-> task.taskInfo() << std::endl;
        temp = temp->next; 
    }
}