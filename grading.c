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
    
     FILE *fp;
     
     if(!(fp = fopen("GradeBook.csv", "r"))){
         printf("Can not opne the file \n");
         exit(1);
     }
     
    char gradeBook[SUBJECT][STUDENT][EXAMS] = {{{0}}};
    char subjects[SUBJECT][STRING_BUF] = {" "};
    char students[STUDENT][STRING_BUF] = {{0}};
    char buf[LINE_BUF];
    char * temp1, *temp2;
    
    int i = 0, j, k, studentIndex = 0, subjectIndex = 0;
    
    
    while(fgets(buf, 255, fp) != NULL){
       temp1 = strtok(buf, "," );
       temp2 = strtok(NULL, ",");
       
       // get rid of the label
       if(strcmp(temp1, "Last Name") == 0){
	   continue;
       }
       
       // getting subjects
	if (strlen(temp2) == 1){
	    sprintf(subjects[subjectIndex++],"%s", temp2);
        
	    continue;
	}
       
    
       // getting students
    if(isString(temp1) && isString(temp2)){
        char fullName[STRING_BUF];
        makeName(temp1, temp2, fullName);

        if(!isNameInArr(fullName, students)){
            sprintf(students[studentIndex++],"%s", fullName);
        }
        printf("%s\n",fullName);
    }
     
       // getting grade
        while(temp2 != NULL){
            temp2 = strtok(NULL, ",");
	    if(temp2 != NULL)
		printf("%d ", atoi(temp2));
        } // while temp
    } // while fgets
}

// it's check of the tokens is a number of a string
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


// make the full name of the student in one string
void makeName(char *s1, char *s2, char temp[STRING_BUF])
{
    
    int i, tempIndex = 0;
    for (i = 0; i < strlen(s1); i++) {
        temp[tempIndex++] = s1[i];
    }
    
    temp[tempIndex++] = ' ';
    
    for (i = 0; i < strlen(s2); i++) {
        temp[tempIndex++] = s2[i];
    }
    temp[tempIndex++] = '\0';
}

// check if the name is in the student array.
int isNameInArr(char *name, char arr[][STRING_BUF])
{
    int i, result = 0;
    
    for (i = 0; i < STUDENT; i++) {
        if(strcmp(name, arr[i]) == 0)
	{
	    result = 1;
	    break;
	} 
    }
    return result;
}
