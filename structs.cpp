#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
  string name;
  int age;
  float gpa;
};

struct Point
{
  int x;
  int y;
};

int main()
{

  Student student1;

  student1.name = "Joe";
  student1.age = 20;
  student1.gpa = 3.5;

  cout << "Name: " << student1.name << endl
       << "Age: " << student1.age << endl
       << "GPA: " << student1.gpa << endl;

  Student students[3];

  students[0] = {"Joe", 20, 3.5};
  students[1] = {"Jane", 21, 3.8};
  students[2] = {"Jack", 22, 3.2};

  for (int i = 0; i < 3; i++)
  {
    cout << "Student #" << (i + 1) << ": " << students[i].name << ", Age: " << students[i].age << ", GPA: " << students[i].gpa << endl;
  }

  vector<Student> studentList;
  studentList.push_back({"Joe", 20, 3.5});
  studentList.push_back({"Jane", 21, 3.8});
  studentList.push_back({"Jack", 22, 3.2});

  // auto to automatically deduce the type of the variable
  for (const auto &student : studentList) // range-based for loop (need C++11 or later) this means student is a reference to each element in studentList
  {
    cout << "Name: " << student.name << ", Age: " << student.age << ", GPA: " << student.gpa << endl;
  }

  int nums[] = {1, 2, 3, 4, 5};
  for (auto num : nums) // nums is an array, so the type of num is int
  {
    cout << num << " ";
  }
  cout << endl;

  Point *pPoint = new Point; // new is used to dynamically allocate memory for a Point struct

  // Accessing members of the struct using the pointer
  pPoint->x = 10;
  pPoint->y = 20;

  // Displaying the values
  cout << "Point coordinates: (" << pPoint->x << ", " << pPoint->y << ")" << endl;

  delete pPoint; // free the dynamically allocated memory

  Point pt;
  pt.x = 10;
  pt.y = 20;

  Point pt2 = pt; // copy struct (value copy)
  pt2.x = 30;     // modify pt2
  cout << "pt.x: " << pt.x << endl;
  cout << "pt2.x: " << pt2.x << endl;

  Point *pPt = new Point;
  pPt->x = 10;
  pPt->y = 20;
  cout << "pPt->x: " << pPt->x << endl;
  cout << "pPt->y: " << pPt->y << endl;

  Point *pPt2 = pPt; // copy pointer (address copy)
  pPt2->x = 30;      // modify pPt2
  cout << "pPt->x: " << pPt->x << endl;
  cout << "pPt2->x: " << pPt2->x << endl;

  return 0;
}
