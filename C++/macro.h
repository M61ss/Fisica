#ifndef MACRO_H
#define MACRO_H

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>



/********************************************************************************/
/*									DEFINE										*/
/********************************************************************************/



#ifndef MATH_ERROR
/** @brief Macro prints an error message advising about a fatal error caused by a math operation.

@param[in] message = a string that contains the error message;
@param[in] location = it is a paramter that is supposed to be the macro __FILE__ which represent the file's path string where the error has occurred;
@param[in] line = it is a paramter that is supposed to be the macro __LINE__ which represent an integer that refers to the line where the error has occurred;
*/
#define MATH_ERROR(message, location, line) printf(message, location, line); exit(1)
#endif // !MATH_ERROR

#ifndef ERROR_READING_STDIN
/** @brief Macro prints an error message advising about a fatal error caused by having read from standard input. 

@param[in] location = it is a paramter that is supposed to be the macro __FILE__ which represent the file's path string where the error has occurred;
@param[in] line = it is a paramter that is supposed to be the macro __LINE__ which represent an integer that refers to the line where the error has occurred;
*/
#define ERROR_READING_STDIN(location, line) printf("%s: line: %d. Error reading string from stdin\n.", location, line); exit(2)
#endif // !ERROR_READING_STDIN

#ifndef INVALID_NULL_POINTER
/** @brief Macro prints an error message advising about a fatal error caused by having passed a NULL pointer to a function that doesn't accept that.

@param[in] message = a string that contains the error message;
@param[in] location = it is a paramter that is supposed to be the macro __FILE__ which represent the file's path string where the error has occurred;
@param[in] line = it is a paramter that is supposed to be the macro __LINE__ which represent an integer that refers to the line where the error has occurred;
*/
#define INVALID_NULL_POINTER(message, location, line) printf(message, location, line); exit(3)
#endif // !INVALID_NULL_POINTER

#ifndef INVALID_PARAMETER
/** @brief Macro prints an error message advising about a fatal error caused by having passed to a function a parameter that is not accepted

@param[in] message = a string that contains the error message;
@param[in] location = it is a paramter that is supposed to be the macro __FILE__ which represent the file's path string where the error has occurred;
@param[in] line = it is a paramter that is supposed to be the macro __LINE__ which represent an integer that refers to the line where the error has occurred;
*/
#define INVALID_PARAMETER(message, location, line) printf(message, location, line); exit(4)
#endif // !INVALID_PARAMETER

#endif // !MACRO_H
