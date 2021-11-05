#include <torch/extension.h>

#include <iostream>

#include <torch/csrc/jit/codegen/cuda/interface.h>
#include <torch/csrc/jit/frontend/function_schema_parser.h>
#include <torch/csrc/jit/ir/constants.h>

#include <unordered_map>
#include <utility>

void register_squeeze() {
  printf("registered\n");
  auto ptr_op = torch::jit::getOperatorForLiteral("aten::unsqueeze(Tensor(a) self) -> Tensor(a)");
  torch::jit::fuser::cuda::addParseRule(
      ptr_op,
      [](std::vector<void*> inputs) -> std::vector<void*> {
      });
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("register", &register_squeeze, "squeeze registered");
}
