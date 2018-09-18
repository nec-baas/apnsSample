//
//  NBObjectBucketManager.h
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
@class NBObjectBucket;

NS_ASSUME_NONNULL_BEGIN

/**
 *  ObjectBucketの管理クラス
 *
 *  Bucketの生成を行う。
 */
@interface NBObjectBucketManager : NSObject <NSCopying>

/**
 *  クラスファクトリ
 *
 *  本メソッドを使用してインスタンスを取得すること。
 *
 *  @return NBObjectBucketManagerのインスタンス
 */
+ (NBObjectBucketManager *)sharedInstance;

/**
 *  NBObjectBucketの生成
 *
 *  @param bucketName バケット名
 *
 *  @return NBObjectBucketのインスタンス
 */
- (NBObjectBucket *)bucketWithName:(NSString *)bucketName;

@end

NS_ASSUME_NONNULL_END
