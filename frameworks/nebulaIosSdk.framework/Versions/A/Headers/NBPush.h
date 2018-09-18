//
//  NBPush.h
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

@class NBAPNSFields;
@class NBGCMFields;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Pushクラス
 *
 *  Pushメッセージ送信を行うクラス
 */
@interface NBPush : NSObject

/**
 *  送信先インスタレーションを指定するためのクエリ
 *
 *  NBClauseにて生成したクエリをNSDictionary型で設定する。
 *  初期値はnil、nilオブジェクトは要求時のデータには含まれない。
 */
@property (nonatomic, nullable) NSDictionary *query;

/**
 *  Pushメッセージ本文
 *
 *  初期値はnil、nilオブジェクトは要求時のデータには含まれない。
 */
@property (nonatomic, nullable) NSString *message;

/**
 *  通知を受信可能なユーザ・グループの一覧
 *
 *  受信可能なユーザ・グループを制限することが可能。
 *
 *  適合する owner (allowedReceivers に含まれるユーザIDの１つに一致する、もしくは
 *  allowedReceivers に指定されたグループのいずれかに所属する)がセットされているインスタレーションに
 *  対してのみ Push が配信される。
 *
 *  allowedReceivers に適合しないか、または owner が設定されていないインスタレーションには配信されない。
 *  allowedReceivers を指定しなかった場合は、配信の制限は実施されず、query で指定された全インスタレーション
 *  に Push 配信される。
 *
 *  初期値はnil、nilオブジェクトは要求時のデータには含まれない。
 */
@property (nonatomic, nullable) NSArray<NSString *> *allowedReceivers;

/**
 *  iOS 固有値
 *
 *  初期値はnil、nilオブジェクトは要求時のデータには含まれない。
 */
@property (nonatomic, nullable) NBAPNSFields *apnsFields;

/**
 *  Android 固有値
 *
 *  初期値はnil、nilオブジェクトは要求時のデータには含まれない。
 */
@property (nonatomic, nullable) NBGCMFields *gcmFields;

/**
 *  Pushメッセージ送信
 *
 *  Pushメッセージを送信する。
 *
 *  @param block 実行結果を受け取るブロック
 */
- (void)sendPushInBackgroundWithBlock:(NBPushBlock)block;

@end

NS_ASSUME_NONNULL_END
