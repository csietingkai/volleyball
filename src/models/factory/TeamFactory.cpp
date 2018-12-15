#include "TeamFactory.h"

voba::MySQLConnector<voba::Team> voba::TeamFactory::connector;

const voba::Team& voba::TeamFactory::create()
{
	return voba::TeamFactory::connector.select("id");
}
