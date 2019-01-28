#include "redis_helper.h"

int RedisHelper::addErizoAgent(const std::string &area, const ErizoAgent &agent)
{
    std::string key = "erizo_agent_" + area;
    if (ACLRedis::getInstance()->hset(key, agent.id, agent.toJSON()) == -1)
        return 1;
    return 0;
}

int RedisHelper::removeErizoAgent(const std::string &area, const std::string &agent_id)
{
    std::string key = "erizo_agent_" + area;
    if (ACLRedis::getInstance()->hdel(key, agent_id) == -1)
        return 1;
    return 0;
}

int RedisHelper::addErizo(const std::string &agent_id, const Erizo &erizo)
{
    if (ACLRedis::getInstance()->hset(agent_id, erizo.id, erizo.toJSON()) == -1)
        return 1;
    return 0;
}

int RedisHelper::removeErizo(const std::string &agent_id, const std::string &erizo_id)
{
    if (ACLRedis::getInstance()->hdel(agent_id, erizo_id) == -1)
        return 1;
    return 0;
}

int RedisHelper::getAllErizo(const std::string &agent_id, std::vector<Erizo> &erizos)
{
    std::vector<std::string> fields, values;
    if (ACLRedis::getInstance()->hvals(agent_id, fields, values) == -1)
        return 1;
    erizos.clear();
    for (std::string &v : values)
    {
        Erizo e;
        if (!Erizo::fromJSON(v, e))
            erizos.push_back(e);
    }
    return 0;
}