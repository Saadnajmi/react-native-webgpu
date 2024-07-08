#pragma once

#include <memory>

#include "webgpu/webgpu_cpp.h"

#include <RNFHybridObject.h>

#include "RNFJSIConverter.h"

namespace jsi = facebook::jsi;

namespace rnwgpu {
class GPUBufferBinding {
public:
  wgpu::BufferBinding *getInstance() { return &_instance; }

  wgpu::BufferBinding _instance;
};
} // namespace rnwgpu

namespace margelo {

template <> struct JSIConverter<std::shared_ptr<rnwgpu::GPUBufferBinding>> {
  static std::shared_ptr<rnwgpu::GPUBufferBinding>
  fromJSI(jsi::Runtime &runtime, const jsi::Value &arg, bool outOfBounds) {
    auto result = std::make_unique<rnwgpu::GPUBufferBinding>();
    if (!outOfBounds && arg.isObject()) {
      auto value = arg.getObject(runtime);
      if (value.hasProperty(runtime, "buffer")) {
        auto buffer = value.getProperty(runtime, "buffer");

        if (buffer.isUndefined()) {
          throw std::runtime_error(
              "Property GPUBufferBinding::buffer is required");
        }
      } else {
        throw std::runtime_error(
            "Property GPUBufferBinding::buffer is not defined");
      }
      if (value.hasProperty(runtime, "offset")) {
        auto offset = value.getProperty(runtime, "offset");
      }
      if (value.hasProperty(runtime, "size")) {
        auto size = value.getProperty(runtime, "size");
      }
    }
    // else if () {
    // throw std::runtime_error("Expected an object for GPUBufferBinding");
    //}
    return result;
  }
  static jsi::Value toJSI(jsi::Runtime &runtime,
                          std::shared_ptr<rnwgpu::GPUBufferBinding> arg) {
    // No conversions here
    return jsi::Value::null();
  }
};
} // namespace margelo
