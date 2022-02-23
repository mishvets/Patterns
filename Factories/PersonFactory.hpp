#include <string>
#include <ostream>
using namespace std;

struct Person
{
  int id;
  string name;

  friend ostream &operator<<(ostream &os, const Person &obj)
  {
    os << "name - " << obj.name << ", id = " << obj.id << ";";
    return os;
  }
};

class PersonFactory
{
  int m_nextId;

public:
  PersonFactory() : m_nextId(0)
  {
  }

  Person create_person(const string &name)
  {
    Person obj;
    obj.name = name;
    obj.id = m_nextId++;
    return obj;
  }
};