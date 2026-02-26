#include "task.h"
#include <sstream>

void Task::setTask(std::string t,
                   std::string s,
                   std::string sd,
                   std::string ed,
                   std::string tl) {
    title = t;
    status = s;
    startDate = sd;
    endDate = ed;
    timeline = tl;
}

std::string Task::taskInfo() {
    std::stringstream ss;
    ss << title << " | " << status << " | "
       << startDate << " | " << endDate << " | "
       << timeline;

    return ss.str();
}