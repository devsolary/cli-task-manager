#include <iostream>
#include "task/task_list.h"

using namespace std;

int main()
{
    TaskList list;
    list.loadFromJson("tasks.json");
    int choice;

    while (true)
    {
        cout << "\n==== TASK MANAGER ====\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1)
        {
            string title, status, startDate, endDate, duration;

            cin.ignore(); // clear newline from buffer

            cout << "Enter title: ";
            getline(cin, title);

            cout << "Enter status: ";
            getline(cin, status);

            cout << "Enter start date: ";
            getline(cin, startDate);

            cout << "Enter end date: ";
            getline(cin, endDate);

            cout << "Enter duration: ";
            getline(cin, duration);

            list.addTask(title, status, startDate, endDate, duration);
            cout << "Task added.\n";
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Task ID to remove: ";
            cin >> id;

            list.removeTask(id);
        }
        else if (choice == 3)
        {
            list.displayTasks();
        }
        else if (choice == 4)
        {
            list.saveToJson("tasks.json");
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}