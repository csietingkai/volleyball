#ifndef I_MODEL_H_
#define I_MODEL_H_

#include <iostream>

namespace voba
{
	class IModel
	{
		public:
			IModel() {};
			
			virtual const std::string get_id() const { return this->id; };
			
			virtual void update_id() = 0;
		
		protected:
			std::string id;
	};
}

#endif // I_MODEL_H_
