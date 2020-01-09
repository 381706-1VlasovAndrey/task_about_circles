#pragma once
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Circle
{
protected:
  int id;
  double x, y;
  double r;
public:
  Circle(int id, double x, double y, double r);
  double GetR();

  friend bool Intersection(const Circle &A, const Circle &B);
  friend int Finding_biggest_circle_without_intersections(const char* filename);
};

Circle::Circle(int _id, double _x, double _y, double _r) {
  id = _id;
  x = _x;
  y = _y;
  r = _r;
}

double Circle::GetR() {
  return r;
}

bool Intersection(const Circle& A, const Circle& B) {
  return (pow(A.x - B.x, 2) + pow(A.y - B.y, 2)) <= pow(A.r + B.r, 2);
}

int Finding_biggest_circle_without_intersections(const char* filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    std::string line;
    std::vector<Circle> vector_Circles;
    while (std::getline(file, line))
    {
      int id;
      double x, y, r;
      std::istringstream iss(line);
      std::string temp;
      for (int i = 0; i < 4; i++) {
        getline(iss, temp, ',');
        if (i == 0)
          id = std::stoi(temp);
        if (i == 1)
          x = std::stod(temp);
        if (i == 2)
          y = std::stod(temp);
        if (i == 3)
          r = std::stod(temp);
      }
      Circle A(id, x, y, r);
      vector_Circles.push_back(A);
    }
    int size = static_cast<int>(vector_Circles.size());
    std::vector<bool> intersections(size);
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size && intersections[i] == 0; j++)
        if (i != j) {
          intersections[i] = Intersection(vector_Circles[i], vector_Circles[j]);
          if (intersections[i] == 1)
            intersections[j] = 1;
        }
    std::vector<int> without_intercect;
    for (int i = 0; i < size; i++)
      if (intersections[i] == 0)
        without_intercect.push_back(i);
    size = static_cast<int>(without_intercect.size());
    int number_Circle = -1;
    if (size != 0) {
      double max_r = -1;
      number_Circle = without_intercect[0];
      for (int i = 0; i < size; i++)
        if (vector_Circles[without_intercect[i]].GetR() > max_r) {
          max_r = vector_Circles[without_intercect[i]].GetR();
          number_Circle = without_intercect[i];
        }
    }
    return number_Circle;
  }
  else
    throw "file not found";
}
