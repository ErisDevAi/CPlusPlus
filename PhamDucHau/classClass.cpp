#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <conio.h>
class Student
{
public:
  char fullName[100], birthday[20], sex[7], grade[20];
  float mathPoint, physicPoint, chemiPoint, averagePoint;
  void input()
  {
    fflush(stdin);
    std::cout << "Enter FullName : " << std::endl;
    std::cin.getline(fullName, 100);
    std::cout << "Enter Birthday : " << std::endl;
    std::cin.getline(birthday, 20);
    std::cout << "Enter Sex : " << std::endl;
    std::cin.getline(sex, 7);
    std::cout << "Enter Grade : " << std::endl;
    std::cin.getline(grade, 20);
    std::cout << "Enter Math Point : " << std::endl;
    std::cin >> mathPoint;
    std::cout << "Enter PhySical Point : " << std::endl;
    std::cin >> physicPoint;
    std::cout << "Enter Chemical Point : " << std::endl;
    std::cin >> chemiPoint;
  }
  void output()
  {
    std::cout << "FullName : " << fullName << std::endl;
    std::cout << "Birthday : " << birthday << std::endl;
    std::cout << "Sex : " << sex << std::endl;
    std::cout << "Grade : " << grade << std::endl;
    std::cout << "Math Point : " << mathPoint << std::endl;
    std::cout << "PhySical Point : " << physicPoint << std::endl;
    std::cout << "Chemical Point : " << chemiPoint << std::endl;
  }
  float calculatorAverage()
  {
    return (mathPoint + physicPoint + chemiPoint) / 3;
  }
  void sort()
  {
  }
};

int main()
{
  int n;
  std::cout << "Enter Number Student In Class: ";
  std::cin >> n;
  Student *st = new Student[n];
  for (int i = 0; i < n; i++)
  {
    st[i].input();
  }
  std::cout << std::endl;
  for (int i = 0; i < n; i++)
  {
    st[i].output();
    std::cout << "Average Point: " << st[i].calculatorAverage();
    std::cout << std::endl;
  }
  float maxA = st[0].calculatorAverage();
  Student tmp;
  Student currentIndex;
  for (size_t i = 0; i < n; i++)
  {
    currentIndex = st[i];
    for (size_t j = i + 1; j < n; j++)
    {
      if (currentIndex.calculatorAverage() > st[j].calculatorAverage())
      {
        currentIndex = st[j];
        st[j] = st[j - 1];
        st[j - 1] = currentIndex;
      }
    }
  }
}