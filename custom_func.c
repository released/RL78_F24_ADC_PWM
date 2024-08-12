/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>

#include "inc_main.h"

#include "misc_config.h"
#include "custom_func.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

struct flag_32bit flag_PROJ_CTL;
#define FLAG_PROJ_TIMER_PERIOD_1000MS                 	(flag_PROJ_CTL.bit0)
#define FLAG_PROJ_TRIG_BTN1                       	    (flag_PROJ_CTL.bit1)
#define FLAG_PROJ_TRIG_BTN2                 	        (flag_PROJ_CTL.bit2)
#define FLAG_PROJ_TRIG_ADC_CH                 		    (flag_PROJ_CTL.bit3)
#define FLAG_PROJ_TRIG_ADC_LOG                          (flag_PROJ_CTL.bit4)
#define FLAG_PROJ_PWM_DUTY_INC                          (flag_PROJ_CTL.bit5)
#define FLAG_PROJ_PWM_DUTY_DEC                              (flag_PROJ_CTL.bit6)
#define FLAG_PROJ_TIMER_PERIOD_SPECIFIC                 (flag_PROJ_CTL.bit7)


#define FLAG_PROJ_REVERSE8                              (flag_PROJ_CTL.bit8)
#define FLAG_PROJ_REVERSE9                              (flag_PROJ_CTL.bit9)
#define FLAG_PROJ_REVERSE10                             (flag_PROJ_CTL.bit10)
#define FLAG_PROJ_REVERSE11                             (flag_PROJ_CTL.bit11)
#define FLAG_PROJ_REVERSE12                             (flag_PROJ_CTL.bit12)
#define FLAG_PROJ_REVERSE13                             (flag_PROJ_CTL.bit13)
#define FLAG_PROJ_REVERSE14                             (flag_PROJ_CTL.bit14)
#define FLAG_PROJ_REVERSE15                             (flag_PROJ_CTL.bit15)

/*_____ D E F I N I T I O N S ______________________________________________*/

volatile unsigned int counter_tick = 0;
volatile unsigned int btn_counter_tick = 0;

#define BTN_PRESSED_LONG                                (2500)

volatile unsigned int pwm_duty[16] = {0};

#define VBG_VOLTAGE                                     (1.45)  //(1450)

/*F24 V_BGR : 1.45 V*/
unsigned long vdd_Vbgr = 0;

unsigned short adc_buffer[31] = {0};
/*_____ M A C R O S ________________________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/

void set_TIMER_PERIOD_1000MS(void)
{
    FLAG_PROJ_TIMER_PERIOD_1000MS = 1;
}

void reset_TIMER_PERIOD_1000MS(void)
{
    FLAG_PROJ_TIMER_PERIOD_1000MS = 0;
}

bool Is_TIMER_PERIOD_1000MS_Trig(void)
{
    return FLAG_PROJ_TIMER_PERIOD_1000MS;
}

unsigned int btn_get_tick(void)
{
	return (btn_counter_tick);
}

void btn_set_tick(unsigned int t)
{
	btn_counter_tick = t;
}

void btn_tick_counter(void)
{
	btn_counter_tick++;
    if (btn_get_tick() >= 60000)
    {
        btn_set_tick(0);
    }
}

unsigned int get_tick(void)
{
	return (counter_tick);
}

void set_tick(unsigned int t)
{
	counter_tick = t;
}

void tick_counter(void)
{
	counter_tick++;
    if (get_tick() >= 60000)
    {
        set_tick(0);
    }
}

void delay_ms(unsigned int ms)
{
	#if 1
    unsigned int tickstart = get_tick();
    unsigned int wait = ms;
	unsigned int tmp = 0;
	
    while (1)
    {
		if (get_tick() > tickstart)	// tickstart = 59000 , tick_counter = 60000
		{
			tmp = get_tick() - tickstart;
		}
		else // tickstart = 59000 , tick_counter = 2048
		{
			tmp = 60000 -  tickstart + get_tick();
		}		
		
		if (tmp > wait)
			break;
    }
	
	#else
	TIMER_Delay(TIMER0, 1000*ms);
	#endif
}

/*
    TAU1 PWM : 250K
        - SLAVE 1 : P12 , duty : 80%
        - SLAVE 4 : P31 , duty : 20%
*/
unsigned int get_TAU1_pwm_ch_duty(unsigned char ch)
{
	return (pwm_duty[ch]);
}

void set_TAU1_pwm_ch_duty(unsigned char ch ,unsigned int duty)
{
    pwm_duty[ch] = duty;
}


/*copy from R_Config_TAU1_0_Create*/
void generate_TAU1_pwm_ch1(void)
{
    TOM1 |= _0002_TAU_CH1_SLAVE_OUTPUT;
    TOL1 &= (uint16_t)~_0002_TAU_CH1_OUTPUT_LEVEL_L;
    TO1 &= (uint16_t)~_0002_TAU_CH1_OUTPUT_VALUE_1;
    PWMDLY2 &= _FFF3_TAU_CH1_OUTPUT_CLEAR;
    PWMDLY2 |= _0000_TAU_CH1_OUTPUT_NO_DELAY;
    TOE1 |= _0002_TAU_CH1_OUTPUT_ENABLE; 
}

void PWM_Process_Adjust(void)
{
    int tmp = 0;
    unsigned int duty_hex = 0;

    /*
        duty * 16
        --------  = target hex 
            10
    */

    if (FLAG_PROJ_PWM_DUTY_INC)
    {
        FLAG_PROJ_PWM_DUTY_INC = 0;

        tmp = get_TAU1_pwm_ch_duty(1);
	
	/*
	   _00A0_TAU_TDR11_VALUE : 100%
	*/
        duty_hex = _00A0_TAU_TDR11_VALUE / 100 * 5;   // + 5 %
        tmp = (tmp >= _00A0_TAU_TDR11_VALUE) ? (_00A0_TAU_TDR11_VALUE) : (tmp + duty_hex ) ;   
	
        set_TAU1_pwm_ch_duty(1,tmp);
        printf("+duty:0x%02X(%2.2f)\r\n",tmp , (float) tmp/_00A0_TAU_TDR11_VALUE*100 );

        TDR11 = get_TAU1_pwm_ch_duty(1);
        generate_TAU1_pwm_ch1();

    }
    if (FLAG_PROJ_PWM_DUTY_DEC)
    {
        FLAG_PROJ_PWM_DUTY_DEC = 0;

        tmp = get_TAU1_pwm_ch_duty(1);
	
        duty_hex = _00A0_TAU_TDR11_VALUE / 100 * 5;   // - 5 %
        tmp = (tmp <= 0) ? (0) : (tmp - duty_hex ) ;  
	
        set_TAU1_pwm_ch_duty(1,tmp);
        printf("-duty:0x%02X(%2.2f)\r\n",tmp , (float) tmp/_00A0_TAU_TDR11_VALUE*100 );

        TDR11 = get_TAU1_pwm_ch_duty(1);
        generate_TAU1_pwm_ch1();
    }
}

unsigned short ADC_To_Voltage(unsigned short adc_value)
{
	unsigned short volt = 0;

	// volt = (vdd_Vbgr*adc_value)/4096;
	volt = (vdd_Vbgr*adc_value) >> 12;
	
	#if 0   //debug
    printf(",0x%4X(%5d,%5d),",adc_value,adc_value , volt);
	#endif

	return volt;	
}

void GetADC(unsigned char ch)
{
    unsigned short tmp_buffer = 0;

    FLAG_PROJ_TRIG_ADC_CH = 0;
    R_Config_S12AD0_Start();
    while(!FLAG_PROJ_TRIG_ADC_CH);
    R_Config_S12AD0_Get_ValueResult((e_ad_channel_t) ch,&tmp_buffer);
    R_Config_S12AD0_Stop();
    FLAG_PROJ_TRIG_ADC_CH = 0;

    adc_buffer[ch] = tmp_buffer;    
    // printf("ch[%d]:0x%04X\r\n",ch,adc_buffer);

}

void GetVDDVoltage(void)
{
    unsigned long tmp_ul = 0;
    float tmp_float = 0;
    unsigned short tmp_buffer = 0;

    /*
        VDD = VBG * 4096 / ConversionResult
        VDD/VBG = 4096 / ConversionResult
    
    */
    FLAG_PROJ_TRIG_ADC_CH = 0;
    R_Config_S12AD0_Start();    // to get ADC internal vref channel
    while(!FLAG_PROJ_TRIG_ADC_CH);
    R_Config_S12AD0_Get_ValueResult(ADINTERREFVOLT,&tmp_buffer);
    R_Config_S12AD0_Stop();
    FLAG_PROJ_TRIG_ADC_CH = 0;

    tmp_float = VBG_VOLTAGE*4096/tmp_buffer;
    tmp_ul = (VBG_VOLTAGE*1000)*4096/tmp_buffer;
    vdd_Vbgr = tmp_ul;

    // printf("VBGR:%2.2fv,%4dmv(0x%04X)\r\n",tmp_float,tmp_ul,tmp_buffer);
    (void)(tmp_float);

}

void ADC_Process_in_IRQ(void)
{
    FLAG_PROJ_TRIG_ADC_CH = 1;
}

/*
    COPY FROM R_Config_S12AD0_Create
    channel : internal reference voltage
*/
void ADC_VREF_config_Init(void)
{
    ADCEN = 1U;    /* supply AD clock */
    ADCKS = _00_AD_CONVERSION_CLOCK;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR &= (~_8000_AD_CONVERSION_START);
    ADMK = 1U;    /* disable INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
    /* Set INTAD low priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR = _0000_AD_SINGLE_SCAN_MODE | _0000_AD_SYNCASYNCTRG_DISABLE | _1000_AD_SCAN_END_INTERRUPT_ENABLE;
    ADWINR = _01_AD_REGISTER_GROUP2_RW_ENABLE;
    ADEXICR = _0200_AD_IREF_USED;
    ADWINR = _08_AD_ADGSPCR_ADHVREFCNT_RW_ENABLE;
    ADHVREFCNT = _00_AD_ANALOG_BLOCK_NORMAL | _00_AD_LOW_POTENTIAL_VSS | _00_AD_HIGH_POTENTIAL_VDD;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCER = _0000_AD_RIGHT_ALIGNMENT | _0000_AD_SELFDIAG_DISABLE | _0000_AD_AUTO_CLEARING_DISABLE;
    ADWINR = _07_AD_ADDISCR_RW_ENABLE;
    ADDISCR = _00_AD_DISCONNECT_UNUSED;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADADC = _80_AD_AVERAGE_MODE | _01_AD_2_TIME_CONVERSION;
    ADWINR = _0D_AD_ADSSTRL_ADSSTRO_RW_ENABLE;
    ADSSTRO = _C8_AD_SAMPLING_STATE_O;  

    
    R_Config_S12AD0_Start();  
}

/*
    COPY FROM R_Config_S12AD0_Create
    channel : 0 , 1 , 6 , 7
    P80
    P81
    P33
    P34
*/
void ADC_Channel_config_Init(void)
{
    const unsigned char SAMPLING_STATE = 0x0DU;

    #if 1
    ADCEN = 1U;    /* supply AD clock */
    ADCKS = _00_AD_CONVERSION_CLOCK;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR &= (~_8000_AD_CONVERSION_START);
    ADMK = 1U;    /* disable INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
    /* Set INTAD low priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR = _0000_AD_SINGLE_SCAN_MODE | _0000_AD_SYNCASYNCTRG_DISABLE | _1000_AD_SCAN_END_INTERRUPT_ENABLE;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADANSA0 = _0001_AD_ANI0_USED | _0002_AD_ANI1_USED | _0040_AD_ANI6_USED | _0080_AD_ANI7_USED;
    ADWINR = _08_AD_ADGSPCR_ADHVREFCNT_RW_ENABLE;
    ADHVREFCNT = _00_AD_ANALOG_BLOCK_NORMAL | _00_AD_LOW_POTENTIAL_VSS | _00_AD_HIGH_POTENTIAL_VDD;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCER = _0000_AD_RIGHT_ALIGNMENT | _0000_AD_SELFDIAG_DISABLE | _0000_AD_AUTO_CLEARING_DISABLE;
    ADWINR = _07_AD_ADDISCR_RW_ENABLE;
    ADDISCR = _00_AD_DISCONNECT_UNUSED;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADADC = _80_AD_AVERAGE_MODE | _01_AD_2_TIME_CONVERSION;
    ADWINR = _0E_AD_ADSSTR0_15_RW_ENABLE;
    ADSSTR0 = SAMPLING_STATE;//_0D_AD_SAMPLING_STATE_0;
    ADWINR = _0E_AD_ADSSTR0_15_RW_ENABLE;
    ADSSTR1 = SAMPLING_STATE;//_0D_AD_SAMPLING_STATE_1;
    ADWINR = _0E_AD_ADSSTR0_15_RW_ENABLE;
    ADSSTR6 = SAMPLING_STATE;//_0D_AD_SAMPLING_STATE_6;
    ADWINR = _0E_AD_ADSSTR0_15_RW_ENABLE;
    ADSSTR7 = SAMPLING_STATE;//_0D_AD_SAMPLING_STATE_7;
    /* Set ANI0 pin */
    PMC8 |= 0x01U;
    PM8 |= 0x01U;
    /* Set ANI1 pin */
    PMC8 |= 0x02U;
    PM8 |= 0x02U;
    /* Set ANI6 pin */
    PMC3 |= 0x08U;
    PM3 |= 0x08U;
    /* Set ANI7 pin */
    PMC3 |= 0x10U;
    PM3 |= 0x10U;    
    #endif

    
    R_Config_S12AD0_Start();
}


void ADC_Process(void)
{    
    // init internal vref channel
    ADC_VREF_config_Init();
    // get VREF
    GetVDDVoltage();

    // init normal adc channel
    ADC_Channel_config_Init();
    // get ADC channel
    GetADC(0);
    GetADC(1);
    GetADC(6);
    GetADC(7);
    
    #if 1   //ADC debug log
    if (FLAG_PROJ_TRIG_ADC_LOG)
    {
        printf("VREF:%d,",vdd_Vbgr);
        printf("ch[%d]:0x%04X(%4d mv),",0,adc_buffer[0],ADC_To_Voltage(adc_buffer[0]));
        printf("ch[%d]:0x%04X(%4d mv),",1,adc_buffer[1],ADC_To_Voltage(adc_buffer[1]));
        printf("ch[%d]:0x%04X(%4d mv),",6,adc_buffer[6],ADC_To_Voltage(adc_buffer[6]));
        printf("ch[%d]:0x%04X(%4d mv),",7,adc_buffer[7],ADC_To_Voltage(adc_buffer[7]));
        printf("\r\n");
    }
    #endif
    
}

void Timer_1ms_IRQ(void)
{
    tick_counter();

    if ((get_tick() % 1000) == 0)
    {
        set_TIMER_PERIOD_1000MS();
    }

    
    if ((get_tick() % 200) == 0)
    {
        FLAG_PROJ_TIMER_PERIOD_SPECIFIC = 1;
    }

    if ((get_tick() % 50) == 0)
    {

    }	

    Button_Process_long_counter();
}


/*
    F24 target board
    LED1 connected to P66, LED2 connected to P67
*/
void LED_Toggle(void)
{
    PIN_WRITE(6,6) = ~PIN_READ(6,6);
    PIN_WRITE(6,7) = ~PIN_READ(6,7);
}

void loop(void)
{
	// static unsigned int LOG1 = 0;

    if (Is_TIMER_PERIOD_1000MS_Trig())
    {
        reset_TIMER_PERIOD_1000MS();

        // printf("log(timer):%4d\r\n",LOG1++);
        LED_Toggle();             
    }

    Button_Process_in_polling();

    if (FLAG_PROJ_TIMER_PERIOD_SPECIFIC)
    {
        FLAG_PROJ_TIMER_PERIOD_SPECIFIC = 0;

        ADC_Process();
    }

    PWM_Process_Adjust();

}

// F24 EVB , P137/INTP0 , set both edge 
void Button_Process_long_counter(void)
{
    if (FLAG_PROJ_TRIG_BTN2)
    {
        btn_tick_counter();
    }
    else
    {
        btn_set_tick(0);
    }
}

void Button_Process_in_polling(void)
{
    static unsigned char cnt = 0;

    if (FLAG_PROJ_TRIG_BTN1)
    {
        FLAG_PROJ_TRIG_BTN1 = 0;
        printf("BTN pressed(%d)\r\n",cnt);

        if (cnt == 0)   //set both edge  , BTN pressed
        {
            FLAG_PROJ_TRIG_BTN2 = 1;
        }
        else if (cnt == 1)  //set both edge  , BTN released
        {
            FLAG_PROJ_TRIG_BTN2 = 0;
        }

        cnt = (cnt >= 1) ? (0) : (cnt+1) ;
    }

    if ((FLAG_PROJ_TRIG_BTN2 == 1) && 
        (btn_get_tick() > BTN_PRESSED_LONG))
    {         
        printf("BTN pressed LONG\r\n");
        btn_set_tick(0);
        FLAG_PROJ_TRIG_BTN2 = 0;
    }
}

// F24 EVB , P137/INTP0
void Button_Process_in_IRQ(void)    
{
    FLAG_PROJ_TRIG_BTN1 = 1;
}

void UARTx_Process(unsigned char rxbuf)
{    
    if (rxbuf > 0x7F)
    {
        printf("invalid command\r\n");
    }
    else
    {
        printf("press:%c(0x%02X)\r\n" , rxbuf,rxbuf);   // %c :  C99 libraries.
        switch(rxbuf)
        {
            case '1':   // enable adc log
                FLAG_PROJ_TRIG_ADC_LOG = ~FLAG_PROJ_TRIG_ADC_LOG;
                break;

            case 'a':
            case 'A':
                FLAG_PROJ_PWM_DUTY_INC = 1;
                break;
            case 'd':
            case 'D':
                FLAG_PROJ_PWM_DUTY_DEC = 1;
                break;

            case 'X':
            case 'x':
                RL78_soft_reset(7);
                break;
            case 'Z':
            case 'z':
                RL78_soft_reset(1);
                break;
        }
    }
}

/*
    Reset Control Flag Register (RESF) 
    BIT7 : TRAP
    BIT6 : 0
    BIT5 : 0
    BIT4 : WDCLRF
    BIT3 : 0
    BIT2 : 0
    BIT1 : IAWRF
    BIT0 : LVIRF
*/
void check_reset_source(void)
{
    /*
        Internal reset request by execution of illegal instruction
        0  Internal reset request is not generated, or the RESF register is cleared. 
        1  Internal reset request is generated. 
    */
    uint8_t src = RESF;
    printf("Reset Source <0x%08X>\r\n", src);

    #if 1   //DEBUG , list reset source
    if (src & BIT0)
    {
        printf("0)voltage detector (LVD)\r\n");       
    }
    if (src & BIT1)
    {
        printf("1)illegal-memory access\r\n");       
    }
    if (src & BIT2)
    {
        printf("2)EMPTY\r\n");       
    }
    if (src & BIT3)
    {
        printf("3)EMPTY\r\n");       
    }
    if (src & BIT4)
    {
        printf("4)watchdog timer (WDT) or clock monitor\r\n");       
    }
    if (src & BIT5)
    {
        printf("5)EMPTY\r\n");       
    }
    if (src & BIT6)
    {
        printf("6)EMPTY\r\n");       
    }
    if (src & BIT7)
    {
        printf("7)execution of illegal instruction\r\n");       
    }
    #endif

}

/*
    7:Internal reset by execution of illegal instruction
    1:Internal reset by illegal-memory access
*/
//perform sofware reset
void _reset_by_illegal_instruction(void)
{
    static const unsigned char illegal_Instruction = 0xFF;
    void (*dummy) (void) = (void (*)(void))&illegal_Instruction;
    dummy();
}
void _reset_by_illegal_memory_access(void)
{
    #if 1
    const unsigned char ILLEGAL_ACCESS_ON = 0x80;
    IAWCTL |= ILLEGAL_ACCESS_ON;            // switch IAWEN on (default off)
    *(__far volatile char *)0x00000 = 0x00; //write illegal address 0x00000(RESET VECTOR)
    #else
    signed char __far* a;                   // Create a far-Pointer
    IAWCTL |= _80_CGC_ILLEGAL_ACCESS_ON;    // switch IAWEN on (default off)
    a = (signed char __far*) 0x0000;        // Point to 0x000000 (FLASH-ROM area)
    *a = 0;
    #endif
}

void RL78_soft_reset(unsigned char flag)
{
    switch(flag)
    {
        case 7: // do not use under debug mode
            _reset_by_illegal_instruction();        
            break;
        case 1:
            _reset_by_illegal_memory_access();
            break;
    }
}

// retarget printf
int __far putchar(int c)
{
    // F24 , UART0
    STMK0 = 1U;    /* disable INTST0 interrupt */
    SDR00L = (unsigned char)c;
    while(STIF0 == 0)
    {

    }
    STIF0 = 0U;    /* clear INTST0 interrupt flag */
    return c;
}

void hardware_init(void)
{
    const unsigned char indicator[] = "hardware_init";
    BSP_EI();
    R_Config_UART0_Start();
    R_Config_TAU0_1_Start();  
    R_Config_INTC_INTP0_Start();
    
    R_Config_TAU1_0_Start();    // PWM , 250K

    // check_reset_source();
    printf("\r\n%s finish\r\n\r\n",indicator);
}
