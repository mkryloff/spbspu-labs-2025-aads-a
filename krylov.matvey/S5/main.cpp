#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    std::cerr << "Wrong arguments\n";
    return 1;
  }
  std::ifstream file(argv[2]);
  if (!file)
  {
    std::cerr << "Wrong filename\n";
  }
}
