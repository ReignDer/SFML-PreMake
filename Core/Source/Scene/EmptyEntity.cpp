#include "Corepch.h"
#include "EmptyEntity.h"

namespace Core {
	EmptyEntity::EmptyEntity(const std::string& name) : Entity(name)
	{
	}
	EmptyEntity::~EmptyEntity()
	{
	}
	void EmptyEntity::initialize()
	{
	}
}
