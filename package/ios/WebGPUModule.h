#pragma once

#include "RNWebGPUManager.h"
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

@interface WebGPUModule : NSObject <RCTBridgeModule>

@property(nonatomic, weak) RCTBridge *bridge;
@property(nonatomic, weak) RCTModuleRegistry *moduleRegistry;

- (rnwgpu::RNWebGPUManager *)getManager;

@end

#ifdef RCT_NEW_ARCH_ENABLED
#import <rnwebgpu/rnwebgpu.h>

@interface WebGPUModule () <WebGPUModuleSpec>
@end
#endif
