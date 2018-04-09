//
//  BGNetworkAgent.h
//  BGNetwork
//
//  Created by yanyan on 2018/4/3.
//  Copyright © 2018年 PotatoYY. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BGBaseRequest;

///  BGNetworkAgent is the underlying class that handles actual request generation,
///  serialization and response handling.
@interface BGNetworkAgent : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

///  Get the shared agent.
+ (BGNetworkAgent *)sharedAgent;

///  Add request to session and start it.
- (void)addRequest:(BGBaseRequest *)request;

///  Cancel a request that was previously added.
- (void)cancelRequest:(BGBaseRequest *)request;

///  Cancel all requests that were previously added.
- (void)cancelAllRequests;

///  Return the constructed URL of request.
///
///  @param request The request to parse. Should not be nil.
///
///  @return The result URL.
- (NSString *)buildRequestUrl:(BGBaseRequest *)request;

@end

NS_ASSUME_NONNULL_END

