#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string minutesToTime(int minutes)
{
 int hours = minutes / 60;
 int mins = minutes % 60;
 string result = "";

 if (hours < 10)
 {
  result += "0";
 }
 result += to_string(hours) + ":";

 if (mins < 10)
 {
  result += "0";
 }
 result += to_string(mins);

 return result;
}

int timeToMinutes(string timeStr)
{
 int hours = stoi(timeStr.substr(0, 2));
 int minutes = stoi(timeStr.substr(3, 2));
 return hours * 60 + minutes;
}

vector<pair<int, int>> findAvailableTimes(vector<vector<string>> p1Sched, vector<string> p1WorkHours,
                                          vector<vector<string>> p2Sched, vector<string> p2WorkHours,
                                          int duration)
{

 vector<pair<int, int>> unavailableTimes;

 for (auto &i : p1Sched)
 {
  unavailableTimes.emplace_back(timeToMinutes(i[0]), timeToMinutes(i[1]));
 }
 for (auto &i : p2Sched)
 {
  unavailableTimes.emplace_back(timeToMinutes(i[0]), timeToMinutes(i[1]));
 }

 sort(unavailableTimes.begin(), unavailableTimes.end());

 vector<pair<int, int>> availableTimes;

 int time_start = max(timeToMinutes(p1WorkHours[0]), timeToMinutes(p2WorkHours[0]));
 int slot_end_time = min(timeToMinutes(p1WorkHours[1]), timeToMinutes(p2WorkHours[1]));
 int prev = time_start;

 for (auto &i : unavailableTimes)
 {
  if (i.first < time_start || i.second > slot_end_time)
  {
   continue;
  }
  else if (i.first - prev >= duration)
  {
   availableTimes.push_back({prev, i.first});
  }

  prev = max(prev, i.second);
 }
 if (slot_end_time - prev >= duration)
 {
  availableTimes.push_back({prev, slot_end_time});
 }

 return availableTimes;
}

int main()
{
 vector<vector<string>> person1_busy_Schedule = {{"8:00", "9:30"}, {"10:00", "12:00"}, {"14:30", "16:30"}};
 vector<string> person1_work_hours = {"8:00", "17:00"};
 vector<vector<string>> person2_busy_Schedule = {{"9:00", "10:30"}, {"11:00", "12:30"}, {"13:30", "15:00"}};
 vector<string> person2_work_hours = {"9:00", "16:00"};
 int duration_of_meeting = 60;

 vector<pair<int, int>> availableTimes = findAvailableTimes(person1_busy_Schedule, person1_work_hours,
                                                            person2_busy_Schedule, person2_work_hours,
                                                            duration_of_meeting);
 for (auto &i : availableTimes)
 {
  cout << "[" << minutesToTime(i.first) << ", " << minutesToTime(i.second) << "] ";
 }
 cout << endl;
 return 0;
}
