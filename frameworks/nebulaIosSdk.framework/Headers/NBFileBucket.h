//
//  NBFileBucket.h
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
#import "NBFile.h"
#import "NBBlocks.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ファイルバケットクラス
 *
 *  所属するファイルの管理機能を提供する。
 */

@interface NBFileBucket : NSObject


/**
 *  検索対象指定
 */
    typedef NS_ENUM (NSInteger,NBFileConditions){
    /**
     *  指定なし
     */
    NBFileConditionNone = 0,
    /**
     *  公開ファイルのみ
     */
    NBFileConditionPublished
};

/**
 *  バケット名
 */
@property (nonatomic, readonly, copy) NSString *bucketName;

/**
 *  バケット名を指定したイニシャライザ
 *
 *  @param name バケット名
 *
 *  @return 初期化したインスタンス
 */
- (instancetype)initWithName:(NSString *)name NS_DESIGNATED_INITIALIZER;

/**
 *  Objectの生成
 *
 *  Objectを新規作成する場合に使用する。
 *
 *  @return バケット名で初期化したNBFileのインスタンス
 */
- (NBFile *)createObject;

/**
 *  ファイル一覧(メタデータ)をダウンロードする
 *
 *  リクエストパラメータで指定がある場合は、公開済みファイル一覧をダウンロードする
 *
 *  @param conditions ファイル公開状態
 *  @param block      実行結果を受け取るブロック
 */
- (void)queryFileInBackgroundWithConditions:(NBFileConditions)conditions block:(NBFilesBlock)block;

/**
 *  特定ファイルのメタデータを取得する
 *
 *  @param name       取得希望ファイル名
 *  @param block      実行結果を受け取るブロック
 */
- (void)getFileInBackgroundWithFilename:(NSString *)name block:(NBFilesBlock)block;

@end

NS_ASSUME_NONNULL_END
