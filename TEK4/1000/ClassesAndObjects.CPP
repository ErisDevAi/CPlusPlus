// Done
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student
{
public:
  int Scores[5];
  void input()
  {
    for (int i = 0; i < 5; i++)
    {
      cin >> Scores[i];
    }
  }
  int calculateTotalScore()
  {
    int total = 0;
    for (int i = 0; i < 5; i++)
    {
      total += Scores[i];
    }
    return total;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<Student> students(n);
  // Student *students = new Student[n];
  
  for (int i = 0; i < n; i++)
  {
    students[i].input();
  }

  int flags = 0;
  int KristenScores = students[0].calculateTotalScore();
  for (int i = 1; i < n; i++)
  {
    if (students[i].calculateTotalScore() > KristenScores)
    {
      flags++;
    }
  }
  cout << flags;
  return 0;
}
