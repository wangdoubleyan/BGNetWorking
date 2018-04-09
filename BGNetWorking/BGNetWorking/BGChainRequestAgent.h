//
//  BGChainRequestAgent.h
//  BGNetwork
//
//  Created by yanyan on 2018/4/3.
//  Copyright © 2018年 PotatoYY. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BGChainRequest;

///  BGChainRequestAgent handles chain request management. It keeps track of all
///  the chain requests.
@interface BGChainRequestAgent : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

///  Get the shared chain request agent.
+ (BGChainRequestAgent *)sharedAgent;

///  Add a chain request.
- (void)addChainRequest:(BGChainRequest *)request;

///  Remove a previously added chain request.
- (void)removeChainRequest:(BGChainRequest *)request;

@end

NS_ASSUME_NONNULL_END

