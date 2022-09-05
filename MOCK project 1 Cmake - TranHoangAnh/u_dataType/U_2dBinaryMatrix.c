/**
  ******************************************************************************
  * @file    u_2dBinaryMatrix.c
  * @author  TranHoangAnh
  * @brief
  *
  ==============================================================================
						##### 2dBinaryMatrix Class #####
  ==============================================================================
  */

#include "U_2dBinaryMatrix.h"
#include "U_staticMethod_2dBinaryMatrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"

/**
 * @brief  binMatrix Class constructor
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int):			row Size
 * @param  column (int):		collum Size
 * @retval (void)
 */
void binMatrix_constructor(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{

	this_->numbOfElm = row * column;
	this_->data == NULL;
	this_->data = (binMatrix_elementType *)malloc(sizeof(binMatrix_elementType) * this_->numbOfElm);
	if (this_->data == NULL)
	{
		// todo:	 Call Dynamic-Allocating-Fail-Handler.
	}
	else
	{
		this_->firstElm = this_->data;
		this_->lastElm = &this_->data[this_->numbOfElm - 1];
		this_->numbOfCol = column;
		this_->numbOfRow = row;

		for (uint16_t i = 0; i <= this_->numbOfElm - 1; i++)
		{
			this_->data[i] = 0;
		}
	}
}
/**
 * @brief  binMatrix Class constructor
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @retval (void)
 */
void binMatrix_destructor(binMatrix_2dBinaryMatrix *this_)
{
	if (this_->data != NULL)
	{
		free(this_->data);
	}
}
/**
 * @brief  print All element of the matrix
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @retval (void)
 */
void binMatrix_print(binMatrix_2dBinaryMatrix *this_)
{
	int32_t row, columns;
	printf("===========================================================");
	printf("\n");
	for (row = 0; row < this_->numbOfRow; row++)
	{
		for (columns = 0; columns < this_->numbOfCol; columns++)
		{
			if (*binMatrix_pointToElement(this_, row, columns) == 0)
			{
				printf(ANSI_COLOR_GREEN "%d     ", *binMatrix_pointToElement(this_, row, columns));
			}
			else
			{
				printf(ANSI_COLOR_RED "%d     ", *binMatrix_pointToElement(this_, row, columns));
			}
		}
		printf("\n");
	}
}
/**
 * @brief  pointing to the address of the element which at pos: row, column
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (binMatrix_elementType*) pointer to the address of the element which at pos:row, column
 */
binMatrix_elementType *binMatrix_pointToElement(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{
	int32_t rowIndex = 0;
	int32_t colIndex = 0;
	int32_t posOfMatrix = 0;
	rowIndex = (row)*this_->numbOfCol;
	colIndex = (column + 1);
	posOfMatrix = rowIndex + colIndex;

	return &this_->data[posOfMatrix - 1];
}
/**
 * @brief  Do not use this method, it had is not completely developed yet
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @retval
 */
binMatrix_axis_T binMatrix_arrIndex2AxisIndex(uint16_t arrayIndex)
{
	binMatrix_axis_T res = {.col = 0, .row = 0};

	// Todo: inlement this

	return res;
}
/**
 * @brief  cheack if the emlement at pos: row, collum is set
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (uint32_t*) :(1) is set, (0) is clear
 */
uint32_t binMatrix_isSet(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{
	uint32_t res = 0;
	if (*binMatrix_pointToElement(this_, row, column) == 1)
	{
		res = 1;
	}
	else
	{
		res = 0;
	}
	return res;
}
/**
 * @brief  cheack if all the emlement in this obj is set
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (uint32_t*) :(1) is all set, (0) is not all set
 */
uint32_t binMatrix_isAllSet(binMatrix_2dBinaryMatrix *this_)
{
	uint32_t res = 1;
	for (uint32_t i = 0; i <= this_->numbOfElm - 1; i++)
	{
		if (this_->data[i] == 0)
		{
			res = 0;
			break;
		}
	}
	return res;
}

/**
 * @brief  setting all the adjacency element at this position.
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (void)
 */
void binMatrix_setAdjElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{
	if (binMatrix_getLeftElm(this_, row, column) != NULL)
	{
		*binMatrix_getLeftElm(this_, row, column) = 1;
	}
	if (binMatrix_getRightElm(this_, row, column) != NULL)
	{
		*binMatrix_getRightElm(this_, row, column) = 1;
	}
	if (binMatrix_getUpElm(this_, row, column) != NULL)
	{
		*binMatrix_getUpElm(this_, row, column) = 1;
	}
	if (binMatrix_getDowntElm(this_, row, column) != NULL)
	{
		*binMatrix_getDowntElm(this_, row, column) = 1;
	}
}
/**
 * @brief  overloading copy operation
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @retval (void)
 */
void binMatrix_copyData(binMatrix_2dBinaryMatrix *des, binMatrix_2dBinaryMatrix *src)
{
	memcpy(des->data, src->data, sizeof(binMatrix_elementType) * src->numbOfElm);
}
/**
 * @brief  overloading Wise OR operation
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @retval (void)
 */
void binMatrix_bitWiseOrData(binMatrix_2dBinaryMatrix *des, binMatrix_2dBinaryMatrix *src)
{
	for (uint16_t i = 0; i <= des->numbOfElm - 1; i++)
	{
		des->data[i] = des->data[i] || src->data[i];
	}
}
/**
 * @brief  poiting to the left element of the element which at pos: row, column
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (binMatrix_elementType*)	  the left emlement
 */
static binMatrix_elementType *binMatrix_getLeftElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{
	binMatrix_elementType *res = NULL;
	int32_t s32_columnAdj = 0;
	s32_columnAdj = column - 1;
	if (s32_columnAdj < 0)
	{
		res = NULL;
	}
	else
	{
		res = binMatrix_pointToElement(this_, row, s32_columnAdj);
	}
	return res;
}
/**
 * @brief  poiting to the right element of the element which at pos: row, column
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (binMatrix_elementType*)	  the right emlement
 */
static binMatrix_elementType *binMatrix_getRightElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{
	binMatrix_elementType *res = NULL;
	int32_t s32_columnAdj = 0;
	s32_columnAdj = column + 1;
	if (s32_columnAdj >= this_->numbOfCol)
	{
		res = NULL;
	}
	else
	{
		res = binMatrix_pointToElement(this_, row, s32_columnAdj);
	}
	return res;
}
/**
 * @brief  poiting to the above element of the element which at pos: row, column
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (binMatrix_elementType*)	  the above emlement
 */
static binMatrix_elementType *binMatrix_getUpElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{
	binMatrix_elementType *res = NULL;
	int32_t s32_rowAdj = 0;
	s32_rowAdj = row - 1;
	if (s32_rowAdj < 0)
	{
		res = NULL;
	}
	else
	{
		res = binMatrix_pointToElement(this_, s32_rowAdj, column);
	}
	return res;
}
/**
 * @brief  poiting to the below element of the element which at pos: row, column
 * @param  this_	(binMatrix_2dBinaryMatrix * )		 pointer to the binMatrix_2dBinaryMatrix obj.
 * @param  row (int32_t):			row pos
 * @param  column (int32_t):		collum pos
 * @retval (binMatrix_elementType*)	  the below emlement
 */
static binMatrix_elementType *binMatrix_getDowntElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column)
{
	binMatrix_elementType *res = NULL;
	int32_t s32_rowAdj = 0;
	s32_rowAdj = row + 1;
	if (s32_rowAdj >= this_->numbOfRow)
	{
		res = NULL;
	}
	else
	{
		res = binMatrix_pointToElement(this_, s32_rowAdj, column);
	}
	return res;
}
