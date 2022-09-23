#include <iostream>
#include <string>

class Person
{
    friend class ResponsiblePerson;
    int age;

public:
    Person(int age) : age(age) {}

    int get_age() const { return age; }
    void set_age(int age) { this->age = age; }

    std::string drink() const { return "drinking"; }
    std::string drive() const { return "driving"; }
    std::string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
public:
    ResponsiblePerson(const Person &person) : m_person(person), m_ageForDrink(18), m_ageForDrive(16), m_msgIfYoung("too young") {}

    int get_age() const { return m_person.get_age(); }
    void set_age(int age) { m_person.set_age(age); }
    std::string drink() const
    {
        return m_person.get_age() >= m_ageForDrink ? m_person.drink() : m_msgIfYoung;
    }
    std::string drive() const
    {
        return m_person.get_age() >= m_ageForDrive ? m_person.drive() : m_msgIfYoung;
    }
    std::string drink_and_drive() const { return "dead"; }

private:
    Person m_person;
    const int m_ageForDrink;
    const int m_ageForDrive;
    const std::string m_msgIfYoung;
};

void test(const ResponsiblePerson &resp)
{
    std::cout << "Drink: " << resp.drink() << std::endl;
    std::cout << "Drive: " << resp.drive() << std::endl;
    std::cout << "Drink&drive: " << resp.drink_and_drive() << std::endl;
}

int main()
{
    Person human(5);
    ResponsiblePerson resp(human);

    std::cout << "Age = " << resp.get_age() << std::endl;
    test(resp);

    resp.set_age(17);
    std::cout << "Age = " << resp.get_age() << std::endl;
    test(resp);

    resp.set_age(20);
    std::cout << "Age = " << resp.get_age() << std::endl;
    test(resp);
    return 0;
}