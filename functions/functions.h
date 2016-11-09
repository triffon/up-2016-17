/*
 * functions.h
 *
 *  Created on: 9.11.2016 г.
 *      Author: trifon
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/* математически формули */
double square(double);
double distance(double, double, double, double);
double semiPerimeter(double, double, double);
double heron(double, double, double);

/* функции за въвеждане */
void enterTriangle();
double enterCoordinate(char, int);

/* функции за извеждане */
void printTrinagle();

/* функции за пресмятане */
double calculateTriangleArea();

double magic();


#endif /* FUNCTIONS_H_ */
