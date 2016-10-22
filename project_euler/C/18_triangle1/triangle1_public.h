/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Triangle1
* Description       : Euler Project 18
* Original Author   : Jake Nabozny
* Date Created      : 10/26/2012
\*****************************************************************************************************************************************************************/

#ifndef TRIANGLE1_PUBLIC_H
#define TRIANGLE1_PUBLIC_H


/*******************************************************************************\
* Type Definitions
\*******************************************************************************/
typedef struct
{
    U1         u1_num_col;
    U1         u1_num_row;
    const U1 * u1_p_triangle;
}
ST_TRIANGLE_TYPE;


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define TRIANGLE_LEFT               (0)
#define TRIANGLE_RIGHT              (1)
#define TRIANGLE_TEST_NUMS          (5) /* How many look ahead values ? */


/*******************************************************************************\
* Public Function Declarations
\*******************************************************************************/
void vd_g_Triangle1_Main(void);
void vd_g_Triangle_GetMaxSum(U4, U4, U4 *);


#endif // TRIANGLE1_PUBLIC_H