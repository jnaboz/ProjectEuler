/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Sequence
* Description       : Euler Project 14 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/25/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "sequence_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define SEQUENCE_LIMIT    (1000000)
// Answer: 837,799


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4   u4_s_Sequence_GetStartNum(void);
static void vd_s_Sequence_EvenNum(U4 *);
static void vd_s_Sequence_OddNum(U4 *);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Sequence_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 14 Sequence
\*****************************************************************************************************************************************************************/
void vd_g_Sequence_Main(void)
{
    U4 u4_t_ans;

    cout << "Find the longest sequence with a start number below " << SEQUENCE_LIMIT << "..\n\n";

    u4_t_ans = u4_s_Sequence_GetStartNum();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Sequence_GetStartNum
* Called by         : vd_g_Sequence_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetStartNum
\*****************************************************************************************************************************************************************/
static U4 u4_s_Sequence_GetStartNum(void)
{
    U4 u4_t_startnum;
    U4 u4_t_tmp;
    U1 u1_t_iseven;
    U4 u4_t_length;
    U4 u4_t_max_length;
    U4 u4_t_max_start;

    u4_t_max_start  = (U4)0;
    u4_t_max_length = (U4)0;

    for(u4_t_startnum = (U4)2; u4_t_startnum < (U4)SEQUENCE_LIMIT; u4_t_startnum++)
    {
        u4_t_tmp    = u4_t_startnum;
        u4_t_length = (U4)1;

        while(u4_t_tmp != (U4)1)
        {
            u1_t_iseven = (U1)FALSE;

            if((u4_t_tmp % (U4)2) == (U4)0)
            {
                u1_t_iseven = (U1)TRUE;
            }

            if(u1_t_iseven == (U1)TRUE)
            {
                vd_s_Sequence_EvenNum(&u4_t_tmp);
            }
            else
            {
                vd_s_Sequence_OddNum(&u4_t_tmp);
            }

            u4_t_length++;

            if(u4_t_length > u4_t_max_length)
            {
                u4_t_max_length = u4_t_length;
                u4_t_max_start  = u4_t_startnum;
            }
        }
    }

    return(u4_t_max_start);
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_s_Sequence_OddNum
* Called by         : u4_s_Sequence_GetStartNum
* Argument(s)       : U4 *
* Return            : void
* Description       : Handle Odd Number Sequence Value
\*****************************************************************************************************************************************************************/
static void vd_s_Sequence_OddNum(U4 * u4_a_val)
{
    (*u4_a_val) = ((*u4_a_val) * (U4)3) + (U4)1;
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_s_Sequence_EvenNum
* Called by         : u4_s_Sequence_GetStartNum
* Argument(s)       : U4 *
* Return            : void
* Description       : Handle Even Number Sequence Value
\*****************************************************************************************************************************************************************/
static void vd_s_Sequence_EvenNum(U4 * u4_a_val)
{
    (*u4_a_val) = (*u4_a_val) / (U4)2;
}
