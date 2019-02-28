#include "IModel.h"

const voba::UUID voba::IModel::get_id() const
{
	// return id value
	return this->id;
}

void voba::IModel::update_id(const voba::UUID id)
{
	// set id value
	this->id = id;
}
