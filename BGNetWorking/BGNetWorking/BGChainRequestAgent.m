//
//  BGChainRequestAgent.m
//  BGNetwork
//
//  Created by yanyan on 2018/4/3.
//  Copyright © 2018年 PotatoYY. All rights reserved.
//


#import "BGChainRequestAgent.h"
#import "BGChainRequest.h"

@interface BGChainRequestAgent()

@property (strong, nonatomic) NSMutableArray<BGChainRequest *> *requestArray;

@end

@implementation BGChainRequestAgent

+ (BGChainRequestAgent *)sharedAgent {
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

- (void)addChainRequest:(BGChainRequest *)request {
    @synchronized(self) {
        [_requestArray addObject:request];
    }
}

- (void)removeChainRequest:(BGChainRequest *)request {
    @synchronized(self) {
        [_requestArray removeObject:request];
    }
}

@end

