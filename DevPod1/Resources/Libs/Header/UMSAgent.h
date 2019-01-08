/**
 * Cobub Razor
 *
 * An open source analytics iphone sdk for mobile applications
 *
 * @package		Cobub Razor
 * @author		WBTECH Dev Team
 * @copyright	Copyright (c) 2011 - 2012, NanJing Western Bridge Co.,Ltd.
 * @license		http://www.cobub.com/products/cobub-razor/license
 * @link		http://www.cobub.com/products/cobub-razor/
 * @since		Version 0.1
 * @filesource
 * SDK_version:
 *************************************************************
 2.0.0
 修复的问题:
 1.修改deviceId生成的bug
 2.clientdata日志中网络类型区分2G、3G、4G和WIFI
 3.修复接口上传时对特殊字符转义的bug,使用更全的转义API
 *************************************************************
 2.0.1
 修复的问题：
 1.优化usinglog日志结算的逻辑
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class WKWebView;

typedef NS_ENUM(NSInteger,UMSReportPolicy) {
    UMSReportPolicyBatch = 0,      //send data When APP Launch
    UMSReportPolicyRealtime = 1,   //send data realtime
    UMSReportPolicyInterval = 2    //send data interval
};

@interface UMSAgent : NSObject

#pragma mark - init
/**
 * 单例初始化
 *
 */
+ (instancetype)sharedUMSAgent;

#pragma mark - register app
/**
 *  向服务器注册第三方应用,并设置发送方式(系统默认采用UMSReportPolicyRealtime实时发送的方式。)
 *
 *
 *  @param appKey 开发者注册应用的appKey
 *  @param policy 日志上传方式
 *   UMSReportPolicyBatch --- 下次启动发送，系统会将数据缓存到临时文件中，待下次启动时一起将数据发送。如对实时性要求
 *   高，可采用此种方法。采用UMSReportPolicyBatch模式，减少APP与网络交互，节约流量，增强用户体验。
 *   UMSReportPolicyRealtime --- 实时发送为系统推荐模式，系统会将数据实时发送到平台。这样可以使数据及时准确的发送到平
 *   台系统。
 *   UMSReportPolicyInterval --- 间隔发送，SDK会每隔一定时间发送数据到平台。时间间隔通过SDK进行设置。
 */
+ (void)startWithAppKey:(NSString*)appKey reportPolicy:(UMSReportPolicy)policy serverURL:(NSString *)serverURL;

#pragma mark - setting
/**
 * 设置是否允许开启无码模式,请在startWithAppKey调用之前调用setWumaEnabled)
 *
 * @param wumaEnabled 是否开始无码圈选功能
 */
+ (void)setWumaEnabled:(BOOL)wumaEnabled;

/**
 *  是否采用在线配置的参数(如果希望使用服务器在线配置,请在startWithAppKey调用之前调用setOnLineConfig)
 *  具体的在线配置项如下：
 *  开启自动定位      对应本地设置API setAutoLocationEnabled
 *  wifi下才检查更新  对应本地设置API setUpdateOnlyWifi
 *  日志发送的模式    对应本地设置API setReportPolicy
 *  session相关设置  对应本地设置API setSessionmillis
 *  间隔发送的时间    对应本地设置API setSendInterval
 *  日志缓存大小上限  对应本地设置API setMaxFileSize
 *  备注：如果启动在线配置，那么本地API配置的选项将会被覆盖
 *  @param onlineConfig 是否采用在线配置
 */
+ (void)setOnLineConfig:(BOOL)onlineConfig;

/**
 *  是否开始自动定位功能。请在startWithAppKey调用之前调用setAutoLocationEnabled
 *
 *  @param autoLocationEnabled 是否开始自动定位功能
 */
+ (void)setAutoLocationEnabled:(BOOL)autoLocationEnabled;

/**
 * 设置在wifi环境下提示更新，请在startWithAppKey调用之前调用setUpdateOnlyWifi
 *
 * updateOnlyWifi 是否仅在wifi下更新
 */
+ (void)setUpdateOnlyWifi:(BOOL)updateOnlyWifi;

/**
 * 设置日志的发送模式，请在startWithAppKey调用之前调用setReportPolicy
 *
 * reportPolicy 日志发送模式
 */
+ (void)setReportPolicy:(UMSReportPolicy)reportPolicy;

/**
 * 设置Session的有效期，请在startWithAppKey调用之前调用setSessionmillis
 *
 * sessionmillis session有效期时长（秒）
 */
+ (void)setSessionmillis:(NSUInteger)sessionmillis;

/**
 * 设置在日志间隔发送模式的间隔时间，请在startWithAppKey调用之前调用setSendInterval
 *
 * sendInterval 日志间隔发送时间（分钟）
 */
+ (void)setSendInterval:(NSUInteger)sendInterval;

/**
 * 设置本地缓存文件的大小上限，请在startWithAppKey调用之前调用setMaxFileSize
 *
 * maxFileSize 日志大小的上限（M）
 */
+ (void)setMaxFileSize:(NSUInteger)maxFileSize;

/**
 *  是否打开调试日志,请在startWithAppKey调用之前调用setLogEnabled
 *
 *  @param logEnabled 是否打印调试日志
 */
+ (void)setLogEnabled:(BOOL)logEnabled;

/**
 *  手动设置DeviceID
 *  手动设置设备识别号。请在startWithAppKey调用之前调用setDeviceID，否则会导致数据不一致
 *
 *  @param deviceID DeviceID
 */
+ (void)setDeviceID:(NSString *)deviceID;

/**
 * 数据是否需要压缩
 *
 * @param gzipData 是否压缩
 */
+ (void)setIsGzipData:(BOOL)gzipData;

#pragma mark - bind userId
/**
 *  绑定用户ID，每个用户在应用中的userId都是不同的，需要主动调用API传入SDK
 *  例如可以传用户的手机号等
 *  @param userId 用户ID
 */
+ (void)bindUserIdentifier:(NSString *)userId;

#pragma mark - Error API
/**
 *  发送错误日志
 *
 *  @param stackTrace 错误栈信息
 */
+ (void)postErrorLog:(NSString *)stackTrace;

#pragma mark - Event API
/**
 *  发送单个事件
 *
 *  @param event_id 事件ID
 *  @param activity 事件页面标识
 */
+ (void)postEvent:(NSString *)event_id activity:(NSString *)activity;

/**
 *  发送单个事件,可以同时发送一个对应的标签
 *
 *  @param event_id 事件ID
 *  @param activity 事件页面标识
 *  @param label 标签
 */
+ (void)postEvent:(NSString *)event_id activity:(NSString *)activity label:(NSString *)label;

/**
 *  发送多个相同事件，多个高频率出现的事件，可采用此方法降低网络流量。
 *
 *  @param event_id 事件ID
 *  @param activity 事件页面标识
 *  @param acc      计数器
 */
+ (void)postEvent:(NSString *)event_id activity:(NSString *)activity  acc:(NSInteger)acc;

/**
 *  发送多个事件，并含有相应的标签
 *
 *  @param event_id 事件ID
 *  @param activity 事件页面标识
 *  @param label    标签
 *  @param acc      计数器
 */
+ (void)postEvent:(NSString *)event_id activity:(NSString *)activity label:(NSString *)label acc:(NSInteger)acc;

/**
 *  发送默认的系统事件，事件ID需要事先在系统配置好,ID默认为:default_maadmin_event
 *
 *  @param label 标签
 *  @param activity 事件页面标识
 *  @param acc   计数器
 */
+ (void)postGenericEvent:(NSString *)label activity:(NSString *)activity acc:(NSInteger)acc;

/**
 *  发送JSON数据，JSON数据格式为{"a":"avalue","b":"bvalue"....}
 *
 *  @param event_id 事件ID
 *  @param activity 事件页面标识
 *  @param jsonStr  json数据
 */
+ (void)postEventJSON:(NSString *)event_id activity:(NSString *)activity json:(NSString *)jsonStr;

/**
 * 发送加载的事件
 *
 * @param event_id 事件ID
 * @param activity 事件页面标识
 */
+ (void)postLoadEvent:(NSString *)event_id activity:(NSString *)activity;

//记录事件响应时间
+ (void)recordduration;

//页面开始加载时
+ (void)startLoadThisView:(NSString *)event_identifier withTime:(int)timeOut;

//页面结束加载时
+ (void)endLoadThisView:(NSString *)event_identifier;

#pragma mark - Tag API
/**
 *  绑定Tags
 *  用户可以自定义设置tag信息，并发送至后台
 *
 *  @param tag 标签
 */
+ (void)postTag:(NSString *)tag;

#pragma mark - Acitivity Log API
/**
 *  开始页面统计 注意此API要和endTracePage结束页面统计配合调用。
 *
 *  @param page_name 页面名称
 */
+ (void)startTracePage:(NSString *)page_name;

/**
 *  结束页面统计 注意此API要和startTracePage开始页面统计配合调用。
 *
 *  @param page_name 页面名称
 */
+ (void)endTracePage:(NSString *)page_name;

/**
 *  h5页面统计
 *
 *  @param page_name 页面名称
 */
+ (void)traceH5Page:(NSString *)page_name;

#pragma mark - h5 API
/**
 *  无码功能H5页面绑定操作
 *
 *  @param webView UIWebView对象
 */
+ (void)setWebView:(UIWebView *)webView;

/**
 *  无码功能H5页面绑定操作
 *
 *  @param webView WKWebView对象
 */
+ (void)setWkWebView:(WKWebView *)webView;

//获取服务器端绑定的事件列表
- (void)fetchAppEventTrackInfo;
@end
