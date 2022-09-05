/**
  ******************************************************************************
  * @file    u_theRottenApple.h
  * @author  TranHoangAnh
  * @brief
  *
  ==============================================================================
            #####  #####
  ==============================================================================
  */
#ifndef __U_THEROTTENAPPLE_H__
#define __U_THEROTTENAPPLE_H__

#include "u_dataType/U_2dBinaryMatrix.h"

#define SHOW_DATA 1 // For print	the Basket after each day.

typedef binMatrix_elementType theBasket;

enum
{
  fresh = 0,
  rotten = 1
};

typedef struct
{
  int32_t row;
  int32_t col;

} matrix_position;

int rotAllAppleMainFunction(int n, int m, matrix_position *positions, uint32_t numberOfRotten);

static void putTheRottenAppleIntoBasket(theBasket *basket, matrix_position positions);
static uint32_t isAllAppleRotten(theBasket *basket);
static binMatrix_elementType isTheAppleRotten(theBasket *basket, matrix_position positions);
static void rotAdjApple(theBasket *basket, matrix_position positions);

#endif // __U_THEROTTENAPPLE_H__