#include <stdio.h>
#include <string.h>

struct tasks {
    char title[300];
    char description[300];
    char date[11];
    int priorite;
};

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

void display_tasks(struct tasks task) {
    printf("Title: %s\n", task.title);
    printf("Description: %s\n", task.description);
    printf("Date: %s\n", task.date);
    printf("Priority: %d\n", task.priorite);
}

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

    do {
        printf("1: Enter tasks\n");
        printf("2: Display all tasks\n");
        printf("3: Modify a task\n");
        printf("4: Delete a task\n");
        printf("5: Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

   switch (choice) {
       case 1:
                if (nbr_tasks < 100) {
                    add_tasks(&tasks[nbr_tasks]);
                    nbr_tasks++;
                } else {
                    printf("Maximum number of tasks reached.\n");
                }
                break;

    case 2:
                if (nbr_tasks == 0) {
                    printf("There are no tasks.\n");
                } else {
                    for (i = 0; i < nbr_tasks; i++) {
                        display_tasks(tasks[i]);
                    }
                }
                break;

