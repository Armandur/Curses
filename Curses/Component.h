#ifndef COMPONENT_H
#define COMPONENT_H

#include "Common.h"

class Entity;

enum ComponentType
{
	COMPONENT
};

class Component
{
	public:
		Component();
		~Component();

		const boost::uuids::uuid& id();

		virtual ComponentType getType() = 0;
		virtual void handleMessage(EntityMessage& message) = 0;
		void setParent(Entity* entity);

	private:
		Entity *parent;
		boost::uuids::uuid _id;
		static boost::uuids::random_generator rg;
};

#endif