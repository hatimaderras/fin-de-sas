#include <stdio.h>
#include <string.h>

struct tasks {
    char title[300];
    char description[300];
    char date[11];
    int priorite;
};
// Function to add a new task
void add_tasks(struct tasks *task) {
    printf("Enter title: ");
    scanf(" %[^\n]%*c", task->title);

    printf("Enter description: ");
    scanf(" %[^\n]%*c", task->description);

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", task->date);

    printf("Please enter a priority level between 1 and 10 (1 is the highest priority, 10 is the lowest): ");
    scanf("%d", &task->priorite);
}
// Function to display a task

void display_tasks(struct tasks task) {
    printf("Title: %s\n", task.title);
    printf("Description: %s\n", task.description);
    printf("Date: %s\n", task.date);
    printf("Priority: %d\n", task.priorite);
}
// Function to modifie an existing task
void modifier_tasks(struct tasks *task) {
    printf("Enter title: ");
    scanf(" %[^\n]%*c", task->title);

    printf("Enter description: ");
    scanf(" %[^\n]%*c", task->description);

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", task->date);

    printf("Please enter a priority level between 1 and 10 (1 is the highest priority, 10 is the lowest): ");
    scanf("%d", &task->priorite);
}
// Function to delete an existing task

void delete_tasks(struct tasks tasks[], int *nbr_tasks, int index) {
    for (int i = index; i < (*nbr_tasks) - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*nbr_tasks)--;
}

int main() {
    struct tasks tasks[100];
    int nbr_tasks = 0;
    int index, choice, i;
// Display options in a loop
    do {
        printf("1: Enter tasks\n");
        printf("2: Display all tasks\n");
        printf("3: Modify a task\n");
        printf("4: Delete a task\n");
        printf("5: Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice); // choice dyal user from 1/5

   switch (choice) {
       case 1: // // Option to add task
                if (nbr_tasks < 100) {
                    add_tasks(&tasks[nbr_tasks]);
                    nbr_tasks++;
                } else {
                    printf("Maximum number of tasks reached.\n");
                }
                break;

    case 2: // Option to display task
                if (nbr_tasks == 0) {
                    printf("There are no tasks.\n");
                } else {
                    for (i = 0; i < nbr_tasks; i++) {
                        display_tasks(tasks[i]);
                    }
                }
                break;
    case 3: // Option to modify an existing task
                if (nbr_tasks == 0) {
                    printf("There are no tasks.\n");
                } else {
                    printf("Enter the number of the task you want to modify (0 to %d): ", nbr_tasks - 1);
                    scanf("%d", &index);
                    index-=1;
                    if (index >= 0 && index < nbr_tasks) {
                        modifier_tasks(&tasks[index]);
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;

     case 4: // Option to delete an existing task
                if (nbr_tasks == 0) {
                    printf("There are no tasks.\n");
                } else {
                    printf("Enter the number of the task you want to delete (0 to %d): ", nbr_tasks - 1);
                    scanf("%d", &index);
                    index-=1; // hit array ktbda mn 0 if user put 1 it will be index 2 in the array
                    if (index >= 0 && index < nbr_tasks) {
                        delete_tasks(tasks, &nbr_tasks, index);
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;

     case 5: // exit option
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);// kteawd hta user kikhtar exit

    return 0; // kikhrj lprograme
}

