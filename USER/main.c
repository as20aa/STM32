#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
//ALIENTEK Mini STM32�����巶������3
//����ʵ��   
//����֧�֣�www.openedv.com
//�������������ӿƼ����޹�˾
 int main(void)
 {	
	u8 t;
	u8 len;	
	u16 times=0; 
 
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	 //ע��uart2,uart3��ʱ��Ƶ�ʱ�uart1��ʱ��Ƶ��Ҫ��һ������Ӧ���ڲ����������⴦��
	 //���͹��������ݾ���0x0d 0x0a��β�����ݾ�������unsigned char���Ͷ�����int����
	uart2_init(9600);
	uart3_init(9600);
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
 
	while(1)
	{
//		if((USART1_RX_STA&0x8000)&&(USART2_RX_STA&0X8000))
//		{
//			//�����ͬʱ��������˵�Ƭ���͵��Ե�����
//			�������ݴ������ּ���
//		}
		
		
		
		
		
		
		
		if(USART1_RX_STA&0x8000)
		{					   
			len=USART1_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
			printf("\r\n�����͵���ϢΪ:\r\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART1_RX_BUF[t];
				while((USART1->SR&0X40)==0);//�ȴ����ͽ���
			}
			printf("\r\n\r\n");//���뻻��
			USART1_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\nALIENTEK MiniSTM32������ ����ʵ��\r\n");
				printf("����ԭ��@ALIENTEK\r\n\r\n\r\n");
			}
			if(times%200==0)printf("����������,�Իس�������\r\n");  
			if(times%30==0)LED0=!LED0;//��˸LED,��ʾϵͳ��������.
			delay_ms(10);   
		}
		
		
		
	}	 
}

