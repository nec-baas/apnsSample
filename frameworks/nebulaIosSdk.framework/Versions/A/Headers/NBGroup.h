//
//  NBGroup.h
//  nebulaIosSdk
//
//  COPYRIGHT (C) 2014 NEC CORPORATION
//
//  ALL RIGHTS RESERVED BY NEC CORPORATION, THIS PROGRAM
//  MUST BE USED SOLELY FOR THE PURPOSE FOR WHICH IT WAS
//  FURNISHED BY NEC CORPORATION, NO PART OF THIS PROGRAM
//  MAY BE REPRODUCED OR DISCLOSED TO OTHERS, IN ANY FORM
//  WITHOUT THE PRIOR WRITTEN PERMISSION OF NEC CORPORATION.
//
//  NEC CONFIDENTIAL AND PROPRIETARY
//

#import <Foundation/Foundation.h>
#import "NBBlocks.h"
@class NBAcl;

NS_ASSUME_NONNULL_BEGIN

/**
 *  グループクラス
 */
@interface NBGroup : NSObject

/**
 *  グループID
 */
@property (nonatomic, readonly, nullable) NSString *groupId;

/**
 *  グループネーム
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 *  ACL
 */
@property (nonatomic, nullable) NBAcl *acl;

/**
 *  ユーザ一覧
 */
@property (nonatomic, nullable) NSMutableArray<NSString *> *users;

/**
 *  グループ一覧
 */
@property (nonatomic, nullable) NSMutableArray<NSString *> *groups;

/**
 *  グループ情報作成時刻
 */
@property (nonatomic, readonly, nullable) NSDate *created;

/**
 *  グループ情報更新時刻
 */
@property (nonatomic, readonly, nullable) NSDate *updated;


/**
 *  グループ名を指定したイニシャライザ
 *
 *  @param name グループ名
 *
 *  @return NBGroupのインスタンス
 */
- (instancetype)initWithName:(nullable NSString *)name NS_DESIGNATED_INITIALIZER;

/**
 *  グループ名を指定したNBGroupの生成を行う
 *
 *  @param name グループ名
 *
 *  @return NBGroupのインスタンス
 */
+ (instancetype)groupWithName:(NSString *)name;

/**
 *  グループの新規作成・変更を行う。
 *
 *  @param block 実行結果を受け取るブロック
 */
- (void)saveInBackgroundWithBlock:(NBGroupsBlock)block;

/**
 *  グループの削除を行う。
 *
 *  @param block 実行結果を受け取るブロック
 */
- (void)deleteInBackgroundWithBlock:(NBResultBlock)block;

/**
 *  グループ情報の一覧取得を行う。
 *
 *  @param block 実行結果を受け取るブロック
 */
+ (void)queryGroupInBackgroundWithBlock:(NBGroupsBlock)block;

/**
 *  グループ情報の取得を行う。
 *
 *  @param name 検索対象のグループ名
 *  @param block 実行結果を受け取るブロック
 */
+ (void)getGroupInBackgroundWithName:(NSString *)name block:(NBGroupsBlock)block;

@end

NS_ASSUME_NONNULL_END

