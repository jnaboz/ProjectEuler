/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Sum of Primes under 2 Million
* Description       : Euler Project 10 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/22/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "prime2mil_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define PRIME2MIL_MAX_PRIMES        (150000)
#define PRIME2MIL_LIMIT             (2000000)
// Answer: 142,913,828,922


/*******************************************************************************\
* Static Variables
\*******************************************************************************/
static U4 u4_s_primevals[PRIME2MIL_MAX_PRIMES];
static U4 u4_s_primeidx;


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U8   u8_s_Prime2Mil_GetSum(void);
static void vd_s_Prime2Mil_FindPrimes(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Prime2Mil_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 10 Prime2Mil
\*****************************************************************************************************************************************************************/
void vd_g_Prime2Mil_Main(void)
{
    U8 u8_t_ans;

    cout << "Find the sum of all primes under 2 million..\n\n";

    u8_t_ans = u8_s_Prime2Mil_GetSum();

    cout << "Answer:\t" << u8_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u8_s_Prime2Mil_GetSum
* Called by         : vd_g_Prime2Mil_Main
* Argument(s)       : void
* Return            : U8
* Description       : Get sum of all primes
\*****************************************************************************************************************************************************************/
static U8 u8_s_Prime2Mil_GetSum(void)
{
    U4 u4_t_idx;
    U8 u8_t_rtn;

    vd_s_Prime2Mil_FindPrimes();

    u8_t_rtn = (U8)0;

    for(u4_t_idx = (U4)0; u4_t_idx < u4_s_primeidx; u4_t_idx++)
    {
        u8_t_rtn += (U8)u4_s_primevals[u4_t_idx];
    }

    return(u8_t_rtn);
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_s_Prime2Mil_FindPrimes
* Called by         : u4_s_Prime2Mil_GetSum
* Argument(s)       : void
* Return            : void
* Description       : Create array of prime numbers
\*****************************************************************************************************************************************************************/
static void vd_s_Prime2Mil_FindPrimes(void)
{
    U4 u4_t_val;
    U4 u4_t_check_idx;
    U4 u4_t_prime_flag;

    u4_s_primevals[0] = (U4)2;
    u4_s_primeidx     = (U4)1;
    
    for(u4_t_val = (U4)3; u4_t_val < (U4)PRIME2MIL_LIMIT; u4_t_val += (U4)2)
    {
        if(u4_s_primeidx < (U4)PRIME2MIL_MAX_PRIMES)
        {
            u4_t_prime_flag = (U4)TRUE;

            for(u4_t_check_idx = (U4)0; u4_t_check_idx < u4_s_primeidx; u4_t_check_idx++)
            {
                if((u4_t_val % u4_s_primevals[u4_t_check_idx]) == (U4)0)
                {
                    u4_t_prime_flag = (U4)FALSE;
                    u4_t_check_idx  = u4_s_primeidx;
                }
            }

            if(u4_t_prime_flag == (U4)TRUE)
            {
                u4_s_primevals[u4_s_primeidx] = u4_t_val;
                u4_s_primeidx++;
            }
        }
        else
        {
            cout << "Error: Array too small\n\n";
            u4_t_val = (U4)PRIME2MIL_LIMIT;
        }
    }
}
