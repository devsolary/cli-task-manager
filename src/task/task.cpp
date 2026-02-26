#include "task.h"
#include <sstream>

Task::Task(int id,
           std::string t,
           std::string s,
           std::string sd,
           std::string ed,
           std::string tl)
    : id(id),
      title(t),
      status(s),
      startDate(sd),
      endDate(ed),
      timeline(tl) {}

int Task::getId() const
{
    return id;
}
std::string Task::taskInfo() const {
    std::stringstream ss;
    ss << "[" << id << "] "
       << title << " | "
       << status << " | "
       << startDate << " | "
       << endDate << " | "
       << timeline;
    return ss.str();
}