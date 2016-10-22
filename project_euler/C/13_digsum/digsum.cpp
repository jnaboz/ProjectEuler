/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Calculate Sum of Digits
* Description       : Euler Project 13 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/24/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "digsum_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define DIGSUM_OFFSET           (2)
#define DIGSUM_ANS_LENGTH       (DIGSUM_INPUT_LENGTH+DIGSUM_OFFSET)
#define DIGSUM_LIMIT            (10)
// Answer: 5,537,376,230


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static void vd_s_DigSum_GetSum(U2 *);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_DigSum_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 13 DigSum
\*****************************************************************************************************************************************************************/
void vd_g_DigSum_Main(void)
{
    U2 u2_t_ans[DIGSUM_LIMIT];
    U1 u1_t_idx;

    cout << "Find the first " << DIGSUM_LIMIT << " digits of the sum of the " << DIGSUM_INPUT_NUM << " " << DIGSUM_INPUT_LENGTH << "-digit numbers..\n\n";

    vd_s_DigSum_GetSum(&u2_t_ans[0]);

    cout << "Answer:\t";

    for(u1_t_idx = (U1)0; u1_t_idx < (U1)DIGSUM_LIMIT; u1_t_idx++)
    {
        cout << u2_t_ans[u1_t_idx];
    }

    cout << endl << endl;
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_DigSum_GetSum
* Called by         : vd_g_DigSum_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetSum
\*****************************************************************************************************************************************************************/
static void vd_s_DigSum_GetSum(U2 * u2_a_val)
{
    U1   u1_t_place;
    U2   u2_t_ans[DIGSUM_ANS_LENGTH];
    U1   u1_t_idx;
    U2   u2_t_carry;
    U1   u1_t_number;
    U2 * u2_t_ptr;

    u2_t_carry   = (U2)0;
    u2_t_ptr     = u2_a_val;

    /* Clear intermediate buffer */
    for(u1_t_place = (U1)0; u1_t_place < (U1)DIGSUM_ANS_LENGTH; u1_t_place++)
    {
        u2_t_ans[u1_t_place] = (U2)0;
    }

    /* Determine sum place by place */
    for(u1_t_place = (U1)(DIGSUM_INPUT_LENGTH); u1_t_place > (U1)0; u1_t_place--)
    {
        u1_t_idx           = u1_t_place + (U1)DIGSUM_OFFSET - (U1)1;
//        u2_t_ans[u1_t_idx] = u2_t_carry; 
//        u2_t_carry         = (U2)0;

        for(u1_t_number = (U1)0; u1_t_number < (U1)DIGSUM_INPUT_NUM; u1_t_number++)
        {
            u2_t_ans[u1_t_idx] += st_sp_DIGSUM_INPUT[u1_t_number].u1_val[u1_t_place-1];
        }

//        if(u2_t_ans[u1_t_idx] > (U1)9)
//        {
//            u2_t_carry          = u2_t_ans[u1_t_idx] / (U2)10;
//            u2_t_ans[u1_t_idx] %= (U2)10;
//        }
    }

    for(u1_t_place = (U1)(DIGSUM_ANS_LENGTH-1); u1_t_place > (U1)0; u1_t_place--)
    {
        u2_t_carry              = u2_t_ans[u1_t_place] / (U2)10;
        u2_t_ans[u1_t_place]   %= (U2)10;
        u2_t_ans[u1_t_place-1] += u2_t_carry;
    }

    for(u1_t_idx = (U1)0; u1_t_idx < (U1)DIGSUM_LIMIT; u1_t_idx++)
    {
        (*u2_t_ptr) = u2_t_ans[u1_t_idx];
        u2_t_ptr++;
    }
}
