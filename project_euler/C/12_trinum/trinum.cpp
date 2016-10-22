/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Triangle Number Factors
* Description       : Euler Project 12 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/23/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "trinum_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define TRINUM_LIMIT    (500)
// Answer: 76,576,500


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_TriNum_GetTriNum(void);
static U1 u1_s_TriNum_IsEven(U4);
static U1 u1_s_TriNum_CountOdd(U4);
static U1 u1_s_TriNum_CountEven(U4);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_TriNum_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 12 TriNum
\*****************************************************************************************************************************************************************/
void vd_g_TriNum_Main(void)
{
    U4 u4_t_ans;

    cout << "Find the first triangle number to have more than " << TRINUM_LIMIT << " factors..\n\n";

    u4_t_ans = u4_s_TriNum_GetTriNum();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_TriNum_GetTriNum
* Called by         : vd_g_TriNum_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetTriNum
\*****************************************************************************************************************************************************************/
static U4 u4_s_TriNum_GetTriNum(void)
{
    U1 u1_t_iseven;
    U4 u4_t_val;
    U4 u4_t_trinum;
    U1 u1_t_continue;

    u4_t_val         = (U4)1;
    u4_t_trinum      = (U4)1;
    u1_t_continue    = (U1)TRUE;

    while(u1_t_continue == (U1)TRUE)
    {
        u4_t_val++;
        u4_t_trinum += u4_t_val;
        
        if(u4_t_trinum >= (U4)TRINUM_LIMIT)
        {
            u1_t_iseven = u1_s_TriNum_IsEven(u4_t_trinum);

            if(u1_t_iseven == (U1)FALSE)        /* Odd number factor count */
            {
                u1_t_continue = u1_s_TriNum_CountOdd(u4_t_trinum);
            }
            else                                /* Even number factor count */
            {
                u1_t_continue = u1_s_TriNum_CountEven(u4_t_trinum);
            }
        }
    }

    return(u4_t_trinum);
}


/*****************************************************************************************************************************************************************\
* Function name     : u1_s_TriNum_IsEven
* Called by         : u4_s_TriNum_GetTriNum
* Argument(s)       : U4
* Return            : U1
* Description       : Determine if even Number
\*****************************************************************************************************************************************************************/
static U1 u1_s_TriNum_IsEven(U4 u4_a_val)
{
    U1 u1_t_rtn;

    u1_t_rtn = (U1)FALSE;

    if((u4_a_val % (U4)2) == (U4)0)
    {
        u1_t_rtn = (U1)TRUE;
    }

    return(u1_t_rtn);
}


/*****************************************************************************************************************************************************************\
* Function name     : u1_s_TriNum_CountOdd
* Called by         : u4_s_TriNum_GetTriNum
* Argument(s)       : U4 u4_a_val     .. current test value
* Return            : U1
* Description       : Count number of factors
\*****************************************************************************************************************************************************************/
static U1 u1_s_TriNum_CountOdd(U4 u4_a_val)
{
    U1 u1_t_continue;
    U4 u4_t_idx;
    U4 u4_t_limit;
    U2 u2_t_factors;

    u1_t_continue = (U1)TRUE;
    u4_t_limit    = u4_a_val;
    u2_t_factors  = (U2)2;       /* Account for 1 and u4_a_val */

    for(u4_t_idx = (U4)3; u4_t_idx < u4_t_limit; (u4_t_idx += (U4)2))
    {
        if((u4_a_val % u4_t_idx) == (U4)0)
        {
            u2_t_factors += (U2)2;
            u4_t_limit    = u4_a_val / u4_t_idx;

            if(u2_t_factors > (U2)TRINUM_LIMIT)
            {
                u1_t_continue = (U1)FALSE;
                break;
            }
        }
    }

    return(u1_t_continue);
}


/*****************************************************************************************************************************************************************\
* Function name     : u1_s_TriNum_CountEven
* Called by         : u4_s_TriNum_GetTriNum
* Argument(s)       : U4 u4_a_val     .. current test value
* Return            : U4
* Description       : GetTriNum
\*****************************************************************************************************************************************************************/
static U1 u1_s_TriNum_CountEven(U4 u4_a_val)
{
    U1 u1_t_continue;
    U4 u4_t_idx;
    U4 u4_t_limit;
    U2 u2_t_factors;

    u1_t_continue = (U1)TRUE;
    u2_t_factors  = (U2)4;
    u4_t_limit    = u4_a_val / (U4)2;

    for(u4_t_idx = (U4)4; u4_t_idx < u4_t_limit; u4_t_idx++)
    {
        if((u4_a_val % u4_t_idx) == (U4)0)
        {
            u2_t_factors += (U2)2;
            u4_t_limit    = u4_a_val / u4_t_idx;

            if(u2_t_factors > (U2)TRINUM_LIMIT)
            {
                u1_t_continue = (U1)FALSE;
                break;
            }
        }
    }

    return(u1_t_continue);
}
