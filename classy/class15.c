#include <stdio.h>
#include <stdlib.h>
struct hospital {
    char name[50];
    char disease[100];
    int num_beds;
};
int main() {
    struct hospital h1;
    printf("Enter hospital name: ");
    fgets(h1.name, sizeof(h1.name), stdin);
    printf("Enter disease treated: ");
    fgets(h1.disease, sizeof(h1.disease), stdin);
    printf("Enter number of beds: ");
    scanf("%d", &h1.num_beds);
    printf("Patient Information:\n");
    struct patient {
        char name[50];
        int age;
        char disease[100];
    } p1;
    printf("Enter patient name:\n ");
    scanf("%s", p1.name);
    fgets(p1.name,sizeof(p1.name),stdin);
    printf("enter patient age:\n");
    scanf("%d",&p1.age);
    printf("enter patient disease:\n");
    scanf("%s", p1.disease);
    fgets(p1.disease,sizeof(p1.disease),stdin);
    struct doctor {
        char name[50];
        char specialization[100];
    } d1;
    printf("Enter doctor name:\n");
    fgets(d1.name, sizeof(d1.name), stdin);
    printf("Enter doctor specialization:\n");
    fgets(d1.specialization, sizeof(d1.specialization), stdin);
    printf("Name: %s", h1.name);
    printf("Disease Treated: %s", h1.disease);
    printf("Number of Beds: %d\n", h1.num_beds);
    printf("Patient Information:\n");
    printf("Name: %s", p1.name);
    printf("Age: %d\n", p1.age);
    printf("Disease: %s", p1.disease);
    printf("Doctor Information:\n");
    printf("Name: %s", d1.name);
    printf("Specialization: %s", d1.specialization);
    printf("\nHospital Information:\n");

    return 0;
}
