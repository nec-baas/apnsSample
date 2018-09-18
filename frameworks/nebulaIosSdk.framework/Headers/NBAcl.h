//
//  NBAcl.h
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

#import "NBAclBase.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  ACLクラス
 *
 *  バケットやオブジェクト自体のACLを指定するクラス
 */

@interface NBAcl : NBAclBase

/**
 *  管理者ユーザリスト
 */
@property (nonatomic) NSMutableArray<NSString *> *admin;

/**
 *  オーナユーザID
 */
@property (nonatomic, nullable) NSString *owner;

@end

NS_ASSUME_NONNULL_END
