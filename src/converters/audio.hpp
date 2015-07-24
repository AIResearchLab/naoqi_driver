/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef AUDIO_EVENT_CONVERTER_HPP
#define AUDIO_EVENT_CONVERTER_HPP

/*
* LOCAL includes
*/
#include "converter_base.hpp"
#include <alrosbridge/message_actions.h>

/*
* ROS includes
*/
#include <naoqi_msgs/AudioBuffer.h>

/*
* ALDEBARAN includes
*/
#include <qi/anymodule.hpp>

namespace alros{

namespace converter{

class AudioEventConverter : public BaseConverter<AudioEventConverter>
{

  typedef boost::function<void(naoqi_msgs::AudioBuffer&) > Callback_t;

public:
  AudioEventConverter(const std::string& name, const float& frequency, const qi::SessionPtr& session);

  ~AudioEventConverter();

  virtual void reset();

  void registerCallback( const message_actions::MessageAction action, Callback_t cb );

  void callAll(const std::vector<message_actions::MessageAction>& actions, naoqi_msgs::AudioBuffer& msg);

private:
  /** Registered Callbacks **/
  std::map<message_actions::MessageAction, Callback_t> callbacks_;
  naoqi_msgs::AudioBuffer msg_;
};

}

}

#endif // AUDIO_CONVERTER_HPP