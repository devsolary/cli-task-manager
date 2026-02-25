#include <iostream>
#include <string>
#include <sstream>
#include "task.h"
using namespace std;

class Task
{
private:
    int id;
    string title, status, startDate, endDate, timeline;

public:
    void setTask(string t, string s, string sd, string ed, string tl)
    {
        title = t;
        status = s;
        startDate = sd;
        endDate = ed;
        timeline = tl;
    };
    string taskInfo()
    {
        stringstream ss;
        ss << title << " | " << status << " | "
           << startDate << " | " << endDate << " | "
           << timeline;
        return ss.str();
    }
};