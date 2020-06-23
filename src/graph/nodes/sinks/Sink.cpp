//
// Created by Carson Fricke on 6/20/2020 8:50pm PST
//

#include "Sink.h"

namespace Graph {

	namespace Node {

		Tensor::Tensor<float> Sink::forward() {
			
			bool parents_are_visited = true;
			for (size_t parent_index = 0; parent_index < this->parents_size; parent_index++) {
				parents_are_visited = parents_are_visisted && this->parents[parent_index].visited;
			}

			if (parents_are_visited) {

				this->visited = true;

				// perform operation here

			}

		}

		Tensor::Tensor<float> Sink::backward() {

			this->visited = true;

			// perform operation here

			for (size_t parent_index = 0; parent_index < this->children_size; parent_index++) {
				this->parents[parent_index].backward();
			}

		}

	} // namespace Graph::Node

} // namespace Graph