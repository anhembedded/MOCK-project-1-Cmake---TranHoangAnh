/**
  ******************************************************************************
  * @file    u_2dBinaryMatrix.h
  * @author  TranHoangAnh
  * @brief
  *
  ==============================================================================
                        ##### 2dBinaryMatrix Class #####
  ==============================================================================
  */

#ifndef MOCK_PROJECT_1_CMAKE_TRANHOANGANH_U_2DBINARYMATRIX_H
#define MOCK_PROJECT_1_CMAKE_TRANHOANGANH_U_2DBINARYMATRIX_H

#include <stdint.h>

// pos-fix for this module is: binMatrix

typedef uint32_t binMatrix_elementType;

typedef struct
{
  int32_t col;
  int32_t row;
} binMatrix_axis_T;

typedef struct
{
  uint16_t numbOfElm;
  uint16_t numbOfRow;
  uint16_t numbOfCol;
  binMatrix_elementType *firstElm;
  binMatrix_elementType *lastElm;
  binMatrix_elementType *data;

} binMatrix_2dBinaryMatrix;

/* Constructor and Destructor */
void binMatrix_constructor(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column);
void binMatrix_destructor(binMatrix_2dBinaryMatrix *this_);

/* Public Methods*/
binMatrix_elementType *binMatrix_pointToElement(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column);
uint32_t binMatrix_isSet(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column);
uint32_t binMatrix_isAllSet(binMatrix_2dBinaryMatrix *this_);
void binMatrix_setAdjElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column); // Todo: inline
void binMatrix_print(binMatrix_2dBinaryMatrix *this_);
/* Overloading operator*/
void binMatrix_copyData(binMatrix_2dBinaryMatrix *des, binMatrix_2dBinaryMatrix *src);      // "==" Operator
void binMatrix_bitWiseOrData(binMatrix_2dBinaryMatrix *des, binMatrix_2dBinaryMatrix *src); // "|=" Operator

#endif // MOCK_PROJECT_1_CMAKE_TRANHOANGANH_U_2DBINARYMATRIX_H
