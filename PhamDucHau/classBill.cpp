#include <iostream>
#include <conio.h>
#include <stdio.h>

class Bill
{
private:
  char ID[20], Name[30], Type[10], Date[15];
  float Mass, fistCost;

public:
  float lastCost;
  void input();
  void output();
};
void Bill::input()
{
  fflush(stdin);
  std::cout << "Enter ID Item : ";
  std::cin.getline(ID, 20);
  std::cout << "Enter Name Item : ";
  std::cin.getline(Name, 30);
  std::cout << "Enter Type Item : ";
  std::cin.getline(Type, 10);
  std::cout << "Enter Date Item : ";
  std::cin.getline(Date, 20);
  std::cout << "Enter Mass Item : ";
  std::cin >> Mass;
  std::cout << "Enter Fist Cost Item : ";
  std::cin >> fistCost;
  std::cout << "Enter Last Cost Item : ";
  std::cin >> lastCost;
}
void Bill::output()
{
  std::cout << "ID:" << ID;
  std::cout << "|Name:" << Name;
  std::cout << "|Type:" << Type;
  std::cout << "|Date:" << Date;
  std::cout << "|Mass:" << Mass;
  std::cout << "|Fist Cost:" << fistCost;
  std::cout << "|Last Cost:" << lastCost;
}
int main()
{
  int n;
  std::cout << "Enter List Items : ";
  std::cin >> n;
  Bill *BigC = new Bill[n];
  for (int i = 0; i < n; i++)
  {
    std::cout << "Enter Item " << i + 1;
    std::cout << std::endl;
    BigC[i].input();
  }
  for (int i = 0; i < n; i++)
  {
    BigC[i].output();
    std::cout << std::endl;
  }
  Bill currentIndex;
  for (size_t i = 0; i < n; i++)
  {
    currentIndex = BigC[i];
    for (size_t j = i + 1; j < n; j++)
    {
      if (currentIndex.lastCost < BigC[j].lastCost)
      {
        currentIndex = BigC[j];
        BigC[j] = BigC[j - 1];
        BigC[j - 1] = currentIndex;
      }
    }
  }
  float res = 0;
  for (int i = 0; i < n; i++)
  {
    res += BigC[i].lastCost;
  }

  std::cout << std::endl
            << "-----------------\n"
            << "Total Your Bill: " << res << std::endl
            << "Print Bill:\n";
  for (int i = 0; i < n; i++)
  {
    BigC[i].output();
    std::cout << std::endl;
  }
}