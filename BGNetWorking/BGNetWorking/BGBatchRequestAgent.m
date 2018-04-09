//
//  BGBatchRequestAgent.m
//  BGNetwork
//
//  Created by yanyan on 2018/4/3.
//  Copyright © 2018年 PotatoYY. All rights reserved.
//

#import "BGBatchRequestAgent.h"
#import "BGBatchRequest.h"

@interface BGBatchRequestAgent()

@property (strong, nonatomic) NSMutableArray<BGBatchRequest *> *requestArray;

@end

@implementation BGBatchRequestAgent

+ (BGBatchRequestAgent *)sharedAgent {
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _requestArray = [NSMutableArray array];
    }
    return self;
}

- (void)addBatchRequest:(BGBatchRequest *)request {
    @synchronized(self) {
        [_requestArray addObject:request];
    }
}

- (void)removeBatchRequest:(BGBatchRequest *)request {
    @synchronized(self) {
        [_requestArray removeObject:request];
    }
}

@end

