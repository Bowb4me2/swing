//
// Created by Carson Fricke on 6/23/2020 2:43pm PST
//

#include "Operator.h"
#include "../../tensor/operator/tensor_operators.h"

namespace Graph {

	namespace Operator {

		void Operator::construct_jacobians() {

			Tensor::Shape jacobian_shape;

			Tensor::Tensor<scalar_t>* jacobian;

			for (size_t jacobian_index = 0; jacobian_index < this->inputs.get_size(); jacobian_index++) {

				jacobian_shape = Tensor::Shape::concatenate(this->operation_shape, this->inputs[jacobian_index].get_shape());

				jacobian = new Tensor::Tensor<scalar_t>(jacobian_shape);

				this->jacobians.push_back(*jacobian);
			}
		}

		void Operator::add_input(Tensor::Tensor<scalar_t>& input) {
			this->inputs.push_back(input);
		}

		void Operator::add_grad(Tensor::Tensor<scalar_t>& grad) {
			this->grads.push_back(grad);
		}

		void Operator::aggregate_grads(Tensor::TensorArray<scalar_t>& out) {

			for (size_t grad_index = 0; grad_index < this->grads.get_size(); grad_index++) {
				Tensor::operate(this->aggregate_grad, this->aggregate_grad, this->grads[grad_index], Tensor::Operators::add);
			}

		}

		void Operator::clear() {
			this->inputs.clear();

			this->grads.clear();
		}

	} // namespace Graph::Operator

} // namespace Graph
