#include <iostream>
class Vector
{
  int n;
  int *arr = new int[n];
  void input(int *arr)
  {
    for (int i = 0; i < n; i++)
    {
      std::cin >> arr[i];
    }
  }
  void output(int *arr)
  {
    for (int i = 0; i < n; i++)
    {
      std::cout << arr[i] << " ";
    }
  }
  int Sum(int *arr)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += arr[i];
    }
    return sum;
  }
  int Plus(int *arr)
  {
    int plus = 0;
    for (int i = 0; i < n; i++)
    {
      plus *= arr[i];
    }
    return plus;
  }
};