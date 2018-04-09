//
//  BGNetwork.h
//  BGNetwork
//
//  Created by yanyan on 2018/4/3.
//  Copyright © 2018年 PotatoYY. All rights reserved.
//
#import <Foundation/Foundation.h>
#ifndef BGNetwork_h
#define BGNetwork_h
#if __has_include(<BGNetwork/BGNetwork.h>)

FOUNDATION_EXPORT double BGNetworkVersionNumber;
FOUNDATION_EXPORT const unsigned char BGNetworkVersionString[];

#import <BGNetwork/BGRequest.h>
#import <BGNetwork/BGBaseRequest.h>
#import <BGNetwork/BGNetworkAgent.h>
#import <BGNetwork/BGBatchRequest.h>
#import <BGNetwork/BGBatchRequestAgent.h>
#import <BGNetwork/BGChainRequest.h>
#import <BGNetwork/BGChainRequestAgent.h>
#import <BGNetwork/BGNetworkConfig.h>

#else

#import "BGRequest.h"
#import "BGBaseRequest.h"
#import "BGNetworkAgent.h"
#import "BGBatchRequest.h"
#import "BGBatchRequestAgent.h"
#import "BGChainRequest.h"
#import "BGChainRequestAgent.h"
#import "BGNetworkConfig.h"

#endif /* __has_include */

#endif /* BGNetwork_h */
