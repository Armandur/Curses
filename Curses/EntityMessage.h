#ifndef ENTITYMESSAGE_H
#define ENTITYMESSAGE_H

#include "Common.h"

enum EntityMessageType
{
	ENTMSG_MOVE
};

class EntityMessage
{
	public:
		EntityMessage();
		~EntityMessage();

		void addArgument(std::string key, boost::variant<std::string, double> val);

		void removeArgument(std::string key);

		bool hasArgument(std::string key);

		EntityMessageType& type();

		void type(const EntityMessageType& t);

		boost::variant<double, std::string> getValue(std::string key);

		const std::string toString() const;
	
	private:
		std::map<std::string, boost::variant<std::string, double> > arguments;
		EntityMessageType _type;
};

#endif