#include <stdio.h>
struct tasks{
char title[300];
char description[300];
int date;
int priorite;

};
void add_tasks(struct tasks *task) {
    printf("Enter title: ");
    fgets(task->title, sizeof(task->title), stdin);

    printf("Enter description: ");
    fgets(task->description, sizeof(task->description), stdin);

    printf("Enter date: ");
    scanf("%d", &task->date);

    printf("Please enter a priority level between 1 and 10, where 1 is the highest priority and 10 is the lowest: ");
    scanf("%d", &task->priorite);
}
void display_tasks(struct tasks tasks)
{
    printf("your title:",tasks.title);
    printf("your title:",tasks.description);
    printf("your title:",tasks.date);
    printf("your title:",tasks.priorite);

}
void modifier_tasks(struct tasks *tasks)
{
     printf("Enter title: ");
    fgets(tasks->title, sizeof(tasks->title), stdin);

    printf("Enter description: ");
    fgets(tasks->description, sizeof(tasks->description), stdin);

    printf("Enter date: ");
    scanf("%d", &tasks->date);

    printf("Please enter a priority level between 1 and 10, where 1 is the highest priority and 10 is the lowest: ");
    scanf("%d", &tasks->priorite);
}
void delete_date(struct tasks tasks[],int *nbr_tasks,int index)
{
    for(int i=index;i<(*nbr_tasks)-1;i++)
    {
         nbr_tasks[i]=nbr_tasks[i+1];

    } (*nbr_tasks)--;

}
