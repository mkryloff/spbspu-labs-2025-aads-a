#ifndef DATACOMMANDS_HPP
#define DATACOMMANDS_HPP

#include <string>
#include <map>

namespace krylov
{
  void inputFile(const std::string& filename, std::map< std::string, std::map< int, std::string, std::less< int > >, std::less< std::string > >& dicts);
  void printComm(std::istream& in, std::ostream& out, const std::map< std::string, std::map< int, std::string, std::less< int > >, std::less< std::string > >& dicts);
  void complementComm(std::istream& in, std::map< std::string, std::map< int, std::string, std::less< int > >, std::less< std::string > >& dicts);
  void intersectComm(std::istream& in, std::map< std::string, std::map< int, std::string, std::less< int > >, std::less< std::string > >& dicts);
  void unionComm(std::istream& in, std::map< std::string, std::map< int, std::string, std::less< int > >, std::less< std::string > >& dicts);
}

#endif
