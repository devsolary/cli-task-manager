#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string title, status, startDate, endDate, timeline;

public:
    Task(int id, std::string t, std::string s,
                 std::string sd, std::string ed,
                 std::string tl);

    int getId() const;
    std::string taskInfo() const;
};

#endif