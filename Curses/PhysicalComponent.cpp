#include "PhysicalComponent.h"


PhysicalComponent::PhysicalComponent()
{
}


PhysicalComponent::~PhysicalComponent()
{
}

void PhysicalComponent::handleMessage(EntityMessage& message)
{
	switch(message.type())
	{
		case ENTMSG_MOVE :
				setPositionMsg(message);
			break;

		default:
			break;
	}
}

void PhysicalComponent::setPositionMsg(EntityMessage& messsage)
{
	if(messsage.hasArgument("posY"))
	{
		posX = (int)boost::get<double>(messsage.getValue("posY"));
	}

	if(messsage.hasArgument("posX"))
	{
		posX = (int)boost::get<double>(messsage.getValue("posX"));
	}
}
