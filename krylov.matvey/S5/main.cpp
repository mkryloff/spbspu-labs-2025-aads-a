#include <iostream>
#include <fstream>
#include <binaryTree.hpp>

int main(int argc, char** argv)
{
  using namespace krylov;
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
  std::string value;
  int key = 0;
  BiTree< int, std::string, std::less< int > > biTree;
  while ((file >> key >> value) && !file.eof())
  {
    biTree[key] = value;
  }
  if (!file.eof())
  {
    std::cerr << "Incorrect input!\n";
    return 1;
  }
}
