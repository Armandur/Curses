#include "Entity.h"

boost::uuids::random_generator Entity:: rg = boost::uuids::random_generator();

Entity::Entity()
{
	init();
	_name = "undef";
}

Entity::Entity(std::string name)
{
	init();
	_name = name;
}

Entity::~Entity()
{

}

void Entity::name(std::string n)
{
	_name = n;
}

const std::string& Entity::name()
{
	return _name;
}

const boost::uuids::uuid& Entity::id()
{
	return _id;
}

const std::string Entity::toString() const
{
	std::stringstream ss;
	ss << "ID: " << _id << std::endl;
	ss << "Name: " << _name << std::endl;

	return ss.str();
}

void Entity::init()
{
	_id = rg();
}

void Entity::addComponent(std::string name, boost::shared_ptr<Component> component)
{
	if(components.find(name) != components.end())
	{
		throw "Component already exists";
		return;
	}

	components[name] = component;
}

void Entity::removeComponent(std::string name)
{
	if(components.find(name) == components.end())
	{
		throw "Tried to delete a non-existent component";
		return;
	}

	components.erase(name);
}

void Entity::removeComponent(boost::uuids::uuid id)
{
	for(auto it = components.begin(); it != components.end(); it++)
	{
		if(it->second->id() == id)
		{
			it = components.erase(it);
			return;
		}
	}

	throw "Tried to delete a non-existent component";
}

bool Entity::hasComponent(std::string name)
{
	return (components.find(name) != components.end());
}

bool Entity::hasComponent(boost::uuids::uuid id)
{
	for(auto it = components.begin(); it != components.end(); it++)
	{
		if(it->second->id() == id)
		{
			return true;
		}
	}

	return false;
}

boost::shared_ptr<Component> Entity::accessComponent(std::string name)
{
	if(components.find(name) == components.end())
	{
		throw "Tried to access a non-existent component";
		return nullptr;
	}

	return(components[name]);
}

boost::shared_ptr<Component> Entity::accessComponent(boost::uuids::uuid id)
{
	for(auto it = components.begin(); it != components.end(); it++)
	{
		if(it->second->id() == id)
		{
			return it->second;
		}
	}

	throw "Access: No component matches uuid";

	return nullptr;
}

void Entity::handleMessage(EntityMessage& message)
{
	for(auto it = components.begin(); it != components.end(); it++)
	{
		it->second->handleMessage(message);
	}
}