#include <iostream>
#include "problems.hpp"
#include "point.hpp"

// function declaration
int add(int x, int y);

// function definition
int add(int x, int y)
{
  return x + y;
}

// function declaration
int subtract(int x, int y);

// function definition
int subtract(int x, int y)
{
  return x - y;
}

// function declaration
int multiply(int x, int y);

// function definition
int multiply(int x, int y)
{
  return x * y;
}

// function declaration
int divide(int x, int y);

// function definition
int divide(int x, int y)
{
  return x / y;
}

int main()
{
  std::cout << "Hello, world!" << std::endl;

  int x = 5;
  int y = 7;

  std::string name = "Alex";
  std::string classroom = "AUV";

  std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
  std::cout << "My name is " << name << " and I belong to the " << classroom << " classroom." << std::endl;

  int z = 6;
  std::cout << x + y + z << " is the sum of " << x << " and " << y << " and " << z << std::endl;

  int w = 8;
  std::cout << x * y * z * w << " is the product of " << x << " and " << y << " and " << z << " and " << w << std::endl;

  int v = 9;
  std::cout << x / y << " is the division of " << x << " and " << y << ", and " << v << " is " << v <<std::endl;

  auto a = Circle<double>{10}.area();
  std::cout << "The area of your circle is " << a << std::endl;

  return 0;
}

