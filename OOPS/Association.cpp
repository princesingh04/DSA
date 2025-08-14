#include <iostream>
#include <string>
#include <vector>

// Forward declaration is necessary because Doctor and Patient
// refer to each other.
class Doctor;

// The Patient class can exist independently of a Doctor.
class Patient {
private:
    std::string m_name;
    Doctor* m_doctor = nullptr; // Pointer to a Doctor (doesn't own it)

public:
    Patient(const std::string& name) : m_name(name) {
        std::cout << "Patient " << m_name << " created.\n";
    }

    ~Patient() {
        std::cout << "Patient " << m_name << " destroyed.\n";
    }

    std::string getName() const {
        return m_name;
    }

    // A patient can be assigned a doctor.
    void assignDoctor(Doctor* doc) {
        m_doctor = doc;
    }
};

// The Doctor class can exist independently of any Patients.
class Doctor {
private:
    std::string m_name;
    std::vector<Patient*> m_patients; // Vector of pointers to Patients (doesn't own them)

public:
    Doctor(const std::string& name) : m_name(name) {
        std::cout << "Doctor " << m_name << " created.\n";
    }

    ~Doctor() {
        std::cout << "Doctor " << m_name << " destroyed.\n";
    }

    std::string getName() const {
        return m_name;
    }

    // A doctor can add a patient to their list.
    void addPatient(Patient* patient) {
        m_patients.push_back(patient);
        patient->assignDoctor(this); // Establish the link back
    }

    void listPatients() const {
        std::cout << "Doctor " << m_name << "'s patients: ";
        if (m_patients.empty()) {
            std::cout << "None.\n";
            return;
        }
        for (const auto& patient : m_patients) {
            std::cout << patient->getName() << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    // Create patient objects. They exist on their own.
    Patient* p1 = new Patient("Alice");
    Patient* p2 = new Patient("Bob");
    Patient* p3 = new Patient("Charlie");

    std::cout << "\n--- Creating Doctor and forming associations ---\n";
    
    // Create a doctor object.
    Doctor* d1 = new Doctor("Smith");

    // Associate the doctor with patients.
    d1->addPatient(p1);
    d1->addPatient(p2);
    
    d1->listPatients();

    std::cout << "\n--- Demonstrating Independent Lifecycles ---\n";
    
    // Delete the Doctor object.
    delete d1;
    d1 = nullptr;

    // The Patient objects still exist and are perfectly valid.
    std::cout << "Patient " << p1->getName() << " still exists after the doctor is gone.\n";
    std::cout << "Patient " << p2->getName() << " still exists after the doctor is gone.\n";

    std::cout << "\n--- Cleaning up remaining objects ---\n";

    // Clean up the patient objects.
    delete p1;
    delete p2;
    delete p3;

    return 0;
}
