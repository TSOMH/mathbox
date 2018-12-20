#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
typedef struct problem
{
    int num1;
    int num2;
    int num3;
}PROBLEM;
int score=0;
void MakeProblem(PROBLEM problems[]);
void PrintfProblem(PROBLEM problems[]);
void ModifyProblem(PROBLEM problems[]);
void RespondProblem(PROBLEM problems[]);
void GradeProblem(PROBLEM problems[]);
void CorrectProblem(PROBLEM problems[]);
void MyChallenge(void);
int main()
{
    int menu;
    PROBLEM problems[21];
    FILE *fp;
    
    do {
    printf("**********数学作业盒子**********\n" 
		   "1.自动生成作业题\n"
		   "2.修改作业题\n"
		   "3.学生作答\n"
           "4.作业评分\n"
		   "5.作业订正\n"
		   "6.我来挑战\n"
    	   "0.退出系统\n"
		   "提示：请输入数字序号选择对应的操作\n");
    scanf("%d",&menu);
    switch (menu)
    {
        case 1:
        	MakeProblem(problems);
        	PrintfProblem(problems);
        	printf("按任意键回到主菜单!\n");
        	getchar();
        	getchar();
        	break ;
        case 2:
        	ModifyProblem(problems);
        	printf("试题修改完毕，按任意键回到主菜单!\n");
        	getchar();
        	break ;
		case 3:
			getchar();
			RespondProblem(problems);
			printf("作答完毕，按任意键回到主菜单!\n");
        	getchar();
        	getchar();
        	break ;
		case 4:
			GradeProblem(problems);
			printf("按任意键回到主菜单!\n");
        	getchar();
        	getchar();
        	break ;
        case 5:
        	CorrectProblem(problems);
        	printf("订正完毕，按任意键回到主菜单!\n");
        	getchar();
        	getchar();
        	break ;
        case 6:
        	MyChallenge();
        	printf("按任意键回到主菜单!\n");
        	getchar();
        	getchar();
        	break ;
        case 0:
        	exit(0);
    }

    }while(1);
    return 0;
}



void MakeProblem(PROBLEM problems[])
{
    int i;
    srand(time(NULL));
    for(i=1;i<=20;i++)
    {
        problems[i].num1=rand()%19+1;
        problems[i].num2=(rand()%19+1)*pow(-1,rand()%2);
    }
}


void PrintfProblem(PROBLEM problems[])
{
    int i=1,n=1;
    for(i=1;i<=20;i++)
    {
        if(problems[i].num2>0)
			printf("第%d题:%d+%d= \n",n,problems[i].num1,problems[i].num2);
        else
			printf("第%d题:%d%d= \n",n,problems[i].num1,problems[i].num2);
        n++;
    }
}


void ModifyProblem(PROBLEM problems[])
{
    int i,n,flag=0;     //flag为正确试题数目 
    for(i=1;i<=20;i++)
    {
        if(problems[i].num2>=0)
		{
			flag++;
		}
        else
        	{
        		if(problems[i].num1+problems[i].num2>=0) flag++;	
			}
    }
    printf("还有%d道错题\n",20-flag);
    while(flag!=20)
    {
    printf("错误试题编号:");
    scanf("%d",&n);
    printf("正确试题:");
    scanf("%d%d",&problems[n].num1,&problems[n].num2);
    printf("试题答案:%d\n",problems[n].num1+problems[n].num2);
    flag++;
    printf("还有%d道错题\n",20-flag);
    }
}
void RespondProblem(PROBLEM problems[])
{
	int i;
	FILE *fp;
	for(i=1;i<=20;i++)
	{
		if(problems[i].num2>0) printf("第%d题:%d+%d=",i,problems[i].num1,problems[i].num2);
		else printf("第%d题:%d%d=",i,problems[i].num1,problems[i].num2);
		scanf(" %d",&problems[i].num3);
	}
	for(i=1;i<=20;i++)
	{
		if(problems[i].num2>=0)
		{
			printf("第%d题:%d+%d=%d\n",i,problems[i].num1,problems[i].num2,problems[i].num3);
		}
		else 
		{
			printf("第%d题:%d%d=%d\n",i,problems[i].num1,problems[i].num2,problems[i].num3);
		}
	}
	if((fp=fopen("C:\\Users\\Mr.XU\\Desktop\\data.txt","w"))==NULL)
	{
		printf("Failure to open data.txt!\n");
		exit(0);
	}
	for(i=1;i<=20;i++)
	{
		if(problems[i].num2>=0) fprintf(fp,"%d+%d=%d\n",problems[i].num1,problems[i].num2,problems[i].num3);
		else fprintf(fp,"%d%d=%d\n",problems[i].num1,problems[i].num2,problems[i].num3);
	}
	fclose(fp);
}
void GradeProblem(PROBLEM problems[])
{
	int i;
	for(i=1;i<=20;i++)
	{
		if(problems[i].num2>=0)
		{
			printf("%d+%d=%d",problems[i].num1,problems[i].num2,problems[i].num3);
		}
		else
			printf("%d%d=%d",problems[i].num1,problems[i].num2,problems[i].num3);
		if(problems[i].num1+problems[i].num2==problems[i].num3)
		{
			printf("  Yes\n");
			score=score+5;
		}
		else
			printf("  No\n");
	}
	printf("score=%d\n",score);
}
void CorrectProblem(PROBLEM problems[])
{
	int i;
	if(score==100)
	{
		printf("恭喜你，全答对拉!\n");
	}
	else
	{
		for(i=1;i<=20;i++)
		{
			if(problems[i].num1+problems[i].num2!=problems[i].num3)
			{
				do{
					if(problems[i].num2>=0)
					{
						printf("%d+%d=",problems[i].num1,problems[i].num2);
						scanf("%d",&problems[i].num3);
					}
					else
					{
						printf("%d%d=",problems[i].num1,problems[i].num2);
						scanf("%d",&problems[i].num3);
					}
				}while(problems[i].num1+problems[i].num2!=problems[i].num3);
			}
		}		
	}
	printf("恭喜你，全答对啦!\n");
	
}
void MyChallenge(void)
{
	int a,b,c,d;
	char m,n;
	srand(time(NULL));
	a=rand()%19+1;
	b=rand()%19+1;
	c=rand()%19+1;
	printf("%d",a);
	if(b>0) printf("+%d",b);
	else printf("%d",b);
	if(c>0) printf("+%d=",c);
	else printf("%d=",c);
	
	scanf("%d",&d);
	if(a+b+c==d) printf("恭喜你，答对啦!******\n");
	else printf("很遗憾，你答错了，加油!\n");	
}

