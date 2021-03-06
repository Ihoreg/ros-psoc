#ifndef _ROS_SERVICE_GetPointMap_h
#define _ROS_SERVICE_GetPointMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace map_msgs
{

static const char GETPOINTMAP[] = "map_msgs/GetPointMap";

  class GetPointMapRequest : public ros::Msg
  {
    public:

    GetPointMapRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
#endif
     return offset;
    }

    const char * getType(){ return GETPOINTMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPointMapResponse : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 map;

    GetPointMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      offset += this->map.serialize(outbuffer + offset);
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      offset += this->map.deserialize(inbuffer + offset);
#endif
     return offset;
    }

    const char * getType(){ return GETPOINTMAP; };
    const char * getMD5(){ return "b84fbb39505086eb6a62d933c75cb7b4"; };

  };

  class GetPointMap {
    public:
    typedef GetPointMapRequest Request;
    typedef GetPointMapResponse Response;
  };

}
#endif
