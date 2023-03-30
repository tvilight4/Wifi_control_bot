#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"
#include "tuning_http_server.h"

#define MODE NORMAL_MODE
/*#define BLACK_MARGIN 4095
#define WHITE_MARGIN 0
#define bound_LSA_LOW 0
#define bound_LSA_HIGH 1000
#define BLACK_BOUNDARY  700    // Boundary value to distinguish between black and white readings */

/*
 * weights given to respective line sensor
 */
//const int weights[5] = {-5, -3, 1, 3, 5};

/*
 * Motor value boundts
 */
int optimum_duty_cycle = 63;
const int lower_duty_cycle = 60;
const int higher_duty_cycle = 90;
float left_duty_cycle = 0.0;
float right_duty_cycle = 0.0;
float duty_cycle_val= 0.0;

/*
 * Line Following PID Variables
 */
//float error=0, prev_error=0, difference, cumulative_error, correction;

/*
 * Union containing line sensor readings
 */
//line_sensor_array line_sensor_readings;





void line_follow_task(void* arg)
{
    ESP_ERROR_CHECK(enable_motor_driver(a, NORMAL_MODE));
  //  ESP_ERROR_CHECK(enable_line_sensor());
    //ESP_ERROR_CHECK(enable_bar_graph());
#ifdef CONFIG_ENABLE_OLED
    // Initialising the OLED
    ESP_ERROR_CHECK(init_oled());
    vTaskDelay(100);

    // Clearing the screen
    lv_obj_clean(lv_scr_act());

#endif
    duty_cycle_val= (lower_duty_cycle + (((higher_duty_cycle-lower_duty_cycle)/100)*  read_pid_const().speed));


    while(true)
    {
      
      left_duty_cycle=bound(duty_cycle_val,higher_duty_cycle,lower_duty_cycle);
      right_duty_cycle=bound(duty_cycle_val,higher_duty_cycle,lower_duty_cycle);
      int a=0;
      if(      read_pid_const().angle>=0 &&       read_pid_const().angle<90){
         int a=1;
         }
       if(      read_pid_const().angle>90 &&       read_pid_const().angle<=180){
         int a=2;
       }
       if(      read_pid_const().angle>=180 &&     read_pid_const().angle<270){
          int a=3;
       }
       if(      read_pid_const().angle>270 &&     read_pid_const().angle<=360){
          int a=4;
       }
       if(      read_pid_const().angle==90){
          int a=5;
       }
       if(      read_pid_const().angle==270){
          int a=6;
       }
    if(    read_pid_const().x!=0 ||     read_pid_const().y!=0)
    {
      switch (a)
      {
         case 1:
         set_motor_speed(MOTOR_A_0,MOTOR_FORWARD,left_duty_cycle);
         set_motor_speed(MOTOR_A_1,MOTOR_FORWARD,lower_duty_cycle);
         break;
      
          case 2:
         set_motor_speed(MOTOR_A_0,MOTOR_FORWARD,lower_duty_cycle);
         set_motor_speed(MOTOR_A_1,MOTOR_FORWARD,right_duty_cycle);
         break;
      
         case 3:
         set_motor_speed(MOTOR_A_0,MOTOR_BACKWARD,lower_duty_cycle);
         set_motor_speed(MOTOR_A_1,MOTOR_BACKWARD,right_duty_cycle);
         break;
        
         case 4:
         set_motor_speed(MOTOR_A_0,MOTOR_BACKWARD,left_duty_cycle);
         set_motor_speed(MOTOR_A_1,MOTOR_BACKWARD,lower_duty_cycle);
         break;

         case 5:
         set_motor_speed(MOTOR_A_0,MOTOR_FORWARD,left_duty_cycle);
         set_motor_speed(MOTOR_A_1,MOTOR_FORWARD,right_duty_cycle);
         break;

         case 6:
         set_motor_speed(MOTOR_A_0,MOTOR_BACKWARD,left_duty_cycle);
         set_motor_speed(MOTOR_A_1,MOTOR_BACKWARD,right_duty_cycle);
         break;

      } 
    }
        //ESP_LOGI("debug","left_duty_cycle:  %f    ::  right_duty_cycle :  %f  :: error :  %f  correction  :  %f  \n",left_duty_cycle, right_duty_cycle, error, correction);
        ESP_LOGI("debug", "X: %f ::  Y: %f  :: SPEED: %f :: ANGLE: %f",     read_pid_const() .x,     read_pid_const() .y,     read_pid_const() .speed,     read_pid_const() .angle);

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

void app_main()
{
    
    start_tuning_http_server();
}
