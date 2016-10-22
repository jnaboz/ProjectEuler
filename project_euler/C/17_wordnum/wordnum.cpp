/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : WordNum
* Description       : Euler Project 17 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/25/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "wordnum_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define WORDNUM_LIMIT    (1000)
// Answer: 21,124


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_WordNum_GetNumLetters(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_WordNum_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 17 WordNum
\*****************************************************************************************************************************************************************/
void vd_g_WordNum_Main(void)
{
    U4 u4_t_ans;

    cout << "Count number of letters to spell numbers 1 to 1000..\n\n";

    u4_t_ans = u4_s_WordNum_GetNumLetters();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_WordNum_GetNumLetters
* Called by         : vd_g_WordNum_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetNumLetters
\*****************************************************************************************************************************************************************/
static U4 u4_s_WordNum_GetNumLetters(void)
{
    U4 u4_t_num_letters;
    U2 u2_t_cntr;
    U1 u1_t_valarray[4];
    U1 u1_t_tmp;
    U1 u1_t_continue;

    u4_t_num_letters = (U4)0;

    /* Count 0 to 19 */
    for(u2_t_cntr = (U2)0; u2_t_cntr < (U2)WORDNUM_20; u2_t_cntr++)
    {
        u4_t_num_letters += (U4)u1_sp_NUM_LETTERS_UNDER_20[u2_t_cntr];
    }

    u1_t_valarray[3] = (U1)0;
    u1_t_valarray[2] = (U1)0;
    u1_t_valarray[1] = (U1)2;
    u1_t_valarray[0] = (U1)0;

    /* Count 20 to 1000 */
    for(u2_t_cntr = (U2)WORDNUM_20; u2_t_cntr <= (U2)WORDNUM_LIMIT; u2_t_cntr++)
    {
        /* Add thousands letter count */
        if(u1_t_valarray[3] != (U1)0)
        {
            u4_t_num_letters += (U4)u1_sp_NUM_LETTERS_UNDER_20[u1_t_valarray[3]];
            u4_t_num_letters += (U4)WORDNUM_THOUSAND;
        }

        /* Add hundreds letter count */
        if(u1_t_valarray[2] != (U1)0)
        {
            u4_t_num_letters += (U4)u1_sp_NUM_LETTERS_UNDER_20[u1_t_valarray[2]];
            u4_t_num_letters += (U4)WORDNUM_HUNDRED;

            if(
                (u1_t_valarray[1] != (U1)0) ||
                (u1_t_valarray[0] != (U1)0)
              )
            {
                u4_t_num_letters += (U4)WORDNUM_AND;
            }
        }

        /* Add tens and ones letter count */
        if(u1_t_valarray[1] >= (U1)2)
        {
            u4_t_num_letters += (U4)u1_sp_NUM_LETTERS_MULT_10[u1_t_valarray[1]];
            u4_t_num_letters += (U4)u1_sp_NUM_LETTERS_UNDER_20[u1_t_valarray[0]];
        }
        else
        {
            u1_t_tmp          = (u1_t_valarray[1] * (U1)10) + (U1)u1_t_valarray[0];
            u4_t_num_letters += (U4)u1_sp_NUM_LETTERS_UNDER_20[u1_t_tmp];
        }


        /* Increment u1_t_valarray */
        u1_t_continue = (U1)FALSE;
        u1_t_valarray[0]++;

        if(u1_t_valarray[0] > (U1)9)
        {
            u1_t_continue = (U1)TRUE;
            u1_t_tmp      = (U1)0;
        }

        while(u1_t_continue == (U1)TRUE)
        {
            u1_t_valarray[u1_t_tmp] = (U1)0;
            u1_t_valarray[u1_t_tmp+1]++;
            
            if(u1_t_valarray[u1_t_tmp+1] > (U1)9)
            {
                u1_t_tmp++;
            }
            else
            {
                u1_t_continue = (U1)FALSE;
            }
        }
    }

    return(u4_t_num_letters);
}
