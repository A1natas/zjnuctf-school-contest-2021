#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//? tcache double free challenges
//? gcc judger.c -o judger

//! The judger functions

int checkanswer(int ind, int ans)
{
    char pathtmp[100] = "/tmp/Data/out/";
    char index[10] = "";
    sprintf(index, "%d", ind);
    strcat(pathtmp, index);
    strcat(pathtmp, ".out");
    FILE *fp = fopen(pathtmp, "r");
    int correctans;
    fscanf(fp, "%d", &correctans);
    if (ans == correctans)
    {
        return 1;
    }
    return 0;
}

int mainjudger()
{
    for (int i = 1; i <= 18; i++)
    {
        char pathtmp[100] = "/tmp/Data/in/";
        char index[10] = "";
        sprintf(index, "%d", i);
        strcat(pathtmp, index);
        strcat(pathtmp, ".in");
        FILE *fp = fopen(pathtmp, "r");
        printf("Please input the answer of below input: \n");
        char tmpstr[100];
        while (fgets(tmpstr, 100, fp) != NULL)
        {
            printf("  %s", tmpstr);
        }
        printf("\n");

        struct timeval start, end;
        double duration;
        gettimeofday(&start, NULL);

        printf("Your Answer (Time limit 5s): ");
        int answer;
        scanf("%d", &answer);

        gettimeofday(&end, NULL);
        duration = (double)((1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec) / 1000000);

        if (duration > 5)
        {
            return 2;
        }
        if (checkanswer(i, answer) == 0)
        {
            return 0;
        }
    }
    return 1;
}

//! The pwnable data

typedef struct
{
    char *judgername;
    int type;
} Judger;
Judger *judgerlist[6];
int judgercnt = 0;

//! The pwnable functions

void initfun()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
}

void showmenu()
{
    puts("\n");
    puts("1 . Create a judger");
    puts("2 . Start a judger");
    puts("3 . Destory a judger");
    puts("4 . Check a judger");
    puts("5 . Edit a judger");
    puts("6 . Exit");
    puts("\n");
    printf("Your choice : ");
}

//? Choice 1
void createjudger()
{
    if (judgercnt == 4)
    {
        printf("Too many judgers!\n");
        return;
    }
    Judger *p = malloc(sizeof(Judger));
    void *name = malloc(0x30);
    printf("Please input judger name: ");
    read(0, name, 0x30);
    p->judgername = name;
    printf("Please input judger type: ");
    scanf("%d", &(p->type));
    judgerlist[judgercnt++] = p;
}

//? Choice 2
void startjudger()
{
    if (judgercnt == 0)
    {
        printf("You don't have any judger!\n");
        return;
    }
    printf("Let's break WQT's problem <Marigold -reality-!>\n");
    printf("(The problem's description is in attachment files!)\n");
    int res = mainjudger();
    if (res == 1)
    {
        printf("Accepted! Your flag is here!\n");
        system("cat /flag");
    }
    else if (res == 2)
    {
        printf("Time Limit Excceed!\nToo Slow? Maybe you need Pwntools!\n");
    }
    else
    {
        printf("Wrong Answer!\nToo much input? Maybe you need Pwntools!\n");
    }
}

//? Choice 3
void destoryjudger()
{
    printf("Please input the judger index you wanna destory: ");
    int index;
    scanf("%d", &index);
    if (index < judgercnt)
    {
        free(judgerlist[index]);
    }
    else
    {
        printf("Bad index!");
    }
}

//? Choice 4
void checkjudger()
{
    printf("Please input the judger index you wanna check: ");
    int index;
    scanf("%d", &index);
    if (index < judgercnt)
    {
        printf("Judger info: ");
        printf("%s", judgerlist[index]->judgername);
        printf("Judger type: %d\n", judgerlist[index]->type);
    }
    else
    {
        printf("Bad index!");
    }
}

//? Choice 5
void editjudger()
{
    printf("Please input the judger index you wanna edit: ");
    int index;
    scanf("%d", &index);
    if (index < judgercnt)
    {
        printf("Please new judger name: ");
        read(0, judgerlist[index]->judgername, 0x40);
    }
    else
    {
        printf("Bad index!");
    }
}

//? Main menu
void mainmenu()
{
    while (1)
    {
        showmenu();
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createjudger();
            break;
        case 2:
            startjudger();
            break;
        case 3:
            destoryjudger();
            break;
        case 4:
            checkjudger();
            break;
        case 5:
            editjudger();
            break;
        case 6:
            return;
        default:
            printf("Bad Choice!");
        }
    }
}

int main()
{
    printf("=============================\n");
    printf("Welcome to WQT Judger system!\n");
    printf("=============================\n");
    initfun();
    mainmenu();
    return 0;
}