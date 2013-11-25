#ifndef PHYSICALCOMPONENT_H
#define PHYSICALCOMPONENT_H

#include "Common.h"

#include "Component.h"

class PhysicalComponent : public Component
{
	public:
		PhysicalComponent();
		~PhysicalComponent();

		ComponentType getType();
		void handleMessage(EntityMessage& message);

	private:
		int posY;
		int posX;

		void setPositionMsg(EntityMessage& messsage);
};

#endif