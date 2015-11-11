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
    char * temp1, *temp2;
    int i = 0, j, k, studentIndex = 0, subjectIndex = 0;
    
    while(fgets(buf, 255, fp) != NULL){
       temp1 = strtok(buf, "," );
       temp2 = strtok(NULL, ",");
       
       if(strcmp(temp1, "Last Name") == 0){
	   continue;
       }
	if (strlen(temp2) == 1){
	    sprintf(subjects[subjectIndex++], temp2);
	    continue;
	}
       
       if(isString(temp1) && isString(temp2)){
	   char *fullName;
	   makeName(temp1, temp2, fullName);
	   
		sprintf(students[studentIndex++], fullName);

       }
        while(temp2 != NULL){
	    
            printf("%s ", temp2);
            temp2 = strtok(NULL, ",");
        } // while temp
    } // while fgets
}

int isString(char * s){
    int i, resutl = 1;
    for (i = 0; i < strlen(s); i++) {
        if(isdigit(s[i])){
	    resutl = 0;
	    break;
	}
    }

    return resutl;
}

void makeName(char *s1, char *s2, char *temp)
{
    
//    char *temp;
    strcpy(temp, s1);
    strcat(temp, " ");
    strcat(temp, s2);
}