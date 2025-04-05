#pragma once
#include "Entity.h"

namespace Core {
	class EmptyEntity : public Entity
	{
	public:
		EmptyEntity(const std::string& name);
		virtual ~EmptyEntity();
		virtual void initialize() override;
		
	};
}