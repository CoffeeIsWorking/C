#include <stdio.h>

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;
    float da;
    float pf;
    float net_salary;
};

int main() {
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name); 

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);


    emp.hra = 0.20 * emp.basic_salary;
    emp.da  = 0.10 * emp.basic_salary;
    emp.pf  = 0.12 * emp.basic_salary;

    emp.net_salary = emp.basic_salary + emp.hra + emp.da - emp.pf;

    printf("\n--- Employee Salary Slip ---\n");
    printf("Employee ID   : %d\n", emp.id);
    printf("Employee Name : %s\n", emp.name);
    printf("Basic Salary  : %.2f\n", emp.basic_salary);
    printf("HRA (20%%)     : %.2f\n", emp.hra);
    printf("DA (10%%)      : %.2f\n", emp.da);
    printf("PF (12%%)      : %.2f\n", emp.pf);
    printf("Net Salary    : %.2f\n", emp.net_salary);

    return 0;
}

