//
//  NBUser.h
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

NS_ASSUME_NONNULL_BEGIN

/**
 *  ユーザクラス
 */
@interface NBUser : NSObject

/**
 *  ユーザID
 */
@property (nonatomic, readonly, nullable) NSString *userId;

/**
 *  ユーザネーム
 */
@property (nonatomic, nullable) NSString *username;

/**
 *  Emailアドレス
 */
@property (nonatomic, nullable) NSString *email;

/**
 *  ユーザ情報作成時刻
 */
@property (nonatomic, readonly, nullable) NSDate *created;

/**
 *  ユーザ情報更新時刻
 */
@property (nonatomic, readonly, nullable) NSDate *updated;

/**
 *  ユーザのサインアップを行う。
 *
 *  @param password サインアップするユーザのパスワード
 *  @param block    実行結果を受け取るブロック
 */
- (void)signUpInBackgroundWithPassword:(NSString *)password block:(NBUserBlock)block;

/**
 *  ユーザのログインを行う。
 *
 *  @param username ログインするユーザのユーザネーム
 *  @param email    ログインするユーザのEmailアドレス
 *  @param password ログインするユーザのパスワード
 *  @param block    実行結果を受け取るブロック
 */
+ (void)logInInBackgroundWithUsername:(nullable NSString *)username email:(nullable NSString *)email password:(NSString *)password block:(NBUserBlock)block;

/**
 *  ログアウトを行う。
 *
 *  @param block 実行結果を受け取るブロック
 */
+ (void)logOutInBackgroundWithBlock:(NBUserBlock)block;

/**
 *  パスワードのリセット要求を行う。
 *
 *  @param username リセット対象のユーザネーム
 *  @param email    リセット対象のEmailアドレス
 *  @param block    実行結果を受け取るブロック
 */
+ (void)resetPasswordInBackgroundWithUsername:(nullable NSString *)username email:(nullable NSString *)email block:(NBResultBlock)block;

/**
 *  ユーザ情報の変更を行う。
 *
 *  @param password 変更するユーザのパスワード
 *  @param block    実行結果を受け取るブロック
 */
- (void)saveInBackgroundWithPassword:(NSString *)password block:(NBUserBlock)block;

/**
 *  ユーザの削除を行う。
 *
 *  @param block 実行結果を受け取るブロック
 */
- (void)deleteInBackgroundWithBlock:(NBResultBlock)block;

/**
 *  ユーザ情報の検索を行う。
 *
 *  @param username 検索対象のユーザネーム
 *  @param email    検索対象のEmailアドレス
 *  @param block    実行結果を受け取るブロック
 */
+ (void)queryUserInBackgroundWithUsername:(nullable NSString *)username email:(nullable NSString *)email block:(NBUsersBlock)block;

/**
 *  ユーザ情報の取得を行う。
 *
 *  @param userId 検索対象のユーザID
 *  @param block  実行結果を受け取るブロック
 */
+ (void)getUserInBackgroundWithUserId:(NSString *)userId block:(NBUserBlock)block;

/**
 *  現在ログインしているユーザの情報を取得する。
 *
 *  @param block 実行結果を受け取るブロック
 */
+ (void)refreshCurrentUserInBackgroundWithBlock:(NBUserBlock)block;

/**
 *  現在ログインしているユーザの情報をキャッシュから取得する(通信を行わない)。
 *
 *  @return ログイン中ユーザのユーザ情報
 */
+ (nullable NBUser *)currentUser;

/**
 *  ログイン状態の確認を行う。
 *
 *  @return ログイン中であればYES、未ログインであればNO
 */
+ (BOOL)loggedIn;

/**
 *  セッショントークンを取得する。
 *
 *  @return セッショントークン
 */
+ (nullable NSString *)sessionToken;

/**
 *  セッショントークンの有効期限を取得する。
 *
 *  @return セッショントークンの有効期限
 */
+ (long long)sessionTokenExpiration;

@end

NS_ASSUME_NONNULL_END
