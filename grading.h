/*
 * =====================================================================================
 *
 *       Filename:  grading.h
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

#ifndef GRADING_H
#define GRADING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define STUDENT 3
#define SUBJECT 2
#define EXAMS 4
#define STRING_BUF 25
#define LINE_BUF 225

    void startingGrading();
    void getSubject(char *line, char result[][STRING_BUF]);
    void getStudent(char *line, char result[][STRING_BUF]);
    int isString(char * s);
    void makeName(char *s1, char *s2, char *temp);
    int isNameInArr(char *name, char arr[][STRING_BUF]);
    void fillArraysWithInput(int gradeBook[][STUDENT][EXAMS],
               char subjects[][STRING_BUF], char students[][STRING_BUF]);
    int getAllAvg(int grades[EXAMS]);
    int getAvgforStudent(int grades[EXAMS]);





#endif /* GRADING_H */

