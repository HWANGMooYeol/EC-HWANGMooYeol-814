/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : SSS LAB
Created          : 05-03-2021
Modified         : 08-23-2024
Language/ver     : C++ in Keil uVision

Description      : Distributed to Students for LAB_GPIO
/----------------------------------------------------------------*/



#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecGPIO2_student.h"

void GPIO_init(PinName_t pinName, uint32_t mode){     
	GPIO_TypeDef * Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	
	// mode  : Input(0), Output(1), AlterFunc(2), Analog(3)   
	if (Port == GPIOA)
		RCC_GPIOA_enable();
	if (Port == GPIOB)
		RCC_GPIOB_enable();
	if (Port == GPIOC)
		RCC_GPIOC_enable();
	
	//[TO-DO] YOUR CODE GOES HERE
	// Make it for GPIOB, GPIOD..GPIOH

	// You can also make a more general function of
	void RCC_GPIO_enable(GPIO_TypeDef *Port); 

	GPIO_mode(pinName, mode);
}


// GPIO Mode          : Input(00), Output(01), AlterFunc(10), Analog(11)
void GPIO_mode(PinName_t pinName, uint32_t mode){
   GPIO_TypeDef * Port;
   unsigned int pin;
   ecPinmap(pinName,&Port,&pin);
   Port->MODER &= ~(3UL<<(2*pin));     
   Port->MODER |= mode<<(2*pin);    
}


// GPIO Speed          : Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
void GPIO_ospeed(PinName_t pinName, int speed){
	//[TO-DO] YOUR CODE GOES HERE
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	//[TO-DO] YOUR CODE GOES HERE
	Port->OSPEEDR &= ~(3UL << (2 * pin));
	Port->OSPEEDR |= speed<<(2 * pin);
}

// GPIO Output Type: Output push-pull (0, reset), Output open drain (1)
void GPIO_otype(PinName_t pinName, int type){
   	//[TO-DO] YOUR CODE GOES HERE
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	//[TO-DO] YOUR CODE GOES HERE
	Port->OTYPER &= ~(1 << (pin));
	Port->OTYPER |= type << (pin);
}

// GPIO Push-Pull    : No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
void GPIO_pupd(PinName_t pinName, int pupd){
   	//[TO-DO] YOUR CODE GOES HERE
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	//[TO-DO] YOUR CODE GOES HERE
	Port-> PUPDR &= ~(3UL << (2 * pin));
	Port-> PUPDR |= pupd << (2 * pin);
}

int GPIO_read(PinName_t pinName){
   	//[TO-DO] YOUR CODE GOES HERE
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	//[TO-DO] YOUR CODE GOES HERE
	return (Port->IDR >> pin) & (1UL); //[TO-DO] YOUR CODE GOES HERE	
}

void GPIO_write(PinName_t pinName, int Output) {
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	Port->ODR &= ~(1 << (pin));
	Port->ODR |= Output << (pin);
}

void GPIO_toggle(PinName_t pinName) {
	GPIO_TypeDef* Port;
	unsigned int pin;
	ecPinmap(pinName, &Port, &pin);
	Port->ODR ^= 1 << (pin);
}

void sevensegment_display_init(PinName_t pinNameA, PinName_t pinNameB, PinName_t pinNameC, PinName_t pinNameD) {

	static GPIO_TypeDef* PortA;
  static unsigned int pinA;
	ecPinmap(pinNameA, &PortA, &pinA);
	
	static GPIO_TypeDef* PortB;
	static unsigned int pinB;
	ecPinmap(pinNameB, &PortB, &pinB);
	
	static GPIO_TypeDef* PortC;
	static unsigned int pinC;
	ecPinmap(pinNameC, &PortC, &pinC);
	
	static GPIO_TypeDef* PortD;
	static unsigned int pinD;
	ecPinmap(pinNameD, &PortD, &pinD);
	
	GPIO_init(pinNameA, OUTPUT);
	GPIO_init(pinNameB, OUTPUT);
	GPIO_init(pinNameC, OUTPUT);
	GPIO_init(pinNameD, OUTPUT);
}



void sevensegment_display(uint8_t  num) {
	
	extern GPIO_TypeDef* PortA;
  extern unsigned int pinA;
	
	extern GPIO_TypeDef* PortB;
  extern unsigned int pinB;
	
	extern GPIO_TypeDef* PortC;
  extern unsigned int pinC;
	
	extern GPIO_TypeDef* PortD;
  extern unsigned int pinD;
	
	switch(num) {
		case 0:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= LOW << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= LOW << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= LOW << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 1:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= HIGH << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= LOW << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= LOW << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 2:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= LOW << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= HIGH << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= LOW << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 3:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= HIGH << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= HIGH << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= LOW << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 4:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= LOW << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= LOW << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= HIGH << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 5:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= HIGH << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= LOW << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= HIGH << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 6:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= LOW << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= HIGH << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= HIGH << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 7:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= HIGH << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= HIGH << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= HIGH << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= LOW << (pinD);
			break;
		case 8:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= LOW << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= LOW << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= LOW << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= HIGH << (pinD);
			break;
		case 9:
			PortA->ODR &= ~(1 << (pinA));
	    PortA->ODR |= HIGH << (pinA);
		
			PortB->ODR &= ~(1 << (pinB));
	    PortB->ODR |= LOW << (pinB);
		
			PortC->ODR &= ~(1 << (pinC));
	    PortC->ODR |= LOW << (pinC);
		
			PortD->ODR &= ~(1 << (pinD));
	    PortD->ODR |= HIGH << (pinD);
			break;
	}
}