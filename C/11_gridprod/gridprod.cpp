/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Grid Product
* Description       : Euler Project 11 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/22/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "gridprod_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
// Answer: 70,600,674


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U4 u4_s_GridProd_GetProduct(void);
static U4 u4_s_GridProd_CheckHoriz(void);
static U4 u4_s_GridProd_CheckVert(void);
static U4 u4_s_GridProd_CheckForwardDiag(void);
static U4 u4_s_GridProd_CheckBackwardDiag(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_GridProd_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 11 GridProd
\*****************************************************************************************************************************************************************/
void vd_g_GridProd_Main(void)
{
    U4 u4_t_ans;

    cout << "Using 4 adjacent numbers in all directions, find the largest product in the 20x20 grid..\n\n";

    u4_t_ans = u4_s_GridProd_GetProduct();

    cout << "Answer:\t" << u4_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_GridProd_GetProduct
* Called by         : vd_g_GridProd_Main
* Argument(s)       : void
* Return            : U4
* Description       : GetProduct
\*****************************************************************************************************************************************************************/
static U4 u4_s_GridProd_GetProduct(void)
{
    U4 u4_t_rtn;
    U4 u4_t_horiz;
    U4 u4_t_vert;
    U4 u4_t_for_diag;
    U4 u4_t_back_diag;

    u4_t_horiz     = u4_s_GridProd_CheckHoriz();
    u4_t_vert      = u4_s_GridProd_CheckVert();
    u4_t_for_diag  = u4_s_GridProd_CheckForwardDiag();
    u4_t_back_diag = u4_s_GridProd_CheckBackwardDiag();

    u4_t_rtn = u4_t_horiz;

    if(u4_t_rtn < u4_t_vert)
    {
        u4_t_rtn = u4_t_vert;
    }

    if(u4_t_rtn < u4_t_for_diag)
    {
        u4_t_rtn = u4_t_for_diag;
    }

    if(u4_t_rtn < u4_t_back_diag)
    {
        u4_t_rtn = u4_t_back_diag;
    }

    return(u4_t_rtn);
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_GridProd_CheckHoriz
* Called by         : u4_s_GridProd_GetProduct
* Argument(s)       : void
* Return            : U4
* Description       : Check Horizontal Products
\*****************************************************************************************************************************************************************/
static U4 u4_s_GridProd_CheckHoriz(void)
{
    U4 u4_t_max;
    U1 u1_t_row;
    U1 u1_t_col;
    U4 u4_t_tmp;

    u4_t_max = (U4)0;

    for(u1_t_row = (U1)0; u1_t_row < (U1)GRIDPROD_ROW_LENGTH; u1_t_row++)
    {
        for(u1_t_col = (U1)0; u1_t_col < (U1)(GRIDPROD_COL_LENGTH - 3); u1_t_col++)
        {
            u4_t_tmp = (U4)(u1_sp_GRID[u1_t_col][u1_t_row] * u1_sp_GRID[u1_t_col+1][u1_t_row] * u1_sp_GRID[u1_t_col+2][u1_t_row] * u1_sp_GRID[u1_t_col+3][u1_t_row]);

            if(u4_t_tmp > u4_t_max)
            {
                u4_t_max = u4_t_tmp;
            }
        }
    }

    return(u4_t_max);
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_GridProd_CheckVert
* Called by         : u4_s_GridProd_GetProduct
* Argument(s)       : void
* Return            : U4
* Description       : Check Vertical Products
\*****************************************************************************************************************************************************************/
static U4 u4_s_GridProd_CheckVert(void)
{
    U4 u4_t_max;
    U1 u1_t_row;
    U1 u1_t_col;
    U4 u4_t_tmp;

    u4_t_max = (U4)0;

    for(u1_t_col = (U1)0; u1_t_col < (U1)GRIDPROD_COL_LENGTH; u1_t_col++)
    {
        for(u1_t_row = (U1)0; u1_t_row < (U1)(GRIDPROD_ROW_LENGTH - 3); u1_t_row++)
        {
            u4_t_tmp = (U4)(u1_sp_GRID[u1_t_col][u1_t_row] * u1_sp_GRID[u1_t_col][u1_t_row+1] * u1_sp_GRID[u1_t_col][u1_t_row+2] * u1_sp_GRID[u1_t_col][u1_t_row+3]);

            if(u4_t_tmp > u4_t_max)
            {
                u4_t_max = u4_t_tmp;
            }
        }
    }

    return(u4_t_max);
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_GridProd_CheckForwardDiag
* Called by         : u4_s_GridProd_GetProduct
* Argument(s)       : void
* Return            : U4
* Description       : Check Forward Diagonal Products
\*****************************************************************************************************************************************************************/
static U4 u4_s_GridProd_CheckForwardDiag(void)
{
    U4 u4_t_max;
    U1 u1_t_row;
    U1 u1_t_col;
    U4 u4_t_tmp;

    u4_t_max = (U4)0;

    for(u1_t_col = (U1)3; u1_t_col < (U1)GRIDPROD_COL_LENGTH; u1_t_col++)
    {
        for(u1_t_row = (U1)0; u1_t_row < (U1)(GRIDPROD_ROW_LENGTH - 3); u1_t_row++)
        {
            u4_t_tmp = (U4)(u1_sp_GRID[u1_t_col][u1_t_row] * u1_sp_GRID[u1_t_col-1][u1_t_row+1] * u1_sp_GRID[u1_t_col-2][u1_t_row+2] * u1_sp_GRID[u1_t_col-3][u1_t_row+3]);

            if(u4_t_tmp > u4_t_max)
            {
                u4_t_max = u4_t_tmp;
            }
        }
    }

    return(u4_t_max);
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_s_GridProd_CheckBackwardDiag
* Called by         : u4_s_GridProd_GetProduct
* Argument(s)       : void
* Return            : U4
* Description       : Check Backward Diagonal Products
\*****************************************************************************************************************************************************************/
static U4 u4_s_GridProd_CheckBackwardDiag(void)
{
    U4 u4_t_max;
    U1 u1_t_row;
    U1 u1_t_col;
    U4 u4_t_tmp;

    u4_t_max = (U4)0;

    for(u1_t_col = (U1)0; u1_t_col < (U1)(GRIDPROD_COL_LENGTH-3); u1_t_col++)
    {
        for(u1_t_row = (U1)0; u1_t_row < (U1)(GRIDPROD_ROW_LENGTH - 3); u1_t_row++)
        {
            u4_t_tmp = (U4)(u1_sp_GRID[u1_t_col][u1_t_row] * u1_sp_GRID[u1_t_col+1][u1_t_row+1] * u1_sp_GRID[u1_t_col+2][u1_t_row+2] * u1_sp_GRID[u1_t_col+3][u1_t_row+3]);

            if(u4_t_tmp > u4_t_max)
            {
                u4_t_max = u4_t_tmp;
            }
        }
    }

    return(u4_t_max);
}
