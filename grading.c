/*
 * =====================================================================================
 *
 *       Filename:  grading.c
 *
 *    Description:  This program is keeping track of 2 subjects and 3 students
 *                  and their 4 exam grades.
 *
 *        Version:  1.0
 *        Created:  11/07/2015 21:51:45
 *       Compiler:  gcc
 *
 *         Author:  Roman - Abdulrahman Alshehri, aalshehri@umassd.edu
 *
 * =====================================================================================
 */
#include "grading.h"


/* 
 * ===  FUNCTION =============================================================
 *         Name:  startingGrading
 *  Description:  This function is the start point and it's the function that
 *                get called from main. 
 *                
 *                It has all arrays and initialize variables.
 * 
 *                It's calling the following functions:
 *                  1) fillArraysWithInput => to put the data in it's own array
 *                  2) getAllAvg           => to get sum for all grades
 *                  3) getAvgforStudent    => to get sum of grades 
 *                                            for a student
 * ===========================================================================
 */

void startingGrading()
{
    // initialize variables
    int gradeBook[SUBJECT][STUDENT][EXAMS] = {{{0}}};
    char subjects[SUBJECT][STRING_BUF] = {{0}};
    char students[STUDENT][STRING_BUF] = {{0}};
    int result = 0, i, j;
    float allAvgForAllGrades = 0.0, avgForStudent = 0.0, count = 0.0;
    
    // put the data in arrays
    fillArraysWithInput(gradeBook, subjects, students);
    
    // print all average
    for (i = 0; i < SUBJECT; i++) {
        for (j = 0; j < STUDENT; j++) {
            allAvgForAllGrades += getAllAvg(gradeBook[i][j]);
        }
    }
    count = SUBJECT*STUDENT*EXAMS;
    printf("The all average for all classes is %0.2f\n\n",
            allAvgForAllGrades/(count));
    printf("\n\n");
    
    // print each average of subject for each student
    count = EXAMS;
    for (i = 0; i < STUDENT; i++) {
        printf("The average for %s:\n", students[i]);
        for (j = 0; j < SUBJECT; j++) {
            avgForStudent = 0.0;
            avgForStudent += getAvgforStudent(gradeBook[j][i]); 
            printf("   %d) %s is %.2f\n",j+1, subjects[j], avgForStudent/(count));
        }
        printf("\n");
    }
    printf("\n\n");
    
    // print average of both subject for each student.
    count = SUBJECT*EXAMS;
    for (i = 0; i < STUDENT; i++) {
        avgForStudent = 0.0;
        printf("The average for %s for all subjects is ", students[i]);
        for (j = 0; j < SUBJECT; j++) {
            avgForStudent += getAvgforStudent(gradeBook[j][i]);   
        }
        printf("%.2f\n",avgForStudent/(count));
        printf("\n");
    }
    printf("\n\n");
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  getAllAvg
 *  Description:  get the sum of all grades
 * ===========================================================================
 */

int getAllAvg(int grades[EXAMS])
{
    int sumAvg = 0, k;
    for(k = 0; k <EXAMS; k++){
        sumAvg += grades[k];
    }
    return sumAvg;
    
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  getAvgforStudent
 *  Description:  get the sum of all grades for student
 * ===========================================================================
 */
int getAvgforStudent(int grades[EXAMS])
{
    int sumAvg = 0, k;
    for(k = 0; k <EXAMS; k++){
        sumAvg += grades[k];
    }
    return sumAvg;
    
}


/* 
 * ===  FUNCTION =============================================================
 *         Name:  fillArraysWithInput
 *  Description:  getting the data from the file and insert it the array
 * ===========================================================================
 */
void fillArraysWithInput(int gradeBook[][STUDENT][EXAMS],
           char subjects[][STRING_BUF], char students[][STRING_BUF]){
    FILE *fp;
     
     if(!(fp = fopen("GradeBook.csv", "r"))){
         printf("Can not opne the file \n");
         exit(1);
     }
    
    char buf[LINE_BUF];
    char * temp1, *temp2;
    
    int i = 0, j = 0, k = 0, studentIndex = 0, subjectIndex = 0;
    
    while(fgets(buf, 255, fp) != NULL){
       temp1 = strtok(buf, "," );
       temp2 = strtok(NULL, ",");
       
        // get rid of the label in the input
        if(strcmp(temp1, "Last Name") == 0){
            continue;
        }
       
        // getting subjects
        if (strlen(temp2) == 1){
            sprintf(subjects[subjectIndex++],"%s", temp1);
        
            continue;
        }
       
    
        // getting students
        if(isString(temp1) && isString(temp2)){
            char fullName[STRING_BUF];
            makeName(temp1, temp2, fullName);

            if(!isNameInArr(fullName, students)){
                sprintf(students[studentIndex++],"%s", fullName);
            }
        }
     
       // getting grade
        while(temp2 != NULL){
            temp2 = strtok(NULL, ",");
            if(temp2 != NULL){
//                printf("i=%d j=%d k=%d [=>] %d ",i,j,k, atoi(temp2));
                gradeBook[i][j][k++] = atoi(temp2);
                
                if(k == EXAMS){
                    k = 0;
                    j++;
                }
                
                if(j == STUDENT){
                    k = 0;
                    j = 0;
                    i++;
                }
            }
        } // while temp
    } // while fgets
}

/* 
 * ===  FUNCTION =============================================================
 *         Name:  isString
 *  Description:  it's check of the tokens is a number of a string type
 * ===========================================================================
 */

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

/* 
 * ===  FUNCTION =============================================================
 *         Name:  makeName
 *  Description:  make the full name of the student in one string
 * ===========================================================================
 */


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

/* 
 * ===  FUNCTION =============================================================
 *         Name:  isNameInArr
 *  Description:  check if the name is in the student array.
 * ===========================================================================
 */

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
