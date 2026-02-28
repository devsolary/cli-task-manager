#include "task_list.h"
#include "task.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using json = nlohmann::json;


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

void TaskList::saveToJson(const std::string& filename)
{
    json j = json::array();

    TaskNode* current = head;

    while (current != nullptr)
    {
        json taskJson;
        taskJson["id"] = current->task.getId();
        taskJson["title"] = current->task.getTitle();
        taskJson["status"] = current->task.getStatus();
        taskJson["startDate"] = current->task.getStartDate();
        taskJson["endDate"] = current->task.getEndDate();
        taskJson["duration"] = current->task.getTimeline();

        j.push_back(taskJson);

        current = current->next;
    }

    std::ofstream file(filename);
    file << j.dump(4); // 4 = pretty print
}
void TaskList::loadFromJson(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return;

    json j;
    file >> j;

    for (auto& taskJson : j)
    {
        addTask(
            taskJson["title"],
            taskJson["status"],
            taskJson["startDate"],
            taskJson["endDate"],
            taskJson["duration"]
        );
    }
}