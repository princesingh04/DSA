#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// The "part" class. It can exist on its own.
class Teacher {
private:
    std::string m_name;

public:
    Teacher(const std::string& name) : m_name(name) {
        std::cout << "Teacher " << m_name << " created.\n";
    }

    ~Teacher() {
        std::cout << "Teacher " << m_name << " destroyed.\n";
    }

    std::string getName() const {
        return m_name;
    }
};

// The "whole" class. It contains pointers to Teacher objects but does not own them.
class Department {
private:
    std::string m_name;
    std::vector<Teacher*> m_teachers; // Using pointers to represent aggregation

public:
    Department(const std::string& name) : m_name(name) {
        std::cout << "Department " << m_name << " created.\n";
    }

    ~Department() {
        // Note: The Department does NOT delete the Teacher objects it points to.
        // This is the core of aggregation.
        std::cout << "Department " << m_name << " destroyed.\n";
    }

    // The Department receives a pointer to an already existing Teacher object.
    void addTeacher(Teacher* teacher) {
        m_teachers.push_back(teacher);
    }

    void listTeachers() const {
        std::cout << "Department " << m_name << " has teachers: ";
        for (const auto& teacher : m_teachers) {
            std::cout << teacher->getName() << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    // Create the "part" objects first. They have their own lifecycle.
    Teacher* t1 = new Teacher("Smith");
    Teacher* t2 = new Teacher("Jones");
    Teacher* t3 = new Teacher("Miller");

    std::cout << "\n--- Creating Department and forming aggregation ---\n";
    
    // Create the "whole" object.
    Department* dept = new Department("Computer Science");
    
    // Add the existing teachers to the department.
    dept->addTeacher(t1);
    dept->addTeacher(t2);
    
    dept->listTeachers();

    std::cout << "\n--- Demonstrating Independent Lifecycles ---\n";
    
    // Destroy the "whole" object.
    delete dept;
    dept = nullptr;

    // The "part" objects (Teachers) still exist and are perfectly valid.
    std::cout << "Teacher " << t1->getName() << " still exists after the department is gone.\n";
    std::cout << "Teacher " << t2->getName() << " still exists after the department is gone.\n";

    std::cout << "\n--- Cleaning up remaining objects ---\n";

    // Clean up the teacher objects separately.
    delete t1;
    delete t2;
    delete t3;

    return 0;
}
