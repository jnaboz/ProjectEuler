/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Names
* Description       : Euler Project 22 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/31/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "names_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define NAMES_NUM_NAMES         (5163)
#define NAMES_MAX_NAME_LENGTH   (15)
#define NAMES_SCORE_LENGTH      (10)
// Answer: 871,198,282


/*******************************************************************************\
* Static Variables
\*******************************************************************************/
static U1 u1_s_names_array[NAMES_NUM_NAMES][NAMES_MAX_NAME_LENGTH];
static U4 u4_s_names_score[NAMES_NUM_NAMES];
static U1 u1_s_names_total[NAMES_SCORE_LENGTH];

static ST_CMNFUNC_2D_ARRAY st_s_names = 
{
    &u1_s_names_array[0][0],
    (U4)NAMES_NUM_NAMES,
    (U4)NAMES_MAX_NAME_LENGTH
};

static ST_CMNFUNC_1D_ARRAY st_s_score = 
{
    &u1_s_names_total[0],
    (U4)NAMES_SCORE_LENGTH
};


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4   u4_s_Names_FindSumScores(void);
static void vd_s_Names_SortNames(void);
static void vd_s_Names_DetermineScores(void);
static U4   u4_s_Names_GetTotalScore(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_Names_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 22 Names
\*****************************************************************************************************************************************************************/
void vd_g_Names_Main(void)
{
    U4 u4_t_ans;

    cout << "Find the sum of the score of all names..\n\n";

    u4_t_ans = u4_s_Names_FindSumScores();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Names_FindSumScores
* Called by         : vd_g_Names_Main
* Argument(s)       : void
* Return            : U4
* Description       : FindSumScores
\*****************************************************************************************************************************************************************/
static U4 u4_s_Names_FindSumScores(void)
{
    U4 u4_t_rtn_sum;
    ifstream namesfile;
    U1 u1_t_nextchar;
    U1 u1_t_prevchar;
    U4 u4_t_curr_name;
    U1 u1_t_curr_letter;

    u4_t_curr_name   = (U4)0;
    u1_t_curr_letter = (U1)0;
    u1_t_prevchar    = (U1)0;

    namesfile.open("C:\\Documents and Settings\\dsjnabozny\\My Documents\\02. Learning\\Euler\\src\\22_names\\names.txt");

    if(namesfile.is_open())
    {
        while(namesfile.good())
        {
            u1_t_nextchar = namesfile.get();

            if(                                                                 /* Is a letter ? */
                (u1_t_nextchar >= (U1)NAMES_LETTER_A) &&
                (u1_t_nextchar <= (U1)NAMES_LETTER_Z)
              )
            {
                if(u1_t_curr_letter < (U1)NAMES_MAX_NAME_LENGTH)
                {
                    u1_s_names_array[u4_t_curr_name][u1_t_curr_letter] = u1_t_nextchar;
                    u1_t_curr_letter++;
                }
                else
                {
                    cout << "Name too long...\n\n";
                }
            }
            else                                                                /* Not a letter ... */
            {
                if(
                    (
                        (u1_t_nextchar > (U1)NAMES_LETTER_Z) ||
                        (u1_t_nextchar < (U1)NAMES_LETTER_A)
                    )                                        &&
                    (
                        (u1_t_prevchar > (U1)NAMES_LETTER_Z) ||
                        (u1_t_prevchar < (U1)NAMES_LETTER_A)
                    )
                  )
                {
                    /* Do nothing if both current and previous characters were not letters... */
                }
                else
                {
                    u4_t_curr_name++;
                    u1_t_curr_letter = (U1)0;
                }
            }

            u1_t_prevchar = u1_t_nextchar;
        }
    }
    else
    {
        cout << "Unable to open file..\n\n";
    }

    namesfile.close();

    vd_s_Names_SortNames();
    vd_s_Names_DetermineScores();
    u4_t_rtn_sum = u4_s_Names_GetTotalScore();

    return(u4_t_rtn_sum);
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_s_Names_SortNames
* Called by         : u4_s_Names_FindSumScores
* Argument(s)       : void
* Return            : void
* Description       : Sort Name Array
\*****************************************************************************************************************************************************************/
static void vd_s_Names_SortNames(void)
{
    U4 u4_t_idx;
    U4 u4_t_idx2;
    U1 u1_t_temp_array[NAMES_NUM_NAMES][NAMES_MAX_NAME_LENGTH] = {0};
    ST_CMNFUNC_2D_ARRAY st_tp_temp_array = 
    { 
        &u1_t_temp_array[0][0],
        (U4)NAMES_NUM_NAMES,
        (U4)NAMES_MAX_NAME_LENGTH
    };

    for(u4_t_idx = (U4)0; u4_t_idx < (U4)NAMES_NUM_NAMES; u4_t_idx++)
    {
        for(u4_t_idx2 = (U4)0; u4_t_idx2 < (U4)NAMES_MAX_NAME_LENGTH; u4_t_idx2++)
        {
            u1_t_temp_array[u4_t_idx][u4_t_idx2] = (U1)0;
        }
    }

    vd_g_CmnFunc_Sort2DArray(&st_s_names, &st_tp_temp_array);
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_s_Names_DetermineScores
* Called by         : u4_s_Names_FindSumScores
* Argument(s)       : void
* Return            : void
* Description       : Sort Name Array
\*****************************************************************************************************************************************************************/
static void vd_s_Names_DetermineScores(void)
{
    U4 u4_t_idx;
    U4 u4_t_prev;
    U4 u4_t_letter;

    for(u4_t_idx = (U4)0; u4_t_idx < (U4)NAMES_NUM_NAMES; u4_t_idx++)
    {
        u4_s_names_score[u4_t_idx] = (U4)0;
    }

    for(u4_t_idx = (U4)0; u4_t_idx < (U4)NAMES_NUM_NAMES; u4_t_idx++)
    {
        for(u4_t_letter = (U4)0; u4_t_letter < (U4)NAMES_MAX_NAME_LENGTH; u4_t_letter++)
        {
            if(u1_s_names_array[u4_t_idx][u4_t_letter] != (U1)0)
            {
                u4_s_names_score[u4_t_idx] += (U4)(u1_s_names_array[u4_t_idx][u4_t_letter] - (U1)NAMES_SCORE_OFFSET);
            }
            else
            {
                u4_t_letter = (U4)NAMES_MAX_NAME_LENGTH;
            }
        }
        
        u4_t_prev                   = u4_s_names_score[u4_t_idx];
        u4_s_names_score[u4_t_idx] *= (u4_t_idx + (U1)1);

        if(
            (u4_t_prev > u4_s_names_score[u4_t_idx]) &&
            (u4_t_idx != (U4)0)
          )
        {
            cout << "DetermineScores Overflow, idx " << u4_t_idx << "...\n\n";
        }
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_Names_GetTotalScore
* Called by         : u4_s_Names_FindSumScores
* Argument(s)       : void
* Return            : U4
* Description       : Find total sum of scores
\*****************************************************************************************************************************************************************/
static U4 u4_s_Names_GetTotalScore(void)
{
    U4 u4_t_rtn;
    U4 u4_t_idx;
    U4 u4_t_prev;

    u4_t_rtn  = (U4)0;
    u4_t_prev = (U4)0;

    for(u4_t_idx = (U4)0; u4_t_idx < (U4)NAMES_NUM_NAMES; u4_t_idx++)
    {
        u4_t_prev = u4_t_rtn;
        u4_t_rtn += u4_s_names_score[u4_t_idx];

        if(u4_t_rtn < u4_t_prev)
        {
            cout << "GetTotalScore Overflow...\n\n";
        }
    }

    return(u4_t_rtn);
}
