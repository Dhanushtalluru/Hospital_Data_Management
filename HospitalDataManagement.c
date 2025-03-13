#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Patient
typedef struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char contactInfo[50];
    char medicalHistory[100];
    char currentTreatment[100];
} Patient;

// Node structure for Linked List
typedef struct Node {
    Patient patient;
    struct Node* next;
} Node;

Node* head = NULL; // Head pointer for the list

// Function to create a new patient
Patient createPatient(int id, char name[], int age, char gender[], char contactInfo[], char medicalHistory[], char currentTreatment[]) {
    Patient p;
    p.id = id;
    strcpy(p.name, name);
    p.age = age;
    strcpy(p.gender, gender);
    strcpy(p.contactInfo, contactInfo);
    strcpy(p.medicalHistory, medicalHistory);
    strcpy(p.currentTreatment, currentTreatment);
    return p;
}

// Function to add a patient to the list
void addPatient(int id, char name[], int age, char gender[], char contactInfo[], char medicalHistory[], char currentTreatment[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->patient = createPatient(id, name, age, gender, contactInfo, medicalHistory, currentTreatment);
    newNode->next = head;
    head = newNode;
    printf("Patient added successfully!\n");
}

// Function to display all patients
void displayPatients() {
    if (head == NULL) {
        printf("No patients in the list.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nContact Info: %s\nMedical History: %s\nCurrent Treatment: %s\n", 
               current->patient.id, current->patient.name, current->patient.age, current->patient.gender, 
               current->patient.contactInfo, current->patient.medicalHistory, current->patient.currentTreatment);
        printf("----------------------\n");
        current = current->next;
    }
}

// Function to delete a patient by ID
void deletePatient(int id) {
    if (head == NULL) {
        printf("No patients to delete.\n");
        return;
    }
    Node* temp = head;
    Node* prev = NULL;

    // If head node itself holds the patient to be deleted
    if (temp != NULL && temp->patient.id == id) {
        head = temp->next;
        free(temp);
        printf("Patient deleted successfully!\n");
        return;
    }

    // Search for the patient to be deleted
    while (temp != NULL && temp->patient.id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If patient was not found
    if (temp == NULL) {
        printf("Patient not found.\n");
        return;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);
    printf("Patient deleted successfully!\n");
}

// Main function
int main() {
    int choice, id, age;
    char name[50], gender[10], contactInfo[50], medicalHistory[100], currentTreatment[100];

    while (1) {
        printf("\n1. Add Patient\n2. Display Patients\n3. Delete Patient\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter Age: ");
                scanf("%d", &age);
                getchar();
                printf("Enter Gender: ");
                fgets(gender, sizeof(gender), stdin);
                gender[strcspn(gender, "\n")] = 0;
                printf("Enter Contact Info: ");
                fgets(contactInfo, sizeof(contactInfo), stdin);
                contactInfo[strcspn(contactInfo, "\n")] = 0;
                printf("Enter Medical History: ");
                fgets(medicalHistory, sizeof(medicalHistory), stdin);
                medicalHistory[strcspn(medicalHistory, "\n")] = 0;
                printf("Enter Current Treatment: ");
                fgets(currentTreatment, sizeof(currentTreatment), stdin);
                currentTreatment[strcspn(currentTreatment, "\n")] = 0;
                addPatient(id, name, age, gender, contactInfo, medicalHistory, currentTreatment);
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deletePatient(id);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
