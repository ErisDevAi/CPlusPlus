#include <iostream>

class Vector
{
private:
  float matrix[3];

public:
  friend std::istream &operator>>(std::istream &in, Vector &v);
  friend std::ostream &operator<<(std::ostream &out, const Vector &v);
  Vector operator+(const Vector &other) const;
  float operator*(const Vector &other) const;
};

// Định nghĩa toán tử cộng (+) cho lớp Vector
Vector Vector::operator+(const Vector &other) const
{
  Vector result;
  for (int i = 0; i < 3; ++i)
  {
    result.matrix[i] = matrix[i] + other.matrix[i];
  }
  return result;
}

float Vector::operator*(const Vector &other) const
{
  float dotProduct = 0.0;
  for (int i = 0; i < 3; ++i)
  {
    dotProduct += matrix[i] * other.matrix[i];
  }
  return dotProduct;
}

std::ostream &operator<<(std::ostream &out, const Vector &v)
{
  out << "(" << v.matrix[0] << ", " << v.matrix[1] << ", " << v.matrix[2] << ")";
  return out;
}

std::istream &operator>>(std::istream &in, Vector &v)
{
  std::cout << "Nhap gia tri cho vector (3 so float): ";
  in >> v.matrix[0] >> v.matrix[1] >> v.matrix[2];
  return in;
}

int main()
{
  int n;
  std::cin >> n;
  Vector *v = new Vector[n];

  for (int i = 0; i < n; i++)
  {
    std::cout << "Vector " << i + 1 << std::endl;
    std::cin >> v[i];
  }

  Vector sum;
  float dotProduct = 0.0;

  for (int i = 0; i < n; i++)
  {
    sum = sum + *v;
    dotProduct += sum * *v;
  }

  std::cout << "Tong hai vector: " << sum << std::endl;
  std::cout << "Tich vo huong hai vector: " << dotProduct << std::endl;

  return 0;
}
