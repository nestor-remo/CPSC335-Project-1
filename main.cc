#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void groupSchedule(vector<vector<int>> person1, vector<vector<int>> person2);

int main()
{
 string data;
 ifstream myFile("input.txt");
 while (getline(myFile, data))
 {
  cout << data << endl;
 }
}

void groupSchedule(vector<vector<int>> person1, vector<vector<int>> person2)
{
 for (int i = 0; i < person1.size(); i++)
 {
  for (int j = 0; j < person1[i].size(); j++)
  {
   if (person1[i][j] == 1 && person2[i][j] == 1)
   {
    cout << "Meeting at " << i << " " << j << endl;
   }
  }
 }
}
