//
//  MewoGridPurchaseDetails.h
//  PhotoApp
//
//  Created by vibhuti-iphone on 08/01/16.
//  Copyright (c) 2016 Migital. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MegoGridPurchaseDetails : NSObject


@property(nonatomic,strong)NSString* childBoxId;
@property(nonatomic,assign)BOOL childPurchaseStatus;
@property(nonatomic,assign)BOOL childSubscriptionRem;
@property(nonatomic,strong)NSString* parentBoxId;
@property(nonatomic,assign)BOOL parentPurchaseStatus;
@property(nonatomic,assign)BOOL parentSubscriptionRem;

@end
