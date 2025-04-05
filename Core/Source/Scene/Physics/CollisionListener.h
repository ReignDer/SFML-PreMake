#pragma once
#include "Scene/Entity.h"
namespace Core {
	class CollisionListener
	{
	public:
		virtual void OnCollisionEnter(Entity* entity) = 0;
		virtual void OnCollisionExit(Entity* entity) = 0;
		virtual void OnCollisionStay(Entity* entity) = 0;

	protected:
		CollisionListener() {}
	};
}

