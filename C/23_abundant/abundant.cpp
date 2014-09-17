/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Abundant
* Description       : Euler Project 23 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/31/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "abundant_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define ABUNDANT_LIMIT    (28124)
// Answer: 4,179,871


/*******************************************************************************\
* Static Variables
\*******************************************************************************/
static U2 u2_s_abundant_nums[ABUNDANT_LIMIT];
static U1 u1_s_abundant_sumofabundants[ABUNDANT_LIMIT];


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4   u4_s_Abundant_FindSum(void);
static U2   u2_s_Abundant_BuildAbundantList(void);
static void vd_s_Abundant_BuildSumOfAbundantsTbl(U2);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Abundant_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 23 Abundant
\*****************************************************************************************************************************************************************/
void vd_g_Abundant_Main(void)
{
    U4 u4_t_ans;

    cout << "Find sum of all positive integers that cannot be written as the sum of two abundant numbers..\n\n";

    u4_t_ans = u4_s_Abundant_FindSum();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Abundant_FindSum
* Called by         : vd_g_Abundant_Main
* Argument(s)       : void
* Return            : U4
* Description       : FindSum
\*****************************************************************************************************************************************************************/
static U4 u4_s_Abundant_FindSum(void)
{
    U4 u4_t_rtn_sum;
    U2 u2_t_num;
    U2 u2_t_limit;
    
    u4_t_rtn_sum = (U4)0;

    u2_t_limit = u2_s_Abundant_BuildAbundantList();
    
    vd_s_Abundant_BuildSumOfAbundantsTbl(u2_t_limit);

    for(u2_t_num = (U2)1; u2_t_num < (U2)ABUNDANT_LIMIT; u2_t_num++)
    {
        if(u1_s_abundant_sumofabundants[u2_t_num] == (U1)FALSE)
        {
            u4_t_rtn_sum += (U4)u2_t_num;
        }
    }
    return(u4_t_rtn_sum);
}


/*****************************************************************************************************************************************************************\
* Function name     : u2_s_Abundant_BuildAbundantList
* Called by         : u4_s_Abundant_FindSum
* Argument(s)       : void
* Return            : U2 index
* Description       : Build list of abundant numbers up to ABUNDANT_LIMIT
\*****************************************************************************************************************************************************************/
static U2 u2_s_Abundant_BuildAbundantList(void)
{
    U2 u2_t_idx;
    U2 u2_t_num;
    U2 u2_t_sum;
    U2 u2_t_div;
    U2 u2_t_lim;

    /* Initialize array */
    for(u2_t_idx = (U2)0; u2_t_idx < (U2)ABUNDANT_LIMIT; u2_t_idx++)
    {
        u2_s_abundant_nums[u2_t_idx] = (U2)0;
    }

    /* Reset Index */
    u2_t_idx = (U2)0;

    /* Loop through numbers.. */
    for(u2_t_num = (U2)1; u2_t_num < (U2)ABUNDANT_LIMIT; u2_t_num++)
    {
        u2_t_sum = (U2)0;
        u2_t_lim = u2_t_num;

        /* Check for divisors, add to sum */
        for(u2_t_div = (U2)1; u2_t_div < u2_t_lim; u2_t_div++)
        {
            if((u2_t_num % u2_t_div) == (U2)0)
            {
                u2_t_lim  = (u2_t_num / u2_t_div);
                u2_t_sum += u2_t_div;
                
                if(
                    (u2_t_lim > u2_t_div) &&        /* new "lim" is greater than "div".. prevents repeating numbers */
                    (u2_t_lim < u2_t_num)           /* new "lim" isn't the original number                          */
                  )
                {
                   u2_t_sum += u2_t_lim;
                }
            }
        }

        /* Check sum of divisors > current number, add to abundant number list */
        if(u2_t_sum > u2_t_num)
        {
            u2_s_abundant_nums[u2_t_idx] = u2_t_num;
            u2_t_idx++;
        }
    }

    return(u2_t_idx);
}


/*****************************************************************************************************************************************************************\
* Function name     : u1_s_Abundant_IsSumOfAbundants
* Called by         : u4_s_Abundant_FindSum
* Argument(s)       : U2 number, U2 limit
* Return            : <TRUE, FALSE>
* Description       : Determine if current number is a sum of two abundant numbers...
\*****************************************************************************************************************************************************************/
static void vd_s_Abundant_BuildSumOfAbundantsTbl(U2 u2_a_limit)
{
    U2 u2_t_idx;
    U2 u2_t_idx2;
    U2 u2_t_tmp;

    /* Clear array */
    for(u2_t_idx = (U2)0; u2_t_idx < (U2)ABUNDANT_LIMIT; u2_t_idx++)
    {
        u1_s_abundant_sumofabundants[u2_t_idx] = (U1)FALSE;
    }

    for(u2_t_idx = (U2)0; u2_t_idx < u2_a_limit; u2_t_idx++)
    {
        for(u2_t_idx2 = (U2)0; u2_t_idx2 < u2_a_limit; u2_t_idx2++)
        {
            u2_t_tmp = u2_s_abundant_nums[u2_t_idx] + u2_s_abundant_nums[u2_t_idx2];

            if(u2_t_tmp < (U2)ABUNDANT_LIMIT)
            {
                u1_s_abundant_sumofabundants[u2_t_tmp] = (U1)TRUE;
            }
            else
            {
                u2_t_idx2 = u2_a_limit;
            }
        }
    }
}
