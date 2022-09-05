/**
  ******************************************************************************
  * @file    u_staticMethod_ 2dBinaryMatrix.h
  * @author  TranHoangAnh
  * @brief
  *
  ==============================================================================
                        ##### 2dBinaryMatrix private method #####
  ==============================================================================
  */

#ifndef __U_STATIC__2DBINARYMATRIX_H__
#define __U_STATIC__2DBINARYMATRIX_H__

static binMatrix_axis_T binMatrix_arrIndex2AxisIndex(uint16_t arrayIndex);
static binMatrix_elementType *binMatrix_getLeftElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column);
static binMatrix_elementType *binMatrix_getRightElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column);
static binMatrix_elementType *binMatrix_getUpElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column);
static binMatrix_elementType *binMatrix_getDowntElm(binMatrix_2dBinaryMatrix *this_, int32_t row, int32_t column);

#endif // __U_STATIC__2DBINARYMATRIX_H__