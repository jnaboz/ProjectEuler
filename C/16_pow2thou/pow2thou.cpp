/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Pow2Thou
* Description       : Euler Project 16 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/25/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "pow2thou_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define POW2THOU_LIMIT    (1000)
// Answer: 


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_Pow2Thou_GetSumDigits(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Pow2Thou_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 16 Pow2Thou
\*****************************************************************************************************************************************************************/
void vd_g_Pow2Thou_Main(void)
{
    U4 u4_t_ans;

    cout << "Find the sum of the digits of 2^" << POW2THOU_LIMIT << "..\n\n";

    u4_t_ans = u4_s_Pow2Thou_GetSumDigits();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Pow2Thou_GetSumDigits
* Called by         : vd_g_Pow2Thou_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetSumDigits
\*****************************************************************************************************************************************************************/
static U4 u4_s_Pow2Thou_GetSumDigits(void)
{
    U2 u2_t_cnt;
    U2 u2_t_idx;
    U1 u1_t_value[POW2THOU_LIMIT] = {(U1)0};
    U4 u4_t_rtn;
    U4 u4_t_tmp;
    U1 u1_t_carry;

    u1_t_value[POW2THOU_LIMIT-1] = (U1)1;
    u1_t_carry                   = (U1)0;

    for(u2_t_cnt = (U2)0; u2_t_cnt < (U2)POW2THOU_LIMIT; u2_t_cnt++)
    {
        u2_t_idx = (U2)(POW2THOU_LIMIT-1);
        while(u2_t_idx != (U2)0)
        {
            u1_t_value[u2_t_idx] *= (U1)2;
            u1_t_value[u2_t_idx] += u1_t_carry;
            u1_t_carry            = (U1)0;

            if(u1_t_value[u2_t_idx] > (U1)9)
            {
                u1_t_carry            = u1_t_value[u2_t_idx] / (U1)10;
                u1_t_value[u2_t_idx] %= (U1)10;
            }

            u2_t_idx--;
        }

        if(u1_t_value[0] > (U1)0)
        {
            if(u1_t_value[0] > (U1)9)
            {
                cout << "Not enough space in array...\n\n";
                break;
            }
        }
    }

    u4_t_rtn = (U4)0;   

    for(u2_t_idx = (U2)0; u2_t_idx < (U2)POW2THOU_LIMIT; u2_t_idx++)
    {
        u4_t_tmp  = u4_t_rtn;
        u4_t_rtn += (U4)u1_t_value[u2_t_idx];

        if(u4_t_tmp > u4_t_rtn)
        {
            cout << "Error: Addition overflow..\n\n";
            break;
        }
    }

    return(u4_t_rtn);
}
