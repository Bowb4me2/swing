//
// Created by Carson Fricke on 8/14/2020 8:32pm PST
//


#include "Div.h"

namespace Tensor {

	namespace Operator {

		template<typename T>
		void Div<T>::procedure(T* out, T* arg0, T* arg1, Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			for (size_t index = 0; index < out_shape.size; index++) {
				out[index] = arg0[index] / arg1[index];
			}
		}

		template<typename T>
		void Div<T>::validate(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			if (!(out_shape.is_brodcastable(arg0_shape) || out_shape.is_brodcastable(arg1_shape))) {
				throw "input sizes are incompatible";
			}
		}

		template<typename T>
		bool Div<T>::requires_brodcast(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			return !arg0_shape.is_equal(arg1_shape);
		}

		template<typename T>
		bool Div<T>::brodcast_which(Shape out_shape, Shape arg0_shape, Shape arg1_shape) {
			
			if (out_shape.is_equal(arg1_shape)) {
				if (out_shape.is_brodcastable(arg0_shape)) {
					return true;
				}
				else {
					throw "not brodcastable";
				}
			}
			else if (out_shape.is_equal(arg0_shape)) {
				if (out_shape.is_brodcastable(arg1_shape)) {
					return false;
				}
				else {
					throw "not brodcastable";
				}
			}
		}

		template<typename T>
		Shape Div<T>::brodcast_shape(Shape out_shape, Shape arg0_shape, Shape arg1_shape, bool which)
		{
			return out_shape;
		}

		// explicit instantiations
		template class Div<int>;
		template class Div<float>;
		template class Div<double>;
		template class Div<unsigned int>;

	} // namespace Tensor::Operator

} // namespace Tensor