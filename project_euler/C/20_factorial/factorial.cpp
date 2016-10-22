/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Factorial
* Description       : Euler Project 20 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/26/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "factorial_private.h"
#include "cmn_func_public.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define FACTORIAL_LIMIT     (100)
#define FACTORIAL_SIZE      (200) 
#define FACTORIAL_VAL_SIZE  (3)
// Answer: 648


/*******************************************************************************\
* Static Variables
\*******************************************************************************/
static U1 u1_s_factorial[FACTORIAL_SIZE];
static ST_CMNFUNC_1D_ARRAY st_s_factorial = 
{
    &u1_s_factorial[0],
    (U4)FACTORIAL_SIZE
};


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_Factorial_GetSumOfDig(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Factorial_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 20 Factorial
\*****************************************************************************************************************************************************************/
void vd_g_Factorial_Main(void)
{
    U4 u4_t_ans;

    cout << "Find the sum of the digits of " << FACTORIAL_LIMIT << "! ..\n\n";

    u4_t_ans = u4_s_Factorial_GetSumOfDig();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Factorial_GetSumOfDig
* Called by         : vd_g_Factorial_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetSumOfDig
\*****************************************************************************************************************************************************************/
static U4 u4_s_Factorial_GetSumOfDig(void)
{
    U4 u4_t_idx;
    U4 u4_t_rtn_sum;
    U4 u4_t_next_val;
    U1 u1_t_next_val_array[FACTORIAL_VAL_SIZE];
    ST_CMNFUNC_1D_ARRAY st_t_next_val = 
    {
        &u1_t_next_val_array[0],
        (U4)FACTORIAL_VAL_SIZE
    };
    U1 u1_t_temp_array[FACTORIAL_SIZE];
    ST_CMNFUNC_1D_ARRAY st_t_temp = 
    {
        &u1_t_temp_array[0],
        (U4)FACTORIAL_SIZE
    };

    /*********************************************************************\
    * Calculation Details:
    *
    * 1. Parse next factor into an array
    * 2. Multiply running array with next-factor array
    * 3. Store value in running array
    * 4. Repeat 1-3 until end of factorial calculation
    \*********************************************************************/

    
    /*********************************************************************\
    * Initialize Calcaultion
    \*********************************************************************/
    for(u4_t_idx = (U4)0; u4_t_idx < st_s_factorial.u4_size; u4_t_idx++)
    {
        u1_s_factorial[u4_t_idx] = (U4)0;
    }

    vd_g_CmnFunc_ValInto1DArray((U4)FACTORIAL_LIMIT, &st_s_factorial);        /* Initialize to FACTORIAL_LIMIT     */
    u4_t_next_val = (U4)FACTORIAL_LIMIT - (U4)1;                            /* Initialize to FACTORIAL_LIMIT - 1 */
    u4_t_rtn_sum  = (U4)0;

    while(u4_t_next_val > (U4)0)
    {
        /*********************************************************************\
        * 1. Parse next factor into an array
        \*********************************************************************/
        vd_g_CmnFunc_ValInto1DArray(u4_t_next_val, &st_t_next_val);

        /*********************************************************************\
        * 2. Multiply running array with next-factor array
        * 3. Store value in running array
        \*********************************************************************/
        for(u4_t_idx = (U4)0; u4_t_idx < (U4)FACTORIAL_SIZE; u4_t_idx++)
        {
            u1_t_temp_array[u4_t_idx] = (U1)0;
        }

        vd_g_CmnFunc_MultDec1DArray(&st_s_factorial, &st_t_next_val, &st_t_temp);

        u4_t_next_val--;
    }

    for(u4_t_idx = (U4)0; u4_t_idx < (U4)FACTORIAL_SIZE; u4_t_idx++)
    {
        u4_t_rtn_sum += (U4)(u1_s_factorial[u4_t_idx]);
    }

    return(u4_t_rtn_sum);
}
