/******************************************************************************
*  Nano-RK, a real-time operating system for sensor networks.
*  Copyright (C) 2007, Real-Time and Multimedia Lab, Carnegie Mellon University
*  All rights reserved.
*
*  This is the Open Source Version of Nano-RK included as part of a Dual
*  Licensing Model. If you are unsure which license to use please refer to:
*  http://www.nanork.org/nano-RK/wiki/Licensing
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, version 2.0 of the License.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*******************************************************************************/

#include <nrk.h>
#include <include.h>
#include <ulib.h>
#include <stdio.h>
#include <hal.h>
#include <nrk_error.h>
#include <nrk_timer.h>
#include <nrk_stack_check.h>
#include <nrk_stats.h>
#include <mbed.h>


NRK_STK Stack1[NRK_APP_STACKSIZE];
nrk_task_type TaskOne;
void Task1(void);


void nrk_create_taskset();

DigitalOut myled(LED1);
DigitalOut myled1(LED2);
int
main ()
{
  printf("in main");
  nrk_setup_ports();
  //nrk_setup_uart(UART_BAUDRATE_115K2);
  while (1) {
        myled = 1;
        //myled1 = 1;
        nrk_led_set(1);
    }
    
    

  nrk_init();

  nrk_time_set(0,0);
  //nrk_create_taskset ();
  nrk_start();
    //nrk_gpio_set();
   return 0;
}

void Task1()
{
nrk_time_t t;
uint16_t cnt;
cnt=0;
nrk_kprintf( PSTR("Nano-RK Version ") );
printf( "%d\r\n",NRK_VERSION );

printf( "My node's address is %u\r\n",NODE_ADDR );
  
printf( "Task1 PID=%u\r\n",nrk_get_pid());

  while(1) {
	//nrk_led_toggle(RED_LED);
	//nrk_led_toggle(GREEN_LED);
	//nrk_led_toggle(BLUE_LED);
	//nrk_led_toggle(ORANGE_LED);
	//nrk_wait_until_next_period();
  	}
}


void
nrk_create_taskset()
{
  nrk_task_set_entry_function( &TaskOne, Task1);
  nrk_task_set_stk( &TaskOne, Stack1, NRK_APP_STACKSIZE);
  TaskOne.prio = 1;
  TaskOne.FirstActivation = TRUE;
  TaskOne.Type = BASIC_TASK;
  TaskOne.SchType = PREEMPTIVE;
  TaskOne.period.secs = 0;
  TaskOne.period.nano_secs = 250*NANOS_PER_MS;
  TaskOne.cpu_reserve.secs = 1;
  TaskOne.cpu_reserve.nano_secs = 50*NANOS_PER_MS;
  TaskOne.offset.secs = 0;
  TaskOne.offset.nano_secs= 0;
  nrk_activate_task (&TaskOne);



}


