/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Sundays
* Description       : Euler Project 19
* Original Author   : Jake Nabozny
* Date Created      : 10/26/2012
\*****************************************************************************************************************************************************************/

#ifndef SUNDAYS_PUBLIC_H
#define SUNDAYS_PUBLIC_H


/*******************************************************************************\
* Type Definitions
\*******************************************************************************/


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
/* Months */
#define MONTH_JANUARY               (0)
#define MONTH_FEBRUARY              (1)
#define MONTH_MARCH                 (2)
#define MONTH_APRIL                 (3)
#define MONTH_MAY                   (4)
#define MONTH_JUNE                  (5)
#define MONTH_JULY                  (6)
#define MONTH_AUGUST                (7)
#define MONTH_SEPTEMBER             (8)
#define MONTH_OCTOBER               (9)
#define MONTH_NOVEMBER              (10)
#define MONTH_DECEMBER              (11)
#define NUM_MONTHS_IN_YEAR          (12)

#define JANUARY_NUM_DAYS            (31)
#define FEBRUARY_NUM_DAYS           (28)
#define FEBRUARY_NUM_DAYS_LEAP      (29)
#define MARCH_NUM_DAYS              (31)
#define APRIL_NUM_DAYS              (30)
#define MAY_NUM_DAYS                (31)
#define JUNE_NUM_DAYS               (30)
#define JULY_NUM_DAYS               (31)
#define AUGUST_NUM_DAYS             (31)
#define SEPTEMBER_NUM_DAYS          (30)
#define OCTOBER_NUM_DAYS            (31)
#define NOVEMBER_NUM_DAYS           (30)
#define DECEMBER_NUM_DAYS           (31)

/* Days */
#define DAY_MONDAY                  (0)
#define DAY_TUESDAY                 (1)
#define DAY_WEDNESDAY               (2)
#define DAY_THURSDAY                (3)
#define DAY_FRIDAY                  (4)
#define DAY_SATURDAY                (5)
#define DAY_SUNDAY                  (6)
#define NUM_DAYS_IN_WEEK            (7)


/*******************************************************************************\
* Constant Data
\*******************************************************************************/
static const U1 u1_sp_MONTH_NUMDAYS[NUM_MONTHS_IN_YEAR] =
{
    (U1)JANUARY_NUM_DAYS,       /* 0.  January   */
    (U1)FEBRUARY_NUM_DAYS,      /* 1.  February  */
    (U1)MARCH_NUM_DAYS,         /* 2.  March     */ 
    (U1)APRIL_NUM_DAYS,         /* 3.  April     */ 
    (U1)MAY_NUM_DAYS,           /* 4.  May       */ 
    (U1)JUNE_NUM_DAYS,          /* 5.  June      */ 
    (U1)JULY_NUM_DAYS,          /* 6.  July      */ 
    (U1)AUGUST_NUM_DAYS,        /* 7.  August    */ 
    (U1)SEPTEMBER_NUM_DAYS,     /* 8.  September */ 
    (U1)OCTOBER_NUM_DAYS,       /* 9.  October   */ 
    (U1)NOVEMBER_NUM_DAYS,      /* 10. November  */ 
    (U1)DECEMBER_NUM_DAYS       /* 11. December  */ 
};


/*******************************************************************************\
* Public Function Declarations
\*******************************************************************************/
void vd_g_Sundays_Main(void);
U1   u1_g_Sundays_LeapYear(U4);


#endif // SUNDAYS_PUBLIC_H
