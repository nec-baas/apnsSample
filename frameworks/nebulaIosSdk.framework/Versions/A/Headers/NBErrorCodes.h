//
//  NBErrorCodes.h
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

#ifndef nebulaIosSdk_NBErrorCodes_h
#define nebulaIosSdk_NBErrorCodes_h

/**
 *  エラーコード一覧
 */
typedef NS_ENUM (NSInteger,NBErrorCodes){
    /**
     *  Precondition Error
     */
    NBErrorPreconditionError = 1000,
    /**
     *  Invalid Argument Error
     */
    NBErrorInvalidArgumentError,
    /**
     *  Request Error
     */
    NBErrorRequestError = 1099,
    /**
     *  No information available.
     */
    NBErrorNoInfomation = 1100,
    /**
     *  Unsaved.
     */
    NBErrorUnsaved,
    /**
     *  Unable to retrieve valid session token
     */
    NBErrorInvalidSessionToken = 1200,
    /**
     *  Failed to download
     */
    NBErrorFailedToDownload
};


#endif
