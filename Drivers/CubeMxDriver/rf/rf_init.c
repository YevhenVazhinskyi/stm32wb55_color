#include "rf_init.h"

IPCC_HandleTypeDef hipcc;

/**
  * @brief IPCC and RF Initialization Function
  * @param None
  * @retval None
  */
void rf_init(void)
{
  // Initialize IPCC
  hipcc.Instance = IPCC;
  if (HAL_IPCC_Init(&hipcc) != HAL_OK)
  {
    Error_Handler();
  }
  
  // Initialize RF (placeholder for now)
  // RF initialization code can be added here when needed
}