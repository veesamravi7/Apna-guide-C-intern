#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

class Student {
public:
    std::string name;
    int id;
    std::vector<double> assignments;
    std::vector<double> exams;
    double overallGrade;

    Student(std::string name, int id) : name(name), id(id), overallGrade(0.0) {}

    void addAssignmentGrade(double grade) {
        assignments.push_back(grade);
    }

    void addExamGrade(double grade) {
        exams.push_back(grade);
    }

    void calculateOverallGrade() {
        double assignmentsSum = std::accumulate(assignments.begin(), assignments.end(), 0.0);
        double assignmentsAvg = assignments.size() > 0 ? assignmentsSum / assignments.size() : 0.0;
        double examsSum = std::accumulate(exams.begin(), exams.end(), 0.0);
        double examsAvg = exams.size() > 0 ? examsSum / exams.size() : 0.0;
        overallGrade = 0.3 * assignmentsAvg + 0.7 * examsAvg; 
    }
};

bool compareStudents(const Student& a, const Student& b) {
    return a.overallGrade > b.overallGrade;
}

void displayStudentInfo(const Student& student) {
    std::cout << "Student Name: " << student.name << "\n";
    std::cout << "Student ID: " << student.id << "\n";
    std::cout << "Overall Grade: " << student.overallGrade << "\n\n";
}

void displayClassStatistics(const std::vector<Student>& students) {
    double totalGrades = 0.0;
    for (size_t i = 0; i < students.size(); ++i) {
        totalGrades += students[i].overallGrade;
    }
    double classAverage = students.size() > 0 ? totalGrades / students.size() : 0.0;
    std::cout << "Class Average: " << classAverage << "\n";
}

void displayClassToppers(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareStudents);

    std::cout << "Class Toppers:\n";
    for (size_t i = 0; i < 3 && i < students.size(); ++i) {
        std::cout << i+1 << ". " << students[i].name << " (ID: " << students[i].id << ") - Overall Grade: " << students[i].overallGrade << "\n";
    }
}

int main() {
    std::vector<Student> students;
    char choice;
    do {
        std::string name;
        int id;
        std::cout << "Enter student name: ";
        std::cin >> name;
        std::cout << "Enter student ID: ";
        std::cin >> id;

        Student student(name, id);
        int numAssignments, numExams;
        std::cout << "Enter number of assignments: ";
        std::cin >> numAssignments;
        for (int i = 0; i < numAssignments; ++i) {
            double grade;
            std::cout << "Enter grade for assignment(out of 100) " << i+1 << ": ";
            std::cin >> grade;
            student.addAssignmentGrade(grade);
        }

        std::cout << "Enter number of exams: ";
        std::cin >> numExams;
        for (int i = 0; i < numExams; ++i) {
            double grade;
            std::cout << "Enter grade for exam(out of 100) " << i+1 << ": ";
            std::cin >> grade;
            student.addExamGrade(grade);
        }

        student.calculateOverallGrade();
        students.push_back(student);

        std::cout << "Do you want to enter another student? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "\nStudent Information:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        displayStudentInfo(students[i]);
    }

    std::cout << "Class Statistics:\n";
    displayClassStatistics(students);

    std::cout << "Class Toppers:\n";
    displayClassToppers(students);

    return 0;
}

