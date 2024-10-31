#include <stdio.h>
#include <string.h>
// struct date so user can put day and month and years separate
struct Date {
    int day;
    int month;
    int year;
};
// struct hold element of the tasks
struct tasks {
    char title[300];
    char description[300];
    struct Date date_sep;
    int priorite;
};
// Function to add a new task
void add_tasks(struct tasks *task) {
    printf("Enter title: ");
    scanf(" %[^\n]%*c", task->title);

    printf("Enter description: ");
    scanf(" %[^\n]%*c", task->description);

     printf("Enter day: ");
    scanf("%d", &task->date_sep.day);

    printf("Enter month: ");
    scanf("%d", &task->date_sep.month);

    printf("Enter year: ");
    scanf("%d", &task->date_sep.year);

    printf("Please enter a priority level between 1 and 0: 1 being the high and 0 being the low priority): ");
    scanf("%d", &task->priorite);
}
// Function to display a task

void display_tasks(struct tasks task) {
    printf("-----------tasks------\n");
    printf("Title: %s\n", task.title);
    printf("Description: %s\n", task.description);
    printf("Date: %d/%d/%d\n",task.date_sep.day,task.date_sep.month,task.date_sep.year);
    printf("Priority: %d\n", task.priorite);
}
// Function to modifie an existing task
void modifier_tasks(struct tasks *task) {
    int modifie;
    printf("entre 1 to modifie title:\n");
    printf("entre 2 to modifie description:\n");
    printf("entre 3 to modifie date:\n");
    printf("entre 4 to modifie priority:\n");
    printf("choose an option from 1 to 4:");
    scanf("%d",&modifie);
    switch(modifie){
     case 1:
        printf("entre new title:");
        scanf(" %[^\n]%*c",task->title);
        break;
     case 2:
        printf("entre new descreption:");
        scanf(" %[^\n]%*c",task->description);
        break;
     case 3:
    printf("Enter day: ");
    scanf("%d", &task->date_sep.day);

    printf("Enter month: ");
    scanf("%d", &task->date_sep.month);

    printf("Enter year: ");
    scanf("%d", &task->date_sep.year);

        break;
     case 4:
        printf("entre new priority:");
        scanf("%d",&task->priorite);
        break;
     default:
        printf("invalide choice.");
    }
}
// Function to delete an existing task

void delete_tasks(struct tasks tasks[], int *nbr_tasks, int index) {
    for (int i = index; i < (*nbr_tasks) - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*nbr_tasks)--;
}
// Function to display tasks based on priority filter
void filtrer_par_priorite(struct tasks tasks[], int nbr_tasks, int priorite) {
    printf("\n--- Tasks with priority %s ---\n", priorite == 0 ? "Low" : "High");
    for (int i = 0; i < nbr_tasks; i++) {
        if (tasks[i].priorite == priorite) {
            display_tasks(tasks[i]);
        }
    }
}


int main() {
    struct tasks tasks[100];
    int nbr_tasks = 0;
    int index, choice, i,priority_filter;
// Display options in a loop
    do {
        printf("1: Enter tasks\n");
        printf("2: Display all tasks\n");
        printf("3: Modify a task\n");
        printf("4: Delete a task\n");
        printf("5: Exit\n");
        printf("6: Display tasks by priority\n");
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
                    printf("Enter the number of the task you want to modify (you have %d tasks): ", nbr_tasks);
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
                    printf("Enter the number of the task you want to delete (you have %d tasks): ", nbr_tasks);
                    scanf("%d", &index);
                    index-=1;
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
     case 6: // Option to display tasks by priority
                printf("Enter priority to filter by (0 for Low Priority, 1 for High Priority): ");
                scanf("%d", &priority_filter);
                if (priority_filter == 0 || priority_filter == 1) {
                    filtrer_par_priorite(tasks, nbr_tasks, priority_filter);
                } else {
                    printf("Invalid priority. Enter 0 for Low or 1 for High.\n");
                }
                break;
        }
    } while (choice != 5);// kteawd hta user kikhtar exit

    return 0; // kikhrj lprograme
}
