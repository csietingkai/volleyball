#ifndef I_MODEL_H_
#define I_MODEL_H_

#include <iostream>

#include "../beans/UUID.h"

namespace voba
{
	class IModel
	{
		public:
			/**
			 * constructor of interface IModel
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			IModel() {};
			
			/**
			 * get id value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			const UUID get_id() const;
			
			/**
			 * update id value
			 * 
			 * @CreatedBy tingkai
			 * @Date 2018.12.18
			 */
			void update_id(const UUID id);
		
		protected:
			UUID id;
	};
}

#endif // I_MODEL_H_
