

#include "rf_init.h"



IPCC_HandleTypeDef hipcc;

/**
  * @brief IPCC Initialization Function
  * @param None
  * @retval None
  */
 void MX_IPCC_Init(void)
 {
 
  
   hipcc.Instance = IPCC;
   if (HAL_IPCC_Init(&hipcc) != HAL_OK)
   {
     Error_Handler();
   }
  
 
 }
 
 /**
   * @brief RF Initialization Function
   * @param None
   * @retval None
   */
 void MX_RF_Init(void)
 {
 
   
 
 }