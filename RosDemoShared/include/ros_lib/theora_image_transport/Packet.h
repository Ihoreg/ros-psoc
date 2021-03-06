#ifndef _ROS_theora_image_transport_Packet_h
#define _ROS_theora_image_transport_Packet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace theora_image_transport
{

  class Packet : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t data_length;
      uint8_t st_data;
      uint8_t * data;
      int32_t b_o_s;
      int32_t e_o_s;
      int64_t granulepos;
      int64_t packetno;

    Packet():
      header(),
      data_length(0), data(NULL),
      b_o_s(0),
      e_o_s(0),
      granulepos(0),
      packetno(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_b_o_s;
      u_b_o_s.real = this->b_o_s;
      *(outbuffer + offset + 0) = (u_b_o_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b_o_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_b_o_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_b_o_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b_o_s);
      union {
        int32_t real;
        uint32_t base;
      } u_e_o_s;
      u_e_o_s.real = this->e_o_s;
      *(outbuffer + offset + 0) = (u_e_o_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_e_o_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_e_o_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_e_o_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->e_o_s);
      union {
        int64_t real;
        uint64_t base;
      } u_granulepos;
      u_granulepos.real = this->granulepos;
      *(outbuffer + offset + 0) = (u_granulepos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_granulepos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_granulepos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_granulepos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_granulepos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_granulepos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_granulepos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_granulepos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->granulepos);
      union {
        int64_t real;
        uint64_t base;
      } u_packetno;
      u_packetno.real = this->packetno;
      *(outbuffer + offset + 0) = (u_packetno.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packetno.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packetno.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packetno.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_packetno.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_packetno.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_packetno.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_packetno.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->packetno);
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT < data_length)
        data_length = data_lengthT;
      offset += 3;
      for( uint8_t i = 0; i < data_lengthT; i++){
      this->st_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data);
      if (i < data_length) {
          memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
      }
      union {
        int32_t real;
        uint32_t base;
      } u_b_o_s;
      u_b_o_s.base = 0;
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b_o_s = u_b_o_s.real;
      offset += sizeof(this->b_o_s);
      union {
        int32_t real;
        uint32_t base;
      } u_e_o_s;
      u_e_o_s.base = 0;
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->e_o_s = u_e_o_s.real;
      offset += sizeof(this->e_o_s);
      union {
        int64_t real;
        uint64_t base;
      } u_granulepos;
      u_granulepos.base = 0;
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->granulepos = u_granulepos.real;
      offset += sizeof(this->granulepos);
      union {
        int64_t real;
        uint64_t base;
      } u_packetno;
      u_packetno.base = 0;
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->packetno = u_packetno.real;
      offset += sizeof(this->packetno);
#endif
     return offset;
    }

    const char * getType(){ return "theora_image_transport/Packet"; };
    const char * getMD5(){ return "33ac4e14a7cff32e7e0d65f18bb410f3"; };

  };

}
#endif