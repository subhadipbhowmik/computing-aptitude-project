#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string courseCode;
    int credit;
    int grade;
};


void displayGradeOptions() {
    cout << "Grade Options:\n";
    cout << "  10 - A+\n";
    cout << "   9 - A\n";
    cout << "   8 - B+\n";
    cout << "   7 - B\n";
    cout << "   6 - C+\n";
    cout << "   5 - C\n";
    cout << "   4 - D+\n";
    cout << "   3 - D\n";
    cout << "   2 - E+\n";
    cout << "   1 - E\n";
    cout << "   0 - F\n";
}

void calculateSGPA(const vector<Course>& courses) {
    int totalCredits = 0;
    int weightedGradeSum = 0;

    for (const auto& course : courses) {
        totalCredits += course.credit;
        weightedGradeSum += course.credit * course.grade;
    }

    if (totalCredits == 0) {
        cout << "No courses found. Please add courses before calculating SGPA.\n";
        return;
    }

    double sgpa = static_cast<double>(weightedGradeSum) / totalCredits;

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nYour SGPA is: " << fixed << setprecision(2) << sgpa << endl;

    // Display a message based on SGPA
    if (sgpa >= 9.0) {
        cout << "Outstanding performance!\n";
    } else if (sgpa >= 8.0) {
        cout << "Excellent performance!\n";
    } else if (sgpa >= 7.0) {
        cout << "Very good performance!\n";
    } else if (sgpa >= 6.0) {
        cout << "Good performance!\n";
    } else if (sgpa >= 5.0) {
        cout << "Average performance.\n";
    } else {
        cout << "Poor performance.\n";
    }
}


void clearCourses(vector<Course>& courses) {
    courses.clear();
    cout << "All courses have been cleared.\n";
}

int main() {
    vector<Course> courses;
    int choice;

    do {
        cout << "\n--- Chandigarh University SGPA Calculator ---\n";
        cout << "1. Add Course\n";
        cout << "2. Calculate SGPA\n";
        cout << "3. Clear All Courses\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Course course;
            cout << "Enter Course Code: ";
            cin >> course.courseCode;

            cout << "Enter Course Credit (1-10): ";
            cin >> course.credit;
            while (course.credit < 1 || course.credit > 10) {
                cout << "Invalid credit. Please enter a valid credit (1-10): ";
                cin >> course.credit;
            }

            displayGradeOptions();
            cout << "Enter Grade (0-10): ";
            cin >> course.grade;
            while (course.grade < 0 || course.grade > 10) {
                cout << "Invalid grade. Please enter a valid grade (0-10): ";
                cin >> course.grade;
            }

            courses.push_back(course);
            cout << "Course added successfully.\n";
        } 
        else if (choice == 2) {
            calculateSGPA(courses);
        } 
        else if (choice == 3) {
            clearCourses(courses);
        } 
        else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    cout << "Exiting SGPA Calculator.\n";
    return 0;
}
