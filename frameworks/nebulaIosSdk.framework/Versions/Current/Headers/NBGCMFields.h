//
//  NBGCMFields.h
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
 *  GCMメッセージフィールドクラス
 *
 *  Pushメッセージ内のAndroid固有値データクラス
 */
@interface NBGCMFields : NSObject

/**
 *  システムバーに表示するタイトル
 *
 *  初期値はnil、nilオブジェクトは要求時のデータには含まれない。
 */
@property (nonatomic, nullable) NSString *title;

/**
 *  通知を開いたときに起動する URI
 *
 *  初期値はnil、nilオブジェクトは要求時のデータには含まれない。
 */
@property (nonatomic, nullable) NSString *uri;

/**
 *  GCMメッセージフィールドインスタンス作成
 *
 *  GCMメッセージフィールドインスタンスを作成する。
 *
 *  @return GCMメッセージフィールドインスタンス
 */
+ (NBGCMFields *)createFields;

/**
 *  GCMメッセージフィールドデータ取得
 *
 *  GCMメッセージフィールドクラスのオブジェクトをNSDictionary型で取得する。
 *  nilオブジェクト、NSNull値を持つKeyは含まれない。
 *
 *  @return NSDictionaryデータ
 */
- (NSDictionary<NSString *, id> *)dictionaryValue;

@end

NS_ASSUME_NONNULL_END
