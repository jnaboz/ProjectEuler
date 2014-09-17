/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Lexicographic
* Description       : Euler Project 24 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 11/01/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "lexicographic_private.h"
#include <algorithm>


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define LEXICOGRAPHIC_LIMIT     (1000000)
#define LEXICOGRAPHIC_SIZE      (10)
// Answer: 2,783,915,460


/*******************************************************************************\
* Static Variables
\*******************************************************************************/
static U1 u1_s_lexicographic_nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_Lexicographic_GetPermutation(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Lexicographic_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 24 Lexicographic
\*****************************************************************************************************************************************************************/
void vd_g_Lexicographic_Main(void)
{
    U4 u4_t_ans;
    U1 u1_t_idx;

    cout << "Find the " << LEXICOGRAPHIC_LIMIT << " permutation of ";
    
    for(u1_t_idx = (U1)0; u1_t_idx < (U1)LEXICOGRAPHIC_SIZE; u1_t_idx++)
    {
        cout << (U4)u1_s_lexicographic_nums[u1_t_idx] << ", ";
    }

    cout << "..\n\n";

    u4_t_ans = u4_s_Lexicographic_GetPermutation();

/*    cout << "Answer:\t" << u4_t_ans << "\n\n"; */
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Lexicographic_GetPermutation
* Called by         : vd_g_Lexicographic_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetPermutation
\*****************************************************************************************************************************************************************/
static U4 u4_s_Lexicographic_GetPermutation(void)
{
    U4 u4_t_idx;
    U1 u1_t_num;

    u4_t_idx = (U4)0;

    do
    {
        u4_t_idx++;

        if(u4_t_idx == (U4)LEXICOGRAPHIC_LIMIT)
        {
            cout << "Answer:\t";

            for(u1_t_num = (U1)0; u1_t_num < (U1)LEXICOGRAPHIC_SIZE; u1_t_num++)
            {
                cout << (U4)u1_s_lexicographic_nums[u1_t_num];
            }
            
            cout << endl << endl;
            break;
        }

    } while(next_permutation(u1_s_lexicographic_nums, u1_s_lexicographic_nums+10));

    return(0);
}
