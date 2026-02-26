#include <iostream>
#include <iostream>
#include "task/task_list.h"
using namespace std;

int main()
{
    cout << "Program is running\n";
    TaskList list;   // create linked list manager

    list.addTask("Coding", "Pending",
                 "2026-01-01", "2026-01-05", "5 days");

    list.addTask("Testing", "In Progress",
                 "2026-01-06", "2026-01-08", "3 days");

    list.addTask("Deploy", "Pending",
                 "2026-01-09", "2026-01-10", "2 days");

    list.displayTasks();   // print all tasks

    return 0;
}