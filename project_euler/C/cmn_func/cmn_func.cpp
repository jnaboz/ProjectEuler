/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Common Function Source Code
* Description       : Euler Project Common Functions Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/29/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "cmn_func_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/


/*******************************************************************************\
* Static Variables
\*******************************************************************************/


/*******************************************************************************\
* Static Functions
\*******************************************************************************/


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : u4_g_CmnFunc_GetPowXtoY
* Called by         : Applications
* Argument(s)       : U1, U1
* Return            : U4
* Description       : Find x^y
\*****************************************************************************************************************************************************************/
U4 u4_g_CmnFunc_GetPowXtoY(U1 u1_a_x, U1 u1_a_y)
{
    U1 u1_t_idx;
    U4 u4_t_rtn;

    u4_t_rtn = (U4)1;                                                   

    if(u1_a_y > (U1)0)
    {
        for(u1_t_idx = (U1)0; u1_t_idx < u1_a_y; u1_t_idx++)
        {
            u4_t_rtn *= (U4)u1_a_x;
        }
    }

    return(u4_t_rtn);
}


/*****************************************************************************************************************************************************************\
* Function name     : u4_g_CmnFunc_GetMaxTwoVal
* Called by         : Applications
* Argument(s)       : U4, U4
* Return            : U4
* Description       : Find max value between two numbers
\*****************************************************************************************************************************************************************/
U4 u4_g_CmnFunc_GetMaxTwoVal(U4 u4_a_val1, U4 u4_a_val2)
{
    if(u4_a_val1 > u4_a_val2)
    {
        return(u4_a_val1);
    }
    else
    {
        return(u4_a_val2);
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_CmnFunc_ValInto1DArray
* Called by         : Applications
* Argument(s)       : U4, ST_CMNFUNC_1D_ARRAY *
* Return            : void
* Description       : Place u4_a_value into st_ap_array.
\*****************************************************************************************************************************************************************/
void vd_g_CmnFunc_ValInto1DArray(U4 u4_a_value, ST_CMNFUNC_1D_ARRAY * st_ap_array)
{
    U4   u4_t_idx;
    U1 * u1_tp_array;
    U4   u4_t_value;

    u4_t_value  = u4_a_value;
    u1_tp_array = st_ap_array->u1_array;

    for(u4_t_idx = (U4)0; u4_t_idx < st_ap_array->u4_size; u4_t_idx++)
    {
        *u1_tp_array = (U1)(u4_t_value % (U4)10);
        u4_t_value  /= (U4)10;
        u1_tp_array++;
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_CmnFunc_Copy1DArray
* Called by         : Applications
* Argument(s)       : ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *
* Return            : void
* Description       : Store 1D array into a different array
\*****************************************************************************************************************************************************************/
void vd_g_CmnFunc_Copy1DArray(ST_CMNFUNC_1D_ARRAY * st_ap_result, ST_CMNFUNC_1D_ARRAY * st_ap_tocopy)
{    
    U1 * u1_tp_result;
    U1 * u1_tp_tocopy;
    U4   u4_t_idx;

    u1_tp_result = st_ap_result->u1_array;
    u1_tp_tocopy = st_ap_tocopy->u1_array;

    for(u4_t_idx = (U4)0; u4_t_idx < (U4)st_ap_result->u4_size; u4_t_idx++)
    {
        (*(u1_tp_result + u4_t_idx)) = (*(u1_tp_tocopy + u4_t_idx));
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_CmnFunc_Add1DArray
* Called by         : Applications
* Argument(s)       : ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *
* Return            : void
* Description       : Add two 1D arrays
\*****************************************************************************************************************************************************************/
void vd_g_CmnFunc_Add1DArray(ST_CMNFUNC_1D_ARRAY * st_ap_result, ST_CMNFUNC_1D_ARRAY * st_ap_addin)
{
    U1 * u1_tp_result;
    U1 * u1_tp_addin;
    U4   u4_t_idx;

    u1_tp_result = st_ap_result->u1_array;
    u1_tp_addin  = st_ap_addin->u1_array;

    for(u4_t_idx = (U4)0; u4_t_idx < st_ap_result->u4_size; u4_t_idx++)
    {
        (*(u1_tp_result + u4_t_idx)) += (*(u1_tp_addin + u4_t_idx));

        if((*(u1_tp_result + u4_t_idx)) > (U1)9)
        {
            (*(u1_tp_result + u4_t_idx + (U4)1)) += ((*(u1_tp_result + u4_t_idx)) / (U1)10);
            (*(u1_tp_result + u4_t_idx))         %= (U1)10;
        }
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_CmnFunc_Sub1DArray
* Called by         : Applications
* Argument(s)       : ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *
* Return            : void
* Description       : Subtract two 1D arrays ... MUST RETURN POSITIVE
\*****************************************************************************************************************************************************************/
void vd_g_CmnFunc_Sub1DArray(ST_CMNFUNC_1D_ARRAY * st_ap_result, ST_CMNFUNC_1D_ARRAY * st_ap_subin)
{
    U1 * u1_tp_result;
    U1 * u1_tp_subin;
    U4   u4_t_idx;
    U4   u4_t_borrow_idx;
    U1   u1_t_primary;
    U1   u1_t_secondary;
    U1   u1_t_borrow_continue;

    u1_tp_result = st_ap_result->u1_array;
    u1_tp_subin  = st_ap_subin->u1_array;

    for(u4_t_idx = (U4)0; u4_t_idx < (U4)st_ap_result->u4_size; u4_t_idx++)
    {
        u4_t_borrow_idx = u4_t_idx + (U4)1;

        u1_t_primary   = (*(u1_tp_result + u4_t_idx));
        u1_t_secondary = (*(u1_tp_subin + u4_t_idx));

        if(u1_t_secondary > u1_t_primary)
        {
            u1_t_borrow_continue = (U1)TRUE;

            while(u1_t_borrow_continue == (U1)TRUE)
            {
                if(u4_t_borrow_idx < st_ap_result->u4_size)
                {
                    if((*(u1_tp_result + u4_t_borrow_idx)) == (U1)0)
                    {
                        u4_t_borrow_idx++;
                    }
                    else
                    {
                        while(u4_t_borrow_idx > u4_t_idx)
                        {
                            (*(u1_tp_result + u4_t_borrow_idx))         -= (U1)1;       /* Subtract 1 to borrow  */
                            (*(u1_tp_result + u4_t_borrow_idx - (U4)1)) += (U1)10;      /* Add 10 from borrowing */
                            u4_t_borrow_idx--;
                        }

                        u1_t_borrow_continue = (U1)FALSE;
                    }
                }
                else
                {
                    cout << "Error: Negative result...\n\n";
                    u1_t_borrow_continue = (U1)FALSE;
                }
            }
        }
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_CmnFunc_MultDecArray
* Called by         : Applications
* Argument(s)       : 
* Return            : void
* Description       : Multiply decimal numbers via 1D array. 
\*****************************************************************************************************************************************************************/
void vd_g_CmnFunc_MultDec1DArray(ST_CMNFUNC_1D_ARRAY * st_ap_product, ST_CMNFUNC_1D_ARRAY * st_ap_multby, ST_CMNFUNC_1D_ARRAY * st_ap_temp)
{
    U4   u4_t_product_size;
    U1 * u1_tp_product_array;
    U4   u4_t_multby_size;
    U1 * u1_tp_multby_array;
    U4   u4_t_temp_size;
    U1 * u1_tp_temp_array;

    U4   u4_t_temp_prod;
    U1   u1_t_carry;
    U4   u4_t_multby_idx;
    U4   u4_t_product_idx;

    /* Get array information */
    u4_t_product_size   = st_ap_product->u4_size;
    u1_tp_product_array = st_ap_product->u1_array;
    u4_t_multby_size    = st_ap_multby->u4_size;
    u1_tp_multby_array  = st_ap_multby->u1_array;
    u4_t_temp_size      = st_ap_temp->u4_size;
    u1_tp_temp_array    = st_ap_temp->u1_array;

    /* Initialize running variables */
    u4_t_temp_prod      = (U4)0;
    u1_t_carry          = (U1)0;

    /* Loop through multiplying number digits */
    for(u4_t_multby_idx = (U4)0; u4_t_multby_idx < st_ap_multby->u4_size; u4_t_multby_idx++)
    {
        /* Loop through product digits */
        for(u4_t_product_idx = (U4)0; u4_t_product_idx < st_ap_product->u4_size; u4_t_product_idx++)
        {
            (*(u1_tp_temp_array + u4_t_product_idx + u4_t_multby_idx)) += ((*(u1_tp_multby_array + u4_t_multby_idx)) * (*(u1_tp_product_array + u4_t_product_idx)));

            if((*(u1_tp_temp_array + u4_t_product_idx + u4_t_multby_idx)) > (U1)9)
            {
                (*(u1_tp_temp_array + u4_t_product_idx + u4_t_multby_idx + 1)) += ((*(u1_tp_temp_array + u4_t_product_idx + u4_t_multby_idx)) / (U1)10);
                (*(u1_tp_temp_array + u4_t_product_idx + u4_t_multby_idx))     %= (U1)10;
            }
        }
    }

    for(u4_t_product_idx = (U4)0; u4_t_product_idx < st_ap_product->u4_size; u4_t_product_idx++)
    {
        (*(u1_tp_product_array + u4_t_product_idx)) = (*(u1_tp_temp_array + u4_t_product_idx));
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_CmnFunc_Sort2DArray
* Called by         : Applications
* Argument(s)       : 
* Return            : void
* Description       : Sort a 2D array, smallest value in a row to largest value in a row.. excess space (no data) is left at the bottom
\*****************************************************************************************************************************************************************/
void vd_g_CmnFunc_Sort2DArray(ST_CMNFUNC_2D_ARRAY * st_ap_input, ST_CMNFUNC_2D_ARRAY * st_ap_temp)
{
    U1 * u1_tp_temp_array;
    U1 * u1_tp_input_array;
    U4   u4_t_temp_row;
    U4   u4_t_input_row;
    U4   u4_t_col;
    U4   u4_t_temp_idx;
    U1   u1_t_min_value;
    U1   u1_t_continue;

    u1_tp_temp_array  = st_ap_temp->u1_2d_array;
    u1_tp_input_array = st_ap_input->u1_2d_array;

    for(u4_t_temp_row = (U4)0; u4_t_temp_row < st_ap_temp->u4_num_row; u4_t_temp_row++)
    {
        u4_t_temp_idx  = (U4)0;
        u1_t_min_value = (U1)0xFF;

        for(u4_t_input_row = (U4)0; u4_t_input_row < st_ap_input->u4_num_row; u4_t_input_row++)
        {
            u4_t_col = (U4)0;

            if((*(u1_tp_input_array + ((u4_t_input_row * st_ap_input->u4_num_col)))) != (U1)0)
            {
                if(u1_t_min_value > (*(u1_tp_input_array + (u4_t_input_row * st_ap_input->u4_num_col))))
                {
                    /* New smallest value */
                    u1_t_min_value = (*(u1_tp_input_array + (u4_t_input_row * st_ap_input->u4_num_col)));
                    u4_t_temp_idx  = u4_t_input_row;
                }
                else if(u1_t_min_value == (*(u1_tp_input_array + (u4_t_input_row * st_ap_input->u4_num_col))))
                {
                    /* Check next values */
                    u4_t_col++;
                    u1_t_continue = (U1)TRUE;

                    while(u1_t_continue == (U1)TRUE)
                    {
                        if(u4_t_col < st_ap_input->u4_num_col)
                        {
                            if((*(u1_tp_input_array + ((u4_t_input_row * st_ap_input->u4_num_col) + u4_t_col))) < (*(u1_tp_input_array + ((u4_t_temp_idx * st_ap_input->u4_num_col) + u4_t_col))))
                            {
                                /* New value less than old value */
                                u4_t_temp_idx = u4_t_input_row;
                                u1_t_continue = (U1)FALSE;
                            }
                            else if((*(u1_tp_input_array + ((u4_t_input_row * st_ap_input->u4_num_col) + u4_t_col))) > (*(u1_tp_input_array + ((u4_t_temp_idx * st_ap_input->u4_num_col) + u4_t_col))))
                            {
                                /* Old value less than new value */
                                u1_t_continue = (U1)FALSE;
                            }
                            else
                            {
                                /* Still equal ... */
                                u4_t_col++;
                            }
                        }
                        else
                        {
                            /* Rows are equal */
                            u1_t_continue = (U1)FALSE;
                        }
                    }
                }
            }
            else
            {
                /* Do nothing.. still maintain current index */
            }
        }

        for(u4_t_col = (U4)0; u4_t_col < st_ap_temp->u4_num_col; u4_t_col++)
        {
            /* Place smallest row in temp array */
            (*(u1_tp_temp_array + ((u4_t_temp_row * st_ap_temp->u4_num_col) + u4_t_col))) = (*(u1_tp_input_array + ((u4_t_temp_idx * st_ap_input->u4_num_col) + u4_t_col)));

            /* Clear input area for next iteration */
            (*(u1_tp_input_array + ((u4_t_temp_idx * st_ap_input->u4_num_col) + u4_t_col))) = (U1)0xFF;
        }
    }

    /* Place data back into original array */
    for(u4_t_temp_row = (U4)0; u4_t_temp_row < st_ap_temp->u4_num_row; u4_t_temp_row++)
    {
        for(u4_t_col = (U4)0; u4_t_col < st_ap_temp->u4_num_col; u4_t_col++)
        {
            (*(u1_tp_input_array + ((u4_t_temp_row * st_ap_input->u4_num_col) + u4_t_col))) = (*(u1_tp_temp_array + ((u4_t_temp_row * st_ap_temp->u4_num_col) + u4_t_col)));
        }
    }
}


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_CmnFunc_GetNextFibNum
* Called by         : Applications
* Argument(s)       : ST_CMNFUNC_1D_ARRAY *, ST_CMNFUNC_1D_ARRAY *
* Return            : void
* Description       : Use 1D arrays to find next fibonacci number
\*****************************************************************************************************************************************************************/
void vd_g_CmnFunc_GetNextFibNum(ST_CMNFUNC_1D_ARRAY * st_ap_curr, ST_CMNFUNC_1D_ARRAY * st_ap_prev, ST_CMNFUNC_1D_ARRAY * st_ap_temp)
{
    vd_g_CmnFunc_Copy1DArray(st_ap_temp, st_ap_curr);       /* Save value               */
    vd_g_CmnFunc_Add1DArray(st_ap_curr, st_ap_prev);        /* Find new number          */
    vd_g_CmnFunc_Copy1DArray(st_ap_prev, st_ap_temp);       /* Save previous value      */
}
