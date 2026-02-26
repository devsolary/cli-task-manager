#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string title, status, startDate, endDate, timeline;

public:
    void setTask(std::string t, std::string s,
                 std::string sd, std::string ed,
                 std::string tl);

    std::string taskInfo();
};

#endif