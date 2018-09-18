//
//  NBCore.h
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

NS_ASSUME_NONNULL_BEGIN

/**
 *  初期化クラス
 *
 *  アプリ全体の設定値のうち、起動時に一度だけ設定するパラメータを保持する。
 */
@interface NBCore : NSObject <NSCopying>

/**
 *  アプリケーションID、アプリケーションキー、テナントIDの初期化を行う。
 *
 *  @param appId    アプリケーションID
 *  @param appKey   アプリケーションキー
 *  @param tenantId テナントID
 */
+ (void)setUpWithAppId:(nonnull NSString *)appId appKey:(nonnull NSString *)appKey tenantId:(nonnull NSString *)tenantId;

/**
 *  エンドポイントURIを設定する。nilを設定するとクラウド用URIとなる。
 *
 *  @param endPointUri エンドポイントURI
 */
+ (void)setEndPointUri:(nonnull NSString *)endPointUri;

/**
 *  アプリケーションIDを取得する。
 *
 *  @return アプリケーションID
 */
+ (NSString *)appId;

/**
 *  アプリケーションキーを取得する。
 *
 *  @return アプリケーションキー
 */
+ (NSString *)appKey;

/**
 *  テナントIDを取得する。
 *
 *  @return テナントID
 */
+ (NSString *)tenantId;

/**
 *  エンドポイントURIを取得する。
 *
 *  @return エンドポイントURI
 */
+ (NSString *)endPointUri;

/**
 *  セッションの再生成およびcompletionHandlerの保存
 *
 *  UIApplicationDelegate handleEventsForBackgroundURLSessionでコールする必要がある。
 *
 *  @param identifier        再生成するセッションのID
 *  @param completionHandler システムへ完了を通知するcompletionHandler
 */
+ (void)recreateSessionWithIdentifier:(NSString *)identifier completionHandler:(void (^)(void))completionHandler;

@end

NS_ASSUME_NONNULL_END

