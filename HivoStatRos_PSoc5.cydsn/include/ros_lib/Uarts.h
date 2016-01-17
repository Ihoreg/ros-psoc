/* ========================================
 * 
 * Host Uart for HiveBio Ministat
 * 
 * Copyright C. Harrison
 * BSD 2-clause license http://opensource.org/licenses/BSD-2-Clause
 *
 */

#ifndef ROS_UARTS_H_
#define ROS_UARTS_H_

#include "HardwareSerial.h"

class Uart : public HardwareSerial
{
  public:
    void begin(unsigned long baud); // TBD: set baud rate
    int read(void);
    size_t write(uint8_t data);
  private:
    uint8_t read_buf[64];
    uint8_t *read_ptr, *read_tail;
} ;

extern Uart Uart0;

#endif

