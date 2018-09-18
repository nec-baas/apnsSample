//
//  NBObjectBucket.h
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
@class NBQuery;
@class NBObject;

NS_ASSUME_NONNULL_BEGIN

/**
 *  ObjectBucketクラス
 *
 *  所属するNBObjectの管理機能を提供する。
 */
@interface NBObjectBucket : NSObject

/**
 *  Bucket名
 *
 *  bucket生成時に指定したbucket名
 */
@property (nonatomic, readonly, copy) NSString *bucketName;

/**
 *  bucket名を指定したイニシャライザ
 *
 *  @param name Bucket名
 *
 *  @return 初期化したインスタンス
 */
- (instancetype)initWithBucketName:(NSString *)name NS_DESIGNATED_INITIALIZER;

/**
 *  Objectの取得処理
 *
 *  オブジェクトIDを指定してバケットからNebulaObjectを検索する。
 *
 *  @param objectId 取得対象のObjectId
 *  @param block    処理結果のコールバック。NBObjectsListBlockのシグネチャのBlockを指定すること。
 */
- (void)getObjectInBackgroundWithId:(NSString *)objectId block:(NBObjectsBlock)block;

/**
 *  BucketからObjectを検索する。
 *
 *  @param query  検索条件を設定したNBQuery
 *  @param block  処理結果のコールバック。NBObjectsListBlockのシグネチャのBlockを指定すること。
 */
- (void)queryInBackgroundWithQuery:(NBQuery *)query block:(NBObjectsBlock)block;

/**
 *  NBObjectの生成
 *
 *  NBObjectを新規作成する場合に使用する。
 *
 *  @return Bucket名で初期化したNBObjectのインスタンス
 */
- (NBObject *)createObject;

@end

NS_ASSUME_NONNULL_END