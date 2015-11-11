/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "grading.h"


/* 
 * ===  FUNCTION =============================================================
 *         Name:  main
 *  Description:  
 * ===========================================================================
 */

void startingGrading()
{
     FILE *fp = fopen("Gradebook.csv", "r");

    char gradeBook[SUBJECT][STUDENT][EXAMS] = {{{0}}};
    char subjects[SUBJECT][STRING_BUF] = {" "};
    char students[STUDENT][STRING_BUF] = {{0}};
    char buf[LINE_BUF];
    char * temp1, temp2;
    int i = 0, j, k, studentIndex = 0, subjectIndex = 0;
    
    while(fgets(buf, 255, fp) != NULL){
       temp1 = strtok(buf, "," );
       temp2 = strtok(NULL, ",");
       if(strcmp(temp1, "Last Name") == 0){
	   continue;
       }
       sprintf(students[studentIndex++], temp1);
       
	if (strlen(temp2) == 1){
	    sprintf(subjects[subjectIndex++], temp2);
	    continue;
	}
        while(temp2 != NULL){
	    
            printf("%s ", temp2);
            temp2 = strtok(NULL, ",");
        } // while temp
       i++;
    } // while fgets
}

void getSubject(char *line, char result[][STRING_BUF])
{
    char *temp;
    static int i = 0;
    temp = strtok(line, "," );
    if(strlen(strtok(NULL, ","))== 1){
        sprintf(result[i++],temp );
    }
}

void getStudent(char *line, char result[][STRING_BUF])
{
    char *temp;
    int i = 0;
    printf("[+] %s ", line);
     temp = strtok(line, "," );
     while(temp != NULL){
//	 if(strcmp(temp, "Last Name") == 0)
//	     break;
//	printf("[+] %s ", temp);
	temp = strtok(NULL, ",");
     } // while temp
    
}


