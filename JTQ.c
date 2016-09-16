#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>

int point=0,count1=0,count2=0,count3=0,count4=0,k;

typedef struct question
{
   char quest[200];
   char op1[40];
   char op2[40];
   char op3[40];
   char op4[40];
   int correct_ans;
   int input_ans;
   struct question *below;
   struct question *below1;
}question;
typedef struct category
{
   char category[20];
   struct category *next;
   struct question *down;
}category;
typedef struct level
{
  char data[20];
  struct level *next;
  struct category *downC;
  struct category *downSC;
  struct category *downSP;
  struct category *downH;
  struct category *downCA;
}level;
void fun(question *ptrQ, FILE *x,long j)
{ //FILE *x;
 int i;
   char c;
    i=0;
   // x=fopen("C:\\SPORTS4.TXT","r");
    if(x==NULL)
        printf("Error");

    fseek(x,j,SEEK_SET);
    while((c=getc(x))!='\n')
    {
      ptrQ->quest[i]=c;
      i++;
    }
    ptrQ->quest[i]='\0';
    i=0;
    while((c=getc(x))!='\n')
    {
      ptrQ->op1[i]=c;
      i++;
    }
    ptrQ->op1[i]='\0';
    i=0;
    while((c=getc(x))!='\n')
    {
      ptrQ->op2[i]=c;
      i++;
    }
    ptrQ->op2[i]='\0';
    i=0;
    while((c=getc(x))!='\n')
    {
      ptrQ->op3[i]=c;
      i++;
    }
    ptrQ->op3[i]='\0';
    i=0;
    while((c=getc(x))!='\n')
    {
      ptrQ->op4[i]=c;
      i++;
    }
    ptrQ->op4[i]='\0';
}


//LIFELINES

void double_dip(question *read)
 {
 int ans;
 int i=0;
 printf("\n");
  while(i<2)
  {
   printf("\n\t Enter your %d answer : ",i+1);
   scanf("%d",&ans);
   read->input_ans=ans;
   printf("\n");
   if(ans==read->correct_ans)
    {
            printf("\t   Congratulations! Your answer is CORRECT \n\n");
            getch();
            point=point+10;
            break;
    }
    else
    {
            printf("\t    Sorry,Your Answer was wrong \n");
            if(i==1)
             {
              point=point-5;
              printf("\t   Your points have been reduced by 5 \n  ");
              getch();
             }
             i++;
    }
  }
 return;
 }

 void expertAdvice(question *read)
{
int i,j,ans;
printf("\n\n\t ACCORDING TO THE EXPERTS, THE CORRECT ANSWER is : ");
for(i=0;i<10;i++)
{
for(j=0;j<9;j++)
{
Sleep(10);
printf("%d",j);
Sleep(10);
printf("\b");
}
}
printf("%d\n",read->correct_ans);
printf("\n\t\t Enter your answer : ");
                     scanf("%d",&ans);
                     read->input_ans=ans;
                     printf("\n");
                     if(ans!=read->correct_ans)
                     {
                        printf("   \t Sorry,Your Answer was WRONG \n");
                        point=point-5;
                        printf("   \t Your points have been reduced by 5 \n ");
                        getch();
                     }
                     else
                     {
                        printf("   \t Congratulations! Your answer is CORRECT \n\n");
                        getch();
                        point=point+10;
                     }
                     return;
}

void skip(question *read)
{
    read=read->below;
    printf("\n");
    return;
}

void saviour()
{
    int mo;
    printf("\n\n\t\t Enter your answer : ");
    scanf("%d",&mo);
    printf("\n\n\tCongrats, Your points are increased by 10\n");
    getch();
    point=point+10;
    return;
}

//LIFELINE UTILITY

void lifeline(question *read)
{
    int line;
    printf("\n\n\t Enter the Lifeline which you want to choose :-");
                        printf("\n\t 1. Double Dip");
                        printf("\n\t 2. Expert Advice");
                        printf("\n\t 3. Skip");
                        printf("\n\t 4. Saviour");
                        printf("\n\n\t Enter here : ");
                        scanf("%d",&line);
                        if(line==1)
                        {
                            if(count1>=1)
                            {
                             printf("\n\t Sorry you can't use this Lifeline Any more,\n\t Please try some other Lifeline");
                             getch();
                             lifeline(read);
                            }
                            else
                            {
                                printf("\n\t *You have chosen Double Dip Lifeline* ");
                                getch();
                              double_dip(read);
                              count1++;
                            }
                        }
                        if(line==2)
                        {
                            if(count2>=1)
                            {
                             printf("\n\t Sorry you can't use this Lifeline Any more,\n\t Please try some other Lifeline");
                             getch();
                             lifeline(read);
                            }
                            else
                            {
                                printf("\n\t *You have chosen Expert Advice Lifeline* ");
                                getch();
                              expertAdvice(read);
                              count2++;
                            }
                        }
                        if(line==3)
                        {
                            if(count3>=1)
                            {
                             printf("\n\t Sorry you can't use this Lifeline Any more,\n\t Please try some other Lifeline");
                             getch();
                             lifeline(read);
                            }
                            else
                            {
                              printf("\n\t *You have chosen Skip Lifeline* ");
                              getch();
                              skip(read);
                              count3++;
                            }
                        }
                        if(line==4)
                        {
                            if(count4>=1)
                            {
                             printf("\n\t Sorry you can't use this Lifeline Any more,\n\t Please try some other Lifeline");
                             getch();
                             lifeline(read);
                            }
                            else
                            {
                              printf("\n\t *You have chosen Saviour Lifeline* ");
                              getch();
                              saviour();
                              count4++;
                            }
                        }
                        else
                        {
                            if(line>4 || line<=0)
                            {
                            printf("\n\t Alert! Please Enter Valid Lifeline");
                            getch();
                            lifeline(read);
                            }
                        }

                        return;
}
question *top=NULL;
//UNDO PROGRAM USING STACKS

  question* push(question *tempo, question *top)
   {
       if(top==NULL)
       {
          top=tempo;
          top->below1=NULL;
       }
       else
       {
           tempo->below1=top;
           top=tempo;
       }
      // printf("%d\n",top);
    return top;
   }

   void pop(question *top)
   {
       char c,ch;
       int answer;
       if(top==NULL)
       {
           printf("\n\t  Sorry, you can't undo further");
           getch();
           printf("\n\n\t    Your points at the end of LEVEL %d is %d ",k+1,point);
             if(point<0)
              {
               printf("\n\t  You cannot Proceed to Next Level \n");
               getch();
               exit(0);
              }
              else
              {
                if(k==3)
                    printf("\n\n\t CONGRATULATIONS! LEVEL ENDS :) ");
                else
                    {
                    printf("\n\n\t  CONGRATULATIONS! You Proceed into Next Level ");
                    getch();
                    }
              }
           return;
       }
         if(top!=NULL)
         {
             ch=0;
             if(top->input_ans==top->correct_ans)
             {
                 point=point-10;
             }
              else
              {
                  if(top->input_ans==0)
                    point=point+0;
                  else
                  point=point+5;
              }

                    printf("\n\n");
                    puts(top->quest);
                    puts(top->op1);
                    puts(top->op2);
                    puts(top->op3);
                    puts(top->op4);
                    printf("\n\t    Do you want any LifeLine (Y/N) : ");
                    ch=getch();
                    printf("%c",ch);
                    if((ch=='y' || ch=='Y') && (count1==0 || count2==0 || count3==0 || count4==0))
                    {
                        lifeline(top);
                    }

                        else
                         {
                         if(ch=='y'||ch=='Y')
                         printf("\n\n\t Sorry You are not Left with any Lifelines\n");
                         printf("\n\n\t\t Enter your answer : ");
                         scanf("%d",&answer);
                         printf("\n");
                         if(answer!=top->correct_ans)
                         {
                          printf("   \t Sorry,Your Answer was WRONG \n");
                          point=point-5;
                          printf("   \t Your points have been reduced by 5 \n ");
                          getch();
                         }
                     else
                     {
                        printf("   \t Congratulations! Your answer is CORRECT \n\n");
                        getch();
                        point=point+10;
                     }
                    }
                    top=top->below1;
         }
         printf("\n\t Do you further want to Undo previous questions(Y/N) : ");
         c=getch();
         printf("%c",c);
         if(c=='y'|| c=='Y')
            pop(top);
            else
            {
              printf("\n\n\t    Your points at the end of LEVEL %d is %d ",k+1,point);
             if(point<0)
              {
               printf("\n\t  You cannot Proceed to Next Level \n");
               getch();
               exit(0);
              }
              else
              {
                if(k==3)
                {
                    printf("\n\n\t CONGRATULATIONS! LEVEL ENDS :) ");
                    getch();
                }
                else
                    {
                    printf("\n\n\t  CONGRATULATIONS! You Proceed into Next Level ");
                    //getch();
                    }
              }
            }
         return;

   }

void main()
{
    char password[20],user_name[20],operator1[20],coupon[10],coupon1[10];
    int i,j,n,answer,line,counter=0,counter1=0,mobile;
    static long f;
    char life,undo,c='y';
    FILE *x,*p;
    question *ptrQ,*startQ=NULL,*currentQ=NULL,*read=NULL;
    category *ptrSP,*ptrC,*ptrSC,*ptrH,*ptrCA,*start_cat=NULL,*current_cat=NULL;
    level *ptrL1,*ptrL2,*ptrL3,*ptrL4, *start_level=NULL,*current_level=NULL,*temp=NULL;

    while(c=='y'||c=='Y')
    {
     printf("\n\t\t\t Welcome To Jaypee Talent Quiz");
     printf("\n\n\t\t\t\tLOGIN ID Page");
     printf("\n\n\n\n\n\n\t\t   Enter the username : ");
     scanf("%s",user_name);
     printf("\n\n\t\t   Enter the password : ");
     for(i=0;i<6;i++)
      {
       password[i]=(char)getch();
       printf("*");
      }
       password[6]='\0';
       if(strcmp(user_name,"JTQ")==0 && strcmp(password,"shivam")==0 || strcmp(user_name,"KBC")==0 && strcmp(password,"jtqkbc")==0)
        {
            printf("\n\n\n\t\t   You are Logged in Successfully");
            c='n';
            getch();
            system("cls");
        }
        else
       {
        c='y';
        counter++;
        if(counter==3)
         {
          printf("\n\n\n\t\t You have reached Maximum Login Limit.");
          printf("\n\n\t\t     Please Try Again Later");
          getch();
          exit(0);
         }
          printf("\n\n\n\t\t Something went wrong, Please try again.");
          getch();
          system("cls");
       }
    }


    //getch();

    printf("\t\t   INSTRUCTIONS FOR THE JTQ  ");
    printf("\n\n  1. This Quiz consists of 4 Levels Each for 5 Different categories. \n     Each Level contains 5 questions");
    printf("\n  2. For each Level you can select either of the 5 categories to proceed");
    printf("\n  3. For each correct answer you will be awarded 10 points ");
    printf("\n  4. For each incorrect answer your points will be reduced by 5 ");
    printf("\n  5. For your convenience we have provided you with 4 Lifelines :- ");
    printf("\n  a. DOUBLE DIP - In this Lifeline you'll get 2 attempts to correctly \n\t    answer the question");
    printf("\n  b. EXPERT ADVICE - In this Lifeline our Expert will help you with the question");
    printf("\n  c. SKIP - In this Lifeline you can skip the question for which you'll \n\t    not be awarded/deducted any points ");
    printf("\n  d. SAVIOUR - In this Lifeline you'll be awarded 10 points irrespective of\n\t  your given answer");
    printf("\n  6. UNDO OPTION - In this quiz you'll get a option to undo your answers at\n\t    the end of each Level");
    printf("\n  7. At the End of the Game, the points will be converted into an amount by \n\t   which you can recharge your phone");
    printf("\n\n  NOTE : 1. You can use each Lifeline only once ");
    printf("\n         2. Throughout the game you can use the UNDO option only \n       \ttwice at the end of each Level");
    getch();




         ptrL1=(level*)malloc(sizeof(level));   //level 1 creation
         strcpy(ptrL1->data,"LEVEL 1");
         ptrL1->next=NULL;

        ptrSP=(category*)malloc(sizeof(category));
        strcpy(ptrSP->category,"SPORTS");
        ptrL1->downSP=ptrSP;
        start_cat=ptrSP;
        current_cat=ptrSP;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           p=fopen("C:\\SPORTS1.TXT","r");
           fun(ptrQ,p,f);
           if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=2;
           }
           if(j==3)
           {
               ptrQ->correct_ans=2;
           }
           if(j==4)
           {
               ptrQ->correct_ans=1;
           }
           f=ftell(p);

           //printf("\n\n");
           //strcpy();

           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(p);
        current_cat->down=startQ;
        f=0;
        //current_level->downSP=ptrSP;       //1st line created

        ptrC=(category*)malloc(sizeof(category));
        strcpy(ptrC->category,"CINEMA");
        ptrL1->downC=ptrC;
        current_cat->next=ptrC;
        current_cat=ptrC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CINEMA1.TXT","r");
           fun(ptrQ,x,f);
           if(j==0)
           {
               ptrQ->correct_ans=2;
           }
           if(j==1)
           {
               ptrQ->correct_ans=4;
           }
           if(j==2)
           {
               ptrQ->correct_ans=2;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=4;
           }
           f=ftell(x);
//           strcpy();
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;  //2nd line created


        ptrH=(category*)malloc(sizeof(category));
        strcpy(ptrH->category,"HISTORY");
        ptrL1->downH=ptrH;
        current_cat->next=ptrH;
        current_cat=ptrH;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\HISTORY1.TXT","r");
           fun(ptrQ,x,f);

         //  strcpy();
         if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=4;
           }
           if(j==2)
           {
               ptrQ->correct_ans=3;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=4;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //3rd line created


        ptrSC=(category*)malloc(sizeof(category));
        strcpy(ptrSC->category,"SCIENCE");
        ptrL1->downSC=ptrSC;
        current_cat->next=ptrSC;
        current_cat=ptrSC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\SCIENCE1.TXT","r");
           fun(ptrQ,x,f);

          // strcpy();
          if(j==0)
           {
               ptrQ->correct_ans=4;
           }
           if(j==1)
           {
               ptrQ->correct_ans=1;
           }
           if(j==2)
           {
               ptrQ->correct_ans=3;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=1;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //4th line created


        ptrCA=(category*)malloc(sizeof(category));
        strcpy(ptrCA->category,"CURRENT AFFAIRS");
        ptrL1->downCA=ptrCA;
        current_cat->next=ptrCA;
        current_cat=ptrCA;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CURRENT1.TXT","r");
           fun(ptrQ,x,f);

          // strcpy();
          if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=3;
           }
           if(j==3)
           {
               ptrQ->correct_ans=2;
           }
           if(j==4)
           {
               ptrQ->correct_ans=4;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
               current_cat->down=startQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
          //5th line created


        //1ST LEVEL CREATED

         startQ=NULL;
         currentQ=NULL;
         start_cat=NULL;
         current_cat=NULL;
         ptrL2=(level*)malloc(sizeof(level));   //level 2 creation
         strcpy(ptrL2->data,"LEVEL 2");
         ptrL2->next=NULL;
         ptrL1->next=ptrL2;

        ptrSP=(category*)malloc(sizeof(category));
        strcpy(ptrSP->category,"SPORTS");
        ptrL2->downSP=ptrSP;
        start_cat=ptrSP;
        current_cat=ptrSP;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\SPORTS2.TXT","r");
           fun(ptrQ,x,f);
           f=ftell(x);

//           strcpy();
if(j==0)
           {
               ptrQ->correct_ans=4;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=3;
           }
           if(j==3)
           {
               ptrQ->correct_ans=4;
           }
           if(j==4)
           {
               ptrQ->correct_ans=3;
           }
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;
        //current_level->downSP->down=startQ;       //1st line created

        ptrC=(category*)malloc(sizeof(category));
        strcpy(ptrC->category,"CINEMA");
        ptrL2->downC=ptrC;
        current_cat->next=ptrC;
        current_cat=ptrC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CINEMA2.TXT","r");
           fun(ptrQ,x,f);

          // strcpy();
          if(j==0)
           {
               ptrQ->correct_ans=2;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=3;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=1;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;  //2nd line created


        ptrH=(category*)malloc(sizeof(category));
        strcpy(ptrH->category,"HISTORY");
        ptrL2->downH=ptrH;
        current_cat->next=ptrH;
        current_cat=ptrH;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\HISTORY2.TXT","r");
           fun(ptrQ,x,f);

         //  strcpy();
         if(j==0)
           {
               ptrQ->correct_ans=2;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=2;
           }
           if(j==3)
           {
               ptrQ->correct_ans=2;
           }
           if(j==4)
           {
               ptrQ->correct_ans=3;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //3rd line created


        ptrSC=(category*)malloc(sizeof(category));
        strcpy(ptrSC->category,"SCIENCE");
        ptrL2->downSC=ptrSC;
        current_cat->next=ptrSC;
        current_cat=ptrSC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\SCIENCE2.TXT","r");
           fun(ptrQ,x,f);

          // strcpy();
          if(j==0)
           {
               ptrQ->correct_ans=1;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=1;
           }
           if(j==3)
           {
               ptrQ->correct_ans=4;
           }
           if(j==4)
           {
               ptrQ->correct_ans=1;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //4th line created


        ptrCA=(category*)malloc(sizeof(category));
        strcpy(ptrCA->category,"CURRENT AFFAIRS");
        ptrL2->downCA=ptrCA;
        current_cat->next=ptrCA;
        current_cat=ptrCA;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CURRENT2.TXT","r");
           fun(ptrQ,x,f);

        //   strcpy();
        if(j==0)
           {
               ptrQ->correct_ans=4;
           }
           if(j==1)
           {
               ptrQ->correct_ans=3;
           }
           if(j==2)
           {
               ptrQ->correct_ans=2;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=2;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;  //5th line created

       //2ND LEVEL CREATED


         startQ=NULL;
         currentQ=NULL;
         start_cat=NULL;
         current_cat=NULL;
         ptrL3=(level*)malloc(sizeof(level));   //level 3 creation
         strcpy(ptrL3->data,"LEVEL 3");
         ptrL3->next=NULL;
         ptrL2->next=ptrL3;

        ptrSP=(category*)malloc(sizeof(category));
        strcpy(ptrSP->category,"SPORTS");
        ptrL3->downSP=ptrSP;
        start_cat=ptrSP;
        current_cat=ptrSP;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\SPORTS3.TXT","r");
           fun(ptrQ,x,f);

         //  strcpy();
         if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=3;
           }
           if(j==2)
           {
               ptrQ->correct_ans=1;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=4;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;
        //current_level->downSP->down=startQ;       //1st line created

        ptrC=(category*)malloc(sizeof(category));
        strcpy(ptrC->category,"CINEMA");
        ptrL3->downC=ptrC;
        current_cat->next=ptrC;
        current_cat=ptrC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CINEMA3.TXT","r");
           fun(ptrQ,x,f);

        //   strcpy();
        if(j==0)
           {
               ptrQ->correct_ans=2;
           }
           if(j==1)
           {
               ptrQ->correct_ans=1;
           }
           if(j==2)
           {
               ptrQ->correct_ans=1;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=2;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;  //2nd line created


        ptrH=(category*)malloc(sizeof(category));
        strcpy(ptrH->category,"HISTORY");
        ptrL3->downH=ptrH;
        current_cat->next=ptrH;
        current_cat=ptrH;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\HISTORY3.TXT","r");
           fun(ptrQ,x,f);

        //   strcpy();
        if(j==0)
           {
               ptrQ->correct_ans=4;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=1;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=1;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //3rd line created


        ptrSC=(category*)malloc(sizeof(category));
        strcpy(ptrSC->category,"SCIENCE");
        ptrL3->downSC=ptrSC;
        current_cat->next=ptrSC;
        current_cat=ptrSC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\SCIENCE3.TXT","r");
           fun(ptrQ,x,f);

        //   strcpy();
        if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=1;
           }
           if(j==3)
           {
               ptrQ->correct_ans=2;
           }
           if(j==4)
           {
               ptrQ->correct_ans=2;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //4th line created


        ptrCA=(category*)malloc(sizeof(category));
        strcpy(ptrCA->category,"CURRENT AFFAIRS");
        ptrL3->downCA=ptrCA;
        current_cat->next=ptrCA;
        current_cat=ptrCA;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CURRENT3.TXT","r");
           fun(ptrQ,x,f);

      //     strcpy();
           if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=3;
           }
           if(j==2)
           {
               ptrQ->correct_ans=4;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=3;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;  //5th line created

       //3RD LEVEL CREATED

         startQ=NULL;
         currentQ=NULL;
         start_cat=NULL;
         current_cat=NULL;
         ptrL4=(level*)malloc(sizeof(level));   //level 1 creation
         strcpy(ptrL4->data,"LEVEL 4");
         ptrL4->next=NULL;
         ptrL3->next=ptrL4;

        ptrSP=(category*)malloc(sizeof(category));
        strcpy(ptrSP->category,"SPORTS");
        //ptrL3->next=ptrL4;
        ptrL4->downSP=ptrSP;
        start_cat=ptrSP;
        current_cat=ptrSP;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\SPORTS4.TXT","r");
           fun(ptrQ,x,f);

//           strcpy();
        if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=2;
           }
           if(j==3)
           {
               ptrQ->correct_ans=2;
           }
           if(j==4)
           {
               ptrQ->correct_ans=3;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;
        //current_level->downSP->down=startQ;       //1st line created

        ptrC=(category*)malloc(sizeof(category));
        strcpy(ptrC->category,"CINEMA");
        ptrL4->downC=ptrC;
        current_cat->next=ptrC;
        current_cat=ptrC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CINEMA4.TXT","r");
           fun(ptrQ,x,f);

       //    strcpy();
       if(j==0)
           {
               ptrQ->correct_ans=1;
           }
           if(j==1)
           {
               ptrQ->correct_ans=2;
           }
           if(j==2)
           {
               ptrQ->correct_ans=2;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=2;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;  //2nd line created


        ptrH=(category*)malloc(sizeof(category));
        strcpy(ptrH->category,"HISTORY");
        ptrL4->downH=ptrH;
        current_cat->next=ptrH;
        current_cat=ptrH;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\HISTORY4.TXT","r");
           fun(ptrQ,x,f);

       //    strcpy();
           if(j==0)
           {
               ptrQ->correct_ans=1;
           }
           if(j==1)
           {
               ptrQ->correct_ans=3;
           }
           if(j==2)
           {
               ptrQ->correct_ans=2;
           }
           if(j==3)
           {
               ptrQ->correct_ans=1;
           }
           if(j==4)
           {
               ptrQ->correct_ans=3;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //3rd line created


        ptrSC=(category*)malloc(sizeof(category));
        strcpy(ptrSC->category,"SCIENCE");
        ptrL4->downSC=ptrSC;
        current_cat->next=ptrSC;
        current_cat=ptrSC;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\SCIENCE4.TXT","r");
           fun(ptrQ,x,f);

        //   strcpy();
        if(j==0)
           {
               ptrQ->correct_ans=4;
           }
           if(j==1)
           {
               ptrQ->correct_ans=4;
           }
           if(j==2)
           {
               ptrQ->correct_ans=3;
           }
           if(j==3)
           {
               ptrQ->correct_ans=1;
           }
           if(j==4)
           {
               ptrQ->correct_ans=1;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ; //4th line created


        ptrCA=(category*)malloc(sizeof(category));
        strcpy(ptrCA->category,"CURRENT AFFAIRS");
        ptrL4->downCA=ptrCA;
        current_cat->next=ptrCA;
        current_cat=ptrCA;
        startQ=NULL;
        currentQ=NULL;
        for(j=0;j<5;j++)
        {
           ptrQ=(question*)malloc(sizeof(question));
           ptrQ->below=NULL;
           x=fopen("C:\\CURRENT4.TXT","r");
           fun(ptrQ,x,f);

        //   strcpy();
        if(j==0)
           {
               ptrQ->correct_ans=3;
           }
           if(j==1)
           {
               ptrQ->correct_ans=4;
           }
           if(j==2)
           {
               ptrQ->correct_ans=3;
           }
           if(j==3)
           {
               ptrQ->correct_ans=3;
           }
           if(j==4)
           {
               ptrQ->correct_ans=3;
           }
           f=ftell(x);
           if(startQ==NULL)
           {

               startQ=ptrQ;
               currentQ=ptrQ;
           }
           else
           {
               currentQ->below=ptrQ;
               currentQ=ptrQ;
           }
        }
        fclose(x);
        f=0;
        current_cat->down=startQ;    //5th line created



        //4TH LEVEL COMPLETED

//printf("Hello Welcome to the Jaypee Talent Quiz\n");
     system("cls");
     printf("\n\n\n\n\n\n\n\n\t\t WELCOME TO JAYPEE TALENT QUIZ HOT SEAT");
     system("KBC.mp3");
     getch();
     system("cls");
     temp=ptrL1;
     for(k=0;k<4;k++)
     {
         top=NULL;
         read=NULL;
         system("cls");
         printf("\t\t\t Welcome to LEVEl %d",k+1);
         printf("\n\n\t Enter your choice of category in level %d",k+1);
         printf("\n\n\t1. SPORTS");
         printf("\n\t2. CINEMA");
         printf("\n\t3. HISTORY");
         printf("\n\t4. SCIENCE");
         printf("\n\t5. CURRENT AFFAIRS");
         printf("\n\n\t CATEGORY:- ");
         scanf("%d",&n);
         system("cls");
         switch(n)
         {
         case 1:
                 {
                 read=temp->downSP->down;
                 printf("\n\t\t LEVEL %d -> Category:- SPORTS",k+1);
                 printf("\n\n");
                 while(read!=NULL)
                 {
                    life=0;
                    printf("\n");
                    puts(read->quest);
                    puts(read->op1);
                    puts(read->op2);
                    puts(read->op3);
                    puts(read->op4);
                    printf("\n\t    Do you want any LifeLine (Y/N) : ");
                    life=getch();
                    printf("%c",life);
                    if((life=='y' || life=='Y') && (count1==0 || count2==0 || count3==0 || count4==0))
                    {
                        lifeline(read);
                    }

                        else
                         {
                         if(life=='y'||life=='Y')
                         printf("\n\n\t Sorry You are not Left with any Lifelines\n");
                         printf("\n\n\t\t Enter your answer : ");
                         scanf("%d",&answer);
                         read->input_ans=answer;
                         printf("\n");
                         if(answer!=read->correct_ans)
                         {
                          printf("   \t Sorry,Your Answer was WRONG \n");
                          point=point-5;
                          printf("   \t Your points have been reduced by 5 \n ");
                          getch();
                         }
                        else
                         {
                          printf("   \t Congratulations! Your answer is CORRECT \n\n");
                          getch();
                          point=point+10;
                         }
                        }
                   // printf("%d\n",read);
                     top=push(read,top);
                    //if(read!=NULL)
                    //printf("%d",read);
                    //getch();
                    read=read->below;
                    //if(read==NULL)
                      //  printf("Error");

                 }
                break;

            }
         case 2:
            {
              read=temp->downC->down;
              printf("\n\t\t LEVEL %d -> Category:- CINEMA",k+1);
                 printf("\n\n");
                while(read!=NULL)
                {
                    life=0;
                    printf("\n");
                    puts(read->quest);
                    puts(read->op1);
                    puts(read->op2);
                    puts(read->op3);
                    puts(read->op4);
                    printf("\n\t    Do you want any LifeLine (Y/N) : ");
                    life=getch();
                    printf("%c",life);
                    if((life=='y' || life=='Y') && (count1==0 || count2==0 || count3==0 || count4==0))
                    {
                        lifeline(read);
                    }
                    else
                    {
                        if(life=='y'||life=='Y')
                        printf("\n\n\t Sorry You are not Left with any Lifelines\n");
                     printf("\n\n\t\t Enter your answer : ");
                     scanf("%d",&answer);
                     read->input_ans=answer;
                     printf("\n");
                     if(answer!=read->correct_ans)
                     {
                        printf("   \t Sorry,Your Answer was WRONG \n");
                        point=point-5;
                        printf("   \t Your points have been reduced by 5 \n ");
                        getch();
                     }
                     else
                     {
                        printf("   \t Congratulations! Your answer is CORRECT \n\n");
                        getch();
                        point=point+10;
                     }
                    }
                    top=push(read,top);
                    read=read->below;
            }
            break;
         }
         case 3:
            {
                read=temp->downH->down;
                printf("\n\t\t LEVEL %d -> Category:- HISTORY",k+1);
                 printf("\n\n");
                while(read!=NULL)
                {
                    life=0;
                    printf("\n");
                    puts(read->quest);
                    puts(read->op1);
                    puts(read->op2);
                    puts(read->op3);
                    puts(read->op4);
                    printf("\n\t    Do you want any LifeLine (Y/N) : ");
                    life=getch();
                    printf("%c",life);
                    if((life=='y' || life=='Y') && (count1==0 || count2==0 || count3==0 || count4==0))
                    {
                        lifeline(read);
                    }
                    else
                    {
                        if(life=='y'||life=='Y')
                        printf("\n\n\t Sorry You are not Left with any Lifelines\n");
                     printf("\n\n\t\t Enter your answer : ");
                     scanf("%d",&answer);
                     read->input_ans=answer;
                     printf("\n");
                     if(answer!=read->correct_ans)
                     {
                        printf("   \t Sorry,Your Answer was WRONG \n");
                        point=point-5;
                        printf("   \t Your points have been reduced by 5 \n ");
                        getch();
                     }
                     else
                     {
                        printf("   \t Congratulations! Your answer is CORRECT \n\n");
                        getch();
                        point=point+10;
                     }
                    }
                    top=push(read,top);
                    read=read->below;
            }
            break;
     }
         case 4:
            {
                read=temp->downSC->down;
                printf("\n\t\t LEVEL %d -> Category:- SCIENCE",k+1);
                 printf("\n\n");
                while(read!=NULL)
                {
                    life=0;
                    printf("\n");
                    puts(read->quest);
                    puts(read->op1);
                    puts(read->op2);
                    puts(read->op3);
                    puts(read->op4);
                    printf("\n\t    Do you want any LifeLine (Y/N) : ");
                    life=getch();
                    printf("%c",life);
                    if((life=='y' || life=='Y') && (count1==0 || count2==0 || count3==0 || count4==0))
                    {
                        lifeline(read);
                    }
                    else
                    {
                        if(life=='y'||life=='Y')
                        printf("\n\n\t Sorry You are not Left with any Lifelines\n");
                     printf("\n\n\t\t Enter your answer : ");
                     scanf("%d",&answer);
                     read->input_ans=answer;
                     printf("\n");
                     if(answer!=read->correct_ans)
                     {
                        printf("   \t Sorry,Your Answer was WRONG \n");
                        point=point-5;
                        printf("   \t Your points have been reduced by 5 \n ");
                        getch();
                     }
                     else
                     {
                        printf("   \t Congratulations! Your answer is CORRECT \n\n");
                        getch();
                        point=point+10;
                     }
                    }
                    top=push(read,top);
                   read=read->below;
            }
            break;
            }
         case 5:
            { //co++;
                read=temp->downCA->down;
                printf("\n\t\t LEVEL %d -> Category:- CURRENT AFFAIRS ",k+1);
                printf("\n\n");
                while(read!=NULL)
                {
                    life=0;
                    printf("\n");
                    puts(read->quest);
                    puts(read->op1);
                    puts(read->op2);
                    puts(read->op3);
                    puts(read->op4);
                    printf("\n\t    Do you want any LifeLine (Y/N) : ");
                    life=getch();
                    printf("%c",life);
                    if((life=='y' || life=='Y') && (count1==0 || count2==0 || count3==0 || count4==0))
                    {
                        lifeline(read);
                    }
                    else
                    {
                        if(life=='y'||life=='Y')
                        printf("\n\n\t Sorry You are not Left with any Lifelines\n");
                     printf("\n\n\t\t Enter your answer : ");
                     scanf("%d",&answer);
                     read->input_ans=answer;
                     printf("\n");
                     if(answer!=read->correct_ans)
                     {
                        printf("   \t Sorry,Your Answer was WRONG \n");
                        point=point-5;
                        printf("   \t Your points have been reduced by 5 \n ");
                        getch();
                     }
                     else
                     {
                        printf("   \t Congratulations! Your answer is CORRECT \n\n");
                        getch();
                        point=point+10;
                     }
                    }
                 top=push(read,top);
                 read=read->below;
            }
            break;
            }
         }
         //printf("\n\n%d",top);
         printf("\n\t  Do you want to Undo the previous questions (Y/N) : ");
         undo=getch();
         printf("%c",undo);

         if(undo=='y' || undo=='Y')
            {
                counter1++;
              if(counter1>2)
              {
               undo='n';
               printf("\n\n\t   Sorry! You don't have any undo options left");
               getch();
               printf("\n\n\t    Your points at the end of LEVEL %d is %d ",k+1,point);
              if(point<0)
                {
               printf("\n\t  You cannot Proceed to Next Level \n");
               getch();
               exit(0);
                }
             else
              {
                   if(k==3)
                    {printf("\n\n\t CONGRATULATIONS! LEVEL ENDS :) ");
                       getch();
                       }
                   else
                    {
                    printf("\n\n\t  CONGRATULATIONS! You Proceed into Next Level ");
                    getch();
                    }
               }

              }
              else
              {
                pop(top);
            // printf("\nPopped");
              getch();
              }
            }
            else
            {
             printf("\n\n\t    Your points at the end of LEVEL %d is %d ",k+1,point);
             if(point<0)
              {
               printf("\n\t  You cannot Proceed to Next Level \n");
               getch();
               exit(0);
              }
             else
              {
                if(k==3)
                  {
                    printf("\n\n\t CONGRATULATIONS! LEVEL ENDS :) ");
                    getch();
                  }
                else
                    {
                    printf("\n\n\t  CONGRATULATIONS! You Proceed into Next Level ");
                    getch();
                    }
              }
            }

         temp=temp->next;
     }

 //RECHARGE PORTAL
system("KBC.mp3");
system("cls");
printf("\t\t\t  RECHARGE PORTAL");
printf("\n\n\t YOUR TOTAL POINTS ARE %d ",point);
printf("\n\n\t The Net Amount after Conversion of points is Rs %d ",point);
undo=0;
printf("\n\n\t Do You want to recharge your phone (Y/N) : ");
undo=getch();
printf("%c",undo);
if(undo=='Y'||undo=='y')
{
    strcpy(coupon,"CV10B2");
    printf("\n\n\t Enter your Mobile no. :- ");
    scanf("%d",&mobile);
    printf("\n\t Enter your operator : ");
    scanf("%s",operator1);
    printf("\n\t There is a special DEAL waiting only for you in which \n\t you will get an additional NET PACK recharge of 1GB");
    printf("\n\n\t Do you want to avail this offer (Y/N) ? ");
    undo=0;
    undo=getch();
    printf("%c",undo);
    if(undo=='Y'||undo=='y')
    {
        printf("\n\n\t Enter the coupon code \"\CV10B2\"\ to avail this offer : ");
        scanf("%s",coupon1);
        if(strcmp(coupon,coupon1)==0)
        {
            printf("\n\t PLEASE WAIT.... ");
            for(i=0;i<35;i++)
            {
                printf("\\");
                printf("\b");
                Sleep(50);
                printf("|");
                printf("\b");
                Sleep(50);
                printf("/");
                printf("\b");
                Sleep(50);
            }
            printf("\n\n\t      RECHARGE SUCCESSFUL!");
            printf("\n\n\t      THANKYOU FOR PLAYING......Please VISIT again :D ");
        }
        else
        {
            printf("\n   Sorry! You entered the wrong Coupon code...And this deal is expired");
            getch();
            printf("\n\n\t PLEASE WAIT YOUR PHONE IS BEING RECHARGED.... ");
            for(i=0;i<35;i++)
            {
                printf("\\");
                printf("\b");
                Sleep(50);
                printf("|");
                printf("\b");
                Sleep(50);
                printf("/");
                printf("\b");
                Sleep(50);
            }
            printf("\n\n\t      RECHARGE SUCCESSFUL!");
            printf("\n\n\t      THANKYOU FOR PLAYING......Please VISIT again :D ");
        }

    }
    else
    {
            printf("\n\t PLEASE WAIT.... ");
            for(i=0;i<35;i++)
            {
                printf("\\");
                printf("\b");
                Sleep(50);
                printf("|");
                printf("\b");
                Sleep(50);
                printf("/");
                printf("\b");
                Sleep(50);
            }
            printf("\n\n\t      RECHARGE SUCCESSFUL!");
            printf("\n\n\t      THANKYOU FOR PLAYING......Please VISIT again :D ");
    }
}
else
 {
     printf("\n\n\t\t THANKYOU FOR PLAYING......Please VISIT again :D ");
 }
getch();

}









