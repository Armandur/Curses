#ifndef ENTITY_H
#define ENTITY_H

#include "Common.h"

class Component;
class EntityMessage;

class Entity
{
	public:
		Entity();
		Entity(std::string name);
		~Entity();

		void name(std::string n);
		const std::string& name();

		const boost::uuids::uuid& id();

		const std::string toString() const;

		void addComponent(std::string name, boost::shared_ptr<Component>);
		
		void removeComponent(std::string name);
		void removeComponent(boost::uuids::uuid id);

		bool hasComponent(std::string name);
		bool hasComponent(boost::uuids::uuid id);

		boost::shared_ptr<Component> accessComponent(std::string name);
		boost::shared_ptr<Component> accessComponent(boost::uuids::uuid id);

		void handleMessage(EntityMessage& message);

	private:

		void init();

		boost::uuids::uuid _id;
		static boost::uuids::random_generator rg;

		std::string _name;

		std::map<std::string, boost::shared_ptr<Component>> components;
};

#endif