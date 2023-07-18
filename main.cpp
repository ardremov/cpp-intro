#include <iostream>

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
  std::cout << x + y + z + w << " is the sum of " << x << " and " << y << " and " << z << " and " << w << std::endl;

  int v = 9;
  std::cout << x + y + v << " is the sum of " << x << " and " << y << " and " << v << std::endl;

  return 0;
}