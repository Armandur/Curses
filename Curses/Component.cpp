#include "Component.h"

boost::uuids::random_generator Component:: rg = boost::uuids::random_generator();

Component::Component()
{
	_id = rg();
}


Component::~Component()
{
}

const boost::uuids::uuid& Component::id()
{
	return _id;
}

void Component::setParent(Entity* entity)
{
	parent = entity;
}
