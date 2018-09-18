//
//  NBSettings.h
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
 *  共通設定クラス
 *
 *  アプリ全体の設定値のうち、アプリ起動後にいつでも設定可能なパラメータを保持する。
 */
@interface NBSettings : NSObject

/**
 *  起動モード
 */
    typedef NS_ENUM (NSInteger, NBOperationMode) {
    /**
     *  オペレーション
     */
    NBOperationModeOperation,
    /**
     *  デバッグ
     */
    NBOperationModeDebug,
};

/**
 *  起動モードを取得する。
 *
 *  @return 起動モード
 */
+ (NBOperationMode)operationMode;

/**
 *  起動モードを設定する。
 *
 *  @param operationMode 起動モード
 */
+ (void)setOperationMode:(NBOperationMode)operationMode;

@end
