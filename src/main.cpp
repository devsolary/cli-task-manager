#include <iostream>
#include "task/task.h"
using namespace std;

int main()
{
    std::cout << "Program is running\n";
    Task task;
    task.setTask("Coding", "Pending", "2026-01-01", "2026-01-05", "5 days");
    cout << task.taskInfo();
}