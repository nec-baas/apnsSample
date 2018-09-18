//
//  NBFileBucketManager.h
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
#import "NBFileBucket.h"
#import "NBBlocks.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ファイルバケットの管理クラス
 *
 *  バケットの生成を行う。
 */

@interface NBFileBucketManager : NSObject

/**
 *  クラスファクトリ
 *
 *  本メソッドを使用してインスタンスを取得すること。
 *
 *  @return NBFileBucketManagerのインスタンス
 */
+ (instancetype)sharedInstance;

/**
 *  NBObjectBucketの生成
 *
 *  @param bucketName バケット名
 *
 *  @return NBFileBucketのインスタンス
 */
- (NBFileBucket *)bucketWithBucketName:(NSString *)bucketName;

@end

NS_ASSUME_NONNULL_END
