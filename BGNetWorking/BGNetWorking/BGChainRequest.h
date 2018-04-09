//
//  BGChainRequest.h
//  BGNetwork
//
//  Created by yanyan on 2018/4/3.
//  Copyright © 2018年 PotatoYY. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BGChainRequest;
@class BGBaseRequest;
@protocol BGRequestAccessory;

///  The BGChainRequestDelegate protocol defines several optional methods you can use
///  to receive network-related messages. All the delegate methods will be called
///  on the main queue. Note the delegate methods will be called when all the requests
///  of chain request finishes.
@protocol BGChainRequestDelegate <NSObject>

@optional
///  Tell the delegate that the chain request has finished successfully.
///
///  @param chainRequest The corresponding chain request.
- (void)chainRequestFinished:(BGChainRequest *)chainRequest;

///  Tell the delegate that the chain request has failed.
///
///  @param chainRequest The corresponding chain request.
///  @param request      First failed request that causes the whole request to fail.
- (void)chainRequestFailed:(BGChainRequest *)chainRequest failedBaseRequest:(BGBaseRequest*)request;

@end

typedef void (^BGChainCallback)(BGChainRequest *chainRequest, BGBaseRequest *baseRequest);

///  BGBatchRequest can be used to chain several BGRequest so that one will only starts after another finishes.
///  Note that when used inside BGChainRequest, a single BGRequest will have its own callback and delegate
///  cleared, in favor of the batch request callback.
@interface BGChainRequest : NSObject

///  All the requests are stored in this array.
- (NSArray<BGBaseRequest *> *)requestArray;

///  The delegate object of the chain request. Default is nil.
@property (nonatomic, weak, nullable) id<BGChainRequestDelegate> delegate;

///  This can be used to add several accossories object. Note if you use `addAccessory` to add acceesory
///  this array will be automatically created. Default is nil.
@property (nonatomic, strong, nullable) NSMutableArray<id<BGRequestAccessory>> *requestAccessories;

///  Convenience method to add request accessory. See also `requestAccessories`.
- (void)addAccessory:(id<BGRequestAccessory>)accessory;

///  Start the chain request, adding first request in the chain to request queue.
- (void)start;

///  Stop the chain request. Remaining request in chain will be cancelled.
- (void)stop;

///  Add request to request chain.
///
///  @param request  The request to be chained.
///  @param callback The finish callback
- (void)addRequest:(BGBaseRequest *)request callback:(nullable BGChainCallback)callback;

@end

NS_ASSUME_NONNULL_END

