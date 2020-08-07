# TYICSDK 使用说明

## 功能介绍

`TYICSDK` 为 腾云互动课堂apass方案SDK简称

## iOS 集成

### pod 集成方式

1. 在工程`Poddile` 文件中添加依赖 `pod 'TYICSDK'`, `TYICSDK` 依赖以下 pod 库，在执行pod install命令时会自动安装。

```
pod 'Masonry'
pod 'YYModel'
pod 'TXLiteAVSDK_TRTC'
```

2.  在终端中跳到`Podfile`所在目录，`pod install` 即可自动安装所需要的依赖;


### 使用说明

1. 在使用处引用 `#import  <TYICSDK/TYICClassRoomViewController.h>` 即可

2. `TYICClassRoomConfig`说明

| 字段 | 类型 | 描述 | 必传 | 
| ---- | ---- | ---- | ---- |
| userId |  string |  进教室用户的userId，可参考 [云 API - 学生老师注册](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=3%e5%ad%a6%e7%94%9f%e8%80%81%e5%b8%88%e6%b3%a8%e5%86%8c) | 必传 |
| token | string | 可参考 [云 API - 换取票据](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=4-%e6%8d%a2%e5%8f%96%e7%a5%a8%e6%8d%ae)，返回的token信息 | 必传 |
| userSig | string | 可参考 [云 API - 换取票据](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=4-%e6%8d%a2%e5%8f%96%e7%a5%a8%e6%8d%ae)，返回的userSig信息 | 必传 |
| newEnterId | string | 机构ID，可参考 [云 API - 创建机构](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=1%e5%88%9b%e5%bb%ba%e6%9c%ba%e6%9e%84) | 必传 |
| classId | uint32 | 课堂编号，可参考 [云 API- 创建课堂](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=12-%e5%88%9b%e5%bb%ba%e8%af%be%e5%a0%82)| 必传 | 

2. `TYICClassRoomViewController `说明

| API | 说明 | 
| --- | ---- | 
| TYIC_SDK_Version | SDK版本号 | 
| TYICWebViewStartLoadNotify | 开始加载课堂通知 |
| TYICWebViewLoadFailedNotify | 加载课堂失败通知 |
| TYICWebViewLoadCompleteNotify | 加载课堂H5完成通知 |
| TYICWebViewLoadCompleteNotify | 进入课堂（TRTC enterRoom）完成通知 |
| TYICStartExitClassRoomNotify | 开始退出课堂（TRTC exitRoom）通知 |
| TYICExitClassRoomCompleteNotify | TYICClassRoomViewController实例释放，完全退出通知 |
|  + (instancetype)classRoomWithConfig:(TYICClassRoomConfig *)roomConfig <br>uiOption:(NSDictionary *)uiOption <br>webOption:(NSDictionary *)webOption | 创建上课页面viewcontroller方法，roomConfig必传，如果roomConfig参数不合法（主要是是空），会返回空, uiOption/webOption 非必传填nil即可，主要方便后续扩展 |

示例代码如下:

```
TYICClassRoomConfig *roomConfig = [[TYICClassRoomConfig alloc] init];
roomConfig.userId = "test";
roomConfig.userSig = "test_usersig";
roomConfig.token = "test_token";
roomConfig.classId = 123454;
roomConfig.newEnterId = xxxxx;
            
TYICClassRoomViewController *vc = [TYICClassRoomViewController classRoomWithConfig:roomConfig uiOption:nil webOption:nil];
if (vc) {
	[(UINavigationController *)self.window.rootViewController pushViewController:vc animated:YES];
} else {
	NSLog(@"参数有误");
}
```

**注意事项**：
1. 如果的你App配置类似下面: 1. 支持iPad ,  2. 支持所有方向；**那么请勾选上 `Requires full screen` 选项 (该选项对现有App不影响)**，否则 ` TYICClassRoomViewController ` 无法正常旋转至横屏

![](https://main.qcloudimg.com/raw/26926026e4a4ed5d565ede21258a47ab.png)



## Android使用方式

### 开发环境
* Android studio 3.0+
* Android 4.4（API 19）及以上系统

### 快速集成 SDK
在项目中快速集成 TYIC 组件，TYIC 组件已发布到 jcenter，您可以通过配置 gradle 自动下载更新。使用 Android Studio 打开需要集成 SDK 的工程，然后通过简单的三个步骤修改`app/build.gradle`文件，即可完成 SDK 集成。

1. 添加 SDK 依赖。在`dependencies`中添加 TYIC 以及其它模块的依赖。

```groovy
 dependencies {
    // TYIC aPaaS 组件
    implementation "com.tencent.tyic:tyicsdk:latest.release"
    // 实时音视频
    implementation "com.tencent.liteav:LiteAVSDK_TRTC:7.2.8927"
}
```

TYIC组件默认引用普通版 TRTC。如果您需要集成专业版 TRTC，首先要把 TYIC 组件依赖的 TRTC 剔除掉，然后集成专业版 TRTC。具体可参考以下示例：

```groovy
 dependencies {
     // TYIC aPaaS 组件
    implementation("com.tencent.tyic:tyicsdk:latest.release") {
        exclude group: 'com.tencent.liteav', module: 'LiteAVSDK_TRTC'
    }
}
```

2. 指定 App 使用架构。在`defaultConfig`中，指定 App 使用的 CPU 架构（目前 TYIC 支持`armeabi`和`armeabi-v7a`）。

```groovy
  defaultConfig {
      ndk {
          abiFilters "armeabi", "armeabi-v7a"
      }
  }
```

3. 使用 JDK 1.8 编译。

```groovy
compileOptions {
    sourceCompatibility 1.8
    targetCompatibility 1.8
}
```

4. 同步 SDK。单击【Sync Now】，如果您的网络连接 jcenter 正常，SDK 就会自动下载集成到工程中。

### 申请必要权限（Android 6.0 以上）
Android 6.0 以上系统，拉起组件前，需动态申请麦克风录音、摄像头和写存储器权限。

```java
Manifest.permission.RECORD_AUDIO
Manifest.permission.CAMERA
Manifest.permission.WRITE_EXTERNAL_STORAGE
```

### 调起 SaaS 组件
只需传递5个参数就可调起 TYIC 组件主页面，分别为SDKAppID、课堂编号、用户账号、用户签名、Token和NewEnterID。

```java
Intent intent = new Intent(getActivity(), InClassActivity.class);
intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_SINGLE_TOP);

Bundle bundle = new Bundle();
bundle.putLong(Constants.KEY_CLASS_CLASS_ID, classId);
bundle.putString(Constants.KEY_CLASS_USER_ID, userId);
bundle.putString(Constants.KEY_CLASS_USER_SIG, userSig);
bundle.putString(Constants.KEY_CLASS_TOKEN, token);
bundle.putInt(Constants.KEY_CLASS_NEW_ENTER_ID, newEnterId);

intent.putExtras(bundle);
startActivity(intent);
```

