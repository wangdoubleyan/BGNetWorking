//
//  BGBatchRequestAgent.h
//  BGNetwork
//
//  Created by yanyan on 2018/4/3.
//  Copyright © 2018年 PotatoYY. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BGBatchRequest;

///  BGBatchRequestAgent handles batch request management. It keeps track of all
///  the batch requests.
@interface BGBatchRequestAgent : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

///  Get the shared batch request agent.
+ (BGBatchRequestAgent *)sharedAgent;

///  Add a batch request.
- (void)addBatchRequest:(BGBatchRequest *)request;

///  Remove a previously added batch request.
- (void)removeBatchRequest:(BGBatchRequest *)request;

@end

NS_ASSUME_NONNULL_END

