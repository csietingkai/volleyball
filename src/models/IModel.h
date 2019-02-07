#ifndef I_MODEL_H_
#define I_MODEL_H_

#include <iostream>

#include "../beans/UUID.h"

namespace voba
{
	class IModel
	{
		public:
			IModel() {};
			
			virtual const UUID get_id() const { return this->id; };
			
			virtual void update_id(const UUID id) = 0;
		
		protected:
			UUID id;
	};
}

#endif // I_MODEL_H_
