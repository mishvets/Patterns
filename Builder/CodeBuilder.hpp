#include <string>
// #include <unordered_map>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class CodeBuilder
{
public:
  CodeBuilder(const string &class_name) : m_name(class_name)
  {
    // todo
  }

  CodeBuilder &add_field(const string &name, const string &type)
  {
    // if (m_fields.find(name) == m_fields.end()){
    //   m_fields.insert({name, type});
    // } else {
    //   cout << "Field " << quoted(name) << " is already exist in class " << m_name << ";" << endl;
    // }
    m_fields.push_back({name, type});
    return *this;
  }

  friend ostream &operator<<(ostream &os, const CodeBuilder &obj)
  {
    os << "class " << obj.m_name << endl;
    os << "{" << endl;
    // for (const auto& [name, type] : obj.m_fields) {
    //   os << "  " << type << " " << name << ";" << endl;
    // }
    for (const auto field : obj.m_fields)
    {
      os << "  " << field.second << " " << field.first << ";" << endl;
    }
    os << "};" << endl;
    return os;
  }

private:
  string m_name;
  // unordered_map<string, string> m_fields;
  vector<pair<string, string>> m_fields;
};