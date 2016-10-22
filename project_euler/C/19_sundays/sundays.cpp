/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Sundays
* Description       : Euler Project 19 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/26/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "sundays_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define SUNDAYS_REF_MONTH       (MONTH_JANUARY)
#define SUNDAYS_REF_DAY         (DAY_MONDAY)
#define SUNDAYS_REF_YEAR        (1900)

#define SUNDAYS_START_MONTH     (MONTH_JANUARY)
#define SUNDAYS_START_YEAR      (1901)
#define SUNDAYS_END_MONTH       (MONTH_DECEMBER)
#define SUNDAYS_END_YEAR        (2000)
// Answer: 171


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_Sundays_GetNum1stSundays(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Sundays_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 19 Sundays
\*****************************************************************************************************************************************************************/
void vd_g_Sundays_Main(void)
{
    U4 u4_t_ans;

    cout << "How many 1st of the month are on Sunday in the 20th century?..\n\n";

    u4_t_ans = u4_s_Sundays_GetNum1stSundays();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Sundays_GetNum1stSundays
* Called by         : vd_g_Sundays_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetNum1stSundays
\*****************************************************************************************************************************************************************/
static U4 u4_s_Sundays_GetNum1stSundays(void)
{
    U4 u4_t_rtn_sundays;
    U1 u1_t_curr_day;
    U1 u1_t_curr_month;
    U4 u4_t_curr_year;
    U1 u1_t_leap_year;

    u4_t_rtn_sundays = (U4)0;

    /* Find beginning day of week */
    u1_t_curr_day    = (U1)SUNDAYS_REF_DAY;
    u1_t_curr_month  = (U1)SUNDAYS_REF_MONTH;
    u4_t_curr_year   = (U1)SUNDAYS_REF_YEAR;

    while(u4_t_curr_year < (U4)SUNDAYS_START_YEAR )
    {
        while(u1_t_curr_month < (U1)NUM_MONTHS_IN_YEAR)
        {
            u1_t_curr_day += u1_sp_MONTH_NUMDAYS[u1_t_curr_month];
            u1_t_curr_day %= (U1)NUM_DAYS_IN_WEEK;
            u1_t_curr_month++;
        }

        u1_t_curr_month = (U1)MONTH_JANUARY;
        u4_t_curr_year++;
    }

    while(u4_t_curr_year  <= (U4)SUNDAYS_END_YEAR)
    {
        u1_t_leap_year = u1_g_Sundays_LeapYear(u4_t_curr_year);

        if(u4_t_curr_year == (U4)SUNDAYS_END_YEAR)                              /* Final Year.. count to final month */
        {
            while(u1_t_curr_month <= (U1)SUNDAYS_END_MONTH)                     /* Loop to last defined month */
            {
                if(u1_t_curr_day == (U1)DAY_SUNDAY)                             /* Is this month's day1 on a Sunday? */
                {
                    u4_t_rtn_sundays++;                                         
                }

                if(
                    (u1_t_curr_month == (U1)MONTH_FEBRUARY) &&                  /* Leap year ? */
                    (u1_t_leap_year  == (U1)TRUE)
                  )
                {
                    u1_t_curr_day += (U1)FEBRUARY_NUM_DAYS_LEAP;                
                }
                else                                                            /* Non-leap year */
                {
                    u1_t_curr_day += u1_sp_MONTH_NUMDAYS[u1_t_curr_month];     
                }

                u1_t_curr_day %= (U1)NUM_DAYS_IN_WEEK;                        
                u1_t_curr_month++;                                           
            }
        }
        else                                                                    /* Not final year.. count to end of year */
        {
            while(u1_t_curr_month < (U1)NUM_MONTHS_IN_YEAR)                     /* Loop through all months */
            {
                if(u1_t_curr_day == (U1)DAY_SUNDAY)                             /* This month's day1 on Sunday? */
                {
                    u4_t_rtn_sundays++;                                     
                }

                if(
                   (u1_t_curr_month == (U1)MONTH_FEBRUARY) &&                   /* Leap Year ? */
                   (u1_t_leap_year  == (U1)TRUE)
                  )
                {
                    u1_t_curr_day += (U1)FEBRUARY_NUM_DAYS_LEAP;
                }
                else                                                            /* Non-leap year */
                {
                    u1_t_curr_day += u1_sp_MONTH_NUMDAYS[u1_t_curr_month];
                }

                u1_t_curr_day %= (U1)NUM_DAYS_IN_WEEK;
                u1_t_curr_month++;
            }
        }

        u1_t_curr_month = (U1)MONTH_JANUARY;                                    /* Reset month    */
        u4_t_curr_year++;                                                       /* Increment year */
    }

    return(u4_t_rtn_sundays);
}


/*****************************************************************************************************************************************************************\
* Function name     : u1_g_Sundays_LeapYear
* Called by         : Applications
* Argument(s)       : U4 year
* Return            : U1 TRUE/FALSE
* Description       : GetNum1stSundays
\*****************************************************************************************************************************************************************/
U1 u1_g_Sundays_LeapYear(U4 u4_a_year)
{
    U1 u1_t_isleap;

    u1_t_isleap = (U1)FALSE;

    if((u4_a_year % (U4)4) == (U4)0)                /* Evenly divisible by 4 ?   */
    {
        if((u4_a_year % (U4)100) == (U4)0)          /* Evenly divisible by 100 ? */
        {
            if((u4_a_year % (U4)400) == (U4)0)      /* Evenly divisible by 400 ? */
            {
                u1_t_isleap = (U1)TRUE;
            }
        }
        else
        {
            u1_t_isleap = (U1)TRUE;
        }
    }

    return(u1_t_isleap);
}
