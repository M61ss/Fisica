#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

/********************************************************************************/
/*									DEFINE										*/
/********************************************************************************/



#ifndef PI
/** @brief Macro represents the greek pi */
#define PI 3.14159265
#endif // !PI

#ifndef E
/** @brief Macro represents the Euler's number */
#define E 2.71828182
#endif // !E

#include "macro.h"
#include <math.h>

/* Controls of functions of this header are realized using macros contained in macro.h */
#ifndef MACRO_H
#error math_functions.h: need the header "macro.h"
#endif // !MACRO_H



/********************************************************************************/
/*									FUNCTIONS									*/
/********************************************************************************/



// calcola il fattoriale dell'intero x
extern int Factorial(const int x);

// calculates the hypotenuse of a right triangle
double Pitagora(const double x, const double y);

// calcola il coefficiente binomiale dei due interi n e k
extern double BinomialCoefficient(const int n, const int k);

// calcola il binomiale simmetrico
extern double SymmetricBinomial(const int n, const int h, const int k);

// calcola il prodotto scalare tra due vettori di dimensione v_size
extern double ScalarProductV(const double* v1, const double* v2, const size_t v1_size, const size_t v2_size);

// calcola il prodotto scalare tra uno scalare(k) e un vettore(v) di dimensione v_size (modifica i valori contenuti in v)
extern void ScalarProductS(double* v, const double k, const size_t v_size);

// calcola l'area del triangolo date base e altezza
extern double TriangleArea(const double base, const double h);

// calcola l'area del quadrato dato il lato
extern double SquareArea(const double l);

// calcola l'area del parallelogramma date base e altezza
extern double ParallelogramArea(const double base, const double h);

// calcola l'area del rombo date le due diagonali
extern double RhombusArea(const double d1, const double d2);

// calcola l'area del trapezio date base minore (b1), base maggiore (b2) e altezza
extern double TrapezeArea(const double b1, const double b2, const double h);

// calcola l'area della circonferenza dato il raggio
extern double CircleArea(const double r);

// calcola l'area della corona circolare dato il raggio della circonferenza esterna e il raggio di quella interna
extern double CircularCrownArea(const double rex, const double rin);

// calcola il volume di un solido rettangolare dati lato, profondità e altezza
extern double RectangleVolume(const double l, const double p, const double h);

// calcola il volume di un cubo dato il lato
extern double CubeVolume(const double l);

// calcola il volume della piramide date base e altezza(hb) del triangolo alla base della piramide e l'altezza della stessa(h) 
extern double PiramidVolume(const double base, const double hb, const double h);

#endif // !MATH_FUNCTIONS_H