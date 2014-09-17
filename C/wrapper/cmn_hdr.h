/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Common Header
* Description       : Header for all Euler projects
* Original Author   : Jake Nabozny
* Date Created      : 10/16/2012
\*****************************************************************************************************************************************************************/

#ifndef CMN_HDR_H
#define CMN_HDR_H

/*******************************************************************************\
* Common Include Files
\*******************************************************************************/
#include <iostream>
#include <cstdlib>


/*******************************************************************************\
* Common Namespaces
\*******************************************************************************/
using namespace std;


/*******************************************************************************\
* Common Types
\*******************************************************************************/
typedef unsigned char       U1;
typedef unsigned short      U2;
typedef unsigned int        U4;
typedef unsigned long long  U8;

typedef char                S1;
typedef short               S2;
typedef int                 S3;
typedef long                S8;


/*******************************************************************************\
* Macro Defines
\*******************************************************************************/
#ifndef NULL
#define NULL                                (0)
#endif

#ifndef TRUE
#define TRUE                                (1)
#endif

#ifndef FALSE
#define FALSE                               (0)
#endif

#define OFF                                 (0)
#define ON                                  (1)

/* Lowercase letters -- ASCII */
#define LETTER_LOWER_OFFSET                 (0x60)
#define LETTER_a                            (0x61)
#define LETTER_b                            (0x62)
#define LETTER_c                            (0x63)
#define LETTER_d                            (0x64)
#define LETTER_e                            (0x65)
#define LETTER_f                            (0x66)
#define LETTER_g                            (0x67)
#define LETTER_h                            (0x68)
#define LETTER_i                            (0x69)
#define LETTER_j                            (0x6A)
#define LETTER_k                            (0x6B)
#define LETTER_l                            (0x6C)
#define LETTER_m                            (0x6D)
#define LETTER_n                            (0x6E)
#define LETTER_o                            (0x6F)
#define LETTER_p                            (0x70)
#define LETTER_q                            (0x71)
#define LETTER_r                            (0x72)
#define LETTER_s                            (0x73)
#define LETTER_t                            (0x74)
#define LETTER_u                            (0x75)
#define LETTER_v                            (0x76)
#define LETTER_w                            (0x77)
#define LETTER_x                            (0x78)
#define LETTER_y                            (0x79)
#define LETTER_z                            (0x7A)

/* Uppercase letters -- ASCII */
#define LETTER_UPPER_OFFSET                 (0x40)
#define LETTER_A                            (0x41)
#define LETTER_B                            (0x42)
#define LETTER_C                            (0x43)
#define LETTER_D                            (0x44)
#define LETTER_E                            (0x45)
#define LETTER_F                            (0x46)
#define LETTER_G                            (0x47)
#define LETTER_H                            (0x48)
#define LETTER_I                            (0x49)
#define LETTER_J                            (0x4A)
#define LETTER_K                            (0x4B)
#define LETTER_L                            (0x4C)
#define LETTER_M                            (0x4D)
#define LETTER_N                            (0x4E)
#define LETTER_O                            (0x4F)
#define LETTER_P                            (0x50)
#define LETTER_Q                            (0x51)
#define LETTER_R                            (0x52)
#define LETTER_S                            (0x53)
#define LETTER_T                            (0x54)
#define LETTER_U                            (0x55)
#define LETTER_V                            (0x56)
#define LETTER_W                            (0x57)
#define LETTER_X                            (0x58)
#define LETTER_Y                            (0x59)
#define LETTER_Z                            (0x5A)

/* Common characters -- ASCII */
#define LETTER_TAB                          (0x09)
#define LETTER_CARRIAGERTN                  (0x0D)
#define LETTER_SPACE                        (0x20)
#define LETTER_QUOTE                        (0x22)


#endif // CMN_HDR_H
