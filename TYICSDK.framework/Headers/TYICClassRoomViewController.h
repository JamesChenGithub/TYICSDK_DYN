//
//  TYICClassRoomViewController.h
//  TIC_Web_SaaS_SDK
//
//  Created by AlexiChen on 2020/5/6.
//  Copyright © 2020 AlexiChen. All rights reserved.
//
// TYICSDKDebugVersion : 2.0.304
// TYICSDKGitCommitID : 6b969c4d384b552a7abeceab33bbfa818346faa7

#import <UIKit/UIKit.h>
#import "TYICClassRoomConfig.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *_Nonnull const TYIC_SDK_Version;

// 开始加载课堂通知
extern NSString *_Nonnull const TYICWebViewStartLoadNotify;
// 加载课堂失败通知
extern NSString *_Nonnull const TYICWebViewLoadFailedNotify;
// 加载课堂H5完成通知
extern NSString *_Nonnull const TYICWebViewLoadCompleteNotify;
// 进入课堂（TRTC enterRoom）完成通知
extern NSString *_Nonnull const TYICEnterClassRoomCompleteNotify;
// 开始退出课堂（TRTC exitRoom）通知
extern NSString *_Nonnull const TYICStartExitClassRoomNotify;
// TYICClassRoomViewController实例释放，完全退出通知
extern NSString *_Nonnull const TYICExitClassRoomCompleteNotify;


@interface TYICClassRoomViewController : UIViewController

// 使用+classRoomWithConfig:uiOption:webOption 进行构建
+ (instancetype)new  __attribute__((unavailable("Use +classRoomWithConfig:uiOption:webOption instead")));
- (instancetype)init __attribute__((unavailable("Use +classRoomWithConfig:uiOption:webOption instead")));

/**
* 使用H5+Native方式使用
* @param roomConfig : 打开教室所需要的配置
* @param uiOption : 如果要进教室，配置UI相关的参数;
* @param webOption : webview相关的配置;
*/
+ (instancetype _Nullable)classRoomWithConfig:(TYICClassRoomConfig * _Nonnull)roomConfig uiOption:(NSDictionary *_Nullable)uiOption webOption:(NSDictionary *_Nullable)webOption;

@end

NS_ASSUME_NONNULL_END
