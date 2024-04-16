# RL78_F24_ADC_PWM
 RL78_F24_ADC_PWM

udpate @ 2024/04/16

1. use RL78 F24 EVB to test ADC , PWM

- smart config set ADC channel to VREF to get reference voltage

- use smart config auto generate code setting , to copy CH0(P80),CH1(P81),CH6(P33),CH7(P34) and re-initial under loop

- PWM select TAU1 , slave1:P12 , slave2:P31

2. use keyboard , digit 1 , to enable ADC log , press again to turn off ADC log

![image](https://github.com/released/RL78_F24_ADC_PWM/blob/main/log_ADC_1.jpg)

3. use keyboard , press 'A' or 'a' , to increase PWM duty 5%

use keyboard , press 'D' or 'd' , to decrase PWM duty 5%

![image](https://github.com/released/RL78_F24_ADC_PWM/blob/main/log_PWM.jpg)

below is PWM duty adjust result (25%)

![image](https://github.com/released/RL78_F24_ADC_PWM/blob/main/waveform_PWM_adjust.jpg)


4. below is ADC log ,

![image](https://github.com/released/RL78_F24_ADC_PWM/blob/main/log_ADC_2.jpg)

5. below is PWM duty capture , 

![image](https://github.com/released/RL78_F24_ADC_PWM/blob/main/waveform_PWM.jpg)
