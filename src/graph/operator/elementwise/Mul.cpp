//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#include "Mul.h"

#include "../../../tensor/operator/elementwise/Mul.h"

namespace Graph {

	namespace Operator {

		void Mul::get_operation(Tensor::Tensor<scalar_t>& out) {

			for (size_t input_index = 1; input_index < this->inputs.get_size(); input_index++) {

				Tensor::Operator::mul(out, this->inputs[input_index - 1], this->inputs[input_index]);
			}
		}

		void Mul::get_jacobians(Tensor::TensorArray<scalar_t>& out) {

		}

		void Mul::init(Tensor::Shape operation_shape) {

			this->operation_shape = operation_shape;

			this->aggregate_grad = Tensor::Tensor<scalar_t>(operation_shape);

			construct_jacobians();
		}

	} // namespace Graph::Operator

} // namespace Graph
