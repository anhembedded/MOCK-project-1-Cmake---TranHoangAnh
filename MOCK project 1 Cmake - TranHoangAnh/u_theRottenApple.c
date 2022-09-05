/**
  ******************************************************************************
  * @file    u_theRottenApple.c
  * @author  TranHoangAnh
  * @brief
  *
  ==============================================================================
						#####  #####
  ==============================================================================
  */
#include "u_theRottenApple.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"

/**
 * @brief  Main function of this Mock
 * @param  buffer			pointer to the Buffer
 * @param  n (int):			row Size
 * @param  m (int):		collum Size
 * @param  positions (matrix_position *):
 * @param  numberOfRotten (uint32_t):
 * @retval (int) Number of days for all the apple completely be rotten
 */
int rotAllAppleMainFunction(int n, int m, matrix_position *positions, uint32_t numberOfRotten)
{
	int numbOfDay = 0;

	binMatrix_2dBinaryMatrix basket;
	binMatrix_2dBinaryMatrix basketBuffer;

	binMatrix_constructor(&basket, n, m);
	binMatrix_constructor(&basketBuffer, n, m);

	for (uint32_t i = 0; i < numberOfRotten; i++)
	{
		positions[i].col--; // Cho phù hợp với testing case input
		positions[i].row--; // Cho phù hợp với testing case input
		putTheRottenAppleIntoBasket((theBasket *)&basket, positions[i]);
	}

#if (SHOW_DATA == 1)
	printf(ANSI_COLOR_MAGENTA "[The first day]");
	printf("\n");
	binMatrix_print(&basket);
#endif

	while (!isAllAppleRotten((theBasket *)&basket))
	{
		int32_t row, columns;
		for (row = 0; row < basket.numbOfRow; row++)
		{
			for (columns = 0; columns < basket.numbOfCol; columns++)
			{
				if (isTheAppleRotten((theBasket *)&basket, (matrix_position){.row = row, .col = columns}))
				{
					rotAdjApple((theBasket *)&basketBuffer, (matrix_position){.row = row, .col = columns});
				}
			}
		}
		numbOfDay++;
		binMatrix_bitWiseOrData(&basket, &basketBuffer);
#if (SHOW_DATA == 1)
		printf("\n");
		printf(ANSI_COLOR_MAGENTA "[After %d day(s)]", numbOfDay);
		printf("\n");
		binMatrix_print(&basket);
#endif
	}
	binMatrix_destructor(&basket);
	binMatrix_destructor(&basketBuffer);
	return numbOfDay;
}

/**
 * @brief  Add a rotten apple to basket
 * @param  basket (theBasket*) Basket ptr Obj
 * @param  positions (matrix_position):	pos of the Basket
 * @retval (void)
 */
static void putTheRottenAppleIntoBasket(theBasket *basket, matrix_position positions)
{
	*binMatrix_pointToElement(basket, positions.row, positions.col) = rotten;
}
/**
 * @brief  Check if all the apple in the basket is rotten all.
 * @param  basket (theBasket*) Basket ptr Obj
 * @retval (uint32_t) status:
 *						(1): rotten all
 *						(O): not rotten all
 */
static uint32_t isAllAppleRotten(theBasket *basket)
{
	return binMatrix_isAllSet((binMatrix_2dBinaryMatrix *)basket);
}
/**
 * @brief  Check if the apple in that position in the basket is rotten.
 * @param  basket (theBasket*) Basket ptr Obj
 * @param  positions (matrix_position *): position of the apple
 * @retval (void)
 */
static binMatrix_elementType isTheAppleRotten(theBasket *basket, matrix_position positions)
{
	return binMatrix_isSet((binMatrix_2dBinaryMatrix *)basket, positions.row, positions.col);
}

/**
 * @brief  Making all the adjacency apple of the apple at this position be rotten
 * @param  basket (theBasket*) Basket ptr Obj
 * @param  positions (matrix_position *): position of the apple
 * @retval (void)
 */
static void rotAdjApple(theBasket *basket, matrix_position positions)
{
	binMatrix_setAdjElm((binMatrix_2dBinaryMatrix *)basket, positions.row, positions.col);
}
