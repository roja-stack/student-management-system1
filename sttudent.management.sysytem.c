#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int roll;
    char department[50];
    float cgpa;
};

struct Student students[100];
int totalStudents = 0;

// Add Student
void addStudent() {

    printf("\nEnter Student ID: ");
    scanf("%d", &students[totalStudents].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[totalStudents].name);

    printf("Enter Roll Number: ");
    scanf("%d", &students[totalStudents].roll);

    printf("Enter Department: ");
    scanf(" %[^\n]", students[totalStudents].department);

    printf("Enter CGPA: ");
    scanf("%f", &students[totalStudents].cgpa);

    totalStudents++;

    printf("\nStudent Added Successfully!\n\n");
}

// View Students
void viewStudents() {

    if (totalStudents == 0) {
        printf("\nNo Students Found.\n\n");
        return;
    }

    printf("\n========== Student List ==========\n");

    for (int i = 0; i < totalStudents; i++) {

        printf("\nStudent %d\n", i + 1);
        printf("ID         : %d\n", students[i].id);
        printf("Name       : %s\n", students[i].name);
        printf("Roll       : %d\n", students[i].roll);
        printf("Department : %s\n", students[i].department);
        printf("CGPA       : %.2f\n", students[i].cgpa);

        printf("----------------------------------\n");
    }

    printf("\n");
}

// Search Student
void searchStudent() {

    int roll;
    int found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < totalStudents; i++) {

        if (students[i].roll == roll) {

            printf("\nStudent Found\n");
            printf("ID         : %d\n", students[i].id);
            printf("Name       : %s\n", students[i].name);
            printf("Roll       : %d\n", students[i].roll);
            printf("Department : %s\n", students[i].department);
            printf("CGPA       : %.2f\n", students[i].cgpa);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student Not Found.\n");
    }

    printf("\n");
}

// Update Student
void updateStudent() {

    int roll;
    int found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (int i = 0; i < totalStudents; i++) {

        if (students[i].roll == roll) {

            printf("\nEnter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Department: ");
            scanf(" %[^\n]", students[i].department);

            printf("Enter New CGPA: ");
            scanf("%f", &students[i].cgpa);

            printf("\nStudent Updated Successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student Not Found.\n");
    }

    printf("\n");
}

// Delete Student
void deleteStudent() {

    int roll;
    int found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < totalStudents; i++) {

        if (students[i].roll == roll) {

            for (int j = i; j < totalStudents - 1; j++) {
                students[j] = students[j + 1];
            }

            totalStudents--;

            printf("\nStudent Deleted Successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student Not Found.\n");
    }

    printf("\n");
}

// Count Students
void countStudents() {

    printf("\nTotal Students: %d\n\n", totalStudents);
}

// Show Highest CGPA
void highestCGPA() {

    if (totalStudents == 0) {
        printf("\nNo Students Found.\n\n");
        return;
    }

    float max = students[0].cgpa;
    int index = 0;

    for (int i = 1; i < totalStudents; i++) {

        if (students[i].cgpa > max) {
            max = students[i].cgpa;
            index = i;
        }
    }

    printf("\n===== Highest CGPA Student =====\n");
    printf("Name       : %s\n", students[index].name);
    printf("Roll       : %d\n", students[index].roll);
    printf("Department : %s\n", students[index].department);
    printf("CGPA       : %.2f\n\n", students[index].cgpa);
}

// Average CGPA
void averageCGPA() {

    if (totalStudents == 0) {
        printf("\nNo Students Found.\n\n");
        return;
    }

    float sum = 0;

    for (int i = 0; i < totalStudents; i++) {
        sum += students[i].cgpa;
    }

    printf("\nAverage CGPA: %.2f\n\n", sum / totalStudents);
}

// Save Data to File
void saveToFile() {

    FILE *file = fopen("students.txt", "w");

    for (int i = 0; i < totalStudents; i++) {

        fprintf(file,
                "%d %s %d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].roll,
                students[i].department,
                students[i].cgpa);
    }

    fclose(file);

    printf("\nData Saved Successfully!\n\n");
}

// Main Function
int main() {

    int choice;

    while (1) {

        printf("====================================\n");
        printf("     Student Management System\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Count Students\n");
        printf("7. Highest CGPA\n");
        printf("8. Average CGPA\n");
        printf("9. Save Data to File\n");
        printf("10. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                countStudents();
                break;

            case 7:
                highestCGPA();
                break;

            case 8:
                averageCGPA();
                break;

            case 9:
                saveToFile();
                break;

            case 10:
                printf("\nProgram Closed Successfully.\n");
                return 0;

            default:
                printf("\nInvalid Choice! Please Try Again.\n\n");
        }
    }

    return 0;
}
