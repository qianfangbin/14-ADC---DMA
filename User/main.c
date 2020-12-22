/*
***********************************************************************************
*�ļ�����main.c
*���ߣ�QFB
*�汾��V1.0
*���ڣ�2020-12-22
*˵����ADC�ɼ���ѹ-DMA
*ƽ̨��Ұ��M3������
***********************************************************************************
*/
#include "stm32f10x.h"
#include "bsp_usart.h"
#include "bsp_adc.h"


extern __IO uint16_t ADC_ConvertedValue;

float ADC_VoltageValue = 0.00;

void Delay(uint32_t Count);

int main(void)
{
    USART_Config();
    ADCX_Init();
    printf("\r\n---����һ��ADC�ɼ���ѹ��ʾ����---   \r\n");
    printf("\n");
    
    while(1)
    {
        ADC_VoltageValue = (float) (ADC_ConvertedValue) / 4096 *3.3;
        printf("ADC_ConvertedValue = %d \r\n", ADC_ConvertedValue);
        printf("ADC_VoltageValue = %.2f V \r\n", ADC_VoltageValue);
        Delay(0xffffff);
    }
	
}


void Delay(uint32_t Count)
{   
    for(; Count != 0; Count--);

}


