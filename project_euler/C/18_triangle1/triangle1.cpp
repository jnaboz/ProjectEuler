/* 1.0.0 */
/*****************************************************************************************************************************************************************\
 * Module Name       : Triangle1
 * Description       : Euler Project 18 Source Code
 * Original Author   : Jake Nabozny
 * Date Created      : 10/26/2012
 \*****************************************************************************************************************************************************************/


/*******************************************************************************\
 * Include Files
 \*******************************************************************************/
#include "triangle1_private.h"
#include "cmn_func_public.h"


/*******************************************************************************\
 * Macro Definitions
 \*******************************************************************************/
#define __TEST_TRIANGLE__       (1)
#define __PROJ_TRIANGLE__       (2)
#define __CURR_TRI_TEST__       (__PROJ_TRIANGLE__)

#define TRIANGLE1_LOOK_AHEAD    (3)
// Answer: 1064


/*******************************************************************************\
 * Static Variables
 \*******************************************************************************/


/*******************************************************************************\
 * Static Functions
 \*******************************************************************************/
static U4 u4_s_Triangle1_GetMaxSum(void);


/*******************************************************************************\
 * Function Definitions
 \*******************************************************************************/


/*****************************************************************************************************************************************************************\
 * Function name     : vd_g_Triangle1_Main
 * Called by         : main
 * Argument(s)       : void
 * Return            : void
 * Description       : Entry Point for Euler Project 18 Triangle1
 \*****************************************************************************************************************************************************************/
void vd_g_Triangle1_Main(void)
{
    U4 u4_t_ans;

    cout << "Find the largest sum in the triangle..\n\n";

    u4_t_ans = u4_s_Triangle1_GetMaxSum();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
 * Function name     : u4_s_triangle1_getmaxsum
 * Called by         : vd_g_triangle1_main
 * Argument(s)       : void
 * Return            : u4
 * Description       : getmaxsum
 \*****************************************************************************************************************************************************************/
static U4 u4_s_Triangle1_GetMaxSum(void)
{
    U4 u4_t_rtn_sum;
    U4 u4_t_curr_row;
    U4 u4_t_curr_col;

#if(__CURR_TRI_TEST__ == __TEST_TRIANGLE__)
    U4 u4_t_ans_tri[TEST_TRIANGLE_ROW][TEST_TRIANGLE_COL];

    for(u4_t_curr_row = (U4)0; u4_t_curr_row < (U4)TEST_TRIANGLE_ROW; u4_t_curr_row++)
    {
        for(u4_t_curr_col = (U4)0; u4_t_curr_col < (U4)TEST_TRIANGLE_COL; u4_t_curr_col++)
        {
            u4_t_ans_tri[u4_t_curr_row][u4_t_curr_col] = u1_sp_TEST_TRIANGLE[u4_t_curr_row][u4_t_curr_col];
        }
    }

    vd_g_Triangle_GetMaxSum((U4)TEST_TRIANGLE_ROW, (U4)TEST_TRIANGLE_COL, &u4_t_ans_tri[0][0]);
#else
    U4 u4_t_ans_tri[TRIANGLE1_NUM_ROW][TRIANGLE1_NUM_COL];

    for(u4_t_curr_row = (U4)0; u4_t_curr_row < (U4)TRIANGLE1_NUM_ROW; u4_t_curr_row++)
    {
        for(u4_t_curr_col = (U4)0; u4_t_curr_col < (U4)TRIANGLE1_NUM_COL; u4_t_curr_col++)
        {
            u4_t_ans_tri[u4_t_curr_row][u4_t_curr_col] = u1_sp_TRIANGLE1_INPUT[u4_t_curr_row][u4_t_curr_col];
        }
    }

    vd_g_Triangle_GetMaxSum((U4)TRIANGLE1_NUM_ROW, (U4)TRIANGLE1_NUM_COL, &u4_t_ans_tri[0][0]);
#endif
    u4_t_rtn_sum = u4_t_ans_tri[0][0];

    return(u4_t_rtn_sum);
}


/*****************************************************************************************************************************************************************\
 * function name     : u4_g_Triangle_GetMaxSum
 * called by         : Triangle Applications
 * argument(s)       : ST_TRIANGLE_TYPE
 * return            : U4 sum
 * description       : Get largest sum in triangle
 \*****************************************************************************************************************************************************************/
void vd_g_Triangle_GetMaxSum(U4 u4_a_num_row, U4 u4_a_num_col, U4 * u4_ap_triangle)
{
    U4   u4_t_curr_row;
    U4   u4_t_curr_col;
    U4   u4_t_curr_row_length;
    U4   u4_t_left_num;
    U4   u4_t_right_num;
    U4   u4_t_addmax;
    U4 * u4_t_curr_place;

    u4_t_curr_row        = (u4_a_num_row - (U4)1);
    u4_t_curr_row_length = u4_a_num_col;

    while(u4_t_curr_row > (U4)0)
    {
        u4_t_curr_row--;
        u4_t_curr_row_length--;

        for(u4_t_curr_col = (U4)0; u4_t_curr_col < u4_t_curr_row_length; u4_t_curr_col++)
        {
            u4_t_left_num     = (U4)(*(u4_ap_triangle + (((u4_t_curr_row + (U4)1) * u4_a_num_col) + u4_t_curr_col)));
            u4_t_right_num    = (U4)(*(u4_ap_triangle + (((u4_t_curr_row + (U4)1) * u4_a_num_col) + (u4_t_curr_col + (U4)1))));
            u4_t_addmax       = u4_g_CmnFunc_GetMaxTwoVal(u4_t_left_num, u4_t_right_num);
            u4_t_curr_place   = (u4_ap_triangle + ((u4_t_curr_row * u4_a_num_col) + u4_t_curr_col));
            *u4_t_curr_place += u4_t_addmax;
        }
    }
}
