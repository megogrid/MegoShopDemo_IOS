//
//  MewoGridInAppModel.h
//  MEPRO
//
//  Created by Daaid-iphone on 04/07/15.
//  Copyright (c) 2015 David-iphone. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MegoGridPurchaseDetails.h"


@protocol MegoGridInAppModelDelegate;


/*!
 @class MewoGridInAppModel
 @discussion Use this to configure feature with EventId which allows features to access either by purchasing or access them as free */


@interface MegoGridInAppModel : UIViewController



/*! @brief Indicates the Event ID of feature */
@property(nonatomic,retain)NSString *_featureId;

/*! @brief Indicates the navigation controller of Application.Pass the navigation of your App */
@property(nonatomic,retain)UINavigationController *custnavController;



/*!
 * @discussion This method perform all validation and give access to feature or not.
 * @param featureId Box ID of Feature.
 *
 *
 */

-(void)getFeatureIdStatus:(NSString*)featureId  item:(int)item;

/*!
 * @discussion This method returns whether all features are purchased.
 *
 * @result true/false
 *
 */
+(BOOL)isFullFeaturePurchased;

/*!
 * @discussion This method returns whether the given feature is purchased.
 * @param featureId Box ID of Feature.
 * @result true/false
 *
 */
+(BOOL)isFeaturePurchased:(NSString*)featureId;

/*!
 * @discussion This method returns the the inapptype (partial,permanent,subscription).
 * @param featureId Box ID of Feature.
 * @result inapptype
 *
 */
+(NSString*)getFeatureInAppType:(NSString*)featureId;

/*!
 * @discussion This method returns the type of Feature.It can be free,paid or trial.
 * @param featureId Box ID of Feature.
 * @result type of feature
 *
 */
+(NSString*)getFeatureType:(NSString*)featureId;


/*!
 * @discussion This method returns the name of Feature.
 * @param featureId Box ID of Feature.
 * @result name of feature
 *
 */
+(NSString*)getFeatureName:(NSString*)featureId;


/*!
 * @discussion This method returns the purchase status of Feature either 0 or 1.
 * @param featureId Box ID of Feature.
 * @result purchasestatus of feature
 *
 */
+(NSString*)getFeaturePurchaseStatus:(NSString*)featureId;

/*!
 * @discussion This method returns the minimum credits to purchase the feature.
 * @param featureId Box ID of Feature.
 * @result purchasestatus of feature
 *
 */
+(NSString*)getFeatureTotalCredits:(NSString*)featureId;



/*!
 * @discussion This method returns the discount type of feature either permanent or fixed.
 * @param featureId Box ID of Feature.
 * @result discount type of feature
 *
 */
+(NSString*)getFeatureDiscountType:(NSString*)featureId;

/*!
 * @discussion This method returns the discounted value of feature after providing discount on feature credits.
 * @param featureId Box ID of Feature.
 * @result discount value of feature
 *
 */
+(NSString*)getFeatureDiscountValue:(NSString*)featureId;


/*!
 * @discussion This method returns the discount on feature.
 * @param featureId Box ID of Feature.
 * @result discount on feature
 *
 */
+(NSString*)getFeatureDiscount:(NSString*)featureId;



/*!
 * @discussion This method returns all the ID of feature configured on CMS panel.
 *
 * @result discount on feature
 *
 */
+(NSMutableArray*)getAllFeatureId;

/*!
 * @discussion Returns all the child ID of respective Parent.
 * @param parentId Box ID of Parent Fetaure.
 * @result discount on feature
 *
 */

+(NSMutableArray*)getFeatureChildID:(NSString*)parentId;


/*!
 * @discussion Returns all the child Name of respective Parent.
 * @param parentId Box ID of Parent Fetaure.
 * @result discount on feature
 *
 */
+(NSMutableArray*)getAllFeatureChildName:(NSString*)parentId;




/*!
 * @discussion This method returns  the seasonalfrom date  of feature.
 * @param featureId Box ID of Feature.
 * @result sesonalfromdate on feature
 *
 */
+(NSString*)getSeasonaFromDate:(NSString*)featureId;

/*!
 * @discussion This method returns  the seasonal end date  of feature.
 * @param featureId Box ID of Feature.
 * @result sesonalenddate on feature
 *
 */
+(NSString*)getSeasonaEndDate:(NSString*)featureId;

/*!
 * @discussion This method returns number of days for which subscription is provided for feature after which feature will autorenew itself unless user cancels it manually.
 * @param featureId Box ID of Feature.
 * @result no of subscription days on feature
 *
 */
+(NSString*)getSubscriptionperiod:(NSString*)featureId;


/*!
 * @discussion This method returns remaining number of days for which subscription is provided for feature.
 * @param featureId Box ID of Feature.
 * @result no of subscription days on feature
 *
 */
+(NSString*)getleftSubscriptionperiod:(NSString*)featureId;



/*!
 * @discussion This method returns total number of partial days is provided after which the feature ie expired.
 * @param featureId Box ID of Feature.
 * @result no of subscription days on feature
 *
 */
+(NSString*)getpartialperiod:(NSString*)featureId;



/*!
 * @discussion This method returns remaining number of days for which partial period is provided for feature.
 * @param featureId Box ID of Feature.
 * @result no of subscription days on feature
 *
 */
+(NSString*)getleftpartialperiod:(NSString*)featureId;



/*!
 * @discussion This method returns the total credits of full feature.
 * @param featureId Box ID of Feature.
 * @result credits of fullfeature
 *
 */
+(NSString*)getFullFeatureCredits:(NSString*)featureId;

/*!
 * @discussion This method returns the purchase status of full feature.
 * @param featureId Box ID of Feature.
 * @result purchase status of fullfeature
 *
 */
+(NSString*)getFullFeaturePurchaseStatus:(NSString*)featureId;

/*!
 * @discussion This method returns the name of full feature.
 * @param featureId Box ID of Feature.
 * @result name of fullfeature
 *
 */
+(NSString*)getFullFeatureName:(NSString*)featureId;

/*!
 * @discussion This method returns the dicount provided on full feature.
 * @param featureId Box ID of Feature.
 * @result discount of fullfeature
 *
 */
+(NSString*)getFullFeatureDiscount:(NSString*)featureId;

/*!
 * @discussion This method returns the type of dicount provided on full feature.
 * @param featureId Box ID of Feature.
 * @result discounttype  of fullfeature
 *
 */
+(NSString*)getFullFeatureDiscountType:(NSString*)featureId;

/*!
 * @discussion This method returns the value of dicount provided on total credits of full feature.
 * @param featureId Box ID of Feature.
 * @result discounttype  of fullfeature
 *
 */
+(NSString*)getFullFeatureDiscountValue:(NSString*)featureId;


/*!
 * @discussion This method returns the inappprice to purchase the feature.
 * @param featureId Box ID of Feature.
 * @result inappprice of feature
 *
 */
+(NSString*)getFeaturePrice:(NSString*)featureId;


/*!
 * @discussion This method returns the currency of feature.
 * @param featureId Box ID of Feature.
 * @result currency of feature
 *
 */
+(NSString*)getFeatureCurrency:(NSString*)featureId;



/*!
 * @discussion This method returns number of days for which feature is accessible.
 * @param featureId Box ID of Feature.
 * @result total number of days of feature
 *
 */
+(NSString*)getFeatureTotalTrial:(NSString*)featureId;


/*!
 * @discussion This method returns number of days remaining for which feature is accessible.
 * @param featureid Box ID of Feature.
 * @result left number of days of feature
 *
 */
+(NSString*)getTrialLeft:(NSString*)featureid;


/*!
 * @discussion This method returns number of usage for which feature is accessible.
 * @param featureId Box ID of Feature.
 * @result usage of feature
 *
 */
+(NSString*)getFeatureTotalCount:(NSString*)featureId;


/*!
 * @discussion This method returns number of remaining usage for which feature is accessible.
 * @param featureId Box ID of Feature.
 * @result remaining usage of feature
 *
 */
+(NSString*)getFeatureCountLeft:(NSString*)featureId;


/*!
 * @discussion This method returns wheather feature can be purchased with adds.
 * @param featureId Box ID of Feature.
 * @result 0/1
 *
 */
+(NSString*)isUnlockWithAddsEnable:(NSString*)featureId;


/*!
 * @discussion This method returns wheather paid feature is given access or not.
 * @param featureId Box ID of Feature.
 * @result 0/1
 *
 */
+(NSString*)isFeatureLockStatusEnable:(NSString*)featureId;



/*!
 * @discussion This method returns the trialtype of Feature.It can be count,trial,trialcount,individual,concurrent.
 * @param featureId Box ID of Feature.
 * @result trialtype of feature
 *
 */
+(NSString*)getFeatureTrialType:(NSString*)featureId;


/*!
 * @discussion This method returns the number of days for which feature is given free access after which it trial starts.
 * @param featureId Box ID of Feature.
 * @result start days of feature
 *
 */
+(NSString*)getFeatureStartDay:(NSString*)featureId;


/*!
 * @discussion This method returns whether some kind of limit is given for feature.
 * @param featureId Box ID of Feature.
 * @result 0/1 for feature
 *
 */
+(NSString*)isLimitAplied:(NSString*)featureId;


/*!
 * @discussion This method returns number of days for which limit is given.
 * @param featureId Box ID of Feature.
 * @result limit period for feature
 *
 */

+(NSString*)getFeaturelimitPeriod:(NSString*)featureId;

/*!
 * @discussion This method returns how much limit is given for feature.
 * @param featureId Box ID of Feature.
 * @result limit Value for feature
 *
 */

+(NSString*)getFeaturelimitValue:(NSString*)featureId;

/*!
 * @discussion This method returns whether the items of feature is provided access in sequential manner or in unordered manner.
 * @param featureId Box ID of Feature.
 * @result 1 - Concuurent+Reoccurence,2-Concurrent+Nonreoccurence,3-Individual
 *
 */

+(NSString*)getFeaturemaxType:(NSString*)featureId;


/*!
 * @discussion This method returns the number of items given access.
 * @param featureId Box ID of Feature.
 * @result max count
 *
 */
+(NSString*)getFeaturemaxCount:(NSString*)featureId;




-(void)beginTransaction:(NSString*)Coins;
+(MegoGridPurchaseDetails*)getPurchaseStatus:(NSString*)boxID;
-(void)startPurchase:(NSString*)boxID mode:(NSString*)mode;
-(void)getTotalCoins;


+(void)intializeBoxCounter:(NSString*)BoxID;
+(void)addBoxCounter:(NSString*)BoxID;
+(void)removeBoxCounter:(NSString*)BoxID;
+(void)deleteBoxCounter:(NSString*)BoxID;
+(BOOL)isItemRangeValid:(NSString*)BoxID;
-(void)trialFeature:(NSString*)featureId;
-(void)trialcountFeature:(NSString*)featureId;
-(void)countFeature:(NSString*)featureId;
-(void)paidFeature:(NSString*)featureId;





@property (nonatomic,retain) id <MegoGridInAppModelDelegate> delegate;




@end
/*!
 @protocol MewoGridInAppModelDelegate
 
 @brief The MewoGridInAppModelDelegate protocol
 
 Use this to recieve callback for feature access allowed or restricted after the feature is clicked.
 */
@protocol MegoGridInAppModelDelegate <NSObject>
@optional

/*!
 * @discussion Callback sent when a feature is accessible.
 * @param mewo The MewoGridInAppModel instance.
 *  *
 */
-(void)isAccessGiven:(MegoGridInAppModel*)mewo didFinishWithStuff:(NSString*)status;
-(void)isFeaturePurchase:(MegoGridInAppModel*)purchase;
-(void)remCoinsSuccess:(MegoGridInAppModel*)dismiss;
-(void)remCoinsFailure:(MegoGridInAppModel*)dismiss;
-(void)totalCoinsSuccess:(MegoGridInAppModel*)dismiss :(NSString*)totalCoins;

-(void)productPurchasedSuccess:(MegoGridInAppModel*)dismiss;
-(void)productPurchasedFailed:(MegoGridInAppModel*)dismiss;


@end





