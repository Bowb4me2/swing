//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#include "Source.h"


namespace swing {

	namespace graph {

		namespace node {

			Source::Source(tensor::Tensor<scalar_t>& contents)
				: Node(contents) {

			}

			void Source::init_input() {

				this->visited = true;

				// init operator here

				for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {

					this->children[child_index].add_input(this->contents);

					this->children[child_index].add_in_grad(*this->contents.clone());

					this->children[child_index].init_input();
				}
			}

			void Source::init_grad() {

				bool children_are_visited = true;
				for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {
					children_are_visited = children_are_visited && this->children[child_index].is_visited();
				}


				if (children_are_visited) {

					this->visited = true;

					// init operator here

				}
			}

			void Source::add_input(tensor::Tensor<scalar_t>& input) {
				// shouldent ever run, has no inputs
			}

			void Source::add_in_grad(tensor::Tensor<scalar_t>& grad) {
				// shouldent ever run because no parents will be differentiable
			}

			void Source::add_out_grad(tensor::Tensor<scalar_t>& grad) {
				// needs fixing. add grad manager, like SGD or Adam for sources
				// this->operation.add_grad(grad);
			}

			void Source::forward() {

				this->visited = true;

				// perform operation here

				for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {

					this->children[child_index].forward();
				}

			}

			void Source::backward() {

				bool children_are_visited = true;
				for (size_t child_index = 0; child_index < this->children.get_size(); child_index++) {
					children_are_visited = children_are_visited && this->children[child_index].is_visited();
				}


				if (children_are_visited) {

					this->visited = true;

					// operation here


				}

			}

		} // namespace swing::graph::node

	} // namespace swing::graph

} // namespace swing