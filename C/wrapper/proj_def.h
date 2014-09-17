/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Project Defines
* Description       : Define project entities
* Original Author   : Jake Nabozny
* Date Created      : 10/16/2012
\*****************************************************************************************************************************************************************/

#ifndef PROJ_DEF_H
#define PROJ_DEF_H


/*******************************************************************************\
* Common Include Files
\*******************************************************************************/
#include "natnum_public.h"
#include "fibsum_public.h"
#include "primefactor_public.h"
#include "palindrome_public.h"
#include "edivis_public.h"
#include "sqsum_public.h"
#include "findprime_public.h"
#include "thoudig_public.h"
#include "pythtrip_public.h"
#include "prime2mil_public.h"
#include "gridprod_public.h"
#include "trinum_public.h"
#include "digsum_public.h"
#include "sequence_public.h"
#include "gridroute_public.h"
#include "pow2thou_public.h"
#include "wordnum_public.h"
#include "triangle1_public.h"
#include "sundays_public.h"
#include "factorial_public.h"
#include "amicable_public.h"
#include "names_public.h"
#include "abundant_public.h"
#include "lexicographic_public.h"
#include "fib1000dig_public.h"
#include "1divd_public.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define NATNUM_PROJ_1                   (0)
#define FIBSUM_PROJ_2                   (1)
#define PRIMEFACTOR_PROJ_3              (2)
#define PALINDROME_PROJ_4               (3)
#define EDIVIS_PROJ_5                   (4)
#define SQSUM_PROJ_6                    (5)
#define FINDPRIME_PROJ_7                (6)
#define THOUDIG_PROJ_8                  (7)
#define PYTHTRIP_PROJ_9                 (8)
#define PRIME2MIL_PROJ_10               (9)
#define GRIDPROD_PROJ_11                (10)
#define TRINUM_PROJ_12                  (11)
#define DIGSUM_PROJ_13                  (12)
#define SEQUENCE_PROJ_14                (13)
#define GRIDROUTE_PROJ_15               (14)
#define POW2THOU_PROJ_16                (15)
#define WORDNUM_PROJ_17                 (16)
#define TRIANGLE1_PROJ_18               (17)
#define SUNDAYS_PROJ_19                 (18)
#define FACTORIAL_PROJ_20               (19)
#define AMICABLE_PROJ_21                (20)
#define NAMES_PROJ_22                   (21)
#define ABUNDANT_PROJ_23                (22)
#define LEXICOGRAPHIC_PROJ_24           (23)
#define FIB1000DIG_PROJ_25              (24)
#define DIVD_PROJ_26                    (25)

#define EULER_NUMOF_PROJ                (26)
#define __ACT_PROJ__                    (DIVD_PROJ_26)


/*******************************************************************************\
* Project Array
\*******************************************************************************/
static void (* const fp_vd_EULER_PROJ_TASK[])(void) = 
{
    &vd_g_NatNumMain,
    &vd_g_FibSum_Main,
    &vd_g_PrimeFactor_Main,
    &vd_g_Palindrome_Main,
    &vd_g_EDivis_Main,
    &vd_g_SqSum_Main,
    &vd_g_FindPrime_Main,
    &vd_g_ThouDig_Main,
    &vd_g_PythTrip_Main,
    &vd_g_Prime2Mil_Main,
    &vd_g_GridProd_Main,
    &vd_g_TriNum_Main,
    &vd_g_DigSum_Main,
    &vd_g_Sequence_Main,
    &vd_g_GridRoute_Main,
    &vd_g_Pow2Thou_Main,
    &vd_g_WordNum_Main,
    &vd_g_Triangle1_Main,
    &vd_g_Sundays_Main,
    &vd_g_Factorial_Main,
    &vd_g_Amicable_Main,
    &vd_g_Names_Main,
    &vd_g_Abundant_Main,
    &vd_g_Lexicographic_Main,
    &vd_g_Fib1000Dig_Main,
    &vd_g_1DivD_Main,
};





#endif // PROJ_DEF_H
