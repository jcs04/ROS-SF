/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/yenn/catkin_ws/src/px4flow_normalized_trajectory/msg/Px4flow_trajectory.msg
 *
 */


#ifndef PX4FLOW_NORMALIZED_TRAJECTORY_MESSAGE_PX4FLOW_TRAJECTORY_H
#define PX4FLOW_NORMALIZED_TRAJECTORY_MESSAGE_PX4FLOW_TRAJECTORY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace px4flow_normalized_trajectory
{
template <class ContainerAllocator>
struct Px4flow_trajectory_
{
  typedef Px4flow_trajectory_<ContainerAllocator> Type;

  Px4flow_trajectory_()
    : header()
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , q(0.0)  {
    }
  Px4flow_trajectory_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , q(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef float _q_type;
  _q_type q;




  typedef boost::shared_ptr< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct Px4flow_trajectory_

typedef ::px4flow_normalized_trajectory::Px4flow_trajectory_<std::allocator<void> > Px4flow_trajectory;

typedef boost::shared_ptr< ::px4flow_normalized_trajectory::Px4flow_trajectory > Px4flow_trajectoryPtr;
typedef boost::shared_ptr< ::px4flow_normalized_trajectory::Px4flow_trajectory const> Px4flow_trajectoryConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace px4flow_normalized_trajectory

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'px4flow_normalized_trajectory': ['/home/yenn/catkin_ws/src/px4flow_normalized_trajectory/msg'], 'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fd728a3a24d70db0fa56f146a4e98970";
  }

  static const char* value(const ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfd728a3a24d70db0ULL;
  static const uint64_t static_value2 = 0xfa56f146a4e98970ULL;
};

template<class ContainerAllocator>
struct DataType< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "px4flow_normalized_trajectory/Px4flow_trajectory";
  }

  static const char* value(const ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float32 x\n\
float32 y\n\
float32 z\n\
float32 q\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.q);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Px4flow_trajectory_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::px4flow_normalized_trajectory::Px4flow_trajectory_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "q: ";
    Printer<float>::stream(s, indent + "  ", v.q);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PX4FLOW_NORMALIZED_TRAJECTORY_MESSAGE_PX4FLOW_TRAJECTORY_H