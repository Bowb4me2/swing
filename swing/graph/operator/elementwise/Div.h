//
// Created by Carson Fricke on 6/27/2020 7:52pm PST
//

#ifndef __GRAPH_OPERATOR_DIV_H__
#define __GRAPH_OPERATOR_DIV_H__

#include "../VectorOperator.h"

namespace swing {

	namespace graph {

		namespace oper {

			class Div : public VectorOperator {

			protected:

				void populate_local_grads() override;

				void construct_constants() override;

			public:

				void get_operation(tensor::Tensor<scalar_t>& out) override;

			}; // class swing::graph::oper::Div

		} // namespace swing::graph::oper

	} // namespace swing::graph

} // namespace swing

#endif // end guards