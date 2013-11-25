#include "EntityMessage.h"


EntityMessage::EntityMessage()
{
}


EntityMessage::~EntityMessage()
{
}


void EntityMessage::addArgument(std::string key, boost::variant<std::string, double> val)
{
	arguments[key] = val;
}

void EntityMessage::removeArgument(std::string key)
{
	if(arguments.find(key) == arguments.end())
	{
		throw "Tried to delete a non-existent component";
		return;
	}

	arguments.erase(key);
}

bool EntityMessage::hasArgument(std::string key)
{
	if(arguments.find(key) == arguments.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

EntityMessageType& EntityMessage::type()
{
	return _type;
}

void EntityMessage::type(const EntityMessageType& t)
{
	_type = t;
}

boost::variant<double, std::string> EntityMessage::getValue(std::string key)
{
	if(arguments.find(key) == arguments.end())
	{
		throw "Tried to get value of non-existent key";
		return -1;
	}

	return arguments[key];
}

const std::string EntityMessage::toString() const
{
	std::stringstream ss;

	ss << "EntityMessage" << std::endl;
	
	for(auto it = arguments.begin(); it != arguments.end(); it++)
	{
		ss << it->first << ": ";

		std::string _type = "";

		if (it->second.type() == typeid(double))
		{
			ss << boost::get<double>(it->second);
		}
		else if (it->second.type() == typeid(std::string))
		{
			ss << boost::get<std::string>(it->second);
		}

		ss << std::endl;
	}

	return ss.str();
}
