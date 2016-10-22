/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Common Function Public Header
* Description       : Euler Project Common Functions
* Original Author   : Jake Nabozny
* Date Created      : 10/29/2012
\*****************************************************************************************************************************************************************/

#ifndef CMNFUNC_PUBLIC_H
#define CMNFUNC_PUBLIC_H


/*******************************************************************************\
* Type Definitions
\*******************************************************************************/
typedef struct
{
    U1 * u1_array;
    U4   u4_size;
}
ST_CMNFUNC_1D_ARRAY;

typedef struct
{
    U1 * u1_2d_array;
    U4   u4_num_row;
    U4   u4_num_col;
}
ST_CMNFUNC_2D_ARRAY;


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/


/*******************************************************************************\
* Constant Data
\*******************************************************************************/


/*******************************************************************************\
* Public Function Declarations
\*******************************************************************************/
U4   u4_g_CmnFunc_GetPowXtoY(U1, U1);                                                                       /* Get value of x^y                         */
U4   u4_g_CmnFunc_GetMaxTwoVal(U4, U4);                                                                     /* Get max value between 2 inputs           */
void vd_g_CmnFunc_ValInto1DArray(U4, ST_CMNFUNC_1D_ARRAY *);                                                /* Put a value into an array                */
void vd_g_CmnFunc_Copy1DArray(ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *);                                /* Copy array into array                    */
void vd_g_CmnFunc_Add1DArray(ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *);                                 /* Add two 1D arrays together               */
void vd_g_CmnFunc_Sub1DArray(ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *);                                 /* Find difference between two 1D arrays    */
void vd_g_CmnFunc_MultDec1DArray(ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *);      /* Multiply two arrays, base 10             */
void vd_g_CmnFunc_Sort2DArray(ST_CMNFUNC_2D_ARRAY *, ST_CMNFUNC_2D_ARRAY *);                                /* Sort a 2D array                          */
void vd_g_CmnFunc_GetNextFibNum(ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *);       /* Use array to find fibonacci number       */


#endif // CMNFUNC_PUBLIC_H
