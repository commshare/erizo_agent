#ifndef CONFIG_H
#define CONFIG_H

#include <string>

#include <json/json.h>
#include <logger.h>

class Config
{
  DECLARE_LOGGER();

public:
  static Config *getInstance();
  ~Config();
  int init(const std::string &config_file);

public:
  // RabbitMQ config
  std::string rabbitmq_username_;
  std::string rabbitmq_passwd_;
  std::string rabbitmq_hostname_;
  unsigned short rabbitmq_port_;

  //Agent config 
  std::string agent_ip_;

private:
  Config();

private:
  static Config *instance_;
};

#endif