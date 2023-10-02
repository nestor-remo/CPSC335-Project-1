#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void groupSchedule(std::vector<std::vector<int>> person1, std::vector<std::vector<int>> person2);

int main () {
 std::string data;
 std::ifstream myFile("data.txt");
 return 0;
}

void groupSchedule(std::vector<std::vector<int>> person1, std::vector<std::vector<int>> person2) {
  for (int i = 0; i < person1.size(); i++) {
    for (int j = 0; j < person1[i].size(); j++) {
      if (person1[i][j] == 1 && person2[i][j] == 1) {
        std::cout << "Meeting at " << i << " " << j << std::endl;
      }
    }
  }
}
