#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define enum for dept types
typedef enum
{
    HR,
    Sales,
    Research,
    Software,
    Executive
} Department;

// Define struct for employee
typedef struct
{
    Department department;
    int annual_salary;
    unsigned int social_security_number;
} Employee;

// Fn to generate a random social security number
unsigned int generateSocialSecurityNumber()
{
    return rand() % 900000000 + 100000000; // Generate random 9-digit number
}

// Fn to generate a random offset for salary based on department
int generateSalaryOffset(Department department)
{
    switch (department)
    {
    case HR:
        return rand() % 5000 + 10000;
    case Sales:
        return rand() % 6000 + 12000;
    case Research:
        return rand() % 7000 + 13000;
    case Software:
        return rand() % 8000 + 14000;
    case Executive:
        return rand() % 10000 + 20000;
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator with current time to ensure different initial state for rand().

    // Generate 10 employees
    Employee employees[10];
    for (int i = 0; i < 10; i++)
    {
        employees[i].social_security_number = generateSocialSecurityNumber();       // Generate random social security number.
        employees[i].department = (Department)(rand() % 5);                         // Generate random department.
        employees[i].annual_salary = generateSalaryOffset(employees[i].department); // Generate salary offset based on department.
    }

    // Print out the employees
    for (int i = 0; i < 10; i++)
    {
        printf("Employee %d:\n", i + 1);
        printf("Department: ");
        switch (employees[i].department)
        {
        case HR:
            printf("HR\n");
            break;
        case Sales:
            printf("Sales\n");
            break;
        case Research:
            printf("Research\n");
            break;
        case Software:
            printf("Software\n");
            break;
        case Executive:
            printf("Executive\n");
            break;
        }
        printf("Annual Salary: %d\n", employees[i].annual_salary);
        printf("Social Security Number: %u\n", employees[i].social_security_number);
        printf("\n");
    }

    return 0;
}
