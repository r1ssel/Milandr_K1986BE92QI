#include "clk.h"
#include "led.h"
#include "uart.h"

int main(void)
{
	//Переменная для чтения команды по UART
	uint8_t cmd = 0;
	
	//Инициализация периферии
	clk_CoreConfig();
	led_Init();
	uart_Init();

  while (1){
		
		//Получение команд по UART
		cmd = uart_Work();
		
		//Условие сравнения команд и вывода (1:0) на светодиод VD7
		if(cmd == 0x00)
			led_Write(false);
		else if(cmd == 0x01)
			led_Write(true);
	}
}
