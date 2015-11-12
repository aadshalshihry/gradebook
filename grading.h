/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   grading.h
 * Author: RomanWin
 *
 * Created on November 11, 2015, 9:47 AM
 */

#ifndef GRADING_H
#define GRADING_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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



#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* GRADING_H */

