#pragma once
#include "Builder.h"
class EntityPoolable : public Core::Entity
{
public:

	EntityPoolable(const std::string& name);
	virtual void initialize() = 0;
	virtual void OnRelease() = 0;
	virtual void OnActivate() = 0;

	virtual EntityPoolable* clone() = 0;


};

