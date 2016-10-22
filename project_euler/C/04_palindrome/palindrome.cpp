/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Palindrome
* Description       : Euler Project 4 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/17/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "palindrome_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define PALINDROME_MAX_DIGITS       (6)
#define PALINDROME_MIN_VAL          (101)
#define PALINDROME_MAX_VAL          (999)
// Answer: 906609


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_Palindrome_TestPalindrome(void);
static U1 u1_s_Palindrome_IsPalindrome(U4);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Palindrome_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 4 Palindrome
\*****************************************************************************************************************************************************************/
void vd_g_Palindrome_Main(void)
{
    U4 u4_t_ans;

    cout << "Find largest palindrome from the product of two 3-digit values..\n\n";

    u4_t_ans = u4_s_Palindrome_TestPalindrome();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Palindrome_TestPalindrome
* Called by         : vd_g_Palindrome_Main
* Argument(s)       : void
* Return            : U4
* Description       : TestPalindrome
\*****************************************************************************************************************************************************************/
static U4 u4_s_Palindrome_TestPalindrome(void)
{
    U2 u2_t_num1;
    U2 u2_t_num2;
    U4 u4_t_prod;
    U1 u1_t_ispal;
    U4 u4_t_max;

    u4_t_max = (U4)0;

    for(u2_t_num1 = (U2)PALINDROME_MAX_VAL; u2_t_num1 >= (U2)PALINDROME_MIN_VAL; u2_t_num1--)
    {
        if((u2_t_num1 % (U2)10) == (U2)0)
        {
            u2_t_num1--;
        }

        for(u2_t_num2 = (U2)PALINDROME_MAX_VAL; u2_t_num2 >= (U2)PALINDROME_MIN_VAL; u2_t_num2--)
        {
            if((u2_t_num2 % (U2)10) == (U2)0)
            {
                u2_t_num2--;
            }

            u4_t_prod  = (U4)((U4)u2_t_num1 * (U4)u2_t_num2);

            if(u4_t_prod > u4_t_max)
            {
                u1_t_ispal = u1_s_Palindrome_IsPalindrome(u4_t_prod);

                if(u1_t_ispal == (U1)TRUE)
                {
                    u4_t_max = u4_t_prod;
                }
            }
        }
    }

    return(u4_t_max);
}


/*****************************************************************************************************************************************************************\
* Function name     : u1_s_Palindrome_IsPalindrome
* Called by         : vd_g_Palindrome_TestPalindrome
* Argument(s)       : U4
* Return            : U1
* Description       : Check if it is a palindrome
\*****************************************************************************************************************************************************************/
static U1 u1_s_Palindrome_IsPalindrome(U4 u4_a_val)
{
    U1 u1_t_rtn;
    U1 u1_t_idx;
    U1 u1_t_array[6];
    U4 u4_t_divisor;

    u1_t_rtn      = (U1)FALSE;
    u4_t_divisor  = (U4)1;
    u1_t_array[0] = (U1)(u4_a_val % 10);

    for(u1_t_idx = (U1)1; u1_t_idx < (U1)PALINDROME_MAX_DIGITS; u1_t_idx++)
    {
        u4_t_divisor        *= (U4)10;
        u1_t_array[u1_t_idx] = (U1)((u4_a_val / u4_t_divisor) % 10);
    }

    if(
        (u1_t_array[0] == u1_t_array[5]) &&
        (u1_t_array[1] == u1_t_array[4]) &&
        (u1_t_array[2] == u1_t_array[3])
      )
    {
        u1_t_rtn = (U1)TRUE;
    }

    return(u1_t_rtn);
}


