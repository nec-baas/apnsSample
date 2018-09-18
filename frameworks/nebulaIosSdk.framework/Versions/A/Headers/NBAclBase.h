//
//  NBAclBase.h
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

/**
 *  ACL基底クラス
 *
 *  ２種類のACLクラスでの共通部実装箇所
 */

NS_ASSUME_NONNULL_BEGIN

/**
 *  権限一覧
 */
typedef NS_ENUM (NSInteger,NBAclPermissions){
    /**
     *  読み込み
     */
    NBAclReadable = 0,
    /**
     *  書き込み
     */
    NBAclWritable,
    /**
     *  作成
     */
    NBAclCreatable,
    /**
     *  削除
     */
    NBAclDeletable,
    /**
     *  更新
     */
    NBAclUpdatable,
    /**
     *  管理者
     */
    NBAclAdmin,
    /**
     *  オーナ
     */
    NBAclOwner
};

@interface NBAclBase : NSObject

/**
 *  読み込み許可リスト
 */
@property (nonatomic) NSMutableArray<NSString *> *r;

/**
 *  書き込み許可リスト
 */
@property (nonatomic) NSMutableArray<NSString *> *w;

/**
 *  更新許可リスト
 */
@property (nonatomic) NSMutableArray<NSString *> *u;

/**
 *  作成許可リスト
 */
@property (nonatomic) NSMutableArray<NSString *> *c;

/**
 *  削除許可リスト
 */
@property (nonatomic) NSMutableArray<NSString *> *d;

/**
 *  権限追加
 *
 *  権限許可リストにユーザIDまたはグループを追加する。
 *
 *  @param entry      ユーザIDまたはグループ名
 *  @param permission 権限
 *
 *  @return 処理結果（YES:成功/NO:失敗）
 */
- (BOOL)addEntry:(NSString *)entry
    permission:(NBAclPermissions)permission;

/**
 *  権限削除
 *
 *  権限許可リストからユーザIDまたはグループを削除する。
 *
 *  @param entry      ユーザIDまたはグループ名
 *  @param permission 権限
 *
 *  @return 処理結果（YES:成功/NO:失敗）
 */
- (BOOL)removeEntry:(NSString *)entry
    permission:(NBAclPermissions)permission;

/**
 *  権限許可リスト一括取得
 *
 *  設定済みの権限情報をNSDictionary型で返却する。
 *
 *  @return 権限リスト
 */
- (NSDictionary *)entriesDictionary;

/**
 *  権限許可リスト一括設定
 *
 *  権限をNSDictionary型で一括設定する。
 *
 *  @param dictionary 権限リスト
 */
- (void)setEntriesDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
