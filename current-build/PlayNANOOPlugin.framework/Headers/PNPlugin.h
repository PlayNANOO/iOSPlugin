//
//  PNPlugin.h
//  PlayNANOOPlugin_BaseTool
//
//  Created by JONGHYUN LIM on 14/08/2019.
//  Copyright © 2019 JONGHYUN LIM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AdSupport/AdSupport.h>
#import <UIKit/UIKit.h>
#import <PlayNANOOPlugin/PNDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface PNPlugin : NSObject {
    NSMutableDictionary *optionalDict;
}
@property (nonatomic, strong) id<PNDelegate> delegate;

-(instancetype)initWithPlugin:(NSString *)uniqueUserID;
-(instancetype)initWithPlugin:(NSString *)uniqueUserID userName:(NSString *)userName;
-(instancetype)initWithPlugin:(NSString *)uniqueUserID userName:(NSString *)userName userLanguage:(NSString *)userLanguage;
-(instancetype)initWithPluginInfo:(NSString *)appID serviceKey:(NSString *)serviceKey secretKey:(NSString *)secretKey uniqueUserID:(NSString *)uniqueUserID;
-(instancetype)initWithPluginInfo:(NSString *)appID serviceKey:(NSString *)serviceKey secretKey:(NSString *)secretKey uniqueUserID:(NSString *)uniqueUserID userName:(NSString *)userName;
-(instancetype)initWithPluginInfo:(NSString *)appID serviceKey:(NSString *)serviceKey secretKey:(NSString *)secretKey uniqueUserID:(NSString *)uniqueUserID userName:(NSString *)userName userLanguage:(NSString *)userLanguage;

// Change Language
-(void)userLanguage:(NSString *)language;
 
// Change Name
-(void)userName:(NSString *)name;

// Access
-(void)accessEvent;

// Stats
-(void)statsConnect:(NSString *)state;

// Coupon
-(void)couponUse:(NSString *)code;

//Forum
//-(void)forumThread:(NSString *)language section:(NSString *)section limit:(NSInteger *)limit;
-(void)forumThread:(NSString *)section limit:(NSInteger *)limit;
-(void)forumThread:(NSInteger *)limit;

// Postbox
-(void)postbox;
-(void)postboxItemUse:(NSString *)uid;
-(void)postboxItemSend:(NSString *)itemCode itemCount:(NSInteger *)itemCount itemExpireDay:(NSInteger *)itemExpireDay itemMessage:(NSString *)itemMessage ;
-(void)postboxItemSend:(NSString *)itemCode itemCount:(NSInteger *)itemCount itemExpireDay:(NSInteger *)itemExpireDay;
-(void)postboxItemFriendSend:(NSString *)friendUUID itemCode:(NSString *)itemCode itemCount:(NSInteger *)itemCount itemExpireDay:(NSInteger *)itemExpireDay itemMessage:(NSString *)itemMessage ;
-(void)postboxItemFriendSend:(NSString *)friendUUID itemCode:(NSString *)itemCode itemCount:(NSInteger *)itemCount itemExpireDay:(NSInteger *)itemExpireDay;
-(void)postboxClear;
-(void)postboxSubscriptionRegister:(NSString *)productUUID;
-(void)postboxSubscriptionRegister:(NSString *)productUUID offset:(NSInteger *)offset;
-(void)postboxSubscriptionCancel:(NSString *)productUUID;

// InAppPurchase
-(void)iapiOS:(NSString *)productUID receipt:(NSString *)receipt currency:(NSString *)currency price:(long)price;

// Storage
-(void)storageSave:(NSString *)key value:(NSString *)value isPrivate:(BOOL)isPrivate;
-(void)storageLoad:(NSString *)key;

// Ranking
-(void)rankingSeason:(NSString *)uid;
-(void)rankingRecord:(NSString *)uid score:(long)score data:(NSString *)data;
-(void)rankingList:(NSString *)uid limit:(NSInteger *)limit;
-(void)rankingList:(NSString *)uid season:(NSInteger *)season limit:(NSInteger *)limit;
-(void)rankingPersonal:(NSString *)uid;
-(void)rankingPersonal:(NSString *)uid season:(NSInteger *)season;

// Forum
-(void)openBanner:(UIViewController *)viewController;
-(void)openForm:(UIViewController *)viewController;
-(void)openForumView:(UIViewController *)viewController url:(NSString *)url;

// HelpDesk
-(void)helpDeskOptional:(NSString *)key value:(NSString *)value;
-(void)openHelpDesk:(UIViewController *)viewController;
@end

NS_ASSUME_NONNULL_END
