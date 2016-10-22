/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : PrimeFactor
* Description       : Euler Project 3 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/17/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "primefactor_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define PRIMEFACTOR_LIMIT       (600851475143)     //600,851,475,143
#define PRIMEFACTOR_PRIMES      (30)
// Answer: 6857


/*******************************************************************************\
* Static Variables
\*******************************************************************************/
static U2 u2_s_primefactor_primes[PRIMEFACTOR_PRIMES];

/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_PrimeFactor_CalcPrime(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_PrimeFactor_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 3 PrimeFactor
\*****************************************************************************************************************************************************************/
void vd_g_PrimeFactor_Main(void)
{
    U4 u4_t_ans;
    U1 u1_t_idx;

    for(u1_t_idx = (U1)0; u1_t_idx < (U1)PRIMEFACTOR_PRIMES; u1_t_idx++)
    {
        u2_s_primefactor_primes[u1_t_idx] = (U2)0;
    }

    cout << "Find the largest prime factor of " << PRIMEFACTOR_LIMIT << "..\n\n";

    u4_t_ans = u4_s_PrimeFactor_CalcPrime();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_PrimeFactor_CalcPrime
* Called by         : vd_g_PrimeFactor_Main
* Argument(s)       : void
* Return            : U4
* Description       : Calculate Largest Prime Factor
\*****************************************************************************************************************************************************************/
static U4 u4_s_PrimeFactor_CalcPrime(void)
{
    U8 u8_t_factor;
    U2 u2_t_running_idx;
    U1 u1_t_factorization_idx;
    U4 u4_t_rtn;

    u8_t_factor            = (U8)PRIMEFACTOR_LIMIT;
    u2_t_running_idx       = (U2)0;
    u1_t_factorization_idx = (U1)0;

    while(u8_t_factor != (U8)1)
    {
        if((u8_t_factor % (U8)u2_s_PRIMES[u2_t_running_idx]) == (U8)0)
        {
            u2_s_primefactor_primes[u1_t_factorization_idx] = u2_s_PRIMES[u2_t_running_idx];
            u8_t_factor                                     = u8_t_factor / (U8)(u2_s_PRIMES[u2_t_running_idx]);
            u2_t_running_idx                                = (U1)0;
            u1_t_factorization_idx++;
        }
        else
        {
            u2_t_running_idx++;

            if(u2_t_running_idx >= (U2)PRIMEFACTOR_SIZEOF_TABLE)
            {
                u8_t_factor = (U8)1;
            }
        }
    }

    u4_t_rtn = (U4)u2_s_primefactor_primes[(u1_t_factorization_idx-(U1)1)];

    return(u4_t_rtn);
}
