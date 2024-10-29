#include <stdio.h>
struct tasks{
char title[300];
char description[300];
char date;
int priorite;

};
void add_tasks(struct tasks *tasks) {
    printf("Enter title: ");
    scanf(" %[^\n]%*c",tasks->title);


    printf("Enter description: ");
   scanf(" %[^\n]%*c",tasks->description);

    printf("Enter date: ");
    scanf(" %[^\n]%*c", &tasks->date);

    printf("Please enter a priority level between 1 and 10, where 1 is the highest priority and 10 is the lowest: ");
    scanf("d", &tasks->priorite);
}
void display_tasks(struct tasks tasks)
{
    printf("your title:%s",tasks.title);
    printf("your title:%s",tasks.description);
    printf("your title:%d",tasks.date);
    printf("your title:%d",tasks.priorite);

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
         tasks[i]=tasks[i+1];

    } (*nbr_tasks)--;

}
int main()
{
    struct tasks tasks[100];
    int nbr_tasks=0;
    int indice,choice,i;
    do {
        printf("1:enter the tasks\n");
        printf("2:display all tasks\n");
        printf("3:modifier a tasks\n");
        printf("4:delete a tasks\n");
        printf("Choose une option : ");
        scanf("%d",&choice);
