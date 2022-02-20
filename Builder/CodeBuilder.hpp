#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

struct Class
{
  string name;
  vector<pair<string, string>> fields;

  friend ostream &operator<<(ostream &os, const Class &obj)
  {
    os << "class " << obj.name << endl;
    os << "{" << endl;
    for (const auto field : obj.fields)
    {
      os << "  " << field.second << " " << field.first << ";" << endl;
    }
    os << "};" << endl;
    return os;
  }
};

class CodeBuilder
{
public:
  CodeBuilder(const string &class_name)
  {
    m_class.name = class_name;
  }

  CodeBuilder &add_field(const string &name, const string &type)
  {
    m_class.fields.push_back({name, type});
    return *this;
  }

  friend ostream &operator<<(ostream &os, const CodeBuilder &obj)
  {
    os << obj.m_class << endl;
    return os;
  }

private:
  Class m_class;
};